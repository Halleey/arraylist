#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

int main() {
    ArrayList *list = create_array(5);

    int a = 42;
    int b = 100;
    setItems(list, &a);
    setItems(list, &b);

    
    char *str1 = strdup("Ola Mundo!"); 
    setItems(list, str1);              

    
    float pi = 3.14f;
    setItems(list, &pi);
    
 
    printf("Itens no ArrayList:\n");
    for (size_t i = 0; i < list->length; i++) {
        if (i < 2) { // Primeiros dois são int
            int *p = (int *)list->data[i];
            printf("Item %zu (int): %d\n", i, *p);
        } else if (i == 2) { // Terceiro é string
            char *p = (char *)list->data[i];
            printf("Item %zu (string): %s\n", i, p);
        } else if (i == 3) { // Quarto é float
            float *p = (float *)list->data[i];
            printf("Item %zu (float): %.2f\n", i, *p);
        }
    }

    free(str1); 

    freeMemory(list);
    return 0;
}
