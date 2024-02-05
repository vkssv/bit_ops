/* 
 * tcpserver.c - A simple TCP echo server 
 * usage: tcpserver <port>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE  16*1024 

#if 0
/* 
 * Structs exported from in.h
 */

/* Internet address */
struct in_addr {
  unsigned int s_addr; 
};



/*
 * Struct exported from netdb.h
 */


#endif

/*
 * error - wrapper for perror
 */
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int listen_fd; /* listen socket */
    int active_fd; /* active socket */
    int port; /* port to listen on */
    int client_addr_len; /* byte size of client's address */
    struct sockaddr_in serveraddr; /* server's addr */
    struct sockaddr_in clientaddr; /* client addr */
    struct hostent *client_host_info; /* client host info */
    char *hostaddrp; /* dotted decimal host addr string */
    int optval; /* flag value for setsockopt */
    int message_len; /* message byte size */

    char *recv_buf = (char*)malloc(BUFSIZE);

    /* 
    * check command line arguments 
    */
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);

    /* 
    * socket: create the parent socket 
    */
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) 
        error("ERROR opening socket");

    /* setsockopt: Handy debugging trick that lets 
    * us rerun the server immediately after we kill it; 
    * otherwise we have to wait about 20 secs. 
    * Eliminates "ERROR on binding: Address already in use" error. 
    */
    optval = 1;

    // For AF_INET sockets this means that a socket may bind, 
    // except when there is an active listening socket bound to
    // the address.  When the listening socket is bound to INADDR_ANY
    // with a specific port then it is not possible to bind to this port
    // for any local address.
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, 
            (const void *)&optval , sizeof(int));

    /*
    * build the server's Internet address
    */
    memset((void *) &serveraddr, 0, sizeof(serveraddr));
    memset((void *) &clientaddr, 0, sizeof(clientaddr));


    /* Internet style socket address
    struct sockaddr_in  {
    unsigned short int sin_family; /* Address family
    unsigned short int sin_port;   /* Port number
    struct in_addr sin_addr;	 /* IP address
    unsigned char sin_zero[...];   /* Pad to size of 'struct sockaddr'
    };
    */

    /* this is an Internet address */
    serveraddr.sin_family = AF_INET;

    /* let the system figure out our IP address */
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    /* this is the port we will listen on */
    serveraddr.sin_port = htons((unsigned short)port);

    /* 
    * bind: associate the parent socket with a port 
    */
    if (bind(listen_fd, (struct sockaddr *) &serveraddr,  sizeof(serveraddr)) < 0) 
        error("ERROR on binding");

    /* 
    * listen: make this socket ready to accept connection requests 
    */
    if (listen(listen_fd, 5) < 0) /* allow 5 requests to queue up */ 
        error("ERROR on listen");

    /* 
    * main loop: wait for a connection request, echo input line, 
    * then close connection.
    */
    client_addr_len = sizeof(clientaddr);
    while (1) {

        /* 
        * accept: wait for a connection request 
        */
        active_fd = accept(listen_fd, (struct sockaddr *) &clientaddr, &client_addr_len);
        if (active_fd < 0) 
            error("ERROR on accept");
        
        /* 
        * gethostbyaddr: determine who sent the message 
        */

        /* Domain name service (DNS) host entry */
        /*
        struct hostent {
            char    *h_name;        /* official name of host
            char    **h_aliases;    /* alias list
            int     h_addrtype;     /* host address type
            int     h_length;       /* length of address
            char    **h_addr_list;  /* list of addresses
        }
        */

        
        client_host_info = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
        if (client_host_info == NULL)
            error("ERROR on gethostbyaddr");
        
        hostaddrp = inet_ntoa(clientaddr.sin_addr);
        
        if (hostaddrp == NULL)
            error("ERROR on inet_ntoa\n");

        printf(">> server established connection with %s (%s) on port %d\n", client_host_info->h_name, hostaddrp, clientaddr.sin_port);
        
        /* 
        * read: read input string from the client
        */
        memeset(recv_buf, BUFSIZE);
        while (1) {
            message_len = read(active_fd, recv_buf, BUFSIZE);
            if (message_len < 0) 
                error("ERROR reading from socket");
            printf("server received %d bytes: %s", message_len, recv_buf);
            printf("First 16 bytes\n");
            for(i=0; i<64; i++) {
                printf(">>0x02%x<<", recv_buf[i]);
            }
            printf("\n");

            
            /* 
            * write: echo the input string back to the client 
            */
            message_len = write(active_fd, recv_buf, strlen(recv_buf));
            if (message_len < 0) 
                error("ERROR writing to socket");
        }

        close(active_fd);
    }
}