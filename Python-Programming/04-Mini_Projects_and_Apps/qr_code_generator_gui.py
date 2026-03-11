"""
QR Code Generator: A GUI tool to generate and save QR codes as SVG files.
Demonstrates the use of pyqrcode and tkinter's file saving dialogs.
"""

import tkinter as tk
from tkinter import filedialog, messagebox
import pyqrcode

def generate_qr():
    """Extracts URL from input, generates a QR code, and prompts for save location."""
    input_text = url_entry.get().strip()

    if not input_text:
        messagebox.showwarning("Input Error", "Please enter a valid URL or text.")
        return

    try:
        # Create the QR code object
        qr_obj = pyqrcode.create(input_text)
        
        # Open file dialog to choose save location
        save_path = filedialog.asksaveasfilename(
            defaultextension=".svg",
            filetypes=[("SVG files", "*.svg"), ("All files", "*.*")],
            title="Save QR Code As"
        )

        if save_path:
            # Save as SVG with scale factor for better quality
            qr_obj.svg(save_path, scale=8)
            status_label.config(text="QR Code generated and saved successfully!", fg="#27ae60")
            messagebox.showinfo("Success", f"QR Code saved to:\n{save_path}")
            
    except Exception as e:
        messagebox.showerror("Error", f"An unexpected error occurred: {e}")

# --- UI Layout ---
root = tk.Tk()
root.title("Python QR Code Generator")
root.geometry("450x200")
root.configure(padx=20, pady=20)

# Input Label
instr_label = tk.Label(root, text="Enter URL or Text:", font=("Arial", 10))
instr_label.grid(row=0, column=0, sticky="w", pady=5)

# Entry Field
url_entry = tk.Entry(root, width=40, font=("Arial", 10))
url_entry.grid(row=0, column=1, padx=10, pady=5)
url_entry.focus() # Set focus to the input field on start

# Generate Button
gen_button = tk.Button(
    root, 
    text="Generate & Save QR Code", 
    command=generate_qr,
    bg="#2980b9", 
    fg="white", 
    font=("Arial", 10, "bold"),
    padx=10,
    pady=5
)
gen_button.grid(row=1, column=0, columnspan=2, pady=20)

# Status Label
status_label = tk.Label(root, text="", font=("Arial", 9, "italic"))
status_label.grid(row=2, column=0, columnspan=2)

if __name__ == "__main__":
    root.mainloop()
