#include <stdio.h>
#include <stdlib.h>
#include "array.h"
int main(int argc, char const *argv[])
{
    
    ArrayList * list = create_array(2);
    int a,b,c;
    a = 10;
    b = 3;
    c = 220;
    int teste = 15;
   
    setItems(list, &a);
    setItems(list, &b);
    setItems(list, &c);
    update(list, 0, &teste);
    int * value = (int*)getItem(list, 0);
    printf("\nelement\n %i\n", *value); 

    removeItem(list, 1);
    int tamanho = length(list);
    printf("List length\n %i\n", tamanho);
    
    printf("Itens no ArrayList:\n");
    for (size_t i = 0; i < list->length; i++) {
        int *p = (int *)list->data[i];
        printf("Item %zu: %d\n", i, *p);
    }

    freeMemory(list);
    return 0;
}
