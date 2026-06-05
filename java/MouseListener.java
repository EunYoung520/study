package swing_action;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class ImageViewer extends JFrame {
	private JLabel la=new JLabel("Hello");
	//내부 클래스
	class MyMouse implements MouseListener{
		public void mousePressed(MouseEvent e) {
			la.setLocation(e.getX(), e.getY());
		}
		public void mouseClicked(MouseEvent e) {}
		public void mouseReleased(MouseEvent e) {}
		public void mouseEntered(MouseEvent e) {}
		public void mouseExited(MouseEvent e) {}
	}
	
	public ImageViewer() {
		setTitle("action");
		Container c=getContentPane();
		c.setLayout(new BorderLayout());
		
		setSize(1200,800);
		JPanel leftpanel=new JPanel();
		leftpanel.setBackground(Color.WHITE);
		leftpanel.setLayout(null);
		la.setSize(50,30);
		la.setLocation(30,30);
		leftpanel.add(la);
		leftpanel.addMouseListener(new MyMouse());
		

		JPanel rightpanel=new JPanel();
		rightpanel.setPreferredSize(new Dimension(250,0));
		rightpanel.setBackground(Color.LIGHT_GRAY);
		
		c.add(leftpanel, BorderLayout.CENTER);
		c.add(rightpanel, BorderLayout.EAST);
		
		JLabel test1 = new JLabel("안녕하세요");
		rightpanel.add(test1);
				
		JMenuBar menubar=new JMenuBar();
		JMenu filemenu=new JMenu("file");
		JMenu editmenu=new JMenu("edit");
		JMenu helpmenu=new JMenu("help");
		menubar.add(filemenu);
		menubar.add(editmenu);
		menubar.add(helpmenu);
		setJMenuBar(menubar);
		
		JMenuItem openitem=new JMenuItem("open");
		JMenuItem saveitem=new JMenuItem("save");
		JMenuItem exititem=new JMenuItem("exit");
		openitem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				JFileChooser chooser =new JFileChooser();
				int result=chooser.showOpenDialog(ImageViewer.this);
			}
		});	
		filemenu.add(openitem);
		filemenu.add(saveitem);
		filemenu.add(exititem);
		

		
		
		setVisible(true);	

		
	}

	public static void main(String[] args) {
		ImageViewer sw = new ImageViewer(); 
	}
}

