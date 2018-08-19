#Makefile
OBJS = lptab.o qptab.o chaintab.o client.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

client: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o client

client.o: client.cpp lptab.h qptab.h chaintab.h
	$(CC) $(CFLAGS) client.cpp

lptab.o: lptab.cpp lptab.h
	$(CC) $(CFLAGS) lptab.cpp

qptab.o: qptab.cpp qptab.h
	$(CC) $(CFLAGS) qptab.cpp

chaintab.o: chaintab.cpp chaintab.h
	$(CC) $(CFLAGS) chaintab.cpp
clean:
	\rm *.o *~ client
