"""
Financial Analysis Tool: Demonstrates advanced arithmetic, 
list processing, and user-driven data analysis.
"""

def investment_analyzer():
    print("\n--- Simple Investment & Expense Analyzer ---")
    try:
        initial_capital = float(input("Enter initial capital: "))
        monthly_savings = float(input("Enter monthly savings: "))
        duration_months = int(input("Enter duration (months): "))
        
       
        total_saved = initial_capital + (monthly_savings * duration_months)
      
        expenses = []
        print("\nEnter your top 3 monthly expenses:")
        for i in range(3):
            expense = float(input(f"Expense {i+1}: "))
            expenses.append(expense)
        
        avg_expense = sum(expenses) / len(expenses)
        max_expense = max(expenses)
        
        print("\n" + "="*35)
        print(f"Total Capital after {duration_months} months: ${total_saved:,.2f}")
        print(f"Average Monthly Expense: ${avg_expense:,.2f}")
        print(f"Highest Single Expense: ${max_expense:,.2f}")
        print("="*35)
        
    except ValueError:
        print("Error: Please enter valid numeric values for all financial data.")

if __name__ == "__main__":
    investment_analyzer()
