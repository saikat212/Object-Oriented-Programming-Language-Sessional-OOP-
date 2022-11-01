/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myserver1;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.IOException;
import java.net.Socket;
import java.nio.file.Files;
import static myserver1.MyServer1.client_OS_list;
import static myserver1.MyServer1.newClientList;

/**
 *
 * @author SAIKAT
 */
class CMessage {

    void CMessage_Action(String client_message, Socket s, DataInputStream dis, DataOutputStream dos, int id) throws IOException {

        String main_msg = client_message.substring(3);
        String[] R_T_F = main_msg.split("##");

        for (int i = 0; i < newClientList.size(); i++) {

            if (newClientList.get(i).getUsername().equals(R_T_F[0])) {
                String server_msg = id + "##" + newClientList.get(id - 1).username + "##" + R_T_F[1] + "##" + R_T_F[2];

                client_OS_list.get(i).writeUTF(server_msg);
                client_OS_list.get(i).flush();
                
                if(!(R_T_F[2].equalsIgnoreCase("")))
                {
                    byte[] content = new byte[dis.available()];
                    dis.read(content);
                    
                  client_OS_list.get(i).write(content);
                   client_OS_list.get(i).flush();
                  
                }

                

            }

        }

    }

}
