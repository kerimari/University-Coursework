"""
School Management System: Demonstrates OOP Inheritance and Overriding.
Features Teacher and Manager roles with salary and branch management.
"""

class Classroom:
    def __init__(self, branch, teacher, department, capacity, salary):
        self.branch = branch
        self.teacher = teacher
        self.department = department
        self.capacity = capacity
        self.salary = float(salary)

    def display_info(self):
        print("\n" + "*"*30)
        print("CLASSROOM INFORMATION")
        print(f"Branch    : {self.branch}\n"
              f"Teacher   : {self.teacher}\n"
              f"Dept      : {self.department}\n"
              f"Capacity  : {self.capacity}")
        print("*"*30)

    def change_department(self):
        print(f"\nCurrent Department: {self.department}")
        new_dept = input("Enter new department: ").strip()
        self.department = new_dept
        print(f"Update Successful! New Department: {self.department}")

    def show_salary(self):
        print(f"\nSalary for {self.teacher}: ${self.salary:,.2f}")


class Manager(Classroom):
    def __init__(self, branch, teacher, department, capacity, salary, seniority):
        # Using super() to inherit base class attributes
        super().__init__(branch, teacher, department, capacity, salary)
        self.seniority = seniority

    def display_info(self):
        """Overriding the base class method to include seniority."""
        super().display_info()
        print(f"Seniority : {self.seniority}")
        print("*"*30)

    def apply_raise(self):
        print(f"\n--- Raise Management for {self.teacher} ---")
        try:
            amount = float(input("Enter raise amount: "))
            self.salary += amount
            print(f"Success! ${amount:,.2f} added to salary.")
            print(f"New Salary: ${self.salary:,.2f}")
        except ValueError:
            print("Error: Please enter a valid numeric amount.")


def main():
    while True:
        print("\n" + "="*30)
        print("  SCHOOL MANAGEMENT PORTAL  ")
        print("="*30)
        print("1. Teacher Module")
        print("2. Manager Module")
        print("3. Exit")
        
        entry_choice = input("\nSelect Module: ")

        if entry_choice == "3":
            print("Exiting System...")
            break

        # Common Inputs
        branch_name = input("Branch Name: ")
        teacher_name = input("Teacher Name: ")
        dept_name = input("Department: ")
        capacity = input("Class Capacity: ")
        salary_input = input("Base Salary: ")

        if entry_choice == "1":
            # Create Teacher Object
            user_obj = Classroom(branch_name, teacher_name, dept_name, capacity, salary_input)
            print("\nTeacher profile created successfully.")
            
            print("\n1. Display Info\n2. Change Department\n3. Show Salary")
            action = input("Selection: ")
            
            if action == "1": user_obj.display_info()
            elif action == "2": user_obj.change_department()
            elif action == "3": user_obj.show_salary()
            else: print("Invalid action selection.")

        elif entry_choice == "2":
            # Manager specific input
            seniority_level = input("Seniority Rank: ")
            # Create Manager Object
            user_obj = Manager(branch_name, teacher_name, dept_name, capacity, salary_input, seniority_level)
            print("\nManager profile created successfully.")
            
            print("\n1. Display Info (With Seniority)\n2. Apply Salary Raise")
            action = input("Selection: ")
            
            if action == "1": user_obj.display_info()
            elif action == "2": user_obj.apply_raise()
            else: print("Invalid action selection.")

        else:
            print("Invalid module selection!")

if __name__ == "__main__":
    main()
