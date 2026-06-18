package swing_action;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class ImageViewer extends JFrame {
	private JLabel la=new JLabel("Hello");
	
	private JLabel imagelabel;
	private JLabel desclabel;
	
	
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
		leftpanel.add(imagelabel, BorderLayout.CENTER);

		JPanel rightpanel=new JPanel();
		rightpanel.setPreferredSize(new Dimension(250,0));
		rightpanel.setBackground(Color.LIGHT_GRAY);
		
		c.add(leftpanel, BorderLayout.CENTER);
		c.add(rightpanel, BorderLayout.EAST);
		
		desclabel=new JLabel("주소");
		rightpanel.add(desclabel);
		
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
				
				if(result == JFileChooser.APPROVE_OPTION) {
					String path=chooser.getSelectedFile().getPath();
					
					ImageIcon icon =new ImageIcon(path);
					imagelabel.setIcon(icon);
					desclabel.setText("주소:"+path);
					System.out.println(path);
				}
				
				

				
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

