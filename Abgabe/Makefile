CC = gcc
CFLAGS = -Wall -std=c11
SRC_FILES = main.c threadfunc.c

all: run

search: $(SRC_FILES:.c=.o)
	$(CC) $(CFLAGS) -o $@.exe $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean run

clean:
	rm -f search.exe *.o

run: search
	./search.exe
