#ifndef _MYSOCK_H
#define _MYSOCK_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>

typedef struct sockaddr SA;
typedef struct sockaddr_in SA_IN;

void error_quit(const char *msg);

int Socket(int domain,int type,int prot);

void Bind(int sockfd,struct sockaddr_in *server_addr);

void Listen(int sockfd,int backlog);

int Accept(int sockfd,struct sockaddr_in *client_addr,socklen_t *size);

void Connect(int sockfd,struct sockaddr_in *server_addr);

void init_data_with_server(struct sockaddr_in *server_addr,int port);

void init_data_with_client(struct sockaddr_in *server_addr,char *host,int port);

void close_with_safe(int sockfd);

#endif
