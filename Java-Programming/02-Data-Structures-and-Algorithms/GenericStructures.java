/**
 * Generic Programming in Java
 * Demonstrating generic classes and methods for type-safe, reusable code
 */

// Generic Database class based on course notes
class Database<E> {
    
    // Generic method to save any object type
    public E save(E object) {
        System.out.println("Object saved to database...");
        return object;
    }

    // Generic method to delete any object type
    public void delete(E object) {
        System.out.println("Object deleted from database...");
    }
}

// Entity class for demonstration
class Employee {
    private Long id;
    private String name;

    public Employee(Long id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public String toString() {
        return "Employee [ID=" + id + ", Name=" + name + "]";
    }
}

public class GenericStructures {

    public static void main(String[] args) {
        
        // 1. Generic Class Usage
        Database<Employee> employeeDb = new Database<>();
        Employee emp = new Employee(1L, "Enes");
        employeeDb.save(emp);

        // 2. Generic Method Usage
        Integer[] intArray = {1, 2, 3, 4, 5};
        String[] stringArray = {"Java", "Generic", "Methods"};
        Double[] doubleArray = {10.5, 20.1, 30.7};

        System.out.println("\nPrinting Integer Array:");
        printArray(intArray);

        System.out.println("Printing String Array:");
        printArray(stringArray);
        
        System.out.println("Printing Double Array:");
        printArray(doubleArray);
    }

    /**
     * A generic method that prints elements of any array type
     * @param <T> Type parameter
     * @param array The array to be printed
     */
    public static <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.println(element);
        }
    }
}
