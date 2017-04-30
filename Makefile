CC = gcc
CFLAGS = -g -std=c99 -Wno-unused-result -pipe -O3

all: generate print execute

generate: io.o generate.o
	$(CC) $^ -o $@

print:    io.o print.o
	$(CC) $^ -o $@

execute:  class.o io.o execute.o
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f generate print execute *.o