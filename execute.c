#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "io.h"

#define MAX_SIZE 11
#define NEED_CLASS 10

typedef struct {
    int group;
    int capacity;
} Class;

int in_classes(Class *classes, int cap, int group)
{
    for (int i = 0; i < cap; ++i) {
        if (classes[i].group == group)
            return 1;
    }
    return 0;
}

int cap_class(Class *classes, int cap, int group)
{
    for (int i = 0; i < cap; ++i) {
        if (classes[i].group == group)
            return classes[i].capacity;
    }

    return 0;
}

void print_comprison_of_student(Class *classes, int cap, int n)
{
    for (int i = 0; i < cap; ++i) {
        if(classes[i].group != NEED_CLASS) {
            if (classes[i].capacity > n)
                fprintf(stdout, "\n%d-й класс больше 10-го на %d\n", classes[i].group, classes[i].capacity - n);
            else if (classes[i].capacity < n)
                fprintf(stdout, "\n%d-й класс меньше 10-го на %d\n", classes[i].group, n - classes[i].capacity);
            else
                fprintf(stdout, "\n%d-й и 10-й классы имеют одинаковое количество учеников - равное %d.\n", classes[i].group, n);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }

    Student student;
    Class classes[MAX_SIZE];
    int number_of_classes = 0;

    while (student_read_bin(&student, in)) {
        if(in_classes(&classes, number_of_classes, student.group)) {
            for (int i = 0; i < number_of_classes; ++i) {
                if (classes[i].group == student.group) {
                    classes[i].capacity += 1;
                    break;
                }
            }
        } else {
            classes[number_of_classes].group = student.group;
            classes[number_of_classes].capacity = 1;
            number_of_classes++;
        }
    }

    int cap_need_class = cap_class(&classes, number_of_classes, NEED_CLASS);
    print_comprison_of_student(&classes, number_of_classes, cap_need_class);
    printf("\n");

    return 0;
}