import java.util.Scanner;

/**
 * Control Flow Structures in Java
 * Demonstrating conditional logic, switch-case, and control statements
 */
public class ControlFlow {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 1. Conditional Logic: Student Grade Calculation
        int examScore = 75; // Example score based on course notes
        if (examScore >= 50) {
            System.out.println("Status: Passed");
        } else {
            System.out.println("Status: Failed");
        }

        // 2. Switch-Case: Mini ATM Application
        int selection = 2; // Simulated user choice for ATM operations
        switch (selection) {
            case 1:
                System.out.println("Action: View Balance");
                break;
            case 2:
                System.out.println("Action: Deposit Money");
                break;
            case 3:
                System.out.println("Action: Withdraw Money");
                break;
            default:
                System.out.println("Invalid Selection");
                break;
        }

        // 3. Control Statements: Break and Continue Usage
        System.out.println("Loop with Break (Stops execution at 4):");
        for (int i = 1; i <= 10; i++) {
            if (i == 4) {
                break; // Exit the loop entirely
            }
            System.out.print(i + " ");
        }

        System.out.println("\nLoop with Continue (Skips 7 and 8):");
        for (int i = 1; i <= 10; i++) {
            if (i == 7 || i == 8) {
                continue; // Skip the current iteration
            }
            System.out.print(i + " ");
        }
    }
}
