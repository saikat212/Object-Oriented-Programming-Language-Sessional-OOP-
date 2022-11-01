package file_selection;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.Scanner;
import java.util.StringTokenizer;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventType;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.stage.FileChooser;

public class FXMLDocumentController implements Initializable {

    @FXML
    private TableColumn<WordFrequency, String> word;
    @FXML
    private TableColumn<WordFrequency, Integer> frequency;

    ObservableList<WordFrequency> list = FXCollections.observableArrayList();

    @FXML
    private TableView<WordFrequency> tableView;

    private ListView<String> listview;

    static String filename;
    static int click_number=0;
    static int click_number1=0;
    @FXML
    private Button filechooser;
    @FXML
    private TextField tfield;
   

    @Override
    public void initialize(URL url, ResourceBundle rb) {

        word.setCellValueFactory(new PropertyValueFactory<WordFrequency, String>("word"));
        frequency.setCellValueFactory(new PropertyValueFactory<WordFrequency, Integer>("frequency"));
        tableView.setItems(list);

    }

    @FXML
    private void fileChoosenAction(ActionEvent event) {
       
        FileChooser fc = new FileChooser();
       
       
        File selectedFile = fc.showOpenDialog(null);
        if (selectedFile != null) {
           // listview.getItems().add(selectedFile.getName());
            tfield.setText(selectedFile.getName());
            filename = selectedFile.getName();
            
        } else {
            System.out.println("Filed to choose a file");
        }
        
        

    }

    @FXML
    private void ShowAction(ActionEvent event) throws IOException {
        
        
        
         click_number++;
        if(click_number>1)
        {
           
             
           
                while(list.size()!=0)
                {
                list.remove(list.get(0));
                }
            
                
             
        }
               
        

        File file = new File(filename);
        if (!(file.exists())) {
            file.createNewFile();
            System.out.println("file not found");

        }
        Scanner input = new Scanner(file);
        
       
       
        String str = "";
        int count = 0;
        int i = 0;
        boolean check = true;
       
       
        
        while (input.hasNext()) {
            str += input.next() + " ";
        }
        
        
        StringTokenizer tokens = new StringTokenizer(str);
        String[] str1 = new String[tokens.countTokens()];
        
        while (tokens.hasMoreTokens()) {
            str1[i] = tokens.nextToken();
            i++;

        }
        
        
        for (int j = 0; j < str1.length; j++) {
           
            count = 0;
            check = true;
            
            
            for (int k = 0; k < str1.length; k++) {
                if (str1[j].equals(str1[k])) {
                    count++;
                }
            }

            for (int k = 0; k < list.size(); k++) {
                WordFrequency s2 = list.get(k);
                String s3 = s2.getWord();
                if ((s3.equals(str1[j]))) {
                    check = false;

                }
            }
            
            
            if (check) {
                WordFrequency wf = new WordFrequency(str1[j], count);
                list.add(wf);

            }
            
            
        }

       // tableView.setItems(list);
        

    }

}
