/* Header file conatins:
 - Global Access to Processor.c from Network.c
 - Global Access to Network.c from App.c
 - Iniates weatherReport, struct to contain the processed data
   from Processor.c */

#include <gtk/gtk.h>



long Processor(char buff[9999]);
void activate (GtkApplication* app, gpointer user_data);
int Network();
struct WeatherReport{
        long temp;
        long feels_like;
        long t_min;
        long t_max;
        long humidity;
        long pressure;
        long wind_dir;
        long wind_spd;
    } weatherReport;
//void activate (GtkApplication* app, gpointer user_data);



