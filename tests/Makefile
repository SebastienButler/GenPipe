CC=g++

INC=-Iinclude/ -I../include/
CFLAGS= -W -Wall -std=c++0x -g -ggdb
LDFLAGS=-pthread
EXEC=pipeline.test

SRC=test.cc
OBJ=$(SRC:.cc=.o)
DEPS=$(wildcard include/*.hh)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	$(CC) $(INC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

distclean: clean
	rm -f $(EXEC)

.PHONY: clean distclean
