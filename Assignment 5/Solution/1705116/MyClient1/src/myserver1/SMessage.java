
package myserver1;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.net.Socket;
import myserver1.LMessage;
import myserver1.MyServer1;
import static myserver1.MyServer1.newClientList;

/**
 *
 * @author SAIKAT
 */
public class SMessage {
    public void SMessage_Action(String st,Socket s1,DataInputStream dis1,DataOutputStream dos1,int id) throws IOException
    {
        DataInputStream dis=dis1;
        DataOutputStream dos=dos1;
        String client_Lmessage=st;
       
         if(client_Lmessage.charAt(3)=='T')
                {
                    String str=client_Lmessage.substring(6);
                    
                    System.out.println("Client SMessage Text sent for Server: "+str);
                }
                 if(client_Lmessage.charAt(3)=='S')
                {
                    String str="";
                    for (LMessage lMessage : newClientList) {
                        str+=lMessage.getUsername()+"#";
                        
                    }
                    dos.writeUTF(str);
                    dos.flush();
                    
                }
                  if(client_Lmessage.charAt(3)=='O')
                {
                    
                    newClientList.remove(id-1);
                   // System.out.println("Client No: "+MyServer1.client_no+" Logout ");
                    dos.writeUTF("Logout");
                    dos.flush();
                }

    }
}
