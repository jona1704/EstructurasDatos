#include <stdio.h>
#include <stdlib.h>
#include "listadoble.h"

void clrscr(){
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

void pausa(){
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system( "read -n 1 -s -p \"\nPresione una tecla para continuar ...\"" );
#endif

#if defined(_WIN32) || defined(_WIN64)
    printf("\nPresione una tecla para continuar ...\n");
        getch();
#endif
}

int main() {
    ListaDoble * ld = listaDoble();
    int opcion, opcion_ingreso, posicion, numero_vuelo, respuesta;
    do{
        clrscr();
        printf("***** Aerolinea MAC FES Acatlan ******\n\n");
        printf("Seleccione una Opcion: ");
        printf("\n[1] Ingresar Pasajero");
        printf("\n[2] Remover Pasajero");
        printf("\n[3] Listar Pasajeros");
        printf("\n[4] Listar Pasajeros Inverso");
        printf("\n[5] Buscar por Numero de Vuelo");
        printf("\n[6] Salir del Programa");
        printf("\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:	clrscr();
                printf("\n\nSeleccione una Operacion: ");
                printf("\n[1] Ingresar al Principio de la Lista");
                printf("\n[2] Ingresar al Final de la Lista");
                printf("\n[3] Ingresar en Alguna Posicion de la Lista");
                printf("\nOpcion: ");
                scanf("%d", &opcion_ingreso);
                fflush(stdin);
                switch (opcion_ingreso){
                    case 1: insertar_inicio(ld);
                        printf("\nSe Ingreso informacion Correctamente\n");
                        break;
                    case 2: insertar_final(ld);
                        printf("\nSe Ingreso informacion Correctamente\n");
                        break;
                    case 3: printf("\nIngrese posicion a ingresar: ");
                        scanf("%d", &posicion);
                        fflush(stdin);
                        insertar_intermedio(ld, posicion);
                        printf("\nSe Ingreso informacion Correctamente\n");
                        break;
                    default: printf("\nOpcion Invalida");
                }
                break;
            case 2: clrscr();
                printf("\n\nSeleccione una Operacion: ");
                printf("\n[1] Remover al Principio de la Lista");
                printf("\n[2] Remover al Final de la Lista");
                printf("\n[3] Remover de Alguna Posicion de la Lista");
                printf("\nOpcion: ");
                scanf("%d", &opcion_ingreso);
                fflush(stdin);
                switch (opcion_ingreso){
                    case 1: borrar_inicio(ld);
                        printf("\nSe Removio informacion Correctamente ...\n");
                        break;
                    case 2: borrar_final(ld);
                        printf("\nSe Removio informacion Correctamente ...\n");
                        break;
                    case 3: printf("\nIngrese posicion a ingresar: ");
                        scanf("%d", &posicion);
                        fflush(stdin);
                        borrar_intermedio(ld, posicion);
                        printf("\nSe Removio informacion Correctamente ...\n");
                        break;
                    default: printf("\nOpcion Invalida");
                }
                break;
            case 3:	clrscr();
                printf("\n\nListado de Pasajeros: \n");
                desplegar_adelante(ld);
                printf("Numero de Registros: %d", no_nodos(ld));
                break;
            case 4:	clrscr();
                printf("\n\nLista de Pasajeros (orden Inverso): \n");
                desplegar_atras(ld);
                printf("Numero de Registros: %d", no_nodos(ld));
                break;
            case 5:	clrscr();
                printf("\nIngrese el numero de vuelo a buscar: ");
                scanf("%d", &numero_vuelo);
                buscar_por_numero(ld, numero_vuelo);
                printf("\n");
                break;
            case 6: printf("\nHasta Pronto!!!\n\n");
                exit(0);
                break;
            default: printf("\nOpcion Invalida");
        }
        printf("\n\nDesea Realizar Otra Operacion: ");
        printf("\n[1] Si, [Otra Valor] No");
        printf("\nOpcion: ");
        scanf("%d", &respuesta);
        pausa();
    } while(respuesta == 1);

    limpiarLista(ld);

    return 0;
}
