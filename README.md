# WeatherReport


C powered desktop application that gets weather data from openweathermap.org API using a locations Latitude and longitude. 
The Application creates a socket connection, receive and process the JSON response and display the processed data in Metric units.

--This will be Updated with ability to select different cities from a MySQL database.

Currently the App is still being built component by component which helps me learn and understand and also way to show 
my understanding of software development with C.

To compile the code:

gcc `pkg-config --cflags gtk+-3.0` App.c Network.c Processor.c Processor.h UserInterface.c `pkg-config --libs gtk+-3.0`

Run the code:
./a.out
