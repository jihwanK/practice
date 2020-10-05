//package Server;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Server ss = new Server();
      ss.ServerRun();
  }
 
  private void ServerRun() throws IOException {
    ServerSocket server = null;
    int port = 4200;
    Socket socket = null;
    BufferedReader in = null; 
    
    try {
      server = new ServerSocket(port);
      System.out.println("--- start server [port: " + port + "] ---");
    } catch (IOException ioe) {
      ioe.printStackTrace();
      System.out.println("The port has already been opened");
    }

    try {
      while(true) {
        socket = server.accept();         
        System.out.println("client [" + socket.getInetAddress() + "] is connected");
              
        in = new BufferedReader(new InputStreamReader(socket.getInputStream())); // create input stream
            
        String data = null;
        data = in.readLine();

        System.out.println("Received data from a client: " + data);
        
        String sendClient = "Responding...";
        echoReceiveData(sendClient, socket);      
        System.out.println();
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      in.close();
      server.close();
    }
  }

  private void echoReceiveData(String data, Socket socket) {
    PrintWriter out = null;   

    try {
      out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()))); // create output stream
      out.println(data);         
      out.flush();
        
      System.out.println("[" + data + "]" +  " has been sent");
    } catch(Exception e) {
      e.printStackTrace();
    } finally {
      out.close();
    }
  }
}
