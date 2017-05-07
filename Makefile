CC = gcc
CFLAGS = -g -std=c99 -Wno-unused-result -pipe -O3

db_obj = db/table.o db/io.o db/class.h

all:  generate print execute #main

generate: $(db_obj) generate.o
	$(CC) $^ -o $@

print:    $(db_obj) print.o
	$(CC) $^ -o $@

execute:  $(db_obj) execute.o
	$(CC) $^ -o $@

#main:   $(db_obj) main.o
#	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f generate print execute main *.o db/*.o