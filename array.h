#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>

typedef struct 
{
    void ** data;
    size_t length;
    size_t capacity;
}ArrayList;

ArrayList * create_array(size_t initial_capacity);
void setItems(ArrayList * list, void * data);
void removeItem(ArrayList * list, size_t element);
void *getItem(ArrayList * list, size_t element);
int length(ArrayList * list);
int update(ArrayList * list, size_t index, void *  element);
void freeMemory(ArrayList * list);

#endif