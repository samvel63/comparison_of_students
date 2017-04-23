#ifndef _CLASS_H_
#define _CLASS_H_

#define MAX_SIZE 11
#define NEED_CLASS 10

typedef struct {
    int group;
    int capacity;
} Class;

int in_classes(Class *classes, int cap, int group);
int cap_class(Class *classes, int cap, int group);
void print_comprison_of_classes(Class *classes, int cap, int n);

#endif