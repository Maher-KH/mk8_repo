#include "tcp_client.h"

Client_socket::Client_socket(){
    create_socket();
    address.sin_family = AF_INET;
    //La fonction htons()  converts a short in hostshort from the host bytes order to the network
    address.sin_port = htons( PORT );
    address_length = sizeof(address);
    //Convert the address 127.0.0.1 to a in_addr struct then copy it in address.sin_addr
    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0) { 
        cout<<"[ERROR] : Invalid address \n";
    }
}

void Client_socket::create_socket(){
    if ((general_socket_descriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        perror("[ERROR] : Socket failed.\n");
        exit(EXIT_FAILURE);
    }
    cout<<"[LOG] : Socket is Successfully Created .\n";
}

int Client_socket::create_connection(){
    if (connect(general_socket_descriptor, (struct sockaddr *)&address, sizeof(address)) < 0) { 
        perror("[ERROR] : connection attempt failed.\n");
        exit(EXIT_FAILURE);
    }
    cout<<"[LOG] : Connection Successfull.\n";
    
    return general_socket_descriptor;
}
