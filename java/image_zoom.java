package swing_action;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class ImageViewer extends JFrame {
	
	private JLabel imagelabel;
	
	public ImageViewer() {
		setTitle("action");
		Container c=getContentPane();
		c.setLayout(new BorderLayout());
		
		setSize(1200,800);
		
		JPanel leftpanel=new JPanel();
		leftpanel.setLayout(new BorderLayout());
		imagelabel = new JLabel();
		imagelabel.setHorizontalAlignment(JLabel.CENTER);
		imagelabel.setVerticalAlignment(JLabel.CENTER);
		ImageIcon icon =new ImageIcon("C:\\Users\\user\\Pictures\\1000035587.jpg"); 
		imagelabel.setIcon(icon);
		leftpanel.add(imagelabel, BorderLayout.CENTER);
		c.add(leftpanel, BorderLayout.CENTER);
		leftpanel.addMouseWheelListener(new MouseWheelListener() {
		    @Override
		    public void mouseWheelMoved(MouseWheelEvent e) {
		        int notches = e.getWheelRotation();
		        int delta = 5;

		        if(notches < 0) {
		            
		        }
		        else {
		            
		        }
		    }
		});
	
	public static void main(String[] args) {
		ImageViewer sw = new ImageViewer(); 
	}
}

