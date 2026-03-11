import sqlite3

def init_db():
    """Initializes the database and creates the table if it doesn't exist."""
    conn = sqlite3.connect("accounting.db")
    cursor = conn.cursor()
    cursor.execute("CREATE TABLE IF NOT EXISTS debts (name TEXT, amount REAL)")
    conn.commit()
    return conn

def add_debtor(conn):
    name = input("Enter debtor name: ").strip()
    try:
        amount = float(input("Enter debt amount: "))
        cursor = conn.cursor()
        cursor.execute("INSERT INTO debts VALUES (?, ?)", (name, amount))
        conn.commit()
        print(f"Successfully added {name} to the database.")
    except ValueError:
        print("Invalid amount! Please enter a numeric value.")

def show_all_debts(conn):
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM debts")
    records = cursor.fetchall()
    
    print("\n--- Current Debt Records ---")
    if not records:
        print("No records found.")
    for row in records:
        print(f"Name: {row[0]:<15} | Amount: ${row[1]:,.2f}")

def main():
    conn = init_db()
    while True:
        print("\n--- SQLite Debt Tracker ---")
        print("1. Add Debtor\n2. View All Debts\n3. Exit")
        choice = input("Select action: ")
        
        if choice == "1": add_debtor(conn)
        elif choice == "2": show_all_debts(conn)
        elif choice == "3": 
            conn.close()
            break
        else:
            print("Invalid choice.")

if __name__ == "__main__":
    main()
