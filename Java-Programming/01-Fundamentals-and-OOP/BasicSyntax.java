/**
 * Basic Data Types and Operators in Java
 * Covering primitive types, assignments, and arithmetic operations
 */
public class BasicSyntax {

    public static void main(String[] args) {
        
        // 1. Primitive Data Types
        long longValue = 1000000000L;    // Long data type for large integers
        float floatValue = 10.5f;        // Float data type for single-precision decimals
        double doubleValue = 20.99;      // Double data type for double-precision decimals
        boolean isActive = true;         // Boolean data type (true/false)
        char letter = 'A';               // Character data type
        String message = "Java Fundamentals"; // String (Reference type)

        // 2. Arithmetic Operators
        int number1 = 20;
        int number2 = 10;

        int sum = number1 + number2;         // Addition
        int difference = number1 - number2;  // Subtraction
        int multiplication = number1 * number2; // Multiplication
        int division = number1 / number2;    // Division
        int remainder = number1 % 3;         // Modulo (Remainder)

        // 3. Increment and Decrement Operators
        int counter = 5;
        counter++; // Increment by 1
        counter--; // Decrement by 1

        // 4. Multiple Assignment and Relational Concepts
        int x = 10, y = 20, z = 30; // Multiple variable declaration
        
        // Console Output
        System.out.println("Message: " + message);
        System.out.println("Addition Result: " + sum);
        System.out.println("Modulo Result: " + remainder);
        System.out.println("Boolean Status: " + isActive);
    }
}
