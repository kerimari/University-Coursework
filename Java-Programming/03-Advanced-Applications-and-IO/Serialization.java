import java.io.*;

/**
 * Object Serialization in Java
 * Demonstrating how to write objects to files and read them back
 */

// Serializable interface is required for object transmission
class StudentEntity implements Serializable {
    private static final long serialVersionUID = 1L;
    private long id;
    private String firstName;
    private String lastName;

    public StudentEntity(long id, String firstName, String lastName) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
    }

    @Override
    public String toString() {
        return "Student [ID=" + id + ", Name=" + firstName + " " + lastName + "]";
    }
}

public class Serialization {

    public static void main(String[] args) {
        String filename = "students_data.bin";
        
        StudentEntity[] studentList = {
            new StudentEntity(1L, "Enes", "Bayram"),
            new StudentEntity(2L, "Yakup", "Recber"),
            new StudentEntity(3L, "Bilal", "Camur")
        };

        // 1. Serialization: Writing Objects to File
        saveObjects(filename, studentList);

        // 2. Deserialization: Reading Objects from File
        loadObjects(filename);
    }

    public static void saveObjects(String path, StudentEntity[] data) {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(path))) {
            out.writeObject(data);
            System.out.println("Objects successfully serialized to " + path);
        } catch (IOException e) {
            System.out.println("Serialization Error: " + e.getMessage());
        }
    }

    public static void loadObjects(String path) {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(path))) {
            StudentEntity[] loadedData = (StudentEntity[]) in.readObject();
            
            System.out.println("\nDeserialized Student List:");
            for (StudentEntity student : loadedData) {
                System.out.println(student);
            }
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Deserialization Error: " + e.getMessage());
        }
    }
}
