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

void removeItem(ArrayList *list, size_t element)
{
    if (element >= list->length) {
        fprintf(stderr, "position not was found\n");
        return;
    }

    void *toFree = list->data[element];  

    for (size_t i = element; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->length--;
    list->data[list->length] = NULL;

    free(toFree); 
}


void *getItem(ArrayList *list, size_t element)
{
    if(element >= list->length){
        fprintf(stderr, "position not was found");
        return NULL;
    }
    return list->data[element];
}

int length(ArrayList * list){
    if(list == NULL) return 0;
    return list->length;
}

int update(ArrayList *list, size_t index, void *element)
{
    if(index >= list->length) {
        fprintf(stderr, "position not was found\n");
        return 0;  
    }

    list->data[index] = element;
    return 1; 
}


void freeMemory(ArrayList *list)
{
    if (list == NULL) return;

    // Libera os elementos armazenados
    for (size_t i = 0; i < list->length; i++) {
        free(list->data[i]);
    }

    // Agora libera o array interno
    if (list->data != NULL) {
        free(list->data);
        list->data = NULL;
    }

    list->length = 0;
    list->capacity = 0;

    free(list);
}
