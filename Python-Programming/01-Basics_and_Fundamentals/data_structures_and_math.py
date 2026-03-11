"""
Data Structures Lab: Lists, Dictionaries, and Arithmetic Operations.
"""

def list_and_math_demo():
    user_data = ["Kerim", "Ari", 2500]
    print(f"Extracted Name: {' '.join(user_data[0:2])}")
    
    a, b = 10, 2
    print(f"Basic Math: {a}*{b}={a*b}, {a}/{b}={a/b}")

def league_tracker():
    teams = {"Galatasaray": 102, "Fenerbahce": 99, "Besiktas": 48}
    print("\n--- League Score Tracker ---")
    
    search = input("Enter team name: ").capitalize()
    score = teams.get(search, "Not Found")
    print(f"{search} Score: {score}")

if __name__ == "__main__":
    list_and_math_demo()
    league_tracker()
