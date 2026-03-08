/**
 * Array Operations in Java
 * Demonstrating single-dimensional, multi-dimensional arrays and iteration
 */
public class ArrayOperations {

    public static void main(String[] args) {
        
        // 1. Single-Dimensional Arrays
        // Initializing an integer array with a specific size
        int[] numbers = new int[6];
        numbers[0] = 15;
        numbers[1] = 12;
        numbers[2] = 23;
        numbers[3] = 76;
        numbers[4] = 89;
        numbers[5] = 67;

        // Initializing a String array with values directly
        String[] names = {"Kerim", "Tuğçe", "Icardi", "Mauro"};

        // 2. Iterating through Arrays
        System.out.println("Integer Array Elements:");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println("\n");

        // 3. Multi-Dimensional Arrays (Matrix)
        // Accessing elements using two indexes: [row][column]
        int[][] myNumbers = { 
            {1, 2, 3, 4}, 
            {5, 6, 7} 
        };

        // Accessing the third element (7) in the second array (index 1)
        int selectedValue = myNumbers[1][2]; 
        
        System.out.println("Multi-dimensional Array Access:");
        System.out.println("Value at myNumbers[1][2]: " + selectedValue);
    }
}
