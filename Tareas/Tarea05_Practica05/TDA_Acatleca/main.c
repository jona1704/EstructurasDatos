#include <stdio.h>
#include <stdlib.h>
#include "acatleca.h"

int operaciones(){
    int i;
    do{
        fflush(stdin);
        printf("\n[1] Ingresar un registro");
        printf("\n[2] Remover un registro");
        printf("\n[3] Desplegar un registro");
        printf("\n[4] Desplegar Nomina");
        printf("\n[5] Ordenar registros");
        printf("\n[6] Empleado de Mayor Antiguedad");
        printf("\n[7] Empleado de Mayor Salario");
        printf("\n[8] Salir");
        printf("\nOpcion: ");
        scanf("%d", &i);
    } while(0<i && i>8);

    return i;
}

int main(){
    // Creamos una lista que almacene registros de Personal
    Lista l1 = crearLista();
    int operacion, opcion;
    do{
        // system("cls");
        printf("\nSeleccione la operacion a realizar");
        operacion = operaciones();
        fflush(stdin);
        switch (operacion) {
            case 1: // system("cls");
                    l1 = insertar(l1);
                    break;
            case 2: // system("cls");
                    l1 = borrar(l1);
                    break;
            case 3: // system("cls");
                    desplegarEmpleado(l1);
                    break;
            case 4: // system("cls");
                    desplegarNomina(l1);
                    break;
            case 5: // system("cls");
                    l1 = ordenar(l1);
                    break;
            case 6: // system("cls");
                    mayorAntiguedad(l1);
                    break;
            case 7: // system("cls");
                    mayorSalario(l1);
                    break;
            case 8: exit(0);
                    break;
            default:
                    printf("\nOpcion Inválida ....");
        }
        printf("\nDesea realizar otra operacion: [1] Si, [2] No");
        printf("\nOpcion: ");
        scanf("%d", &opcion);
    } while(opcion==1);

    // system("pause");

    return 0;
}




