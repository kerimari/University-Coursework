import random
import time

def add_user(user_list):
    """Adds a new person to the giveaway list."""
    print("*" * 30)
    print("--- ADD NEW PARTICIPANT ---")
    name = input("Enter the participant's name: ").strip()
    if name:
        user_list.append(name)
        print(f"'{name}' successfully added to the list.")
    else:
        print("Error: Name cannot be empty!")
    print("*" * 30)

def view_users(user_list):
    """Displays all current participants."""
    print("*" * 30)
    if not user_list:
        print("The list is currently empty.")
    else:
        for index, user in enumerate(user_list, start=1):
            print(f"{index}. Participant: {user}")
    print("*" * 30)
    input("\nPress Enter to continue...")

def select_winners(user_list):
    """Selects a specific number of random winners."""
    if not user_list:
        print("Error: The list is empty. Add participants first!")
        return

    print("*" * 30)
    try:
        count = int(input(f"How many winners do you want to select? (Max {len(user_list)}): "))
        
        if 0 < count <= len(user_list):
            winners = random.sample(user_list, count)
            print(f"\nSelecting {count} winner(s)...")
            
            for index, winner in enumerate(winners, start=1):
                time.sleep(1.5)  # Creating suspense
                print(f"Winner #{index}: {winner}")
                if index < count:
                    print("Drawing next winner...")
        else:
            print(f"Invalid number! Please choose between 1 and {len(user_list)}.")
            
    except ValueError:
        print("Error: Please enter a valid numeric value.")
    print("*" * 30)
    input("\nPress Enter to continue...")

def shuffle_list(user_list):
    """Shuffles the entire participant list randomly."""
    if not user_list:
        print("Error: Nothing to shuffle.")
        return

    print("*" * 30)
    print("Shuffling the list...")
    time.sleep(1)
    random.shuffle(user_list)
    
    for index, user in enumerate(user_list, start=1):
        print(f"{index}. {user}")
    
    print("\nList shuffled successfully!")
    print("*" * 30)
    input("\nPress Enter to continue...")

def main():
    participants = []
    
    while True:
        print("\n" + "="*30)
        print("   LUCKY DRAW SYSTEM V1.0   ")
        print("="*30)
        print("1. Add Participant")
        print("2. View All Participants")
        print("3. Shuffle List")
        print("4. Draw Winners")
        print("5. Exit")
        
        try:
            choice = input("\nSelect an option (1-5): ")
            
            if choice == "1":
                add_user(participants)
            elif choice == "2":
                view_users(participants)
            elif choice == "3":
                shuffle_list(participants)
            elif choice == "4":
                print("\nSetting up the drawing system...")
                time.sleep(1)
                select_winners(participants)
            elif choice == "5":
                print("Exiting system. Good luck!")
                break
            else:
                print("Invalid selection! Please choose between 1 and 5.")
        except KeyboardInterrupt:
            print("\nSystem interrupted. Closing safely...")
            break

if __name__ == "__main__":
    main()
