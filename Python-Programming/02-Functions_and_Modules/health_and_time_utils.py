import time
from datetime import datetime

def calculate_water_intake():
    """Calculates daily water needs based on weight and gender."""
    # Based on PDF concepts of weight-based calculation
    try:
        weight = float(input("Enter your weight (kg): "))
        gender = input("Gender (M/F): ").upper()
        
        # Multipliers based on typical hydration logic
        factor = 0.04 if gender == "M" else 0.03
        needed = weight * factor
        print(f">>> You should drink approximately {needed:.2f} liters of water daily.")
    except ValueError:
        print("Please enter a valid weight.")

def countdown_timer(seconds=5):
    """A countdown timer using time.sleep."""
    print(f"Action will complete in:")
    for i in range(seconds, 0, -1):
        print(f"{i}...", end=" ", flush=True)
        time.sleep(1)
    print("\nDONE!")

def show_current_timestamp():
    """Prints professionally formatted current date and time."""
    now = datetime.now()
    # Using the formatting style from PDF
    print(f"Current System Time: {now.strftime('%c')}")

if __name__ == "__main__":
    show_current_timestamp()
    calculate_water_intake()
    countdown_timer(3)
