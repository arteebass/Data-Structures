#Makefile
OBJS = mysort.o client.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

client: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o client

client.o: client.cpp mysort.h
	$(CC) $(CFLAGS) client.cpp

mysort.o: mysort.cpp mysort.h
	$(CC) $(CFLAGS) mysort.cpp
clean:
	\rm *.o *~
