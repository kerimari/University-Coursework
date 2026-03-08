import java.io.*;
import java.util.Scanner;

/**
 * File Management in Java
 * Demonstrating file creation, writing with BufferedWriter, and reading with BufferedReader
 */
public class FileManagement {

    public static void main(String[] args) {
        String path = "students.txt";

        // 1. Writing to a File (Append mode)
        writeToFile(path);

        // 2. Reading from a File
        readFromFile(path);
    }

    /**
     * Writes student data to a file using BufferedWriter
     * Based on course notes for FileWriter and BufferedWriter
     */
    public static void writeToFile(String filePath) {
        File file = new File(filePath);
        
        // try-with-resources ensures the writer is closed automatically
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file, true))) {
            if (!file.exists()) {
                System.out.println("Creating new file...");
                file.createNewFile();
            }
            
            writer.write("Enes Bayram, Computer Programming\n");
            writer.write("Eren Akar, Civil Engineering\n");
            System.out.println("Data successfully written to the file.");
            
        } catch (IOException e) {
            System.out.println("Write Error: " + e.getMessage());
        }
    }

    /**
     * Reads and displays file content using BufferedReader and Scanner
     */
    public static void readFromFile(String filePath) {
        File file = new File(filePath);

        if (file.exists()) {
            System.out.println("\nReading File Content:");
            try (Scanner scanner = new Scanner(new BufferedReader(new FileReader(file)))) {
                while (scanner.hasNextLine()) {
                    String line = scanner.nextLine();
                    System.out.println(line);
                }
            } catch (FileNotFoundException e) {
                System.out.println("Read Error: File not found.");
            }
        } else {
            System.out.println("Error: Specified file does not exist.");
        }
    }
}
