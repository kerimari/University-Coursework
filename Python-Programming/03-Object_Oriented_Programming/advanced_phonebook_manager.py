import json
import os

class Phonebook:
    def __init__(self, filename="contacts.json"):
        self.filename = filename
        self.contacts = self.load_data()

    def load_data(self):
        """Loads contacts from a JSON file (handling persistence)."""
        if os.path.exists(self.filename):
            with open(self.filename, "r", encoding="utf-8") as f:
                return json.load(f)
        return {}

    def save_data(self):
        """Saves current contacts to the file."""
        with open(self.filename, "w", encoding="utf-8") as f:
            json.dump(self.contacts, f, ensure_ascii=False, indent=4)

    def add_contact(self):
        name = input("Contact Name: ").strip()
        phone = input("Phone Number: ").strip()
        self.contacts[name] = phone
        self.save_data()
        print(f"{name} has been added.")

    def delete_contact(self):
        name = input("Enter name to delete: ").strip()
        if self.contacts.pop(name, None):
            self.save_data()
            print(f"{name} deleted.")
        else:
            print("Contact not found.")

    def list_contacts(self):
        print("\n--- Contacts List ---")
        for name, phone in self.contacts.items():
            print(f"{name}: {phone}")

def main():
    book = Phonebook()
    while True:
        print("\n1. Add\n2. Delete\n3. List\n4. Exit")
        choice = input("Choice: ")
        if choice == "1": book.add_contact()
        elif choice == "2": book.delete_contact()
        elif choice == "3": book.list_contacts()
        elif choice == "4": break

if __name__ == "__main__":
    main()
