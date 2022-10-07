package Snakegame;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Snake extends JFrame {
	
	 Snake()
	 {
		 Board b=new Board();
			add(b);
			pack();
			setLocation(500,200);  // set Frame Location on screen
			//setLocationRelativeTo(null);  // set Location of Frame in middle
			setTitle("SnakeGame");
			setResizable(false);  // prevent the window to resize
 }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		new Snake().setVisible(true);
	}

}
