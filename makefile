CXX = gcc
CFLAGS = -Wall -g 
LIBS = libs/hash/hashtable.c
TARGET = src/main.c
MAIN = main

all: clean main

$(MAIN):
	$(CXX) $(TARGET) $(CFLAGS) $(LIBS) -o $(MAIN)

clean:
	$(RM) mani.o main