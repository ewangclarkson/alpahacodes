
int control=1,track=0;
GtkWidget*dialog,*Qdialog;
GtkWidget*entry,*window,*notebook;
GtkWidget*window,*entry1,*entry2,*entry3;
GtkWidget*enter,*ent,*entry,*button2,*hbox10;
GtkNotebook*track_book[10000];
GtkWidget*track_but[10000];

 void Close_Window(GtkWidget*window,gpointer data)
     {
       gtk_main_quit();
     }

void Quit_App(GtkWidget*window,gpointer close)
   {
     char*message=(char*)close;
     
        gtk_widget_destroy(Qdialog);
     if(strcmp(close,"closetabs")==0)
       {
        gtk_main_quit();
       }
   }

void CloseApp(GtkWidget*window,gpointer data)
 {
   GtkWidget*label,*image,*image1,*image2,*button1,*button2,*hbox,*hbox1;
   GtkWidget*fbox1,*fbox2,*label1,*label2;
   GdkColor color;
    char confirm[120];
       Qdialog=gtk_dialog_new();
          gtk_window_set_title(GTK_WINDOW(Qdialog),"Confirm quit");
          gtk_window_set_modal(GTK_WINDOW(Qdialog),GTK_DIALOG_MODAL);
             if(control<=1)         
                sprintf(confirm,"You are about to quit the program\nAre you sure you want to do this?\0");
             else
                sprintf(confirm,"You are about to close %d tabs\nAre you sure you want to do this?\0",control);
          
        //this stores a desired color from memory into the color variable  color  
          gdk_color_parse("#2951EF",&color); 
          label=gtk_label_new(confirm);
          label1=gtk_label_new("CloseTabs");
          label2=gtk_label_new("Cancel");
        //the following function changes the color of the different labels into blue
          gtk_widget_modify_fg(label,GTK_STATE_NORMAL,&color);
          gtk_widget_modify_fg(label1,GTK_STATE_NORMAL,&color);
          gtk_widget_modify_fg(label2,GTK_STATE_NORMAL,&color);

          //creation of hboxes  
          hbox=gtk_hbox_new(FALSE,0);
          hbox1=gtk_hbox_new(FALSE,0);
           //imports image from stock
          image=gtk_image_new_from_stock(GTK_STOCK_DIALOG_QUESTION,GTK_ICON_SIZE_DIALOG);
           gtk_box_pack_start(GTK_BOX(hbox),image,TRUE,TRUE,0);
           gtk_box_pack_start(GTK_BOX(hbox),label,TRUE,TRUE,0);

          //creatioon of buttons nto pack the hboxes into
             button1=gtk_button_new();
             button2=gtk_button_new();
        //creating hboxes for the yes or no buttons
          image1=gtk_image_new_from_stock(GTK_STOCK_CLOSE,GTK_ICON_SIZE_DIALOG);
          image2=gtk_image_new_from_stock(GTK_STOCK_OK,GTK_ICON_SIZE_DIALOG);
       //packing the images into created hboxes
           fbox1=gtk_hbox_new(TRUE,0);
           fbox2=gtk_hbox_new(TRUE,0);
        
  
          gtk_box_pack_start(GTK_BOX(fbox1),image1,TRUE,TRUE,0);
          gtk_box_pack_start(GTK_BOX(fbox1),label2,TRUE,TRUE,0);


          gtk_container_add(GTK_CONTAINER(button1),fbox1);
          gtk_widget_show_all(button1);

        gtk_box_pack_start(GTK_BOX(fbox2),image2,TRUE,TRUE,0);
          gtk_box_pack_start(GTK_BOX(fbox2),label1,TRUE,TRUE,0);
       

          gtk_container_add(GTK_CONTAINER(button2),fbox2);
          gtk_widget_show_all(button2);
        
      //ihj
          gtk_box_pack_end(GTK_BOX(hbox1),button1,TRUE,TRUE,0);
          g_signal_connect(GTK_OBJECT(button1),"clicked",GTK_SIGNAL_FUNC(Quit_App),"cancel");
         g_object_set(button1,"relief",GTK_RELIEF_NONE,NULL);
          gtk_box_pack_end(GTK_BOX(hbox1),button2,TRUE,TRUE,0);
         g_signal_connect(GTK_OBJECT(button2),"clicked",G_CALLBACK(Quit_App),"closetabs");
        g_object_set(button2,"relief",GTK_RELIEF_NONE,NULL);

        
       //adding the containers into the dialog
        gtk_box_pack_start_defaults(GTK_BOX(GTK_DIALOG(Qdialog)->vbox),hbox);
        gtk_box_pack_start_defaults(GTK_BOX(GTK_DIALOG(Qdialog)->vbox),hbox1);
      
        gtk_widget_show_all(Qdialog);
 
    }


extern void closetab(GtkWidget*widget,GtkNotebook*tab)
 {
   gint pos=0,j=0,i=0,current_pos,new_pos;
    pos=gtk_notebook_get_current_page(tab);
         
        if(control<=2)
            {
              gtk_widget_show_all(hbox10);
              gtk_notebook_remove_page(tab,pos);
               gtk_notebook_set_current_page(tab,pos-1);
             control--;
             }  
        else{
           for(j=0;j<track;)
            {
             if(track_but[j]==widget)
                {
                 gtk_notebook_remove_page(track_book[j],j);
                 control--;
                 if((current_pos=gtk_notebook_get_current_page(tab))<(control-1)){
                      gtk_notebook_set_current_page(tab,current_pos);
                      }
                  else
                    gtk_notebook_prev_page(tab);
                  break;
                }
                j++;
             }
            for(i=j;i<track;)
             {
              track_but[i]=track_but[i+1];
              i++;
             }
            track--;
        }
 } 

 //signal handling function
extern void button_clicked(GtkWidget*button,gpointer data)
 {
  const char*ch=(const char*)data;
  char*cmd;
     if(strcmp(ch,"OK")==0)
     {
      cmd=(char*)gtk_entry_get_text(GTK_ENTRY(entry));
      system(" iceweasel *cmd");
     }
    return ;
}

//this function connects to the internet
  void internet_connection(GtkWidget*connect,gpointer message)
   {
    gtk_widget_destroy(dialog);
   }
  
//the function home takes the user to the homepage


static void home_page(GtkWidget*window,GtkNotebook*notebook)
  {
    int i;

     gtk_notebook_set_current_page(notebook,control-1);
     
      for(i=control-2;i>=0;i--)
       {
        gtk_notebook_set_current_page(notebook,i);
        gtk_notebook_remove_page(notebook,i);
       }
        gtk_widget_show_all(hbox10);
    control=1;
   }

extern void event_button_press(GtkWidget*button,GdkEventButton*eventbox,GtkLabel*label)
     {
      
       if(eventbox->type==GDK_BUTTON_PRESS)
         {
           char*text=(char*)gtk_label_get_text(label);
            if(strcmp(text,"Go")==0){
              gtk_label_set_text(label,"Go..");
             }
            else 
              {
               gtk_label_set_text(label,"Go");
              }
         }
    }

//recieve signals from the generals signaling functions
 static void generals_func(GtkWidget*widget,gpointer name)
   {
    char*search=(char*)name;
         if(strcmp(search,"Joshua")==0)
           {
            ;
           }
         else if(strcmp(search,"Johnson")==0)
           {
            ;
           }
         else if(strcmp(search,"Chris")==0)
           {
            ;
           }
        else if(strcmp(search,"Duncan")==0)
           {
            ;
           }
    }

//definition of the upload_logos

 void upload_logo(GtkWidget*widget,gpointer data)
    {
     GtkWidget*table,*but1,*but2,*but3,*but4,*but5,*but6;
     GtkWidget*image1,*image2,*image3,*image4,*image5,*image6;
     GtkWidget*box1,*box2,*box3,*box4,*box5,*box6;
      int result;
          
       //the followings line of code creats a dialog box
           dialog=gtk_dialog_new();
        //sets a title for the dialog
            gtk_window_set_title(GTK_WINDOW(dialog),"OPTIONS!");
            gtk_container_set_border_width(GTK_CONTAINER(dialog),10);
         //sets iamges from file
         image1=gtk_image_new_from_file("TB.jpg");
         image2=gtk_image_new_from_file("Iyakilome.jpg");
         image3=gtk_image_new_from_file("William.jpg");
         image4=gtk_image_new_from_file("Sulemane.jpg");
         image5=gtk_image_new_from_file("facebook.jpg");
         image6=gtk_image_new_from_file("twitter.jpg");
       //hboxes creations
         box1=gtk_hbox_new(TRUE,0);
         box2=gtk_hbox_new(TRUE,0);
         box3=gtk_hbox_new(TRUE,0);
         box4=gtk_hbox_new(TRUE,0);
         box5=gtk_hbox_new(TRUE,0);
         box6=gtk_hbox_new(TRUE,0);

       //buttons
        but1=gtk_button_new();
        but2=gtk_button_new();
        but3=gtk_button_new();
        but4=gtk_button_new();
        but5=gtk_button_new();
        but6=gtk_button_new();
      //add close button to dialog
         gtk_dialog_add_button(GTK_DIALOG(dialog),GTK_STOCK_CLOSE,GTK_RESPONSE_CLOSE);
     //packing the images into containers
        gtk_box_pack_start_defaults(GTK_BOX(box1),image1);
        gtk_container_add(GTK_CONTAINER(but1),box1);
         gtk_widget_show_all(but1);

        gtk_box_pack_start_defaults(GTK_BOX(box2),image2);
         gtk_container_add(GTK_CONTAINER(but2),box2);
         gtk_widget_show_all(but2);

        gtk_box_pack_start_defaults(GTK_BOX(box3),image3);
         gtk_container_add(GTK_CONTAINER(but3),box3);
         gtk_widget_show_all(but3);

        gtk_box_pack_start_defaults(GTK_BOX(box4),image4);
          gtk_container_add(GTK_CONTAINER(but4),box4);
          gtk_widget_show_all(but4);

        gtk_box_pack_start_defaults(GTK_BOX(box5),image5);
          gtk_container_add(GTK_CONTAINER(but5),box5);
          gtk_widget_show_all(but5);

        gtk_box_pack_start_defaults(GTK_BOX(box6),image6);
          gtk_container_add(GTK_CONTAINER(but6),box6);
          gtk_widget_show_all(but6);
 
     //creation of table
      table=gtk_table_new(4,4,FALSE);

  /****************************************************************************
  *       the following packs the buttons into tables                        *
  ****************************************************************************/      
        gtk_table_attach(GTK_TABLE(table),but1,1,2,1,2,GTK_EXPAND,GTK_SHRINK,0,0);
          g_object_set(but1,"relief",GTK_RELIEF_NONE,NULL);
       g_signal_connect(GTK_OBJECT(but1),"clicked",GTK_SIGNAL_FUNC(internet_connection),"joshua");

        gtk_table_attach(GTK_TABLE(table),but2,2,3,1,2,GTK_EXPAND,GTK_SHRINK,0,0);
          g_object_set(but2,"relief",GTK_RELIEF_NONE,NULL);
         g_signal_connect(GTK_OBJECT(but2),"clicked",GTK_SIGNAL_FUNC(internet_connection),"chris");

        gtk_table_attach(GTK_TABLE(table),but3,3,4,1,2,GTK_EXPAND,GTK_SHRINK,0,0);
          g_object_set(but3,"relief",GTK_RELIEF_NONE,NULL);
          g_signal_connect(GTK_OBJECT(but3),"clicked",GTK_SIGNAL_FUNC(internet_connection),"Duncan");

        gtk_table_attach(GTK_TABLE(table),but4,1,2,2,3,GTK_EXPAND,GTK_SHRINK,0,0);
          g_object_set(but4,"relief",GTK_RELIEF_NONE,NULL);
         g_signal_connect(GTK_OBJECT(but4),"clicked",GTK_SIGNAL_FUNC(internet_connection),"johnson");

        gtk_table_attach(GTK_TABLE(table),but5,2,3,2,3,GTK_EXPAND,GTK_SHRINK,0,0);
          g_object_set(but5,"relief",GTK_RELIEF_NONE,NULL);
          g_signal_connect(GTK_OBJECT(but5),"clicked",GTK_SIGNAL_FUNC(internet_connection),"facebook");

        gtk_table_attach(GTK_TABLE(table),but6,3,4,2,3,GTK_EXPAND,GTK_SHRINK,0,0);
          g_object_set(but6,"relief",GTK_RELIEF_NONE,NULL);
           g_signal_connect(GTK_OBJECT(but6),"clicked",GTK_SIGNAL_FUNC(internet_connection),"twitter");
           
   //sets spacings between rows and columns
     gtk_table_set_row_spacings(GTK_TABLE(table),0);
     gtk_table_set_col_spacings(GTK_TABLE(table),0);

     gtk_widget_show_all(table);
    gtk_box_pack_start_defaults(GTK_BOX(GTK_DIALOG(dialog)->vbox),table);

     result=gtk_dialog_run(GTK_DIALOG(dialog));
     if(result==GTK_RESPONSE_CLOSE)
         gtk_widget_destroy(dialog);

  }
   
  //opens the file chooser to view downloads
 void file_chooser(GtkWidget*widget,gpointer chooser)
     {

       GtkWidget*filechooser;
     
         filechooser=gtk_file_chooser_dialog_new("Dowloads",NULL,GTK_FILE_CHOOSER_ACTION_OPEN,GTK_STOCK_CLOSE,GTK_RESPONSE_CLOSE,NULL);
               gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(filechooser),"/home/ewang/Downloads");


              gtk_dialog_run(GTK_DIALOG(filechooser));

             gtk_widget_destroy(filechooser);
     }

 //this function opens a downlooad dialog to show all downloads
      
//the followingc closes the application
 void switch_page(GtkWidget*widget,GtkNotebook*tab)
 {
   
    GtkWidget*hbox,*label,*vbox,*button,*vbox1,*hbox1,*lab,*label1,*label2,*label3,*label7,*label8,*label9,*label10;
    GtkWidget*label4,*label5,*search,*image,*label6,*pictlogo,*label12;
    GtkWidget*image1,*image2,*image3,*image4,*image5,*image6;
    GtkWidget*but1,*but2,*but3,*but4,*but5,*but6;
    GtkWidget*box1,*box2,*box3,*box4,*box5,*box6,*hbox2,*picture,*boxh,*picture1,*hbox3,*newtab;
    GtkWidget*pict1,*pict2,*pict3,*pict4,*pict5,*lab1,*lab2;
    GtkWidget*fbox1,*fbox2,*fbox3,*fbox4,*fbox5,*settingbut,*img,*imgbox;
    GdkColor color1,color2;
    GtkWidget*button1,*buttone2,*button3,*button4,*button5,*hbox4;
      int pos;
       
       gint tab_pos=0;
       //creating images to add to button
       image2=gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD,GTK_ICON_SIZE_BUTTON);
       image3=gtk_image_new_from_stock(GTK_STOCK_FIND,GTK_ICON_SIZE_BUTTON);
       image4=gtk_image_new_from_stock(GTK_STOCK_HOME,GTK_ICON_SIZE_BUTTON);
       image5=gtk_image_new_from_stock(GTK_STOCK_GO_BACK,GTK_ICON_SIZE_BUTTON);
       image6=gtk_image_new_from_stock(GTK_STOCK_GO_DOWN,GTK_ICON_SIZE_BUTTON);
       img=gtk_image_new_from_stock(GTK_STOCK_EXECUTE,GTK_ICON_SIZE_BUTTON);
    //creating buttons for to pack images inside
      but1=gtk_button_new();
      but2=gtk_button_new();
      but3=gtk_button_new();
      but4=gtk_button_new();
      but5=gtk_button_new();
     search=gtk_button_new();
     settingbut=gtk_button_new();
     button1=gtk_button_new();
     buttone2=gtk_button_new();
     button3=gtk_button_new();
     button4=gtk_button_new();
     button5=gtk_button_new();
   //creating label
       lab1=gtk_label_new("");
       lab2=gtk_label_new("");
       label1=gtk_label_new("");
       label2=gtk_label_new("  ");
       label3=gtk_label_new("  ");
       label4=gtk_label_new("  ");
       label5=gtk_label_new(" ");
       label6=gtk_label_new(" ");
       label7=gtk_label_new(" ");
       label8=gtk_label_new(" ");
       label9=gtk_label_new(" ");
       label10=gtk_label_new("");
       label12=gtk_label_new(" ");
       newtab=gtk_label_new("New Tab");
   //creats entry boxes for text inputing
        ent=gtk_entry_new();
        enter=gtk_entry_new();
        entry=gtk_entry_new();
  //pictures from file
     picture=gtk_image_new_from_file("ego.jpg");
     image1=gtk_image_new_from_file("go.jpg");
      boxh=gtk_hbox_new(TRUE,0);
      gtk_box_pack_start_defaults(GTK_BOX(boxh),image1);
      gtk_container_add(GTK_CONTAINER(search),boxh);
//setting entry boxes with text
       gtk_entry_set_text(GTK_ENTRY(ent),"http//:");
         gtk_entry_set_text(GTK_ENTRY(enter),"search:");
        gtk_entry_set_text(GTK_ENTRY(entry),"www.emmanuelTv.com");

         image=gtk_image_new_from_stock(GTK_STOCK_CLOSE,GTK_ICON_SIZE_MENU);
         button=gtk_button_new();
         g_object_set(button,"relief",GTK_RELIEF_NONE,NULL);
         //creats color buttons
        gdk_color_parse("#29EF2F",&color1);
        gdk_color_parse("#2951EF",&color2);

        gtk_widget_modify_bg(search,GTK_STATE_NORMAL,&color2);
        gtk_widget_modify_fg(label6,GTK_STATE_NORMAL,&color2);
        gtk_widget_modify_fg(newtab,GTK_STATE_NORMAL,&color2);     
   //creating boxes to enter the images
        box1=gtk_hbox_new(TRUE,0);
        box2=gtk_hbox_new(TRUE,0);
        box3=gtk_hbox_new(TRUE,0);
        box4=gtk_hbox_new(TRUE,0);
        box5=gtk_hbox_new(TRUE,0);
        box6=gtk_hbox_new(TRUE,0);
       imgbox=gtk_hbox_new(TRUE,0);
  //this packs the images in to the boxes
    gtk_box_pack_start_defaults(GTK_BOX(box1),image2);
    gtk_container_add(GTK_CONTAINER(but1),box1);
    gtk_widget_show_all(but1);

    gtk_box_pack_start_defaults(GTK_BOX(box2),image3);
    gtk_container_add(GTK_CONTAINER(but2),box2);
     gtk_widget_show_all(but2);

   gtk_box_pack_start_defaults(GTK_BOX(box3),image4);
   gtk_container_add(GTK_CONTAINER(but3),box3);
   gtk_widget_show_all(but3);
   
   gtk_box_pack_start_defaults(GTK_BOX(box4),image5);
   gtk_container_add(GTK_CONTAINER(but4),box4);
   gtk_widget_show_all(but4);
  
   gtk_box_pack_start_defaults(GTK_BOX(box5),image6);
   gtk_container_add(GTK_CONTAINER(but5),box5);
   gtk_widget_show_all(but5);
//hboxes
         hbox=gtk_hbox_new(FALSE,0);
         hbox1=gtk_hbox_new(FALSE,0);
         hbox2=gtk_hbox_new(FALSE,0);
         hbox3=gtk_hbox_new(TRUE,0);
         hbox4=gtk_hbox_new(TRUE,0);
 //packing widgets into hboxes
         gtk_box_pack_start_defaults(GTK_BOX(box6),image);
         gtk_container_add(GTK_CONTAINER(button),box6);
          gtk_widget_show_all(button);
                  gtk_box_pack_start_defaults(GTK_BOX(imgbox),img);
        gtk_container_add(GTK_CONTAINER(settingbut),imgbox);
        gtk_widget_show_all(settingbut);
//the lines below creats vboxes
         vbox=gtk_vbox_new(TRUE,0);
         vbox1=gtk_vbox_new(FALSE,0);
  
  //creating event boxes
   fbox1=gtk_hbox_new(TRUE,0);
   fbox2=gtk_hbox_new(TRUE,0);
   fbox3=gtk_hbox_new(TRUE,0);
   fbox4=gtk_hbox_new(TRUE,0);
   fbox5=gtk_hbox_new(TRUE,0);
 //loading pictures 
  pict1=gtk_image_new_from_file("google.jpg");
  pict2=gtk_image_new_from_file("yahoo.jpg");
  pict3=gtk_image_new_from_file("twitter.jpg");
  pict4=gtk_image_new_from_file("facebook.jpg");
  pict5=gtk_image_new_from_file("youtube.jpg");
  pictlogo=gtk_image_new_from_file("logo.jpg");
//packing the images into event boxes
  gtk_box_pack_start_defaults(GTK_BOX(fbox1),pict1);
  gtk_container_add(GTK_CONTAINER(button1),fbox1);
   gtk_widget_show_all(button1);
 
 gtk_box_pack_start_defaults(GTK_BOX(fbox2),pict2);
  gtk_container_add(GTK_CONTAINER(buttone2),fbox2);
   gtk_widget_show_all(button2);
  
 gtk_box_pack_start_defaults(GTK_BOX(fbox3),pict3);
  gtk_container_add(GTK_CONTAINER(button3),fbox3);
  gtk_widget_show_all(button3);
 
gtk_box_pack_start_defaults(GTK_BOX(fbox4),pict4);
  gtk_container_add(GTK_CONTAINER(button4),fbox4);
 gtk_widget_show_all(button4);

 gtk_box_pack_start_defaults(GTK_BOX(fbox5),pict5);
  gtk_container_add(GTK_CONTAINER(button5),fbox5);
 gtk_widget_show_all(button5);

//box packing
   gtk_box_pack_start(GTK_BOX(hbox),newtab,TRUE,TRUE,0);
   gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,0);
    g_signal_connect(GTK_OBJECT(button),"clicked",G_CALLBACK(closetab),(gpointer)tab);
    gtk_widget_set_size_request(hbox,150,50);
   gtk_box_pack_start_defaults(GTK_BOX(vbox),hbox);
   gtk_widget_show_all(vbox);
   
   gtk_widget_set_size_request(vbox,150,10);

   gtk_box_pack_start_defaults(GTK_BOX(hbox1),but4);
   g_object_set(but4,"relief",GTK_RELIEF_NONE,NULL);
   gtk_box_pack_start_defaults(GTK_BOX(hbox1),but1);
   g_object_set(but1,"relief",GTK_RELIEF_NONE,NULL);     
   gtk_box_pack_start(GTK_BOX(hbox1),ent,TRUE,TRUE,3);
   gtk_box_pack_start(GTK_BOX(hbox1),but2,TRUE,TRUE,0);
   g_object_set(but2,"relief",GTK_RELIEF_NONE,NULL);
      g_signal_connect(GTK_OBJECT(but2),"clicked",G_CALLBACK(event_button_press),(gpointer)search);
   gtk_box_pack_start(GTK_BOX(hbox1),enter,TRUE,TRUE,0);
   gtk_box_pack_start_defaults(GTK_BOX(hbox1),but3);
    g_object_set(but3,"relief",GTK_RELIEF_NONE,NULL);
    g_signal_connect(GTK_OBJECT(but3),"clicked",GTK_SIGNAL_FUNC(home_page),(gpointer)tab);
     gtk_box_pack_start_defaults(GTK_BOX(hbox1),settingbut);
    g_object_set(settingbut,"relief",GTK_RELIEF_NONE,NULL);
    g_signal_connect(GTK_OBJECT(settingbut),"clicked",GTK_SIGNAL_FUNC(upload_logo),"seetingbut");

  gtk_box_pack_start_defaults(GTK_BOX(hbox1),but5);
   g_object_set(but5,"relief",GTK_RELIEF_NONE,NULL);
 g_signal_connect(GTK_OBJECT(but5),"clicked",G_CALLBACK(file_chooser),"but5");
   gtk_widget_set_size_request(hbox1,100,20);
   gtk_box_pack_start_defaults(GTK_BOX(vbox1),hbox1);
  

   gtk_container_add(GTK_CONTAINER(vbox1),hbox4);

   gtk_box_pack_start_defaults(GTK_BOX(hbox2),label6);
   gtk_box_pack_start_defaults(GTK_BOX(hbox2),picture);
   gtk_box_pack_start_defaults(GTK_BOX(hbox2),entry);
   gtk_box_pack_start_defaults(GTK_BOX(hbox2),search);
   gtk_box_pack_start_defaults(GTK_BOX(hbox2),label12);
   g_signal_connect(GTK_OBJECT(search),"clicked",G_CALLBACK(event_button_press),"search");
   gtk_box_pack_start_defaults(GTK_BOX(hbox2),label2);
   gtk_container_add(GTK_CONTAINER(vbox1),hbox2);

  gtk_box_pack_start_defaults(GTK_BOX(hbox3),lab1);
  gtk_box_pack_start_defaults(GTK_BOX(hbox3),label1);
  gtk_box_pack_start_defaults(GTK_BOX(hbox3),button1);
   g_object_set(button1,"relief",GTK_RELIEF_NONE,NULL);
   g_signal_connect(GTK_OBJECT(button1),"clicked",G_CALLBACK(generals_func),"google");
  gtk_box_pack_start_defaults(GTK_BOX(hbox3),buttone2);
   g_object_set(buttone2,"relief",GTK_RELIEF_NONE,NULL);
   g_signal_connect(GTK_OBJECT(buttone2),"clicked",G_CALLBACK(generals_func),"yahoo");
  gtk_box_pack_start_defaults(GTK_BOX(hbox3),button5);
   g_object_set(button5,"relief",GTK_RELIEF_NONE,NULL);
   g_signal_connect(GTK_OBJECT(button5),"clicked",G_CALLBACK(generals_func),"youtube");
  gtk_box_pack_start_defaults(GTK_BOX(hbox3),button3);
   g_object_set(button3,"relief",GTK_RELIEF_NONE,NULL);
   g_signal_connect(GTK_OBJECT(button3),"clicked",G_CALLBACK(generals_func),"twitter");
  gtk_box_pack_start_defaults(GTK_BOX(hbox3),button4);
   g_object_set(button4,"relief",GTK_RELIEF_NONE,NULL);
   g_signal_connect(GTK_OBJECT(button4),"clicked",G_CALLBACK(generals_func),"facebook");
  gtk_box_pack_start_defaults(GTK_BOX(hbox3),label10);
  gtk_box_pack_start_defaults(GTK_BOX(hbox3),lab2);

  gtk_box_pack_start_defaults(GTK_BOX(vbox1),hbox3);
  
  gtk_box_pack_start(GTK_BOX(hbox4),pictlogo,TRUE,TRUE,0);
  gtk_widget_set_size_request(hbox4,900,50);
  gtk_widget_show_all(hbox4);

   gtk_container_add(GTK_CONTAINER(vbox1),label3);
   gtk_container_add(GTK_CONTAINER(vbox1),label4);
   gtk_container_add(GTK_CONTAINER(vbox1),label5);
   gtk_container_add(GTK_CONTAINER(vbox1),label7);
   gtk_container_add(GTK_CONTAINER(vbox1),label8);
   gtk_container_add(GTK_CONTAINER(vbox1),label9);
 
       gtk_widget_show_all(vbox1);

  //resizes the widgets
        
         gtk_widget_set_size_request(ent,800,27);
         gtk_widget_set_size_request(enter,200,27);
         gtk_widget_set_size_request(search,0,0);
         gtk_widget_set_size_request(entry,300,27);
         gtk_widget_set_size_request(hbox2,900,1);
         gtk_widget_set_size_request(hbox3,500,100);
         gtk_widget_set_size_request(hbox1,900,0);
  
      
            gtk_notebook_insert_page(tab,vbox1,vbox,control-1);
            gtk_notebook_set_current_page(tab,control-1);

          gtk_widget_hide_all(button2);
         
         track_but[track]=button;
         track_book[track]=tab;
            control++;track++;
}


