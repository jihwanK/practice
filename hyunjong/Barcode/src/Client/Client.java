//package Client;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * @author YooHy
 *
 */
public class Client {
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Client cm = new Client();
		cm.ClientRun("NEW CONNECTION");
	}

	/**
	 * @param data
	 */
	private void ClientRun(String data) throws IOException {

		Socket socket = null;
		BufferedReader in = null;        
		PrintWriter out = null;          

		try {
			socket = new Socket("127.0.0.1", 4200);   // loopback ip (127.0.0.1), which means myself
		} catch(IOException ioe) {
			ioe.printStackTrace();
		}

		try {
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())));

			out.println(data);                 
			out.flush();

			String receiveData = in.readLine();        
			System.out.println("received data from the server : " + receiveData);

		} catch(Exception e) {
			e.printStackTrace();
		} finally {
			in.close();
			out.close();
			socket.close();
		}    
	}
}
