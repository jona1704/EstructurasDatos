//
// Created by Jonthan Cordoba on 16/09/22.
//

#ifndef SETS_H
#define SETS_H

// TDA Set

#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct set{
    int * array;
    int len;
} Set;

Set * crearSet();
void destruirSet(Set * s);
int search(Set * s, int num);
Set * addSet(Set * s, int num);
Set * removeSet(Set * s, int num);
Set * sort(Set * s);
int size(Set * s);
void printSet(Set * s);

#endif // CONJUNTOS_H
