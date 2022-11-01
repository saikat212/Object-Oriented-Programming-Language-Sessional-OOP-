/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myclient1;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

/**
 * FXML Controller class
 *
 * @author SAIKAT
 */
public class CMessage_pageController implements Initializable {

    @FXML
    private TextField reciever_name;
    @FXML
    private TextField CMessage_text;
    @FXML
    private TextField CMessgage_File_Name;
    @FXML
    private TextArea text_area;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }

    @FXML
    private void CMessage_Send_Action(ActionEvent event) throws IOException {
        String str = "#C#" + reciever_name.getText() + "##" + CMessage_text.getText() + "##" + CMessgage_File_Name.getText();

        DataOutputStream dos = new DataOutputStream(MyClient1.s.getOutputStream());
        // System.out.println("cmgs of send action: "+str);
        dos.writeUTF(str);
        dos.flush();
         /*
        File f = new File(CMessgage_File_Name.getText());
        if (f.exists()) {
            byte[] content = Files.readAllBytes(f.toPath());
            dos.write(content);
            dos.flush();
            System.out.println("file sent");
        } else {
            System.out.println("file not found");
        } */
    }

    @FXML
    private void See_Message_Action(ActionEvent event) throws IOException {

        DataInputStream dis = new DataInputStream(MyClient1.s.getInputStream());

        String Cmsg_from_another = dis.readUTF();

        String[] CNTF = Cmsg_from_another.split("##");
        String msg = CNTF[0] + "-th Client::  " + CNTF[1] + "\n" + "Text: " + CNTF[2] + "\n" + "File: " + CNTF[3];
        text_area.setText(msg);
        
                   byte[] content = new byte[dis.available()];
                   dis.read(content);
                   File f=new File("data1.txt");
                   Files.write(f.toPath(),content);
                    
        
        
        

    }

}
