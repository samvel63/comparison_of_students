#ifndef _TABLE_H_
#define _TABLE_H_

#define NAME_LENGTH 64

typedef char Gender;

typedef struct {
	Gender gender;
	int class;
	char full_name[NAME_LENGTH];
} Tuple;

typedef struct {
	char name[NAME_LENGTH];
	Tuple *tuples;
	size_t num_tuples;
} Table;

void table_create(Table *table, const char *name);
void table_destroy(Table *table);
void tuple_insert(Table *table, Tuple *tuple);
void add_student(Table *table, Tuple *tuple, const char *full_name, const Gender gender, const int class);
void print(Table *table);

#endif