#include <gtk/gtk.h>
#include "Processor.h"

void activate(GtkApplication* app, gpointer user_data) {


//Set up UI components 
  GtkWidget *window;// Window

  GtkWidget *mainFrame; // mainframe to hold navi and data frames in horoz view 
  GtkWidget *naviFrame; // holds a label and selectable city views in a vertical view
  GtkWidget *dataFrame; // holds labels and displayables in grid view

  GtkWidget *scrollableFrame;

  GtkWidget *naviTitle;
  GtkWidget *currentTempTitle;
  GtkWidget *feels_likeTitle;
  GtkWidget *tempMinTitle;
  GtkWidget *tempMaxTitle;
  GtkWidget *pressureTitle;
  GtkWidget *humidityTitle;
  GtkWidget *windspdTitle;
  GtkWidget *windirTitle;

  GtkWidget *currentTempValue;
  GtkWidget *feels_likeValue;
  GtkWidget *tempMinValue;
  GtkWidget *tempMaxValue;
  GtkWidget *pressureValue;
  GtkWidget *humidityValue;
  GtkWidget *windspdValue;
  GtkWidget *windirValue;

  


 /// selectable View of cities avail from database

  //labels

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Weather Reports");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 480);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);

  ///All the code for UI below
  mainFrame = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5); // mainFrame obj filled


/*=========================Navigation Section================================*/

  naviFrame = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5); // naviFrame obj filled

  naviTitle = gtk_label_new("Navigations");
  gtk_label_set_use_markup((GtkLabel *)naviTitle, TRUE);
  gtk_label_set_line_wrap((GtkLabel *)naviTitle, FALSE);
  gtk_box_pack_start(GTK_BOX(naviFrame), naviTitle, TRUE, TRUE, 0);
  gtk_widget_show(naviTitle);

  scrollableFrame = gtk_scrolled_window_new(NULL, NULL);
  gtk_box_pack_end(GTK_BOX(naviFrame), scrollableFrame, TRUE, TRUE, 0);
  gtk_widget_show(scrollableFrame);




/*==========================Data Section===============================*/
  dataFrame = gtk_grid_new();
  gtk_grid_set_row_spacing (GTK_GRID (dataFrame), 3);
  gtk_grid_set_column_homogeneous (GTK_GRID (dataFrame), TRUE);
  gtk_grid_set_row_homogeneous (GTK_GRID (dataFrame), TRUE);


  currentTempTitle = gtk_label_new("Current T˚C: ");
  gtk_label_set_use_markup((GtkLabel *)currentTempTitle, TRUE);
  gtk_label_set_line_wrap((GtkLabel *)currentTempTitle, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame),currentTempTitle, 0,0,1,1);
  gtk_widget_show(currentTempTitle);

  feels_likeTitle = gtk_label_new("Feels Like: ");
  gtk_label_set_use_markup((GtkLabel *)feels_likeTitle, TRUE);
  gtk_label_set_line_wrap((GtkLabel *)feels_likeTitle, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame),feels_likeTitle, 2,0,1,1);
  gtk_widget_show(feels_likeTitle);
  
  tempMinTitle = gtk_label_new("T˚C min: ");
  gtk_label_set_use_markup((GtkLabel *)tempMinTitle, TRUE);
  gtk_label_set_line_wrap((GtkLabel *)tempMinTitle, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame),tempMinTitle, 0,1,1,1);
  gtk_widget_show(tempMinTitle);

  tempMaxTitle= gtk_label_new("T˚C max: ");
  gtk_label_set_use_markup((GtkLabel *)tempMaxTitle, TRUE);
  gtk_label_set_line_wrap((GtkLabel *)tempMaxTitle, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame),tempMaxTitle, 2,1,1,1);
  gtk_widget_show(tempMaxTitle);
  
  pressureTitle = gtk_label_new("Pressure: ");
  gtk_label_set_use_markup((GtkLabel *)pressureTitle, TRUE);
  gtk_label_set_line_wrap((GtkLabel *)pressureTitle, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame),pressureTitle, 0,2,1,1);
  gtk_widget_show(pressureTitle);
  
  humidityTitle = gtk_label_new("Humidity: ");
  gtk_label_set_use_markup((GtkLabel *)humidityTitle, TRUE);
  gtk_label_set_line_wrap((GtkLabel *)humidityTitle, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame),humidityTitle, 2,2,1,1);
  gtk_widget_show(humidityTitle);

  windspdTitle = gtk_label_new("Wind Speed: ");
  gtk_label_set_use_markup((GtkLabel *) windspdTitle, TRUE);
  gtk_label_set_line_wrap((GtkLabel *)windspdTitle, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame),windspdTitle, 0,3,1,1);
  gtk_widget_show(windspdTitle);

  windirTitle = gtk_label_new("Wind Direction: ");
  gtk_label_set_use_markup((GtkLabel *)windirTitle, TRUE);
  gtk_label_set_line_wrap((GtkLabel *)windirTitle, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame),windirTitle, 2,3,1,1);
  gtk_widget_show(windirTitle);


/*========================UI Components Responsible to display Data=========================*/
  gchar *currentValue = g_strdup_printf("%lu˚C", weatherReport.temp);
  currentTempValue = gtk_label_new(currentValue);
  gtk_label_set_use_markup((GtkLabel *)currentTempValue, TRUE);
  gtk_label_set_line_wrap((GtkLabel *) currentTempValue, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame), currentTempValue, 1,0,1,1);
  gtk_widget_show(currentTempValue);

  gchar *feelsValue = g_strdup_printf("%lu˚C", weatherReport.feels_like); 
  feels_likeValue = gtk_label_new(feelsValue);
  gtk_label_set_use_markup((GtkLabel *)feels_likeValue, TRUE);
  gtk_label_set_line_wrap((GtkLabel *) feels_likeValue, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame), feels_likeValue, 3,0,1,1);
  gtk_widget_show(feels_likeValue);

  gchar *tempLowValue = g_strdup_printf("%lu˚C", weatherReport.t_min);
  tempMinValue = gtk_label_new(tempLowValue);
  gtk_label_set_use_markup((GtkLabel *)tempMinValue, TRUE);
  gtk_label_set_line_wrap((GtkLabel *) tempMinValue, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame), tempMinValue, 1,1,1,1);
  gtk_widget_show(tempMinValue);
  
  gchar *tempHighValue = g_strdup_printf("%lu˚C", weatherReport.t_max);
  tempMaxValue = gtk_label_new(tempHighValue);
  gtk_label_set_use_markup((GtkLabel *)tempMaxValue, TRUE);
  gtk_label_set_line_wrap((GtkLabel *) tempMaxValue, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame), tempMaxValue, 3,1,1,1);
  gtk_widget_show(tempMaxValue);

  gchar *pressure = g_strdup_printf("%lu Pa", weatherReport.pressure);
  pressureValue = gtk_label_new(pressure);
  gtk_label_set_use_markup((GtkLabel *)pressureValue, TRUE);
  gtk_label_set_line_wrap((GtkLabel *) pressureValue, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame), pressureValue, 1,2,1,1);
  gtk_widget_show(pressureValue);

  gchar *humidity = g_strdup_printf("%lu", weatherReport.humidity);
  humidityValue = gtk_label_new(humidity);
  gtk_label_set_use_markup((GtkLabel *)humidityValue, TRUE);
  gtk_label_set_line_wrap((GtkLabel *) humidityValue, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame), humidityValue, 3,2,1,1);
  gtk_widget_show(humidityValue);

  gchar *windspd = g_strdup_printf("%lu m/s", weatherReport.wind_spd);
  windspdValue = gtk_label_new(windspd);
  gtk_label_set_use_markup((GtkLabel *)windspdValue, TRUE);
  gtk_label_set_line_wrap((GtkLabel *) windspdValue, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame), windspdValue, 1,3,1,1);
  gtk_widget_show(windspdValue);

  gchar *wind_dir = g_strdup_printf("%lu˚", weatherReport.wind_dir);
  windirValue = gtk_label_new(wind_dir);
  gtk_label_set_use_markup((GtkLabel *)windirValue, TRUE);
  gtk_label_set_line_wrap((GtkLabel *) windirValue, FALSE);
  gtk_grid_attach(GTK_GRID(dataFrame), windirValue, 3,3,1,1);
  gtk_widget_show(currentTempValue);

/*========================UI Components Responsible to display Data=========================*/



  ///All the code for UI above
/*=================================================================*/
  gtk_box_pack_start(GTK_BOX(mainFrame), naviFrame, TRUE, TRUE, 5); 
  gtk_box_pack_end(GTK_BOX(mainFrame), dataFrame, TRUE, TRUE, 5);
/*=================================================================*/

  gtk_container_add(GTK_CONTAINER (window), mainFrame); // mainFrame added to window

  gtk_widget_show_all (window);

}//Activate User interface put in seperate source file in actual project