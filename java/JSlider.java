package swing_action;

import javax.swing.*;
import java.awt.*;
import javax.swing.event.*;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class ImageViewer extends JFrame {
	
	private JLabel imagelabel;
	private int panelwidth;
	private int panelheight;
	private JPanel leftpanel;
	
	public ImageViewer() {
		setTitle("Wheelevwnt");
		Container c=getContentPane();
		c.setLayout(new BorderLayout());
	
		setSize(1200,800);
		setLocationRelativeTo(null);
		leftpanel=new JPanel();
		imagelabel = new JLabel();
		ImageIcon icon =new ImageIcon("C:\\Users\\user\\Pictures\\1000035587.jpg"); 
		imagelabel.setIcon(icon);
		leftpanel.setBounds(100, 100, 500, 500);
		
		panelwidth=leftpanel.getWidth();
		panelheight=leftpanel.getHeight();
		
		c.add(leftpanel,BorderLayout.CENTER);
		leftpanel.add(imagelabel);
		
		JSlider bslider=new JSlider(-100,100,0);
		bslider.setBounds(100, 300, 250, 50);
		c.add(bslider, BorderLayout.SOUTH);
		bslider.addChangeListener(new ChangeListener() {
		    @Override
		    public void stateChanged(ChangeEvent e) {
		        System.out.println(bslider.getValue());
		    }
		});
		
		setVisible(true);
	}
	
	public static void main(String[] args) {
		ImageViewer sw = new ImageViewer(); 
	}
}
