#ifndef _CLASS_H_
#define _CLASS_H_

#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 64
#define MAX_CLASSES 11
#define MAIN_CLASS 10

typedef struct {
    char surname[STR_SIZE];
    char initials[STR_SIZE];
} Student;

typedef struct {
	size_t capacity;
	Student *students;
} Class;

#endif