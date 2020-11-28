#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include<iostream>
#include<fstream>
#include<stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;
#define PORT 8050

class Server_socket{
    fstream file;
    int general_socket_descriptor;
    int new_socket_descriptor;
    struct sockaddr_in address;
    int address_length;

    public:
        Server_socket();
        void create_socket();
        void bind_socket();
        void set_listen_set();
        int accept_connection();
};

#endif
