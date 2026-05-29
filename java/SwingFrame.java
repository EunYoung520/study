
import javax.swing.*;
import java.awt.*;


public class Hello2026 extends JFrame {

	public Hello2026() {
        setTitle("스윙 프레임");
        setSize(500,350);
        Container c=getContentPane();
        c.setBackground(Color.WHITE);
        c.setLayout(new GridLayout());
        JButton b1=new JButton("ok");
        c.add(b1);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setVisible(true);
	}

    public static void main(String[] args) {
        Hello2026 frame=new Hello2026();
    }

}
