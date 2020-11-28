CC=g++
FLAGS= -Wall -std=c++11 -lpthread
SRC=client.cpp 
OUT=-o client
LIB=-L../TCP_Socket_lib ../TCP_Socket_lib/libTcpClientServer.a
INC=-I../TCP_Socket_lib/

all:
	$(CC) $(OUT) $(SRC) $(FLAGS) $(INC) $(LIB)

clean:
	rm client