package Snakegame;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import javax.swing.*;

public class Board extends JPanel implements ActionListener{
	
	PreparedStatement preparedStatement;
	Statement statement;
	ResultSet result;
	String sql;
	String conUrl="jdbc:ucanaccess://C:\\Users\\NASREEN PARWEEN\\eclipse-workspace\\Snake_Game\\src\\SnakeGameRecord.accdb";
	Connection con;
	
	static int count=0;
	    private Image apple;
	    private Image dot;
	    private Image head;
	    
	    private final int DOT_SIZE = 10;    // 300 * 300 = 90000 / 100 = 900
	    private final int ALL_DOTS = 900;
	    private final int RANDOM_POSITION = 25;
	    
	    private int apple_x;
	    private int apple_y;
	    
	    private final int x[] = new int[ALL_DOTS];
	    private final int y[] = new int[ALL_DOTS];
	    
	    private boolean leftDirection = false;
	    private boolean rightDirection =  true;
	    private boolean upDirection =  false;
	    private boolean downDirection =  false;
	    private boolean inGame = true;
	    
	    int dots;
	    
	    private Timer timer;
	    
	    FileOutputStream f1=null;
		FileInputStream f2=null;
			String msg1;
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

	    Board(){
	        
	        addKeyListener(new TAdapter());
	        setBackground(Color.BLACK);
	        setPreferredSize(new Dimension(500,500));
	        
	        setFocusable(true);
	        
	        loadImages();
	        initGame();
	        setBorder(BorderFactory.createLineBorder(Color.magenta, 5));
	    }
	    
	    public void loadImages(){
	    	
	    	ImageIcon i1= new ImageIcon(ClassLoader.getSystemResource("Snakegame/apple.png"));
	    	apple=i1.getImage();
	    	ImageIcon i2= new ImageIcon(ClassLoader.getSystemResource("Snakegame/dot.png"));
	    	dot=i2.getImage();
	    	ImageIcon i3= new ImageIcon(ClassLoader.getSystemResource("Snakegame/head.png"));
	    	head=i3.getImage();
	    }
	    
	    public void initGame(){
	        
	        dots = 3;
	        
	        for(int z = 0 ; z < dots ; z++){
	            x[z] = 50 - z * DOT_SIZE; // x[0] y[0] // x[1] y[1] // x[2] y[2]
	            y[z] = 50;
	        }
	        
	        locateApple();
	        
	        timer = new Timer(120, this);
	        timer.start();
	    }
	    
	    
	    public void locateApple(){
	        
	        int r = (int)(Math.random() * RANDOM_POSITION); // 0 and 1 =>  0.6 * 20 = 12* 10 = 120
	        apple_x = (r * DOT_SIZE); 
	        
	        r = (int)(Math.random() * RANDOM_POSITION); // 0 and 1 =>  0.6 * 20 = 12* 10 = 120
	        apple_y = (r * DOT_SIZE); 
	    }
	    
	    public void checkApple()
	        if((x[0] == apple_x) && (y[0] == apple_y)){
	            dots++;
	            locateApple();
	            count=count+10;
	        }  
	    }
	    
	    public void paintComponent(Graphics g){
	    
	        super.paintComponent(g);
	        
	        draw(g);
	    }
	    
	    public void draw(Graphics g){
	        if(inGame){
	            g.drawImage(apple, apple_x, apple_y, this);
	            
	            for(int z = 0; z < dots ; z++){
	                if(z == 0){
	                    g.drawImage(head, x[z], y[z], this);
	                }else{
	                    g.drawImage(dot, x[z], y[z], this);
	                }
	            }
	            
	            Toolkit.getDefaultToolkit().sync();
	        }else{
	             gameOver(g);   
	        }
	    }
	    
	    public void checkCollision(){
	        
	        for(int z = dots ; z > 0 ; z--){
	            if((z > 4) && (x[0] == x[z]) && (y[0] == y[z])){
	                inGame = false;
	            }
	        } 
	        
	        if(y[0] >= 295){
	            inGame = false;
	        }
	        
	        if(x[0] >= 295){
	            inGame = false;
	        }
	        
	        if(x[0] <=5){
	            inGame = false;
	        }
	        
	        if(y[0] <=5){
	            inGame = false;
	        }
	        
	        if(!inGame){
	            timer.stop();
	        }
	    }
	    
	    public void move(){
	        
	        for(int z = dots ; z > 0 ; z--){
	            x[z] = x[z - 1]; 
	            y[z] = y[z - 1];
	        }
	        
	        if(leftDirection){
	            x[0] = x[0] -  10;
	        }
	        if(rightDirection){
	            x[0] += 10;
	        }
	        if(upDirection){
	            y[0] = y[0] - 10;
	        }
	        if(downDirection){
	            y[0] += 10;
	        }
	        // 240 + 10 = 250
	    }
	    
	    public void actionPerformed(ActionEvent ae){
	        if(inGame){
	            checkApple();
	            checkCollision();
	            move();
	        }
	        
	        repaint();
	    }
	    public int HighScore() {
	    	
			 
			 try {
					Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
		        	 con=DriverManager.getConnection(conUrl);

					if(con!=null) {
						System.out.println("Connected Sucessfully");
						sql="select Score from Score1 where id=1";
						statement=con.createStatement();
						result=statement.executeQuery(sql);
						if(result.next()) {
							int data= result.getInt("Score");
							if(count>data)
							{
								 sql="Update Score1 set Score='"+count+"' where id=1";
								 statement=con.createStatement();
								 preparedStatement=con.prepareStatement(sql);
									int  row=preparedStatement.executeUpdate();
									if(row>0)
									{
										
									  System.out.println("Records has been updated sucesssfuly Sucessfully");
									  return 1;
									}
								 
								 
							}
					}
						return 0;
					}
					else
					{
						System.out.println("No connection");
						return 0;
					}
			 
			 }catch(Exception e)
				{
					System.out.println(e);
				}
		 
		 return 0;
		
		
	 }
	    public void gameOver(Graphics g){
	    	msg1=" ";
	        String msg = "Game Over!!!";
	        
	        msg1="\nYour Final Score is "+count;
	        Font font = new Font("SAN_SERIF", Font.BOLD, 18);
	        FontMetrics metrices = getFontMetrics(font);
	        int u=HighScore();
	        
	        g.setColor(Color.RED);
	        g.setFont(font);
	        g.drawString(msg, (300 - metrices.stringWidth(msg)) / 2 , 280/2);
	        g.setColor(Color.BLUE);
	   	 g.drawString(msg1, (300-metrices.stringWidth(msg))/2,280/2+20);
	   	 if(u==1)
	   	 {
	   		 msg="CONGRATULATION! TOP SCORE!!";
	   		 g.setColor(Color.ORANGE);
	   		 g.drawString(msg, (300-metrices.stringWidth(msg))/2,280/2+45);
	   	 }
	   	 g.setColor(Color.PINK);
	   	 msg1="PLEASE PRESS 'y' or 'Y' If you want to start again!";
	   	 g.drawString(msg1, (240-metrices.stringWidth(msg))/2,280/2+65);
	    }
	    
	    
	    
	    private class TAdapter extends KeyAdapter{
	    
	        @Override
	        public void keyPressed(KeyEvent e){
	           int key =  e.getKeyCode();
	           char ch1=e.getKeyChar();
	           if(key == KeyEvent.VK_LEFT && (!rightDirection)){
	               leftDirection = true;
	               upDirection = false;
	               downDirection = false;
	           }
	           
	           if(key == KeyEvent.VK_RIGHT && (!leftDirection)){
	               rightDirection = true;
	               upDirection = false;
	               downDirection = false;
	           }
	           
	           if(key == KeyEvent.VK_UP && (!downDirection)){
	               leftDirection = false;
	               upDirection = true;
	               rightDirection = false;
	           }
	           
	           if(key == KeyEvent.VK_DOWN && (!upDirection)){
	               downDirection = true;
	               rightDirection = false;
	               leftDirection = false;
	           }
	           if(ch1=='y' || ch1=='Y')
	   		{
	   			new Snake().setVisible(true);
	   		}
	        }
	    }
	    
	}
