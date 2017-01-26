package Template;

import java.awt.image.BufferedImage;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Base64;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

import javax.imageio.ImageIO;


public class Client {

	private static boolean isAdmin = false;
	
	
	public static void main(String[] args) throws UnknownHostException,
			IOException {

		// 1. CONNECT TO THE SERVER AT PORT 4444 
		Socket socket = new Socket("localhost", 4444);
		printSocketInfo(socket);
		
		ServerListener sl = new ServerListener(socket);
		new Thread(sl).start();
		
		//Encrypt what the scanner scans in 
		Scanner clientIn = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new BufferedOutputStream(socket.getOutputStream()));
		System.out.print("Please enter a Username: ");
		String username = clientIn.nextLine();
		System.out.println();
	
		
		if(username.equalsIgnoreCase("admin")) {
			
			System.out.println("Type '/help' for menu options");
			isAdmin = true;
			out.println("Admin");
			out.flush();
		}
		System.out.println();
		System.out.println("Enter 1 to send Message");
		System.out.println("Enter 2 to send Image");
		System.out.println();
		
		boolean started = false; 
		while(true)
		{
				if(!isAdmin){
				
					int selection = 0; 
					
					try{
						selection = clientIn.nextInt(); 
						clientIn.nextLine(); 
					}
					catch(Exception e){
//						System.out.println("You have to enter choice");
					}
				
					if(selection == 1){
						System.out.print("Enter Message: ");
						if(!started){
							out.println(username);
							out.flush();
							started = true; 
						}
						
					}else if(selection == 2)
					{
						started = true; 
						System.out.print("Enter file path of image : ");
						String path = clientIn.nextLine(); 
						File image = new File(path); 
						
//						FileInputStream fis = new FileInputStream(image);
//						byte[] buffer = new byte[fis.available()];
//						fis.read(buffer);
//						out.println(encryptImage(buffer, image));
//						out.flush();
						
						
						Thread t = new Thread(new displayImage(image));
						t.start();
						continue; 
					}
				}
			
			//Encrypt here comes from system.in
			String clientMessage = clientIn.nextLine();
			
			
			if(isAdmin && clientMessage.startsWith("/help"))
			{
				System.out.println("The following are commands you may enter as an Admin:");
				System.out.println("/broadcast Sends message to all clients.");
				System.out.println("/history - show chat history.");
				System.out.println("/delete <Message Number> - delete the message at index <Message Number>.");
			}
			else if(isAdmin && clientMessage.startsWith("/broadcast"))
			{
				System.out.print("Enter message: ");
				out.println(encrypt(clientIn.nextLine()));
				out.flush();
			}
			else if(isAdmin && clientMessage.startsWith("/history"))
			{
				int lineNum = 0;
				Scanner fileIn = new Scanner(new File("chat.txt"));
				while(fileIn.hasNextLine()){
					System.out.println(lineNum + ": " + fileIn.nextLine());
					lineNum++;
				}
				fileIn.close();
			}
			else if(isAdmin && clientMessage.startsWith("/delete"))
			{
				int lineToDelete = Integer.parseInt("" + clientMessage.trim().charAt(clientMessage.length()-1));
				Scanner fileIn = new Scanner(new File("chat.txt"));
				ArrayList<String> history = new ArrayList<String>();
				
				while(fileIn.hasNextLine()){
					history.add(fileIn.nextLine());
				}
				// Removes line from history (text.txt).
				history.remove(lineToDelete);
				PrintWriter fileWrite = new PrintWriter("chat.txt");
				
				while(!history.isEmpty()){
					fileWrite.println(history.get(0));
					history.remove(0);
				}
				fileIn.close();
				fileWrite.close();
			}
			else
			{
				out.println(encrypt(clientMessage));
				out.flush();
			}
		}		
	}



private static String encryptImage(byte[] buffer, File image) throws UnsupportedEncodingException {

	  StringBuilder sb = new StringBuilder(buffer.length * Byte.SIZE);
	    for( int i = 0; i < Byte.SIZE * buffer.length; i++ )
	        sb.append((buffer[i / Byte.SIZE] << i % Byte.SIZE & 0x80) == 0 ? '0' : '1');

	    String string = sb.toString(); 
	    String result = string.replace('1', 'a');
	    String endResult = result.replace('0', 'b'); 
	    

	    return endResult; 
	}



private static String encrypt(String clientMessage) throws UnsupportedEncodingException {
		
		byte[] message = clientMessage.getBytes("UTF-8"); 
		
		String[] compare = {"1", "1", "1", "1", "0", "0", "0", "0"}; 
		Queue<String> q1 = new LinkedList<String>(); 
		Queue<String> q2 = new LinkedList<String>(); 
		
		for(int i = 0; i < compare.length; i++){
			q1.add(compare[i]); 
		}
		
		  StringBuilder sb = new StringBuilder(message.length * Byte.SIZE);
		    for( int i = 0; i < Byte.SIZE * message.length; i++ )
		        sb.append((message[i / Byte.SIZE] << i % Byte.SIZE & 0x80) == 0 ? '0' : '1');

		    String string = sb.toString(); 
		    boolean queue1 = true; 
		    String result = ""; 
		    
		    for(int i = 0; i < string.length(); i++){
		    	int item = 0; 
		    	int token = 0; 
		    	if(i > 0 && i % 8 == 0){
		    		queue1 = !queue1; 
		    	}
		    	if(queue1){
		    		q2.add(q1.peek()); 
		    		token = Integer.parseInt(q1.remove()); 
		    		item = token ^ Integer.parseInt(string.charAt(i) + ""); 
		    		
		    	}else{
		    		q1.add(q2.peek()); 
		    		token = Integer.parseInt(q2.remove()); 
		    		item = token ^ Integer.parseInt(string.charAt(i) + ""); 
		    	}
		    	result = result + (item + "");  
		    }

		return result; 		
	}

static void printSocketInfo(Socket s) {
		System.out.print("Socket on Client Side: ");
		System.out.print("Local Address: " + s.getLocalAddress() + ":"
				+ s.getLocalPort());
		System.out.println("  Remote Address: " + s.getRemoteSocketAddress());
	}
}


class ServerListener implements Runnable{
	Scanner serverIn;
	
	public ServerListener(Socket socket)
	{
		try
		{
			serverIn = new Scanner(new BufferedInputStream(socket.getInputStream()));
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

	@Override
	public void run() 
	{	
		while(true)
		{
			if(serverIn.hasNextLine())
				System.out.println(serverIn.nextLine());
		}
	}
}