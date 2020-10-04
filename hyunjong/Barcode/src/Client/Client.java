package Client;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;

/**
 * @author YooHy
 *
 */
public class Client {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Client cm = new Client();
		cm.ClientRun("Check the connection");
	}

	/**
	 * @param data
	 */
	public void ClientRun(String data){

		Socket socket = null;
		OutputStream os = null;
		OutputStreamWriter osw =null;
		BufferedWriter bw = null;

		InputStream is =null;
		InputStreamReader isr = null;
		BufferedReader br = null;

		try{
//			socket = new Socket("192.168.0.3", 4200);  //��Ʈ�� IP 192.168.0.3
			socket = new Socket("127.0.0.1", 4200);  //��Ʈ�� IP 192.168.0.3
			os = socket.getOutputStream();
			osw = new OutputStreamWriter(os);
			bw = new BufferedWriter(osw);            //������ ������ ���� OutputStream

			bw.write(data);
			bw.newLine();
			bw.flush();
			
			is = socket.getInputStream();
			isr = new InputStreamReader(is);
			br = new BufferedReader(isr);        // �����κ��� Data�� ����

			String receiveData = null;
			receiveData = br.readLine();        // �����κ��� ������ ���� ����
			System.out.println("�����κ��� ���� ������ : " + receiveData);
		}catch(Exception e){
			e.printStackTrace();
		}finally {
			try{
				bw.close();
				osw.close();
				os.close();
				br.close();
				isr.close();
				is.close();
			}catch(Exception e){
				e.printStackTrace();
			}
		}    

	}

}
