#include "Processor.h"
#include <gtk/gtk.h>


int main(int argc,char **argv){

	//App starts here and creates an instance of Network 
  //and creates a connection to API and Call the getRequest
  //Creates User Interface to display processed data
  Network();

  gtk_init(&argc, &argv);

  GtkWidget *window;//W (800 x 480)

  


  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Weather Report");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 480);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);



  
  gtk_widget_show(window);
  gtk_main();

  return 0;


    
}
