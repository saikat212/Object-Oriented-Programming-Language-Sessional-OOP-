
package myserver1;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;



public class MyServer1 extends Application  {
    public static  ObservableList<LMessage> newClientList=FXCollections.observableArrayList();
    public static  ObservableList<DataOutputStream> client_OS_list=FXCollections.observableArrayList();
    public static int client_no=0;
    public static int id=0;
    

    
    @Override
    public void start(Stage stage) throws Exception {
        
         serverThread st=new serverThread();
         Thread t=new Thread(st);
         t.start();
        
        Parent root = FXMLLoader.load(getClass().getResource("ServerHomepage.fxml"));
        
        Scene scene = new Scene(root);
        
        stage.setScene(scene);
        stage.show();
        
        
        
    }

    public static void main(String[] args)  {
        
       
       
        launch(args);
    }
    
    class serverThread implements Runnable
    {

        @Override
        public void run() {
            
        ServerSocket ss;
         
            try {
                ss = new ServerSocket(5110);           
               
                
                
                while(true){

                Socket s;
                
                 //System.out.println("Before connected");
                  s=ss.accept();
                   //client_no++;
                   id++;
                 // System.out.println("connected");
  
                  RegisteredClient rc=new RegisteredClient();
                  DataInputStream dis=new DataInputStream(s.getInputStream());
                  DataOutputStream dos =new DataOutputStream(s.getOutputStream());
                              //    client_OS_list.add(dos);
                   WorkerThread wt=new WorkerThread(s,dis,dos,id);
                   Thread t1=new Thread(wt);
                   t1.start();
                   
                   
                  
                 
                }
            } catch (IOException ex) {
               /// Logger.getLogger(MyServer1.class.getName()).log(Level.SEVERE, null, ex);
            }
            
           
       
    }
    
}
}
