package swing_action;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class ImageViewer extends JFrame {
	
	private JLabel imagelabel;
	private int panelwidth;
	private int panelheight;
	
	public ImageViewer() {
		setTitle("Wheelevwnt");
		Container c=getContentPane();
		c.setLayout(null);
	
		setSize(1200,800);
		setLocationRelativeTo(null);
		JPanel leftpanel=new JPanel();
		imagelabel = new JLabel();
		ImageIcon icon =new ImageIcon("C:\\Users\\user\\Pictures\\1000035587.jpg"); 
		imagelabel.setIcon(icon);
		leftpanel.setBounds(100, 100, 300, 400);
		
		panelwidth=leftpanel.getWidth();
		panelheight=leftpanel.getHeight();
		
		c.add(leftpanel);
		leftpanel.add(imagelabel);
		
		c.addMouseWheelListener(new MouseWheelListener() {
		    @Override
		    public void mouseWheelMoved(MouseWheelEvent e) {
		        int notches = e.getWheelRotation();
		        int delta = 100;

		        if(notches < 0) {
		        	panelwidth +=delta;
		        	panelheight +=delta;
		        }
		            
		        else {
		        	panelwidth -=delta;
		        	panelheight -=delta;		        	
		        }
		        leftpanel.setBounds(leftpanel.getX(), leftpanel.getY(),panelwidth, panelheight);
		    }
		});
		
		setVisible(true);
	}
	
	public static void main(String[] args) {
		ImageViewer sw = new ImageViewer(); 
	}
}
