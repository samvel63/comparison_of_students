CC = gcc
CFLAGS = -g -std=c99 -Wno-unused-result -pipe -O3

db_obj = db/table.o db/io.o

all: generate print execute

generate: $(db_obj) generate.o
	$(CC) $^ -o $@

print:    $(db_obj) print.o
	$(CC) $^ -o $@

execute:  $(db_obj) class.o execute.o
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f generate print execute *.o db/*.o