#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

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

class Client_socket{
    
    fstream file;
    int general_socket_descriptor;
    struct sockaddr_in address;
    int address_length;

    public:
        Client_socket();
        void create_socket();
        int create_connection();
};

#endif
