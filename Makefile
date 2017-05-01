CC = gcc
CFLAGS = -g -std=c99 -Wno-unused-result -pipe -O3

db_obj = db/table.o

all: generate print execute test

generate: io.o generate.o
	$(CC) $^ -o $@

print:    io.o print.o
	$(CC) $^ -o $@

execute:  class.o io.o execute.o
	$(CC) $^ -o $@

test: $(db_obj) io.o test.o
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f generate print execute test *.o