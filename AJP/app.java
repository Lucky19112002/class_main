import java.awt.*;
import java.awt.event.*;
//Fore push
//import javax.security.auth.callback.TextInputCallback;
//import javax.swing.text.LabelView;


 class Myapp extends Frame
{
  Label libTitle,libName,libFature,libAge,libGender,libCources,libHobbies,libAddress;
  TextField txtName,txtFature,txtAge;
  TextArea txtAddress;
  Checkbox checkMale,checkFemale,checkOther,Hobbies,Hobbies1,Hobbies2,Hobbies3,Hobbies4;
  CheckboxGroup cbg;
  Choice course;
  Button bthSave,bthClear;
  public Myapp() 
  {
    super("User Registeraction Form");
    setSize(1000, 600);  // Hight and width
    setLayout(null);
    setVisible(true);
    Color formcColor = new Color(53, 59, 72);
    setBackground(formcColor);

    Font titleFont = new Font("arial",Font.BOLD,25);
    Font lableFont = new Font("arial",Font.BOLD,25);
    Font textFont = new Font("arial",Font.BOLD,25);
    { // Code for libTitle :

      libTitle = new Label("Registraction Form");
      libTitle.setBounds(250,40,300,50);
      libTitle.setFont(titleFont);
      libTitle.setForeground(Color.YELLOW);
      add(libTitle);
    }
    { // Code for libName : 
      libName = new Label("Name");
      libName.setBounds(250,100,150,30);
      libName.setFont(lableFont);
      libName.setForeground(Color.WHITE);
      add(libName);
      // Code for libName : TextFild()
        txtName = new TextField();
        txtName.setBounds(400,100,400,30);
        txtName.setFont(textFont);
        add(txtName);
      
    }
    { // Code for libFather : 
      libFature = new Label("Fathre Name");
      libFature.setBounds(200,150,150,30);
      libFature.setFont(lableFont);
      libFature.setForeground(Color.WHITE);
      add(libFature);
      { // Code for txtFather : Name
        txtFature = new TextField();
        txtFature.setBounds(400,150,400,30);
        txtFature.setFont(textFont);
        add(txtFature);

      }
    }
    { // Code for libAge : 
      libAge = new Label("Age");
      libAge.setBounds(250,150,150,30);
      libAge.setFont(lableFont);
      libAge.setForeground(Color.WHITE);
      add(libAge);
      { // Code for txtAge : Name
        txtAge = new TextField();
        txtAge.setBounds(400,200,400,30);
        txtAge.setFont(textFont);
        add(txtAge);
      }
    }
    { // Code for libGender : 
      libGender = new Label("Gender");
      libGender.setBounds(250,250,150,30);
      libGender.setFont(lableFont);
      libGender.setForeground(Color.WHITE);
      add(libGender);
      { // Code for cheakbox gor gender : Name
        cbg = new CheckboxGroup();
        {// checkMale box
          checkMale = new Checkbox("Male",cbg,true);
          checkMale.setBounds(400,250,100,30);
          checkMale.setFont(lableFont);
          checkMale.setForeground(Color.WHITE);
          add(checkMale);
        }
        {// checkFemal box
          checkFemale = new Checkbox("Female",cbg,true);
          checkFemale.setBounds(500,250,100,30);
          checkFemale.setFont(lableFont);
          checkFemale.setForeground(Color.WHITE);
          add(checkFemale);
        }
        {// checkother box
          checkOther = new Checkbox("Male",cbg,true);
          checkOther.setBounds(400,250,100,30);
          checkOther.setFont(lableFont);
          checkOther.setForeground(Color.WHITE);
          add(checkOther);
        }

      }
    }
    { // Code for Cources
      libCources = new Label("Course");
      libCources.setBounds(250,300,150,30);
      libCources.setFont(lableFont);
      libCources.setForeground(Color.WHITE);
      add(libCources);
      {// code for Choices
        course = new Choice();
        course.setFont(lableFont);
        course.setBounds(400, 300, 400, 50);
        course.add("c");
        course.add("c++");
        course.add("Java");
        course.add("c#");
        course.add("Python");
        add(course);
      }
    }
    { // Code for Hobbies
      libHobbies = new Label("Hobbiles");
      libHobbies.setBounds(250,350,150,30);
      libHobbies.setFont(lableFont);
      libHobbies.setForeground(Color.WHITE);
      add(libHobbies);
      { // code for Hobbie 1
        Hobbies1 = new Checkbox("Hacking");
        Hobbies1.setBounds(250,350,150,30);
        Hobbies1.setFont(lableFont);
        Hobbies1.setForeground(Color.WHITE);
        add(Hobbies1);
      }
      { // code for Hobbie 2
        Hobbies2 = new Checkbox("Playing");
        Hobbies2.setBounds(250,350,150,30);
        Hobbies2.setFont(lableFont);
        Hobbies2.setForeground(Color.WHITE);
        add(Hobbies2);
      }
      { // code for Hobbie 3
        Hobbies3 = new Checkbox("Sex");
        Hobbies3.setBounds(250,350,150,30);
        Hobbies3.setFont(lableFont);
        Hobbies3.setForeground(Color.WHITE);
        add(Hobbies3);
      }
      { // code for Hobbie 4
        Hobbies4 = new Checkbox("Cricket");
        Hobbies4.setBounds(250,350,150,30);
        Hobbies4.setFont(lableFont);
        Hobbies4.setForeground(Color.WHITE);
        add(Hobbies4);
      }
    }
    { // Code For Address
      libAddress = new Label("Address");
      libAddress.setBounds(250,400,150,30);
      libAddress.setFont(lableFont);
      libAddress.setForeground(Color.WHITE);
      add(libAddress);
      { // code for txtAddress
        txtAddress = new TextArea(10,30);
        txtAddress.setBounds(400,400,400,100);
        txtAddress.setFont(lableFont);
        add(txtAddress);
      }
    }
    { // Code for Button
      { // Code for SaveButton
        bthSave = new Button("Save Details");
        bthSave.setBounds(400,530,150,30);
        bthSave.setFont(lableFont);
        bthSave.setBackground(Color.BLUE);
        bthSave.setForeground(Color.WHITE);
        add(bthSave);
      }
      { // Code for ClearButton
        bthClear = new Button("Clear");
        bthClear.setBounds(560,530,150,30);
        bthClear.setFont(lableFont);
        bthClear.setBackground(Color.RED);
        bthClear.setForeground(Color.WHITE);
        add(bthClear);
      }
    }
    {// Code for Closebutton
      this.addWindowListener(new WindowAdapter(){
        public void windowClosing(WindowEvent we){
          System.exit(0);
        }
      });
    } 
  }

}


public class app{public static void main(String[] args){Myapp frm = new Myapp();}}

