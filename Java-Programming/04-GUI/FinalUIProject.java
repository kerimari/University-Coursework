import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Final GUI Project: User Registration System
 * Integrated concepts: Layouts, Components, and Event Handling
 * Based on screenshots and cumulative course materials (Week 5-11)
 */
public class FinalUIProject {
    public static void main(String[] args) {
        // 1. Main Frame Configuration
        JFrame frame = new JFrame("University Portal - Registration");
        frame.setSize(450, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout(15, 15)); // Main container layout

        // 2. Header Panel
        JLabel headerLabel = new JLabel("Student Registration Form", SwingConstants.CENTER);
        headerLabel.setFont(new Font("Arial", Font.BOLD, 18));
        headerLabel.setForeground(Color.BLUE);
        frame.add(headerLabel, BorderLayout.NORTH);

        // 3. Form Content Panel (GridLayout)
        JPanel formPanel = new JPanel(new GridLayout(4, 2, 10, 10));
        formPanel.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));

        formPanel.add(new JLabel("Full Name:"));
        JTextField nameField = new JTextField(); //
        formPanel.add(nameField);

        formPanel.add(new JLabel("Department:"));
        String[] depts = {"Software Engineering", "Civil Engineering", "Computer Science"};
        JComboBox<String> deptCombo = new JComboBox<>(depts); //
        formPanel.add(deptCombo);

        formPanel.add(new JLabel("Registration Type:"));
        JCheckBox fullTimeBox = new JCheckBox("Full-Time Student"); //
        formPanel.add(fullTimeBox);

        frame.add(formPanel, BorderLayout.CENTER);

        // 4. Action Area (Button and Event Handling)
        JButton submitButton = new JButton("Register Student");
        submitButton.setPreferredSize(new Dimension(100, 40));
        
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Collect and display data on click
                String name = nameField.getText();
                String dept = (String) deptCombo.getSelectedItem();
                boolean isFullTime = fullTimeBox.isSelected();
                
                String message = "Registered: " + name + "\nDept: " + dept + "\nFull-Time: " + isFullTime;
                JOptionPane.showMessageDialog(frame, message, "Success", JOptionPane.INFORMATION_MESSAGE);
            }
        });

        frame.add(submitButton, BorderLayout.SOUTH);

        // Final Visibility
        frame.setVisible(true);
    }
}
