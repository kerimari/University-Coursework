import javax.swing.*;
import java.awt.*;

/**
 * Common User Interface Components
 * Demonstrating JTextField, JCheckBox, and JComboBox based on Week 11 notes
 */
public class UserComponents {
    public static void main(String[] args) {
        // 1. Frame Setup
        JFrame frame = new JFrame("Week 11: User Components");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(5, 1, 10, 10)); // Vertical alignment

        // 2. Text Input Component
        JPanel textPanel = new JPanel(new FlowLayout());
        textPanel.add(new JLabel("Name:"));
        JTextField nameField = new JTextField(15); // 15 columns wide
        textPanel.add(nameField);

        // 3. CheckBox Component
        JCheckBox termsBox = new JCheckBox("I accept the terms and conditions");
        
        // 4. ComboBox (Dropdown) Component
        String[] cities = { "Istanbul", "Ankara", "Izmir", "Bursa" };
        JComboBox<String> cityCombo = new JComboBox<>(cities);

        // 5. Submit Button to demonstrate interaction
        JButton submitButton = new JButton("Submit");

        // Adding components to the frame
        frame.add(textPanel);
        frame.add(termsBox);
        frame.add(cityCombo);
        frame.add(submitButton);

        frame.setVisible(true); //
    }
}
