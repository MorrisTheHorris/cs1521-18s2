#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

struct addrinfo a;
int sockfd = socket(a.ai_family, a.ai_socktype, a.ai_protocol);
connect(sockfd, a.ai_addr, a.ai_addrlen);
bind(sockfd, a.ai_addr, a.ai_addrlen);