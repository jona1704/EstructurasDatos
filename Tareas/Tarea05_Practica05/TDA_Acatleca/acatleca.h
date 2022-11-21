//
// Created by Jonthan Cordoba on 19/11/22.
//

#ifndef ACATLECA_H
#define ACATLECA_H
#define MAX 30

// Programa de Control de Personal de la
// Acatleca Feliz

char buffer[50];

typedef struct fecha{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct personal{
    char no_empleado[5];
    char nombre[50];
    char ape_pat[50];
    char ape_mat[50];
    char departamento[50];
    float salario;
    Fecha fecha_ingreso;
    int anios_trabajados;
} Personal;

typedef struct lista{
    int len;
    Personal array[MAX];
} Lista;

Lista crearLista();
Lista insertar(Lista);
Lista borrar(Lista);
void desplegarEmpleado(Lista);
void desplegarNomina(Lista);
void mayorSalario(Lista);
void mayorAntiguedad(Lista);
Lista ordenar(Lista);

#endif // ACATLECA_H
