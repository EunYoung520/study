package swing_action;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class ImageViewer extends JFrame {
	private JButton b1;
	private JLabel l1;
	
	public ImageViewer() {
		setTitle("action");
		Container c=getContentPane();
		c.setLayout(new FlowLayout());
		b1=new JButton("action");
		c.add(b1);
		l1 = new JLabel("테스트 중...");
		c.add(l1);
		b1.addActionListener(new Myactionlistener());
		setSize(300,200);
		setVisible(true);
		
	}
	class Myactionlistener implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e) {
			JButton b=(JButton)e.getSource();
			if(b.getText().equals("action")) {
				b.setText("액션");
			}
			else
				b.setText("action");
			ImageViewer.this.setTitle(b.getText());
			l1.setText(b.getText());
		}
	}
	public static void main(String[] args) {
		ImageViewer sw = new ImageViewer(); 
	}
}

/*class Myactionlistener implements ActionListener{
	@Override
	public void actionPerformed(ActionEvent e) {
		JButton b=(JButton)e.getSource();
		if(b.getText().equals("action")) {
			b.setText("액션");
		}
		else
			b.setText("action");
	}*/
