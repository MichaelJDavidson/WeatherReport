// Move Networking code here
// Document Well
// sort header files into groups of what they're used for e.g. Networking, IOStream
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Processor.h"

int Network(void){

    //Components for Socket Coding
    struct sockaddr_in client;
	int hostname, res, SocketFD, requestBytes;

    //The HTTP request string for get request

    //Change values for Lat and long so more than one city can be seen
    //Soon Database selection from a UI response will replace the Lat and Long value selection
    //Timer to refresh connection and bring in fresh data, 
    //Timer only wrapping the request as city selected does not need to be cleaned

    char *getRequest = "GET /data/2.5/weather?lat=-43.535&lon=172.639&appid=96d62d8d5fc4e02f28e85747582eb22c HTTP/1.0\r\n\r\n";

    //buffer takes in JSON response from API
    char buffer[9999];
   
   //Creates Connection to socket
	SocketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(SocketFD == -1){
		perror("Cannot create socket");
		exit(EXIT_FAILURE);
	}
    //Clears Client variables
	memset(&client, 0, sizeof(client));

    //Assigns internet data to Client variables
	client.sin_family = AF_INET;
	client.sin_port = htons(80);

    //Contains External Server IP Address 
	res = inet_pton(AF_INET, "178.128.25.248", &client.sin_addr);

    //Connection to external Server
	if (connect(SocketFD, (struct sockaddr *)&client, sizeof(client)) == -1){
		perror("Cannot connect");
		close(SocketFD);
		exit(EXIT_FAILURE);
	}
    
    
    requestBytes = strlen(getRequest);

    if(send(SocketFD, getRequest, requestBytes, 0)< 0){
        perror("Failed to send request");
        exit(EXIT_FAILURE);
    }

    /* Receive config information from server */ 
    int totalBytesRcvd = 0; 
    unsigned int echoStringLen;
    int bytesRcvd;
    printf("Received: ");              /* Setup to print the echoed string */ 

    //Recieves response for processing
    recv(SocketFD, buffer, 9999 - 1, 0);

    //Sends response to the processing file
    Processor(buffer);

    close(SocketFD);
    return 0;
}