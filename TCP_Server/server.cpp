#include "server.h"

//open_file() definition
static void open_file(void){
    file.open("../DATA/sent_file.txt", ios::in | ios::binary);
    if(file.is_open()){
        cout<<"[LOG] : File is ready to be Transmitted.\n";
    }
    else{
        cout<<"[ERROR] : File loading failed, Exititng.\n";
        exit(EXIT_FAILURE);
    }
}

//transmit_file() definition
static void transmit_file(int descr){
    std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    cout<<"[LOG] : Transmission Data Size "<<contents.length()<<" Bytes.\n";

    cout<<"[LOG] : Sending...\n";

    int bytes_sent = send(descr , contents.c_str() , contents.length() , 0 );
    cout<<"[LOG] : Transmitted Data Size "<<bytes_sent<<" Bytes.\n";

    cout<<"[LOG] : File Transfer Complete.\n";
}

int main(){
    //Create server socket, bind socket and set listen mode
    Server_socket Server;
    //Accept client connection attempt
    socket_descriptor = Server.accept_connection();
    //Open file to be sent
    open_file();
    //Transmit file to client via a thread (you may not use threads here!)
    thread Transf_thread(transmit_file, socket_descriptor);
    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution
    Transf_thread.join();
    return 0;
}