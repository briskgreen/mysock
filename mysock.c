#include "mysock.h"

void error_quit(const char *msg)
{
	perror(msg);
	exit(-1);
}

int Socket(int domain,int type,int prot)
{
	int sockfd;

	if((sockfd=socket(domain,type,prot))==-1)
		error_quit("Socket");

	return sockfd;
}

void Bind(int sockfd,SA_IN *server_addr)
{
	if(bind(sockfd,(SA *)server_addr,sizeof(SA_IN))==-1)
		error_quit("Bind");
}

void Listen(int sockfd,int backlog)
{
	if(listen(sockfd,backlog)==-1)
		error_quit("Listen");
}

int Accept(int sockfd,SA_IN *client_addr,socklen_t *size)
{
	int new_sockfd;

	if((new_sockfd=accept(sockfd,(SA *)client_addr,size))==-1)
		error_quit("Accept");

	return new_sockfd;
}

void Connect(int sockfd,SA_IN *server_addr)
{
	if(connect(sockfd,(SA *)server_addr,sizeof(SA_IN))==-1)
		error_quit("Connect");
}

void init_data_with_server(SA_IN *server_addr,int port)
{
	bzero(server_addr,sizeof(SA_IN));
	server_addr->sin_family=AF_INET;
	server_addr->sin_port=htons(port);
	server_addr->sin_addr.s_addr=INADDR_ANY;
}

void init_data_with_client(SA_IN *server_addr,char *host,int port)
{
	struct hostent *hostname;

	if((hostname=gethostbyname(host))==NULL)
	{
		herror("gethostbyname");
		exit(-1);
	}

	bzero(server_addr,sizeof(SA_IN));
	server_addr->sin_family=AF_INET;
	server_addr->sin_port=htons(port);
	server_addr->sin_addr.s_addr=inet_addr(inet_ntoa(*(struct in_addr *)hostname->h_addr_list[0]));
}
