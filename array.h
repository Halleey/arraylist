#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>

typedef struct 
{
    void ** data;
    size_t length;
    size_t capacity;
}array;



#endif