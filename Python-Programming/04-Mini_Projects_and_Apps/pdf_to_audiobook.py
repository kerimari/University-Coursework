"""
PDF to Audiobook Converter: Extracts text from PDF files 
and converts it to speech using Google Text-to-Speech (gTTS).
"""

import PyPDF2
from gtts import gTTS
import os
import tkinter as tk
from tkinter import filedialog, messagebox

def extract_text_from_pdf(pdf_path):
    """Reads PDF content and extracts text from every page."""
    text = ""
    try:
        # Open the PDF file in binary read mode
        with open(pdf_path, 'rb') as file:
            pdf_reader = PyPDF2.PdfReader(file)
            # Iterate through each page to collect text
            for page in pdf_reader.pages:
                extracted = page.extract_text()
                if extracted:
                    text += extracted
        return text
    except Exception as e:
        messagebox.showerror("Extraction Error", f"Failed to read PDF: {e}")
        return None

def convert_text_to_speech(text, output_file, language='tr'):
    """Converts the provided text into an MP3 file."""
    try:
        # Initialize Google Text-to-Speech
        tts = gTTS(text=text, lang=language)
        tts.save(output_file)
        return True
    except Exception as e:
        messagebox.showerror("TTS Error", f"Conversion failed: {e}")
        return False

def select_and_process_file():
    """Handles file selection and initiates the conversion process."""
    file_path = filedialog.askopenfilename(filetypes=[("PDF Files", "*.pdf")])
    
    if file_path:
        print("Extracting text from PDF...")
        content = extract_text_from_pdf(file_path)
        
        if content and content.strip():
            output_name = "audiobook_output.mp3"
            print("Converting text to speech (this may take a moment)...")
            
            if convert_text_to_speech(content, output_name):
                messagebox.showinfo("Success", f"Audiobook saved as {output_name}")
                # Open the audio file using the default system player
                os.system(f"start {output_name}")
        else:
            messagebox.showwarning("Warning", "The selected PDF appears to be empty or contains no readable text.")

# --- GUI Setup ---
def main():
    root = tk.Tk()
    root.title("PDF Audiobook Converter")
    root.geometry("300x200")
    root.configure(bg="#f0f0f0")

    label = tk.Label(root, text="PDF to MP3 Converter", font=("Arial", 12, "bold"), bg="#f0f0f0")
    label.pack(pady=20)

    # Selection Button
    select_btn = tk.Button(
        root, 
        text="Select PDF File", 
        command=select_and_process_file,
        padx=20, 
        pady=10,
        bg="#27ae60",
        fg="white",
        font=("Arial", 10)
    )
    select_btn.pack(pady=10)

    root.mainloop()

if __name__ == "__main__":
    main()
