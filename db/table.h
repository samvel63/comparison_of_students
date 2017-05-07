#ifndef _TABLE_H_
#define _TABLE_H_

#include "api.h"

#define DELETE_SUCCESS 0
#define DELETE_ERROR -1

typedef struct {
	char name[STR_SIZE];
	Class *classes;
} Table;

void table_create(Table *table, const char *name);
void table_destroy(Table *table);


void table_load_txt(Table *table, Student *s, FILE *in);
int table_load_bin(Table *table, Student *s, FILE *in);
void table_save(Table *table, FILE *out);

void add_student(Table *table, Student *student, int class);
int delete_student(Table *table, Student *student, int class);

void table_print(Table *table);
void print_comprison_of_classes(Table *table);

#endif