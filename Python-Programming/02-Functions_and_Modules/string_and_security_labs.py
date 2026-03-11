def password_validator():
    """Validates password strength based on length (3-8 characters)."""
    # Logic from PDF's password check loop
    for i in range(3):
        pwd = input(f"Set a new password (Attempt {i+1}/3): ")
        if not pwd:
            print("Error: Field cannot be empty.")
        elif 3 <= len(pwd) <= 8:
            print(f"Success: Password set to '{pwd}'")
            return pwd
        else:
            print("Error: Password must be between 3 and 8 characters.")
    print("Security Alert: Too many invalid attempts.")

def word_splitter():
    """Extracts the first letter of each word in a string."""
    # Logic from PDF's string parsing example
    text = input("\nEnter a sentence to parse: ")
    initials = [word[0].upper() for word in text.split()]
    print(f"Initials: {''.join(initials)}")

if __name__ == "__main__":
    password_validator()
    word_splitter()
