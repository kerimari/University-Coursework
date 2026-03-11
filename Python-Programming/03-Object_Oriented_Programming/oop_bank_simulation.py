"""
Object-Oriented Programming: Bank Account Simulation.
Demonstrates Encapsulation, Methods, and Class Structures.
"""

class BankAccount:
    def __init__(self, owner, balance=0):
        self.owner = owner
        self.__balance = balance  

    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
            print(f"Added {amount}. New balance: {self.__balance}")

    def withdraw(self, amount):
        if 0 < amount <= self.__balance:
            self.__balance -= amount
            print(f"Withdrew {amount}. Remaining: {self.__balance}")
        else:
            print("Insufficient funds or invalid amount.")

    def display_balance(self):
        print(f"Account Owner: {self.owner} | Balance: {self.__balance}")

if __name__ == "__main__":
    my_account = BankAccount("Kerim Ari", 1000)
    my_account.deposit(500)
    my_account.withdraw(200)
    my_account.display_balance()
