//this libraries contains the declarations of functions needed for the program noraml functionning
#include<gtk/gtk.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"gospel.h"

//macro definition
#define handle_err(msg)\
      do{ perror(msg);exit(0);}\
         while(0);
//main takes arguments from the commandline
int main(int argc,char*argv[])
{
  GtkWidget*window;
  GtkWidget*button1,*button3,*button4,*button5,*button6,*button7,*button8,*button9,*handle;
  GtkWidget*picture1,*picture2,*label3,*label4,*label5,*label6,*label7,*label8,*label9,*label10,*label11,*label1,*label2;
  GtkWidget*box1,*box2,*box3,*box4,*box5,*box6,*box7,*box8,*box9,*picture;
  GtkWidget*image1,*image2,*image3,*image4,*image5,*image6,*image7,*image8,*image9,*lab1,*lab2,*lab3,*lab4;
  GtkWidget*hbox1,*hbox2,*hbox3,*hbox4,*hbox5,*hbox6,*hbox7,*hbox8,*hbox9,*hbox11;
  GtkWidget*vbox,*vbox1,*notebook,*fbox1,*fbox2,*fbox3,*fbox4,*pict1,*pict2,*pict3,*pict4;
  GdkColor color1,color2,color3;
  GtkWidget*but1,*but2,*but3,*but4;
  GtkWidget*img1,*img2,*img3,*img4;
   gtk_init(&argc,&argv);

   if(!gtk_init_check(&argc,&argv))
     {
       handle_err("FAILED TO INITIALIZE THE GTK LIBRARIES");
     }

    //the following creats a window
     window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
            gtk_window_set_resizable(GTK_WINDOW(window),TRUE);
            gtk_window_set_title(GTK_WINDOW(window),"GOSPEL BROWSER");
            gtk_window_maximize(GTK_WINDOW(window));
            gtk_window_present(GTK_WINDOW(window));
           gtk_container_set_border_width(GTK_CONTAINER(window),0);
      gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon.jpg",NULL);
       g_signal_connect(GTK_OBJECT(window),"destroy",G_CALLBACK(Close_Window),NULL);
 //the following creats entry boxes
  entry1=gtk_entry_new();
  entry2=gtk_entry_new();
  entry3=gtk_entry_new();
  //reading a picture from the desktop
  picture1=gtk_image_new_from_file("picture.jpg");
  picture2=gtk_image_new_from_file("ogo.jpg");
 gtk_widget_set_size_request(picture1,300,100);
//creating entry boxes

  gtk_entry_set_text(GTK_ENTRY(entry1),"http//:");
  gtk_entry_set_text(GTK_ENTRY(entry2),"search");
  gtk_entry_set_text(GTK_ENTRY(entry3),"www.emmanuelTV.com");
 //the lines of code below creats images from stock
 image1=gtk_image_new_from_stock(GTK_STOCK_ADD,GTK_ICON_SIZE_MENU);
 image2=gtk_image_new_from_stock(GTK_STOCK_CLOSE,GTK_ICON_SIZE_MENU);
 image3=gtk_image_new_from_stock(GTK_STOCK_GO_BACK,GTK_ICON_SIZE_BUTTON);
 image4=gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD,GTK_ICON_SIZE_BUTTON);
 image5=gtk_image_new_from_stock(GTK_STOCK_FIND,GTK_ICON_SIZE_BUTTON);
 image6=gtk_image_new_from_stock(GTK_STOCK_HOME,GTK_ICON_SIZE_BUTTON);
 image7=gtk_image_new_from_file("search.jpg");
 image8=gtk_image_new_from_stock(GTK_STOCK_GO_DOWN,GTK_ICON_SIZE_BUTTON);
 image9=gtk_image_new_from_stock(GTK_STOCK_EXECUTE,GTK_ICON_SIZE_BUTTON);
//creates buttons
 button1=gtk_button_new();
 button2=gtk_button_new();
 button3=gtk_button_new();
 button4=gtk_button_new();
 button5=gtk_button_new();
 button6=gtk_button_new();
 button7=gtk_button_new();
 button8=gtk_button_new();
 button9=gtk_button_new();
 but1=gtk_button_new();
 but2=gtk_button_new();
 but3=gtk_button_new();
 but4=gtk_button_new();

//box creation
 box1=gtk_hbox_new(TRUE,0);
 box2=gtk_hbox_new(TRUE,0);
 box3=gtk_hbox_new(TRUE,0);
 box4=gtk_hbox_new(TRUE,0);
 box5=gtk_hbox_new(TRUE,0);
 box6=gtk_hbox_new(TRUE,0);
 box7=gtk_hbox_new(TRUE,0);
 box8=gtk_hbox_new(TRUE,0);
 box9=gtk_hbox_new(TRUE,0);
//the next lines adds the images to the buttons

  gtk_box_pack_start_defaults(GTK_BOX(box1),image1);
  gtk_container_add(GTK_CONTAINER(button1),box1);
  gtk_widget_show_all(button1);

  gtk_box_pack_start_defaults(GTK_BOX(box2),image2);
  gtk_widget_set_size_request(box2,10,10);
  gtk_container_add(GTK_CONTAINER(button2),box2);
  gtk_widget_show_all(button2);

  gtk_box_pack_start_defaults(GTK_BOX(box3),image3);
    gtk_widget_set_size_request(box3,5,5);
  gtk_container_add(GTK_CONTAINER(button3),box3);
  gtk_widget_show_all(button3);

  gtk_box_pack_start_defaults(GTK_BOX(box4),image4);
  gtk_widget_set_size_request(box4,5,5);
  gtk_container_add(GTK_CONTAINER(button4),box4);
  gtk_widget_show_all(button4);

  gtk_box_pack_start_defaults(GTK_BOX(box5),image5);
  gtk_widget_set_size_request(box5,5,5);
  gtk_container_add(GTK_CONTAINER(button5),box5);
  gtk_widget_show_all(button5);

  gtk_box_pack_start_defaults(GTK_BOX(box6),image6);
  gtk_widget_set_size_request(box6,5,5);

  gtk_container_add(GTK_CONTAINER(button6),box6);
  gtk_widget_show_all(button6);

  gtk_box_pack_start_defaults(GTK_BOX(box7),image7);
   gtk_widget_set_size_request(box7,5,2);

  gtk_container_add(GTK_CONTAINER(button7),box7);
  gtk_widget_show_all(button7);

  gtk_box_pack_start_defaults(GTK_BOX(box8),image8);
   gtk_widget_set_size_request(box8,5,5);

  gtk_container_add(GTK_CONTAINER(button8),box8);
  gtk_widget_show_all(button8);
 
  gtk_box_pack_start_defaults(GTK_BOX(box9),image9);
  gtk_widget_set_size_request(box9,5,5);
  gtk_container_add(GTK_CONTAINER(button9),box9);
  gtk_widget_show_all(button9);
//this creats labels to be added in to the hboxes
 label1=gtk_label_new(" ");
 label2=gtk_label_new(" ");
 label3=gtk_label_new("Gospel");
 label4=gtk_label_new("");
 label5=gtk_label_new(" ");
 label6=gtk_label_new("");
 label7=gtk_label_new(" ");
 label8=gtk_label_new(" ");
 label9=gtk_label_new(" ");
 label10=gtk_label_new(" ");
 label11=gtk_label_new(" ");
 lab1=gtk_label_new(" ");
 lab2=gtk_label_new(" ");
 lab3=gtk_label_new(" ");
 lab4=gtk_label_new(" ");



//color addiotion
 gdk_color_parse("#CA29EF",&color1);
 gdk_color_parse("#29EF2F",&color2);
 gdk_color_parse("#2951EF",&color3);
//the function below changes the color of the labels specified
 gtk_widget_modify_fg(label3,GTK_STATE_NORMAL,&color3);
/*creats hboxes abd vboxes to be added to the window*/
 
 hbox1=gtk_hbox_new(FALSE,0);
 hbox2=gtk_hbox_new(FALSE,0);
 hbox3=gtk_hbox_new(FALSE,0);
 hbox4=gtk_hbox_new(FALSE,3);
 hbox5=gtk_hbox_new(TRUE,0);
 hbox6=gtk_hbox_new(TRUE,0);
 hbox7=gtk_hbox_new(TRUE,0);
 hbox8=gtk_hbox_new(TRUE,0);
 hbox9=gtk_hbox_new(TRUE,0);
 hbox10=gtk_hbox_new(FALSE,0);
 hbox11=gtk_hbox_new(TRUE,0);

 
//vertical boxes
 vbox=gtk_vbox_new(FALSE,0);
 vbox1=gtk_vbox_new(TRUE,0);
//creating event boxes
   fbox1=gtk_hbox_new(TRUE,0);
   fbox2=gtk_hbox_new(TRUE,0);
   fbox3=gtk_hbox_new(TRUE,0);
   fbox4=gtk_hbox_new(TRUE,0);
//crating picutres
pict1=gtk_image_new_from_file("joshua.jpg");
pict2=gtk_image_new_from_file("johnson.jpg");
pict3=gtk_image_new_from_file("chris.jpg");
pict4=gtk_image_new_from_file("Duncan.jpg");
//packing the images into the the event boxes
 
 gtk_box_pack_start_defaults(GTK_BOX(fbox1),pict1);
 gtk_widget_set_size_request(fbox1,65,30);
 gtk_container_add(GTK_CONTAINER(but1),fbox1);
   gtk_widget_show_all(but1);
 gtk_box_pack_start_defaults(GTK_BOX(fbox2),pict2);
  gtk_widget_set_size_request(fbox2,65,30);

 gtk_container_add(GTK_CONTAINER(but2),fbox2);
  gtk_widget_show_all(but2);

 gtk_box_pack_start_defaults(GTK_BOX(fbox3),pict3);
  gtk_widget_set_size_request(fbox3,100,30);
 gtk_container_add(GTK_CONTAINER(but3),fbox3);
   gtk_widget_show_all(but3);

 gtk_box_pack_start_defaults(GTK_BOX(fbox4),pict4);
  gtk_widget_set_size_request(fbox4,100,30);
 gtk_container_add(GTK_CONTAINER(but4),fbox4);
    gtk_widget_show_all(but4);

//the following uses box pack function to add buttons to the hboxes

 gtk_box_pack_start_defaults(GTK_BOX(hbox1),button3);
 g_object_set(button3,"relief",GTK_RELIEF_NONE,NULL);
 gtk_box_pack_start_defaults(GTK_BOX(hbox1),button4);
  g_object_set(button4,"relief",GTK_RELIEF_NONE,NULL);
 gtk_box_pack_start_defaults(GTK_BOX(hbox1),entry1);
 gtk_box_pack_start_defaults(GTK_BOX(hbox1),button5);
  g_object_set(button5,"relief",GTK_RELIEF_NONE,NULL);
  g_signal_connect(GTK_OBJECT(button5),"clicked",G_CALLBACK(button_clicked),"button5");
 gtk_box_pack_start_defaults(GTK_BOX(hbox1),entry2);
 gtk_box_pack_start_defaults(GTK_BOX(hbox1),button6);
  g_object_set(button6,"relief",GTK_RELIEF_NONE,NULL);
   gtk_box_pack_start_defaults(GTK_BOX(hbox1),button9);
  g_object_set(button9,"relief",GTK_RELIEF_NONE,NULL);
 g_signal_connect(GTK_OBJECT(button9),"clicked",GTK_SIGNAL_FUNC(upload_logo),"men_of_God");
 gtk_box_pack_start_defaults(GTK_BOX(hbox1),button8);
 g_object_set(button8,"relief",GTK_RELIEF_NONE,NULL);
  g_signal_connect(GTK_OBJECT(button8),"clicked",GTK_SIGNAL_FUNC(file_chooser),"download");


 gtk_widget_set_size_request(hbox1,800,1);

 gtk_box_pack_start_defaults(GTK_BOX(vbox),hbox1);


  gtk_box_pack_start_defaults(GTK_BOX(hbox9),label11);
 gtk_box_pack_start_defaults(GTK_BOX(vbox),hbox9);

 gtk_box_pack_start_defaults(GTK_BOX(hbox2),label4);
 gtk_box_pack_start_defaults(GTK_BOX(hbox2),picture1);
 gtk_box_pack_start_defaults(GTK_BOX(hbox2),label5);

  
 gtk_box_pack_start_defaults(GTK_BOX(vbox),hbox2);

 gtk_box_pack_start_defaults(GTK_BOX(hbox3),label1);
 gtk_box_pack_start_defaults(GTK_BOX(hbox3),picture2);
 gtk_box_pack_start_defaults(GTK_BOX(hbox3),entry3);
 gtk_box_pack_start_defaults(GTK_BOX(hbox3),button7);
 gtk_box_pack_start_defaults(GTK_BOX(hbox3),label2);
 gtk_box_pack_start_defaults(GTK_BOX(hbox3),label8);
 
 gtk_widget_set_size_request(button7,10,3);
 gtk_widget_set_size_request(hbox3,100,20); 
  g_object_set(button7,"relief",GTK_RELIEF_NONE,NULL);
   g_signal_connect(GTK_OBJECT(button7),"clicked",GTK_SIGNAL_FUNC(button_clicked),"button7");
 gtk_widget_set_size_request(hbox4,100,10);

 gtk_box_pack_start_defaults(GTK_BOX(vbox),hbox3);

 gtk_box_pack_start_defaults(GTK_BOX(hbox4),lab1);
 gtk_box_pack_start_defaults(GTK_BOX(hbox4),lab3);
 gtk_box_pack_start_defaults(GTK_BOX(hbox4),but1);
 g_object_set(but1,"relief",GTK_RELIEF_NONE,NULL);
 g_signal_connect(GTK_OBJECT(but1),"clicked",G_CALLBACK(generals_func),"Joshua");
 gtk_box_pack_start_defaults(GTK_BOX(hbox4),but2);
   g_object_set(but2,"relief",GTK_RELIEF_NONE,NULL);
 g_signal_connect(GTK_OBJECT(but2),"clicked",G_CALLBACK(generals_func),"Johnson");
 gtk_box_pack_start_defaults(GTK_BOX(hbox4),but3);
    g_object_set(but3,"relief",GTK_RELIEF_NONE,NULL);
 g_signal_connect(GTK_OBJECT(but3),"clicked",G_CALLBACK(generals_func),"Chris");
 gtk_box_pack_start_defaults(GTK_BOX(hbox4),but4);
       g_object_set(but4,"relief",GTK_RELIEF_NONE,NULL);
 g_signal_connect(GTK_OBJECT(but4),"clicked",G_CALLBACK(generals_func),"Duncan");
 gtk_box_pack_start_defaults(GTK_BOX(hbox4),lab2);
 gtk_box_pack_start_defaults(GTK_BOX(hbox4),lab4);
 
 gtk_widget_set_size_request(hbox4,100,150);
gtk_box_pack_start_defaults(GTK_BOX(vbox),hbox4);
//the following creats a notebook
 notebook=gtk_notebook_new();
 
           gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook),TRUE);
           gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook),GTK_POS_TOP);

             gtk_box_pack_start_defaults(GTK_BOX(hbox10),button2);
             g_object_set(button2,"relief",GTK_RELIEF_NONE,NULL);
                          

             gtk_box_pack_start_defaults(GTK_BOX(hbox10),label3);

             gtk_box_pack_start_defaults(GTK_BOX(hbox10),button1);
             g_object_set(button1,"relief",GTK_RELIEF_NONE,NULL);
            
               gtk_widget_show_all(hbox10);
           gtk_widget_set_size_request(hbox10,150,35);
             gtk_notebook_append_page(GTK_NOTEBOOK(notebook),vbox,hbox10);
            g_signal_connect(GTK_OBJECT(button1),"clicked",G_CALLBACK(switch_page),(gpointer)notebook);
            g_signal_connect(GTK_OBJECT(button2),"clicked",G_CALLBACK(CloseApp),(gpointer)notebook);
            

      
 gtk_rc_parse("gosple.gtkrc");

//changes the sizes of some widgets
 gtk_widget_set_size_request(entry1,750,27);
 gtk_widget_set_size_request(button3,20,10);
 gtk_widget_set_size_request(button4,20,10);
 gtk_widget_set_size_request(button5,20,10);
 gtk_widget_set_size_request(button6,20,10);
  gtk_widget_set_size_request(button8,20,10);
 gtk_widget_set_size_request(entry3,400,27);
 gtk_widget_set_size_request(entry2,200,27);

 
//adds the notebook to a contiainer
gtk_container_add(GTK_CONTAINER(window),notebook);

gtk_widget_show_all(window);
 gtk_main();
return 0;
}
