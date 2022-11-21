//
// Created by Jonthan Cordoba on 19/11/22.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "acatleca.h"

Lista crearLista(){
    Lista l;
    int i;
    l.len = -1;
    for(i=0; i<MAX; i++){
        strcpy(l.array[i].no_empleado, "");
        strcpy(l.array[i].nombre, "");
        strcpy(l.array[i].ape_pat, "");
        strcpy(l.array[i].ape_mat, "");
        l.array[i].salario = 0.0;
        l.array[i].fecha_ingreso.dia = 0;
        l.array[i].fecha_ingreso.mes = 0;
        l.array[i].fecha_ingreso.anio = 0;
        l.array[i].anios_trabajados = 0;
    }
    return l;
}

static bool esLlena(Lista l){
    return l.len == MAX-1;
}

static bool esVacia(Lista l){
    return l.len == -1;
}

static int departamentos(){
    int i;
    printf("\n[1] Direccion");
    printf("\n[2] Recursos Humanos");
    printf("\n[3] Finanzas");
    printf("\n[4] Marketing");
    printf("\n[5] Tecnología");
    printf("\n[6] Mantenimiento");
    printf("\nOpcion: ");
    scanf("%d", &i);
    return i;
}

static Personal capturar_info(){
    // Variables para capturar el año del sistema
    time_t t;
    struct tm * timeinfo;

    time(&t);
    timeinfo = localtime (&t);
    // Variables de la aplicacion
    Personal p;
    int aux;
    // Capturando el numero de empleado
    printf("\nIngrese el numero de empleado: ");
    fgets(buffer, 5, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(p.no_empleado, buffer);
    fflush(stdin);
    // Capturando el nombre
    printf("Ingrese el nombre del empleado: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(p.nombre, buffer);
    fflush(stdin);
    // Capturando el apellido paterno
    printf("Ingrese el apellido paterno del empleado: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(p.ape_pat, buffer);
    fflush(stdin);
    // Capturando el apellido materno
    printf("Ingrese el apellido materno del empleado: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(p.ape_mat, buffer);
    fflush(stdin);
    // Seleccionando departamento
    printf("\nSeleccione el departamento del empleado:");
    aux = departamentos();
    // Capturando Departamento
    switch (aux) {
        case 1: strcpy(p.departamento, "Direccion");
            break;
        case 2: strcpy(p.departamento, "Recursos Humanos");
            break;
        case 3: strcpy(p.departamento, "Finanzas");
            break;
        case 4: strcpy(p.departamento, "Marketing");
            break;
        case 5: strcpy(p.departamento, "Tecnologia");
            break;
        case 6: strcpy(p.departamento, "Mantenimiento");
            break;
    }
    // Ingresando el salario
    printf("\nIngrese el salario del empleado: ");
    scanf("%f", &p.salario);
    // Ingresando la fecha de ingreso
    printf("Ingrese el día de ingreso a la Empresa: ");
    scanf("%d", &p.fecha_ingreso.dia);
    printf("Ingrese el mes de ingreso a la Empresa: ");
    scanf("%d", &p.fecha_ingreso.mes);
    printf("Ingrese el anio de ingreso a la Empresa: ");
    scanf("%d", &p.fecha_ingreso.anio);
    // Calculando años en la empresa
    // tm.tm_year obtenemos el año actual del sistema
    p.anios_trabajados = (timeinfo->tm_year + 1900) - p.fecha_ingreso.anio;
    fflush(stdin);
    return p;
}

Lista insertar(Lista l){
    if(esLlena(l)){
        printf("\nLista Llena ...");
    } else{
        printf("\nCapturando la informacion del Empleado");
        l.len++;
        l.array[l.len] = capturar_info();
    }
    return l;
}

void desplegar_info(Personal p){
    printf("\nNo_Empleado: %s", p.no_empleado);
    printf("\nNombre(s): %s", p.nombre);
    printf("\nApellidos: %s %s", p.ape_pat, p.ape_mat);
    printf("\nDepartamento: %s", p.departamento);
    printf("\nSalario: %.2f", p.salario);
    printf("\nFecha de ingreso: %.2d/%.2d/%d", p.fecha_ingreso.dia, p.fecha_ingreso.mes, p.fecha_ingreso.anio);
    printf("\nAnios en la empresa: %d", p.anios_trabajados);
    printf("\n");
}

static int buscar(Lista l, char numero[5]){
    int i;
    for(i=0; i<=l.len; i++){
        if(strcmp(l.array[i].no_empleado, numero) == 0) return i;
    }
    return -1;
}

Lista borrar(Lista l){
    int indice;
    char numero[5];
    if(esVacia(l)){
        printf("\nNo hay registros en la Lista");
    } else{
        printf("\nIngrese el Numero del Empleado a borrar: ");
        scanf("%s", numero);
        indice = buscar(l, numero);
        if(indice == -1){
            printf("\nNo se encontro el registro en la lista ...\n");
        } else{
            int i;
            for(i=indice; i<=l.len; i++){
                l.array[i] = l.array[i+1];
            }
            l.len--;
        }
    }
    return l;
}

void desplegarEmpleado(Lista l){
    char numero[5];
    int i, indice;
    printf("\nIngrese el numero del empleado: ");
    scanf("%s", numero);
    indice = buscar(l, numero);
    if(indice == -1){
        printf("\nNo se encontro el registro en la lista ...\n");
    } else {
        desplegar_info(l.array[indice]);
    }
}

void desplegarNomina(Lista l){
    if(esVacia(l)){
        printf("\nNo hay registros en la Lista");
    } else{
        int i;
        for(i=0; i<l.len+1; i++){
            desplegar_info(l.array[i]);
        }
    }
}

void swap(Personal * p1, Personal * p2){
    Personal temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

static int formar_ordenar(){
    int i;
    do{
        printf("\nSeleccione forma de ordenamiento: ");
        printf("\n[1] Numero de Empleado");
        printf("\n[2] Nombre");
        printf("\n[3] Apellido Paterno");
        printf("\n[4] Salario");
        printf("\nOpcion: ");;
        scanf("%d", &i);
    } while(0<i && i>4);
    return i;
}

Lista ordenar(Lista l){
    int orden = formar_ordenar();
    int i, j;
    for(i=0; i<l.len; i++){
        for(j=0; j<l.len; j++){
            if(orden == 1){
                if(strcmp(l.array[j].no_empleado, l.array[j+1].no_empleado) > 0)
                    swap(&l.array[j], &l.array[j+1]);
            } else if(orden == 2){
                if(strcmp(l.array[j].nombre, l.array[j+1].nombre) > 0)
                    swap(&l.array[j], &l.array[j+1]);
            } else if(orden == 3){
                if(strcmp(l.array[j].ape_pat, l.array[j+1].ape_pat) > 0)
                    swap(&l.array[j], &l.array[j+1]);
            } else if(orden == 4){
                if(l.array[j].salario < l.array[j+1].salario)
                    swap(&l.array[j], &l.array[j+1]);
            }
        }
    }
    return l;
}

int salario_mayor(Lista l){
    int i;
    int indice_mayor = 0;
    float salario_ = (float)0.0;
    for(i=0; i<l.len+1; i++){
        if(l.array[i].salario > salario_){
            indice_mayor = i;
            salario_ = l.array[i].salario;
        }
    }
    return indice_mayor;
}

void mayorSalario(Lista l){
    if(esVacia(l)){
        printf("\nNo hay informacion en la lista");
    } else{
        int indice = salario_mayor(l);
        printf("\nInformacion Actual ...\n");
        desplegar_info(l.array[indice]);
    }
}

int mayor_antiguedad(Lista l){
    int i;
    int indice_mayor = 0;
    int antiguedad = 0;
    for(i=0; i<l.len+1; i++){
        if(l.array[i].anios_trabajados > antiguedad){
            indice_mayor = i;
            antiguedad = l.array[i].anios_trabajados;
        }
    }
    return indice_mayor;
}

int mayorAntiguedad(Lista l){
    if(esVacia(l)){
        printf("\nNo hay informacion en la lista");
    } else{
        int indice = mayor_antiguedad(l);
        printf("\nInformacion Actual ...\n");
        desplegar_info(l.array[indice]);
    }
}
