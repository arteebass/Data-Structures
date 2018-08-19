#Makefile
OBJS = myqueue.o client.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

client: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o client

client.o: client.cpp myqueue.h
	$(CC) $(CFLAGS) client.cpp

myqueue.o: myqueue.cpp myqueue.h
	$(CC) $(CFLAGS) myqueue.cpp

clean:
	\rm *.o *~
