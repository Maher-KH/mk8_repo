#include <iostream>
#include <fstream>
#include <signal.h>
#include <thread>
#include "tcp_server.h"

//Global variables
fstream file;
int socket_descriptor;

//Static Functions
static void open_file(void);
static void transmit_file(int descr);