#ifndef _TABLE_H_
#define _TABLE_H_

#define STR_SIZE 64
#define MAX_CLASSES 11

typedef struct {
    char surname[STR_SIZE];
    char initials[STR_SIZE];
    //int  group;
} Student;

typedef struct {
	size_t capacity;
	Student *students;
} Class;

typedef struct {
	char name[STR_SIZE];
	Class *classes;
} Table;

void table_create(Table *table, const char *name);
void table_destroy(Table *table);
void add_student(Table *table, Student *student, int class);
void table_print(Table *table);
void table_load_txt(Table *table, Student *s, FILE *in);
void table_load_bin(Table *table, Student *s, FILE *in);
void table_save(Table *table, FILE *out);
//void table_delete(Table *table, int index);

#endif