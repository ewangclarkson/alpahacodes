#ifndef GOSPLE_H
#define GOSPEL_H

#include"gosfunc.c"
static void home_page(GtkWidget*window,GtkNotebook*notebook);
void CloseApp(GtkWidget*window,gpointer data);
void switch_page(GtkWidget*widget,GtkNotebook*tab);
extern void closetab(GtkWidget*widget,GtkNotebook*tab);
extern void event_button_press(GtkWidget*button,GdkEventButton*eventbox,GtkLabel*label);
void Close_Window(GtkWidget*window,gpointer data);
extern void button_clicked(GtkWidget*button,gpointer data);
static void generals_func(GtkWidget*widget,gpointer name);
void upload_logo(GtkWidget*widget,gpointer data); 
void internet_connection(GtkWidget*connect,gpointer message); 
void file_chooser(GtkWidget*widget,gpointer chooser);
void Quit_App(GtkWidget*window,gpointer close);
#endif
