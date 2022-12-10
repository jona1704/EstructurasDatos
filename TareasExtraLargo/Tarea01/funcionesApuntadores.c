#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * newstrcpy (char * destino, const char *fuente){
    char * ptr = destino;
    while (*fuente != '\0'){
        *destino++ = *fuente++;
    }
    *destino = '\0';
    return ptr;
}

int newstrlen (char * s){
    int cont = 0;
    while (*s != '\0'){
        cont++;
        s++;
    }
    return cont;
}

int newstrcmp (const char * s1, const char * s2){
    while ((*s1 != '\0' && *s2 != '\0') && (*s1 == *s2)){
        s1++;
        s2++;
    }
    if(*s1 == *s2) return 0;
    else if(*s1 > *s2) return 1;
    else return -1;
}

char * every5 (char * input){
    char * ptr = input;
    int contador=0;
    while(*input != '\0'){
        if(*input >= 'a' && *input <= 'z'){
            if(*input != 32 && contador%5==0) {
                *input = *input - 32;
            }
        }
        contador++;
        input++;
    }
    return ptr;
}

int main() {
    const char * fuente = "Hola Mundo Acatlense";
    char * destino = (char*) malloc(strlen(fuente)+1);
    if(destino == NULL) exit(1);
    destino = newstrcpy(destino, fuente);
    printf("destino = %s", destino);
    printf("\nstrlen(destino) = %d", newstrlen(destino));
    // Creando cadenas
    char * cadena1 = "fes";
    char * cadena2 = "Fes";
    if(newstrcmp(cadena1, cadena2) == 0){
        printf("\nCadenas Iguales ...");
    } else {
        if(newstrcmp(cadena1, cadena2) == 1){
            printf("\nCadena 1 alfabeticamente mayor que Cadena 2");
        } else{
            printf("\nCadena 2 alfabeticamente mayor que Cadena 1");
        }
    }
    // Convertir
    char destino2[] = "anitalavalatina";
    printf("\nmayuscula = %s", every5(destino2));



    return 0;
}
