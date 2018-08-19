#Makefile
OBJS = poly.o client.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

client: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o client

client.o: client.cpp poly.h
	$(CC) $(CFLAGS) client.cpp

poly.o: poly.cpp poly.h
	$(CC) $(CFLAGS) poly.cpp

clean:
	\rm *.o *~
