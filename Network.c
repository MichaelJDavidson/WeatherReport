// Move Networking code here
// Document Well

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

    struct sockaddr_in client;
	int hostname, res, SocketFD, requestBytes;
    char *getRequest = "GET /data/2.5/weather?lat=-43.535&lon=172.639&appid=96d62d8d5fc4e02f28e85747582eb22c HTTP/1.0\r\n\r\n";
    char buffer[9999];
    FILE *result;

	SocketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(SocketFD == -1){
		perror("Cannot create socket");
		exit(EXIT_FAILURE);
	}

	memset(&client, 0, sizeof(client));

	client.sin_family = AF_INET;
	client.sin_port = htons(80);

	res = inet_pton(AF_INET, "178.128.25.248", &client.sin_addr);

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

    //recieving
    /* Receive config information from server */ 
    int totalBytesRcvd = 0; 
    unsigned int echoStringLen;
    int bytesRcvd;
    printf("Received: ");                /* Setup to print the echoed string */ 
    recv(SocketFD, buffer, 9999 - 1, 0);

    result = fopen("result.bin", "w");
    fprintf(result, "%s", buffer);

    Processor(buffer);

    close(SocketFD);
    return 0;
}