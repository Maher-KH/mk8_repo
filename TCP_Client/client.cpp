#include "client.h"

//open_file() definition
static void open_file(void){
    file.open("../DATA/received_file.txt", ios::out | ios::trunc | ios::binary);
    if(file.is_open()){
        cout<<"[LOG] : File Created.\n";
    }
    else{
        cout<<"[ERROR] : File creation failed, Exititng.\n";
        exit(EXIT_FAILURE);
    }
}

//receive_file() definition
static void receive_file(int descr){
    int valread = read(descr, buffer, BUFFER_SIZE);
    cout<<"[LOG] : Data received "<<valread<<" bytes\n";
    cout<<"[LOG] : Saving data into file.\n";
    
    file<<buffer;
    cout<<"[LOG] : File Saved.\n";
}

int main(){
    //Create client socket
    Client_socket Client;
    //Try to connect with server socket
    socket_descriptor = Client.create_connection();
    //Open received file
    open_file();
    //Receive file from server via a thread (you may not use threads here!)
    thread Receive_thread(receive_file, socket_descriptor);
    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution
    Receive_thread.join();
    return 0;
}