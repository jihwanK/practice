package Server;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Server ss = new Server();
        ss.ServerRun();
    }
 
    public void ServerRun() throws IOException{
        
        ServerSocket server = null;
        int port = 4200;
        Socket socket = null;
        
        InputStream is = null;
        InputStreamReader isr = null;
        BufferedReader br = null;
        
        try {
        	 server = new ServerSocket(port);
             while(true){
                 System.out.println("-------���� �����------");
                 socket = server.accept();         // Ŭ���̾�Ʈ�� �����ϸ� ����� �� �ִ� ���� ��ȯ
                 System.out.println(socket.getInetAddress() + "�� ���� �����û�� ����");
                 
                 is = socket.getInputStream();
                 isr = new InputStreamReader(is);
                 br = new BufferedReader(isr);
                 // Ŭ���̾�Ʈ�κ��� �����͸� �ޱ� ���� InputStream ����
                 
                 String data=null;
                 data=br.readLine();
                 System.out.println("Ŭ���̾�Ʈ�� ���� ���� ������: " + data);
                 
                 echoReceiveData(data, socket);         // ���� �����͸� �״�� �ٽ� ������
                 System.out.println("****** ���� �Ϸ� ****");
        }
        }catch (Exception e) {
            e.printStackTrace();
        }finally {
            try{
                br.close();
                isr.close();
                is.close();
                server.close();
            }catch(Exception e){
                e.printStackTrace();
            }
        }
    }

public void echoReceiveData(String data, Socket socket){
    OutputStream os = null;
    OutputStreamWriter osw = null;
    BufferedWriter bw = null;
    
    try{
        os = socket.getOutputStream();
        osw = new OutputStreamWriter(os);
        bw = new BufferedWriter(osw);
        // Ŭ���̾�Ʈ�κ��� �����͸� ������ ���� OutputStream ����
        
        bw.write(data);            // Ŭ���̾�Ʈ�� ������ ����
        bw.flush();
        
        System.out.println("------���� �Ϸ�-------");
        System.out.println("------���� �Ϸ�-------");
    }catch(Exception e1){
        e1.printStackTrace();
    }
}
}
