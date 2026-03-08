import javax.swing.JFrame;
import javax.swing.ImageIcon;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Toolkit;

/**
 * Comprehensive JFrame Configuration
 * Topics: Window properties, positioning, background colors, and icons
 */
public class BasicFrame {
    public static void main(String[] args) {
        // 1. Frame Initialization
        JFrame frame = new JFrame();
        frame.setTitle("Java GUI Fundamentals - University Coursework");
        
        // 2. Sizing and Positioning
        frame.setSize(500, 400); // Setting manual size
        frame.setMinimumSize(new Dimension(300, 200)); // Minimum allowed size
        
        // Center the frame on any screen
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (screenSize.width - frame.getWidth()) / 2;
        int y = (screenSize.height - frame.getHeight()) / 2;
        frame.setLocation(x, y);
        
        // 3. Look and Feel
        frame.getContentPane().setBackground(new Color(45, 45, 45)); // Dark theme background
        frame.setResizable(true); // Allowing user to resize
        
        // 4. Default Behavior
        // Ensures the application terminates when window is closed
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // 5. Visibility
        frame.setVisible(true);
    }
}
