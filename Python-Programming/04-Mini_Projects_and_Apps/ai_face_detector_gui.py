"""
AI Face Detector: A Graphical User Interface for Face Recognition.
Uses OpenCV for detection and Tkinter for the UI.
"""

import cv2
import tkinter as tk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk
import os

class FaceDetectorApp:
    def __init__(self, window):
        self.window = window
        self.window.title("AI Face Recognition System")
        self.window.geometry("650x500")

        # Let's check if the Haar Cascade file exists.
        self.cascade_path = 'haarcascade_frontalface_default.xml'
        if not os.path.exists(self.cascade_path):
            # If the file doesn't exist, OpenCV will try to retrieve it using its own path.
            self.cascade_path = cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'

        self.face_cascade = cv2.CascadeClassifier(self.cascade_path)

        # UI Components
        self.canvas = tk.Canvas(window, width=600, height=400, bg="#2c3e50")
        self.canvas.pack(pady=20)

        self.btn_frame = tk.Frame(window)
        self.btn_frame.pack()

        self.open_button = tk.Button(
            self.btn_frame, 
            text="Select Image", 
            command=self.process_image,
            width=20,
            bg="#3498db",
            fg="white",
            font=("Arial", 10, "bold")
        )
        self.open_button.pack(side=tk.LEFT, padx=10)

        self.exit_button = tk.Button(
            self.btn_frame, 
            text="Exit", 
            command=window.quit,
            width=10,
            bg="#e74c3c",
            fg="white"
        )
        self.exit_button.pack(side=tk.LEFT)

    def process_image(self):
        file_path = filedialog.askopenfilename(
            filetypes=[("Image Files", "*.jpg *.jpeg *.png *.bmp")]
        )
        
        if not file_path:
            return

        # Read image
        img = cv2.imread(file_path)
        if img is None:
            messagebox.showerror("Error", "Could not read the image file.")
            return

        # Face detection operations
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        faces = self.face_cascade.detectMultiScale(
            gray, 
            scaleFactor=1.2, 
            minNeighbors=5, 
            minSize=(30, 30)
        )

        # Frame the identified faces.
        for (x, y, w, h) in faces:
            cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 3)
            cv2.putText(img, "Face Detected", (x, y - 10), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)

        # Convert the image to Tkinter format.
        img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        img_pil = Image.fromarray(img_rgb)
        
        # Size while maintaining the aspect ratio.
        img_pil.thumbnail((600, 400), Image.LANCZOS)
        img_tk = ImageTk.PhotoImage(img_pil)

        # Draw on canvas
        self.canvas.img = img_tk  # Keep a reference to prevent garbage collection.
        self.canvas.delete("all")
        self.canvas.create_image(300, 200, anchor=tk.CENTER, image=img_tk)

if __name__ == "__main__":
    root = tk.Tk()
    app = FaceDetectorApp(root)
    root.mainloop()
