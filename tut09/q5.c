#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void fatal(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// ./q5 host port path
int main(int argc, char *argv[]) {
    int sockfd;
    int port = atoi(argv[2]);
    struct sockaddr_in server_address;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        fatal("Socket couldn't be opened");

    server = gethostbyname(argv[1]);
    if (server == NULL)
        fatal("Couldn't get host");

    bzero((char *)&server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;

    bcopy((char *)server->h_addr,
          (char *)&server_address.sin_addr.s_addr, server->h_length);

    server_address.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_address,
                sizeof(server_address)) < 0)
        fatal("Couldn't connect");

    char buffer[BUFSIZ];
    sprintf(buffer, "GET %s HTTP1.1\nHost: %s\n\n", argv[3], argv[1]);
    puts(buffer);

    int bytes = write(sockfd, buffer, strlen(buffer));
    if (bytes < 0)
        fatal("Couldn't write to the socket");

    printf("Response received:\n");
    while ((bytes = read(sockfd, buffer, BUFSIZ)) > 0)
        write(1, buffer, bytes);

    if (bytes < 0)
        fatal("Not response from socket");

    close(sockfd);

    return 0;
}