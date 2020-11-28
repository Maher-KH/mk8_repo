#include <iostream>
#include <fstream>
#include <signal.h>
#include <thread>
#include "tcp_client.h"

//Defines
#define BUFFER_SIZE 1024

//Global variables
fstream file;
int socket_descriptor;
char buffer[BUFFER_SIZE] = {};

//Static Functions
static void open_file(void);
static void receive_file(int descr);