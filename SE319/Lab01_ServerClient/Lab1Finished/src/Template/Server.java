package Template;

import java.io.IOException;
import java.io.File;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Server {
	
	private static ArrayList<Socket> clientSocketList = new ArrayList<Socket>();
	
	public static void main(String[] args) throws IOException, InterruptedException {
		ServerSocket serverSocket = null;
		int clientNum = 0; // keeps track of how many clients were created
		File file = null;
		
		// 1. CREATE A NEW SERVERSOCKET
		try {
			file = new File("chat.txt");
			serverSocket = new ServerSocket(4444); // provide MYSERVICE at port
													// 4444
			System.out.println(serverSocket);
		} catch (IOException e) {
			System.out.println("Could not listen on port: 4444");
			System.exit(-1);
		}
	

		// 2. LOOP FOREVER - SERVER IS ALWAYS WAITING TO PROVIDE SERVICE!
		while (true) {
			Socket clientSocket = null;
			try {
//				// 2.1 WAIT FOR CLIENT TO TRY TO CONNECT TO SERVER
				clientSocket = serverSocket.accept();

				// 2.2 SPAWN A THREAD TO HANDLE CLIENT REQUEST
				System.out.println("Server connected to client"
						+ ++clientNum);
				clientSocketList.add(clientSocket);
				Thread t = new Thread(new ClientHandler(clientSocket, clientNum, file, clientSocketList));
				t.start();
				
			} catch (IOException e) {
				System.out.println("Accept failed: 4444");
				System.exit(-1);
			}

			// 2.3 GO BACK TO WAITING FOR OTHER CLIENTS
			// (While the thread that was created handles the connected client's
			// request)

		} // end while loop

	} // end of main method

} // end of class MyServer