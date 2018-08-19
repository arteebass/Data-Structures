#Makefile
OBJS = bst.o client1.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

client1: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o client1

client1.o: client1.cpp bst.h
	$(CC) $(CFLAGS) client1.cpp

bst.o: bst.cpp bst.h
	$(CC) $(CFLAGS) bst.cpp

clean:
	\rm *.o *~
