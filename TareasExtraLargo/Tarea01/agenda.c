#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

// Programa para administrar una agenda

char buffer[50];

typedef struct agenda{
    int id;
    char nombre[50];
    char ape_pat[50];
    char ape_mat[50];
    char calle[150];
    int no_ext;
    char no_int[10];
    char colonia[50];
    int codigo_postal;
    char tel_fijo[15];
    char tel_movil[15];
    char email[150];
} Agenda;

int operaciones(){
    int i;
    do{
        fflush(stdin);
        printf("\n[1] Ingresar un registro");
        printf("\n[2] Remover un registro");
        printf("\n[3] Buscar un registro");
        printf("\n[4] Listar Agenda");
        printf("\n[5] Ordenar registros");
        printf("\n[6] Salir");
        printf("\nOpcion: ");
        scanf("%d", &i);
    } while(0<i && i>6);

    return i;
}

Agenda capturar_info(){
    // Variables de la aplicacion
    Agenda agenda_;
    // Capturando el ID del registro
    printf("\nIngrese el ID del registro: ");
    scanf("%d", &agenda_.id);
    fflush(stdin);
    // Capturando el nombre
    printf("Ingrese el nombre del empleado: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(agenda_.nombre, buffer);
    // Capturando el apellido paterno
    printf("Ingrese el apellido paterno del empleado: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(agenda_.ape_pat, buffer);
    // Capturando el apellido materno
    printf("Ingrese el apellido materno del empleado: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(agenda_.ape_mat, buffer);
    // Ingresando datos de la dirección
    // Ingresando calle
    printf("Ingrese la Calle donde habita: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(agenda_.calle, buffer);
    // Capturando el numero interior
    printf("Ingrese el No. Exterior: ");
    scanf("%d", &agenda_.no_ext);
    fflush(stdin);
    // Ingresando el numero exterior
    printf("Ingrese el No. Interior: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(agenda_.no_int, buffer);
    // Ingresando la colonia
    printf("Ingrese la Colonia: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(agenda_.colonia, buffer);
    // Ingresando el codigo postal
    printf("Ingrese el Codigo Postal: ");
    scanf("%d", &agenda_.codigo_postal);
    fflush(stdin);
    // Ingresando el telefono fijo
    printf("Ingrese su Telefono Fijo: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(agenda_.tel_fijo, buffer);
    // Ingresando el telefono movil
    printf("Ingrese su Telefono Movil: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(agenda_.tel_movil, buffer);
    // Ingresando el email
    printf("Ingrese su Direccion de Correo: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(agenda_.email, buffer);

    return agenda_;
}

void insertar(Agenda * array, int * no_registros){
    if(*no_registros == MAX-1){
        printf("\nLista Llena ...");
    } else{
        printf("\nCapturando la informacion del Empleado");
        (*no_registros)++;
        array[*no_registros] = capturar_info();
    }
}

void desplegar_info(Agenda agenda_){
    printf("\nID: %d", agenda_.id);
    printf("\nNombre(s): %s", agenda_.nombre);
    printf("\nApellidos: %s %s", agenda_.ape_pat, agenda_.ape_mat);
    printf("\nDireccion: %s %d %s", agenda_.calle, agenda_.no_ext, agenda_.no_int);
    printf("\nColonia: %s", agenda_.colonia);
    printf("\nCodigo Postal: %d", agenda_.codigo_postal);
    printf("\nTelefono Fijo: %s", agenda_.tel_fijo);
    printf("\nTelefono Movil: %s", agenda_.tel_movil);
    printf("\nCorreo Electronico: %s", agenda_.email);
    printf("\n");
}

int buscar_id(Agenda * array, int id_empleado, int * no_registros){
    int i;
    for(i=0; i<=*no_registros; i++){
        if(array[i].id == id_empleado) return i;
    }
    return -1;
}

int buscar_nombre(Agenda * array, char nombre[], int * no_registros){
    int i;
    for(i=0; i<=*no_registros; i++){
        if(strcmp(array[i].nombre, nombre) == 0) return i;
    }
    return -1;
}

void buscar(Agenda * array, int * no_registros){
    int opcion, id_empleado, indice;
    char nombre[50];
    if(*no_registros == -1){
        printf("\nNo hay registros en la Lista\n");
    } else {
        do {
            printf("\nSeleccione el criterio de busqueda:");
            printf("\n[1] Buscar por ID");
            printf("\n[2] Buscar por Nombre");
            printf("\nOpcion: ");
            scanf("%d", &opcion);
        } while (0 < opcion && opcion > 2);
        if (opcion == 1) {
            printf("\nIngrese el ID del Empleado a buscar: ");
            scanf("%d", &id_empleado);
            indice = buscar_id(array, id_empleado, no_registros);
        } else {
            printf("\nIngrese el Nombre del Empleado a buscar: ");
            scanf("%s", nombre);
            indice = buscar_nombre(array, nombre, no_registros);
        }
        // Resultado del indice obtenido
        if (indice == -1) {
            printf("\nNo se encontro el registro en la lista ...\n");
        } else {
            desplegar_info(array[indice]);
        }
    }
}

void ordenar_id(Agenda * array, int no_registros){
    int n = no_registros;
    int i, j;
    Agenda temp;
    for(i=0; i<=n-1; i++){
        for(j=0; j<=n-i-1; j++){
            if(array[j].id > array[j+1].id){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void ordenar_nombre(Agenda * array, int no_registros){
    int n = no_registros;
    int i, j;
    Agenda temp;
    for(i=0; i<=n-1; i++){
        for(j=0; j<=n-i-1; j++){
            if(strcmp(array[j].nombre, array[j+1].nombre) > 0){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void ordenar(Agenda * array, int * no_registros){
    int opcion;
    if(*no_registros == -1){
        printf("\nNo hay registros en la Lista\n4");
    } else{
        int n = *no_registros;
        do {
            printf("\nSeleccione la operacion a realizar");
            printf("\n[1] ID");
            printf("\n[2] Nombre");
            printf("\nOpcion: ");
            scanf("%d", &opcion);
        } while(0<opcion && opcion>2);
        if(opcion == 1){
            ordenar_id(array, n);
        } else{
            ordenar_nombre(array, n);
        }
    }
}

void borrar(Agenda * array, int * no_registros){
    int id_empleado, indice;
    if(*no_registros == -1){
        printf("\nNo hay registros en la Lista\n");
    } else{
        printf("\nIngrese el ID del Empleado a borrar: ");
        scanf("%d", &id_empleado);
        indice = buscar_id(array, id_empleado, no_registros);
        if(indice == -1){
            printf("\nNo se encontro el registro en la lista ...\n");
        } else{
            int i;
            for(i=indice; i < *no_registros; i++){
                array[i] = array[i+1];
            }
            (*no_registros)--;
        }
    }
}

void desplegar_agenda(Agenda * array, int * no_registros){
    if(*no_registros == -1){
        printf("\nNo hay registros en la Lista\n");
    } else{
        printf("\nImprimiendo la lista de Personas: ");
        int i;
        for(i=0; i <= *no_registros; i++){
            desplegar_info(array[i]);
        }
    }
}

int main() {
    Agenda arreglo[MAX];
    int no_registros = -1;
    int operacion, opcion;
    do{
        // system("cls");
        printf("\nSeleccione la operacion a realizar");
        operacion = operaciones();
        fflush(stdin);
        switch (operacion) {
            case 1: // system("cls");
                insertar(arreglo, &no_registros);
                break;
            case 2: // system("cls");
                borrar(arreglo, &no_registros);
                break;
            case 3: // system("cls");
                buscar(arreglo, &no_registros);
                break;
            case 4: // system("cls");
                desplegar_agenda(arreglo, &no_registros);
                break;
            case 5: // system("cls");
                ordenar(arreglo, &no_registros);
                break;
            case 6: exit(0);
            default:
                printf("\nOpcion Inválida ....");
        }
        printf("\nDesea realizar otra operacion: [1] Si, [2] No");
        printf("\nOpcion: ");
        scanf("%d", &opcion);
    } while(opcion==1);
    return 0;
}
