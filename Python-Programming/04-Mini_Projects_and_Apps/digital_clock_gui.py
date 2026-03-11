"""
Digital Clock GUI: A real-time clock and date display application.
Demonstrates Tkinter labels, window configuration, and periodic function updates.
"""

from tkinter import Label, Tk
import time

def update_clock():
    """Fetches the current time and date, then updates the UI labels."""
    # Fetching live time (Hours:Minutes:Seconds)
    time_live = time.strftime("%H:%M:%S")
    time_label.config(text=time_live)
    
    # Fetching live date (Day Month Year)
    date_live = time.strftime("%d %B %Y")
    date_label.config(text=date_live)
    
    # Scheduling the function to run again after 200ms for smooth updates
    time_label.after(200, update_clock)

# --- UI Setup ---
root = Tk()
root.title("Python Digital Clock")
root.geometry("350x200")
root.resizable(True, True)
root.configure(bg="black")

# Styling constants
BG_COLOR = "black"
FG_TIME = "#00FF00"  # Neon Green for a digital look
FG_DATE = "white"
FONT_TIME = ("Courier", 48, 'bold')
FONT_DATE = ("Arial", 18, 'italic')

# Time Label
time_label = Label(root, font=FONT_TIME, bg=BG_COLOR, fg=FG_TIME)
time_label.pack(expand=True, pady=(20, 0))

# Date Label
date_label = Label(root, font=FONT_DATE, bg=BG_COLOR, fg=FG_DATE)
date_label.pack(expand=True, pady=(0, 20))

# Start the clock loop
update_clock()

# Execution
if __name__ == "__main__":
    root.mainloop()
