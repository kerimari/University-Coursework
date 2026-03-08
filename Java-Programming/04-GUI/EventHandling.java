import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Event Handling in Java Swing
 * Demonstrating ActionListeners and button click events based on Week 9 and 10 notes
 */
public class EventHandling {
    public static void main(String[] args) {
        // 1. Frame and Panel Setup
        JFrame frame = new JFrame("Week 9-10: Event Handling");
        frame.setSize(350, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        // 2. Creating Components
        JButton clickButton = new JButton("Click Me!");
        JLabel statusLabel = new JLabel("Button not clicked yet");

        // 3. Adding ActionListener (The Event Handler)
        // Using an anonymous inner class as shown in course materials
        clickButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Logic executed when the button is pressed
                System.out.println("Button was clicked!"); // Console output
                statusLabel.setText("Status: Button Clicked!"); // UI update
                
                // Optional: Change button color on click
                clickButton.setBackground(Color.GREEN);
            }
        });

        // 4. Adding components to the frame
        frame.add(clickButton);
        frame.add(statusLabel);

        frame.setVisible(true); //
    }
}
