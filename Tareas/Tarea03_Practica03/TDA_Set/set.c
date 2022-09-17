//
// Created by Jonthan Cordoba on 16/09/22.
//

#include "set.h"

// TDA Set

Set * crearSet(){
    Set * s = (Set *) malloc(sizeof(struct set));
    if(s == NULL) exit(1);
    s->array = (int *) malloc(MAX * sizeof(int));
    if(s->array == NULL) exit(1);
    s->len = 0;
    return s;
}

void destruirSet(Set * s){
    free(s->array);
    free(s);
    s = NULL;
}

int search(Set * s, int num){
    int i;
    for (i=0; i<=s->len; i++) {
        if(s->array[i] == num) return i;
    }
    return -1;
}

// Añadimos un elemento siempre al final (si este no
// esta repetido)
Set * addSet(Set * s, int num){
    if(search(s, num) == -1){
        s->array[s->len] = num;
        s->len++;
    }
    return s;
}

// Removemos un elemento de acuerdo a la posicion
// del valor a remover. No se hace nada si el
// valor no existe en el arreglo
Set * removeSet(Set * s, int num){
    int i;
    int pos;
    if((pos=search(s, num)) != -1){
        for(i=pos; i<s->len; i++){
            s->array[i] = s->array[i+1];
        }
        s->len--;
    }
    return s;
}

Set * sort(Set * s){
    int i, j;
    int temp;
    for (i=0; i<s->len-1; i++) {
        for (j=0; j<s->len-i-1; j++) {
            if(s->array[j]>s->array[j+1]){
                temp = s->array[j];
                s->array[j] = s->array[j+1];
                s->array[j+1] = temp;
            }
        }
    }
    return s;
}

int size(Set * s){
    return s->len;
}

void printSet(Set * s){
    int i;
    for (i=0; i<s->len; i++){
        printf("%d ", s->array[i]);
    }
    printf("\n");
}
