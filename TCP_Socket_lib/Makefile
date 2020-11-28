CC=g++
FLAGS= -Wall -std=c++11 -I./ 
SRC=tcp_server.cpp tcp_client.cpp 
OUT=-o libTcpClientServer.so -fPIC -shared

all:
	$(CC) $(FLAGS) $(SRC) $(OUT)
	$(CC) -c $(SRC)
	ar rvs libTcpClientServer.a *.o
	rm *.o

clean:
	rm libTcpClientServer.a libTcpClientServer.so
