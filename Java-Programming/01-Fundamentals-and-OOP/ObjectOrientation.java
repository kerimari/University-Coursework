/**
 * Object-Oriented Programming (OOP) Fundamentals in Java
 * Demonstrating classes, constructors, 'this' keyword, and inheritance
 */

// Base class representing Inheritance
class Animal {
    public void eat() {
        System.out.println("This animal is eating.");
    }
}

// Subclass inheriting from Animal
class Dog extends Animal {
    public void bark() {
        System.out.println("The dog is barking.");
    }
}

// Class representing a Student entity
class Student {
    public int studentId;
    public String firstName;
    public String lastName;

    // Default Constructor
    public Student() {}

    // Parameterized Constructor using 'this' keyword
    public Student(int studentId, String firstName, String lastName) {
        this.studentId = studentId;
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public void displayInfo() {
        System.out.println("ID: " + studentId + " | Name: " + firstName + " " + lastName);
    }
}

public class ObjectOrientation {
    public static void main(String[] args) {
        // 1. Instance Creation and Constructor Usage
        Student student1 = new Student(123, "Kerim", "Ari");
        student1.displayInfo();

        // 2. Demonstration of Inheritance
        Dog myDog = new Dog();
        myDog.eat();  // Method from Animal class
        myDog.bark(); // Method from Dog class
    }
}
