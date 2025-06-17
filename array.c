#include "array.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList *create_array(size_t initial_capacity)
{
    
    ArrayList * list = malloc(sizeof(ArrayList));

    list->data = malloc(sizeof(void*) * initial_capacity);
    list->length = 0;
    list->capacity = initial_capacity;
    return list;

}

void setItems(ArrayList *list, void *data)
{
    if(list->length == list->capacity) {
        size_t newCapacity = list->length *2;
        void ** newData = realloc(list->data, sizeof(void*) * newCapacity); 
         if(!newData){
            fprintf(stderr, "Falha ao salvar array");
            return;
        }  
        list->data = newData;
        list->capacity = newCapacity;
    }
    list->data[list->length++] = data;
}

void freeMemory(ArrayList *list)
{
}
