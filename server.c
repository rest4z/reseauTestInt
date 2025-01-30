// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
	
#define PORT	 8080
#define MAXLINE 1024
	
typedef struct {
	char objet[20];
	float index1;
	float index2;
	float index3;
} Message;

// Driver code
int main() {
	int sockfd;
	Message message1;
	struct sockaddr_in servaddr, cliaddr;
		
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	printf("sockfd : %d, \n", sockfd);

	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
		
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
		
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ){
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
		
	int n;
	unsigned int len;

	len = sizeof(cliaddr); //len is value/result

	float message_float;
	while (1){

		n = recvfrom(sockfd, (float *)&message_float,
				MAXLINE,
				MSG_WAITALL,
				( struct sockaddr *) &cliaddr,
				&len);

		printf("Client index : %f\n", message_float);
/*
		sendto(sockfd,
				(const char *)hello,
				strlen(hello),
				MSG_CONFIRM,
				(const struct sockaddr *) &cliaddr,
				len);
		printf("Hello message sent.\n");
*/
	}
	return 0;
}
