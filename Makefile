CC = gcc
CFLAGS = -g -std=c99 -Wno-unused-result -pipe -O3

db_obj = db/io.o db/class.h

all:  generate print_db print_cap execute main

generate: 	$(db_obj) generate.o
	$(CC) $^ -o $@

print_db: 	$(db_obj) print_db.o
	$(CC) $^ -o $@

print_cap:	$(db_obj) print_cap.o
	$(CC) $^ -o $@

execute:  	$(db_obj) execute.o
	$(CC) $^ -o $@

main:   	$(db_obj) main.o
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f generate print_db print_cap execute main *.o db/*.o