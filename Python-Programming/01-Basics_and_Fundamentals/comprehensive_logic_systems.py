"""
Integrated Logic Systems: Auth, Health Assessment, and Academic Grading.
Demonstrates complex boolean logic, nested if-else, and input validation.
"""

def school_grade_system():
    print("\n--- [1] Academic Performance Tracker ---")
    try:
        midterm = float(input("Enter midterm grade: "))
        final = float(input("Enter final grade: "))
        
        if not (0 <= midterm <= 100 and 0 <= final <= 100):
            print("Error: Grades must be between 0 and 100.")
            return

        average = (midterm * 0.4) + (final * 0.6)
        
        if average >= 85: letter = "AA"
        elif average >= 70: letter = "BB"
        elif average >= 50: letter = "CC"
        else: letter = "FF (Failed)"

        print(f"Result: {letter} (Average: {average:.2f})")
    except ValueError:
        print("Invalid input! Please enter numeric values.")

def health_assistant():
    print("\n--- [2] Health Assessment Assistant ---") 
    try:
        fever = float(input("Body temperature: "))
        cough = input("Cough? (y/n): ").lower() == 'y'
        days = int(input("Symptoms duration (days): "))

        if fever >= 39 and days >= 3:
            print(">>> STATUS: Critical. Visit a hospital immediately.")
        elif fever >= 38 or cough:
            print(">>> STATUS: Moderate. Rest and monitor symptoms.")
        else:
            print(">>> STATUS: Stable. Stay hydrated.")
    except ValueError:
        print("Error: Input must be numeric.")

def simple_auth():
    db_user, db_pass = "Admin", "1234"
    print("\n--- [3] System Authentication ---")
    user = input("Username: ")
    pwd = input("Password: ")
    
    if user == db_user and pwd == db_pass:
        print("Access Granted!")
    else:
        print("Access Denied.")

if __name__ == "__main__":
    school_grade_system()
    health_assistant()
    simple_auth()
