#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Processor.h"


// Create equation to convert for Celsius and Metric Measurements
// Send Proccessed data to App or UI file
// Document the code well, short sweet


long Processor(char buff[9999]){
    char catergories[][20]= { "temp" ,"feels_like", "temp_min" ,  "temp_max"  ,  "pressure" ,"humidity", "speed" , "deg"};
    long value;
    char *catSorter;
    char *ptr = buff;
    int catRunner = 0;
    char *proccesorRun;
    long collection[10] = {};

    while (catRunner < 8) {
        catSorter = "";
        catSorter = catergories[catRunner];

        ptr = strstr(ptr, catSorter);
        
        ptr = strchr(ptr, ':');
        
        ptr++;
        value = strtol(ptr, &ptr, 10);
        
        ptr++;

        collection[catRunner] = value;

        printf("\n%s:\n %lu", catSorter, value);
        catRunner++;

        
    };
    // Since I know the API Response Structure I can specifically add to Array
    weatherReport.temp = collection[0] - 273.15; // Converts from Kelvin to Celsius
    weatherReport.feels_like = collection[1] - 273.15;
    weatherReport.t_min = collection[2] - 273.15;
    weatherReport.t_max = collection[3] - 273.15;
    weatherReport.pressure = collection[4];
    weatherReport.humidity = collection[5];
    weatherReport.wind_spd = collection[6];
    weatherReport.wind_dir = collection[7];

    printf("\n%lu\n", value);
    return value;
}