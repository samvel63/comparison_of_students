#include <stdio.h>
#include <stdlib.h>

#include "class.h"


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

void print_comprison_of_classes(Class *classes, int cap, int n)
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