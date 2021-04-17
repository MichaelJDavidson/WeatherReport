#include "Processor.h"
#include <gtk/gtk.h>


int main(int argc,char **argv){

	//App starts here and creates an instance of Network 
  //and creates a connection to API and Call the getRequest
  //Creates User Interface to display processed data
  Network();
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
  
  return status;    
  printf("%lu", weatherReport.feels_like);
}
