
import javax.swing.*;
import java.awt.*;


public class Hello2026 extends JFrame {

	public Hello2026() {
        setTitle("스윙 프레임");
        setSize(500,350);
        Container c=getContentPane();
        c.setBackground(Color.WHITE);
        //c.setLayout(new FlowLayout(FlowLayout.CENTER, 30, 40));
        FlowLayout flow=new FlowLayout(FlowLayout.CENTER, 30, 40);
        c.setLayout(flow);
        c.add(new JButton("add"));
        c.add(new JButton("sub"));
        c.add(new JButton("mul"));
        c.add(new JButton("div"));
        c.add(new JButton("Calculate"));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setVisible(true);
	}

    public static void main(String[] args) {
        Hello2026 frame=new Hello2026();
    }

}
