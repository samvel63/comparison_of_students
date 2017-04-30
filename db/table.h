#ifndef _TABLE_H_
#define _TABLE_H_

#define NAME_LENGTH 64

typedef char Gender;

typedef enum {
	STRING,
	INTEGER,
	CHAR
} Field_type;

typedef struct {
	Field_type type;
	union {
		Gender gender;
		int num;
		int class;
		char full_name[NAME_LENGTH];
	}
} Field;

typedef struct {
	int num;
	Field *field;
	int numFields;

} Tuple;

typedef {
	char name[NAME_LENGTH];
	Tuple *tuples;
	size_t numTuples;
} Table;

#endif