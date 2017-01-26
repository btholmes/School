package Template;

import java.awt.image.BufferedImage;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.net.Socket;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

import javax.imageio.ImageIO;

class ClientHandler implements Runnable {
	Socket s; // this is socket on the server side that connects to the CLIENT
	int num; // keeps track of its number just for identifying purposes
	File file;
	ArrayList<Socket> clientSocketList;


	ClientHandler(Socket s, int n,File f, ArrayList<Socket> clientSocketList) {
		this.s = s;
		num = n;
		file = f;
		this.clientSocketList = clientSocketList; 
	}
	// This is the client handling code
	public void run() {
		printSocketInfo(s); // just print some information at the server side about the connection
		Scanner in;
		PrintWriter serverOut = null;
		FileWriter fileWrite;
		String username;
		
		try {
			// 1. USE THE SOCKET TO READ WHAT THE CLIENT IS SENDING
			in = new Scanner(new BufferedInputStream(s.getInputStream())); 			
			fileWrite = new FileWriter(file.getAbsoluteFile(),true);
			username = in.nextLine() + " : ";
						
			while(true)
			{
				String clientMessage = decrypt(in.nextLine());  
				
					
				// 2. PRINT WHAT THE CLIENT SENT
				
				for(int i = 0; i < clientSocketList.size(); i++){			
					serverOut = new PrintWriter(new BufferedOutputStream(clientSocketList.get(i).getOutputStream()));
						serverOut.println(username + clientMessage);
					
					serverOut.flush();
				}
				
				fileWrite.write(username + clientMessage + "\n");
				
				fileWrite.flush();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	
	private String decryptImage(String clientMessage) throws IOException {
		// TODO Auto-generated method stub
		String result = clientMessage.replace('a', '1'); 
		String endResult = result.replace('b', '0'); 

//		byte[] byteArray = endResult.getBytes(); 
		
		
		return null;
	}
	private String decrypt(String clientMessage) throws UnsupportedEncodingException {
		
		String[] compare = {"1", "1", "1", "1", "0", "0", "0", "0"}; 
		Queue<String> q1 = new LinkedList<String>(); 
		Queue<String> q2 = new LinkedList<String>(); 
		
		for(int i = 0; i < compare.length; i++){
			q1.add(compare[i]); 
		}
		
		    boolean queue1 = true; 
		    String result = ""; 
		    
		    for(int i = 0; i < clientMessage.length(); i++){
		    	int item = 0; 
		    	int token = 0; 
		    	if(i > 0 && i % 8 == 0){
		    		queue1 = !queue1; 
		    	}
		    	if(queue1){
		    		q2.add(q1.peek()); 
		    		token = Integer.parseInt(q1.remove()); 
		    		item = token ^ Integer.parseInt(clientMessage.charAt(i) + ""); 
		    		
		    	}else{
		    		q1.add(q2.peek()); 
		    		token = Integer.parseInt(q2.remove()); 
		    		item = token ^ Integer.parseInt(clientMessage.charAt(i) + ""); 
		    	} 
		    	result = result + item + ""; 
		    }
		    byte[] bval = new BigInteger(result, 2).toByteArray();
		    String endResult = new String(bval, "UTF-8"); 
		    
		return endResult; 	
	}
	void printSocketInfo(Socket s) {
		System.out.print("Socket on Server " + Thread.currentThread() + " ");
		System.out.print("Server socket Local Address: " + s.getLocalAddress()
				+ ":" + s.getLocalPort());
		System.out.println("  Server socket Remote Address: "
				+ s.getRemoteSocketAddress());
	}
}
