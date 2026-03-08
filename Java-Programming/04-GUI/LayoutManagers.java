import javax.swing.*;
import java.awt.*;

/**
 * Basic Layout Management in Java Swing
 * Demonstrating FlowLayout and GridLayout as shown in Week 7 course materials
 */
public class LayoutManagement {
    public static void main(String[] args) {
        // 1. Frame Setup
        JFrame frame = new JFrame("Week 7 - Layout Examples");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        /* * 2. FlowLayout Example
         * Components are arranged in a line, centered by default.
         */
        JPanel topPanel = new JPanel();
        topPanel.setLayout(new FlowLayout()); 
        topPanel.add(new JButton("Button 1"));
        topPanel.add(new JButton("Button 2"));
        topPanel.add(new JButton("Button 3"));

        /* * 3. GridLayout Example
         * Arranges components in a grid (Rows, Columns, Hgap, Vgap).
         * Here we create a 2x2 grid.
         */
        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new GridLayout(2, 2, 10, 10)); 
        centerPanel.add(new JButton("Grid 1"));
        centerPanel.add(new JButton("Grid 2"));
        centerPanel.add(new JButton("Grid 3"));
        centerPanel.add(new JButton("Grid 4"));

        // Adding panels to the main frame using default BorderLayout
        frame.add(topPanel, BorderLayout.NORTH);
        frame.add(centerPanel, BorderLayout.CENTER);

        frame.setVisible(true); //
    }
}
