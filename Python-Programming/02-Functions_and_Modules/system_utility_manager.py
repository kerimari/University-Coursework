import subprocess as sp
import datetime
import codecs
import os

def app_launcher():
    """Starts system applications based on user selection."""
    apps = {
        "1": ("Notepad", "notepad.exe"),
        "2": ("Calculator", "calc.exe"),
        "3": ("Command Prompt", "cmd.exe")
    }
    
    print("\n--- System Application Launcher ---")
    for key, (name, _) in apps.items():
        print(f"{key}. {name}")
    
    choice = input("Select application to launch: ")
    if choice in apps:
        print(f"Launching {apps[choice][0]}...")
        sp.call(apps[choice][1])
    else:
        print("Invalid selection.")

def note_manager():
    """Handles file writing and reading operations."""
    print("\n--- Secure Note Manager ---")
    filename = "user_notes.txt"
    
    mode = input("Do you want to (W)rite a new note or (R)ead existing ones? ").upper()
    
    try:
        if mode == 'W':
            content = input("Enter your note: ")
            timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M")
            with codecs.open(filename, "a", encoding="utf-8") as file:
                file.write(f"[{timestamp}] {content}\n")
            print("Note saved successfully.")
            
        elif mode == 'R':
            if os.path.exists(filename):
                with codecs.open(filename, "r", encoding="utf-8") as file:
                    print("\n--- Saved Notes ---")
                    print(file.read())
            else:
                print("No notes found.")
    except Exception as e:
        print(f"File Error: {e}")

def main():
    # Security layer
    master_pass = "123"
    attempts = 3
    
    while attempts > 0:
        pwd = input("Enter System Password: ")
        if pwd == master_pass:
            print("Access Verified!")
            while True:
                print("\n1. Launch Apps\n2. Manage Notes\n3. Exit")
                choice = input("Action: ")
                if choice == "1": app_launcher()
                elif choice == "2": note_manager()
                elif choice == "3": break
            break
        else:
            attempts -= 1
            print(f"Wrong password! Remaining attempts: {attempts}")

if __name__ == "__main__":
    main()
