/**
 * Iteration and Method Definition in Java
 * Demonstrating loops (for/while) and functional method structures
 */
public class LoopsAndMethods {

    public static void main(String[] args) {
        // 1. For Loop: Calculate sum of even numbers from 1 to 10
        int forSum = 0;
        for (int i = 1; i <= 10; i++) {
            if (i % 2 == 0) {
                forSum += i;
            }
        }
        System.out.println("Sum of even numbers (For): " + forSum);

        // 2. While Loop: Print numbers 1 to 5
        int counter = 1;
        System.out.print("While Loop output: ");
        while (counter <= 5) {
            System.out.print(counter + " ");
            counter++;
        }
        System.out.println();

        // 3. Calling Methods
        printStaticMessage(); // Calling a void method
        
        int result = addNumbers(5, 10); // Calling a return-type method
        System.out.println("Method Addition Result: " + result);
    }

    /**
     * A simple void method that prints a static message
     */
    public static void printStaticMessage() {
        System.out.println("Static message from a void method.");
    }

    /**
     * A method that takes two integers and returns their sum
     * @param num1 first number
     * @param num2 second number
     * @return sum of num1 and num2
     */
    public static int addNumbers(int num1, int num2) {
        return num1 + num2;
    }
}
