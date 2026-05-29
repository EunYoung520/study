
import javax.swing.*;
import java.awt.*;


public class Hello2026 extends JFrame {

	public Hello2026() {
        setTitle("스윙 프레임");
        setSize(500,350);
        Container c=getContentPane();
        c.setBackground(Color.WHITE);
        c.setLayout(new BorderLayout());//괄호 안에 숫자 (10,10)은 버튼끼리의 거리
        c.add(new JButton("add"),BorderLayout.WEST);
        c.add(new JButton("sub"),BorderLayout.EAST);
        c.add(new JButton("mul"),BorderLayout.CENTER);
        c.add(new JButton("div"),BorderLayout.NORTH);
        c.add(new JButton("Calculate"),BorderLayout.SOUTH);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setVisible(true);
	}

    public static void main(String[] args) {
        Hello2026 frame=new Hello2026();
    }

}
