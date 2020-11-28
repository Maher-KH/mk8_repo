#include "tcp_server.h"


Server_socket::Server_socket(){
    create_socket();
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT );
    address_length = sizeof(address);

    bind_socket();
    set_listen_set();
}

void Server_socket::create_socket(){
    if ((general_socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("[ERROR] : Socket failed");
        exit(EXIT_FAILURE);
    }
    cout<<"[LOG] : Socket Created Successfully.\n";
}

void Server_socket::bind_socket(){
    if (bind(general_socket_descriptor, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("[ERROR] : Bind failed");
        exit(EXIT_FAILURE);
    }
    cout<<"[LOG] : Bind Successful.\n";
}

void Server_socket::set_listen_set(){
    if (listen(general_socket_descriptor, 3) < 0) {
        perror("[ERROR] : Listen");
        exit(EXIT_FAILURE);
    }
    cout<<"[LOG] : Socket in Listen State (Max Connection Queue: 3)\n";
}

int Server_socket::accept_connection(){
    if ((new_socket_descriptor = accept(general_socket_descriptor, (struct sockaddr *)&address, (socklen_t*)&address_length))<0) { 
        perror("[ERROR] : Accept");
        exit(EXIT_FAILURE);
    }
    cout<<"[LOG] : Connected to Client.\n";
    return new_socket_descriptor;
}
