package Template;

import java.awt.FlowLayout;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class displayImage implements Runnable {

	File imageFile; 
	public displayImage(File image) throws IOException {
		// TODO Auto-generated method stub
		imageFile = image; 
		
	}
	public void createFrame() throws IOException{
		BufferedImage img = ImageIO.read(imageFile);
	    ImageIcon icon = new ImageIcon(img);
	    JFrame frame = new JFrame();
	    frame.setLayout(new FlowLayout());
	    frame.setSize(500,500);
	    JLabel lbl=new JLabel();
	    lbl.setIcon(icon);
	    frame.add(lbl);
	    frame.setVisible(true);
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		try {
			createFrame();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		
	}

}
