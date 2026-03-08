/**
 * Exception Handling in Java
 * Demonstrating try-catch-finally blocks, throw/throws, and custom exceptions
 */

// Custom Exception Class based on course notes
class CustomerNotFoundException extends Exception {
    public CustomerNotFoundException(String message) {
        super(message);
    }
}

public class ExceptionHandling {

    public static void main(String[] args) {
        
        // 1. Basic Try-Catch-Finally Block
        try {
            int[] numbers = {1, 2, 3};
            System.out.println("Accessing index 10: " + numbers[10]); // Will throw an exception
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Please provide a valid index.");
        } finally {
            System.out.println("Finally block: This always executes.");
        }

        // 2. Handling Multiple Exceptions
        try {
            String text = null;
            text.toLowerCase(); // NullPointerException
        } catch (NullPointerException e) {
            System.out.println("Error: Null pointer exception occurred.");
        }

        // 3. Using Throw and Throws with Custom Exception
        try {
            checkCustomer(10L);
        } catch (CustomerNotFoundException e) {
            System.out.println("Custom Exception Caught: " + e.getMessage());
        }
    }

    /**
     * Method that demonstrates 'throws' keyword
     */
    public static void checkCustomer(Long id) throws CustomerNotFoundException {
        boolean exists = false; // Simulated database check
        
        if (!exists) {
            // Demonstrating 'throw' keyword
            throw new CustomerNotFoundException("Customer with ID " + id + " not found!");
        }
    }
}
