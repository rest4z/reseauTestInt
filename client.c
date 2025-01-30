// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT	 8080
#define MAXLINE 1024

typedef struct {
	char objet[20];
	float index1;
	float index2;
	float index3;
} Message;


void receiveMessage(void *argvp){
}
// Driver code
int main() {

	Message message1 = {
		.objet = "player",
		.index1 = 44.f,
		.index2 = 44.f,
		.index3 = 44.f,
	};

	int sockfd;
	struct sockaddr_in	 servaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	printf("sockfd : %d,\n", sockfd);

	memset(&servaddr, 0, sizeof(servaddr));

	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	float message_float = 12.f;
	sendto( sockfd,
			(float *)&message_float,
			sizeof(float),
			MSG_CONFIRM,
			(const struct sockaddr *) &servaddr,
			sizeof(servaddr) );

	int n;
	unsigned int len;

	/*
	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
			MSG_WAITALL, (struct sockaddr *) &servaddr,
			&len);
	buffer[n] = '\0';
	printf("Server : %s\n", buffer);
	*/
	close(sockfd);
	return 0;
}

