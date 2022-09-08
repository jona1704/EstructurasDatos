#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct prueba{
    char * nombre; // Apuntador a Cadena
    char * apellido; // Apuntador a Cadena
    int edad;
};

int main() {
    // Creamos variable de tipo apuntador a struct prueba
    struct prueba * sp;
    // Asignamos memoria al apuntador struct prueba
    sp = (struct prueba *) malloc(sizeof(struct prueba));
    if(sp == NULL) exit(1);
    // Creamos una variable auxiliar de tipo cadena
    char auxiliar[30];
    // Asignamos un valor a auxiliar
    stpcpy(auxiliar, "Jonathan");
    // Asignamos memoria para el miembro nombre
    sp->nombre = (char *) malloc((strlen(auxiliar)+1));
    if(sp->nombre == NULL) exit(1);
    // Copiamos el contenido de auxiliar en sp->nombre
    stpcpy(sp->nombre, auxiliar);
    // Asignamos el valor de auxiliar
    stpcpy(auxiliar, "Córdoba");
    // Asignamos memoria para el miembro apellido
    sp->apellido = (char *) malloc((strlen(auxiliar)+1));
    if(sp->apellido == NULL) exit(1);
    // Copiamos el contenido de auxiliar en sp->nombre
    stpcpy(sp->apellido, auxiliar);
    // Asignamos un valor al miembro edad
    sp->edad = 30;
    // Imprimimos el contenido del struct prueba
    printf("Nombre Completo: %s %s\n", sp->nombre, sp->apellido);
    printf("Edad: %d\n", sp->edad);
    // Liberamos memoria para el miembro apellido;
    free(sp->apellido);
    // Liberamos memoria para el miembro nombre;
    free(sp->nombre);
    // Liberamos memoria del apuntador sp
    free(sp);

    return 0;
}
