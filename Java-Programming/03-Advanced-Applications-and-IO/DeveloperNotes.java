/**
 * Developer Productivity and Core Java Concepts
 * This file serves as a reference for IDE shortcuts and keyword definitions
 */
public class DeveloperNotes {

    public static void main(String[] args) {
        
        /* * 1. ESSENTIAL IDE SHORTCUTS (Eclipse/STS)
         * ---------------------------------------
         * CTRL + SPACE     : Code completion
         * CTRL + D         : Delete the current line
         * ALT + SHIFT + S  : Open Generate Getters/Setters menu
         * CTRL + SHIFT + F : Format and organize code
         * CTRL + SHIFT + C : Toggle comment for selected lines
         */

        /* * 2. CORE JAVA KEYWORDS & CONCEPTS
         * ---------------------------------------
         * STATIC    : Access members without creating an instance of the class.
         * PROTECTED : Allows access within the same package or by subclasses.
         * ABSTRACT  : Used to define methods without a body; implementation is 
         * handled by subclasses.
         * FINAL     : Prevents classes from being inherited or methods from 
         * being overridden.
         */

        /* * 3. EXCEPTION HANDLING LOGIC
         * ---------------------------------------
         * FINALLY block: This block always executes regardless of whether 
         * an exception is thrown or caught. Ideal for closing resources.
         */
        
        printDeveloperTip();
    }

    public static void printDeveloperTip() {
        System.out.println("Standardize your naming conventions (camelCase) for cleaner code.");
    }
}
