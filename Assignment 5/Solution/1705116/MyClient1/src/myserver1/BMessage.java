/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myserver1;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import static myserver1.MyServer1.newClientList;
import static myserver1.MyServer1.client_OS_list;
/**
 *
 * @author SAIKAT
 */
public class BMessage {
    
    public void BMessage_Action(String str,Socket s,DataInputStream dis,DataOutputStream dos,int id) throws IOException
    {
        String str1=str;
        String text=str1.substring(3);
  
      
        if(newClientList.get(id-1).getType().equalsIgnoreCase("admin"))
        {
            
            for (int i = 0; i < MyServer1.client_OS_list.size(); i++) {
                
                if(i!=(id-1))
                {
                  
                    
                    MyServer1.client_OS_list.get(i).writeUTF(text);
                     MyServer1.client_OS_list.get(i).flush();
                }
                
            }
            dos.writeUTF("BMessage sent sucessfully");
            dos.flush();
               
                
          
        }
        else{
            dos.writeUTF("BMessage Failed to Sent");
            dos.flush();
               
        }
    }
    
}
