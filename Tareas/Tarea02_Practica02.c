#include <stdio.h>
#include <string.h>

char buffer[50];

// Programa de Control de Personal de la
// Acatleca Feliz

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

int departamentos(){
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

Personal capturar_info(){
    Personal p;
    int aux;
    printf("\nIngrese el numero de empleado: ");
    fgets(buffer, 5, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(p.no_empleado, buffer);
    fflush(stdin);
    printf("Ingrese el nombre del empleado: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(p.nombre, buffer);
    fflush(stdin);
    printf("Ingrese el apellido paterno del empleado: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(p.ape_pat, buffer);
    fflush(stdin);
    printf("Ingrese el apellido materno del empleado: ");
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    stpcpy(p.ape_mat, buffer);
    fflush(stdin);
    printf("\nSeleccione el departamento del empleado:");
    aux = departamentos();
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
    printf("\nIngrese el salario del empleado: ");
    scanf("%f", &p.salario);
    printf("Ingrese el día de ingreso a la Empresa: ");
    scanf("%d", &p.fecha_ingreso.dia);
    printf("Ingrese el mes de ingreso a la Empresa: ");
    scanf("%d", &p.fecha_ingreso.mes);
    printf("Ingrese el anio de ingreso a la Empresa: ");
    scanf("%d", &p.fecha_ingreso.anio);
    // Calculando años en la empresa
    p.anios_trabajados = 2022 - p.fecha_ingreso.anio;
    fflush(stdin);
    return p;
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

int buscar_empleado(Personal p[], int n, char * numeroEmpleado){
    int i;
    int indice = -1;
    for(i=0; i<n; i++){
        if(strcmp(p[i].no_empleado, numeroEmpleado) == 0){
            indice = i;
        }
    }
    return indice;
}

void desplegar_empleado(Personal p[], int n, char * numeroEmpleado){
    int i;
    i = buscar_empleado(p, n, numeroEmpleado);
    if(i == -1){
        printf("No existe el empleado ... \n");
    } else{
        printf("Empleado encontrado ...\n");
        desplegar_info(p[i]);
    }
}

int salario_mayor(Personal p[], int n){
    int i;
    int indice_mayor = 0;
    float salario_ = (float)0.0;
    for(i=0; i<n; i++){
        if(p[i].salario > salario_){
            indice_mayor = i;
            salario_ = p[i].salario;
        }
    }
    return indice_mayor;
}

int mayor_antiguedad(Personal p[], int n){
    int i;
    int indice_mayor = 0;
    int antiguedad = 0;
    for(i=0; i<n; i++){
        if(p[i].anios_trabajados > antiguedad){
            indice_mayor = i;
            antiguedad = p[i].anios_trabajados;
        }
    }
    return indice_mayor;
}

int main() {
    // Suponiendo n empleados
    int n = 2;
    int i;
    char noEmpleado[5];
    Personal p[n];
    // Ingresando empleados
    for(i=0; i<n; i++){
        printf("\nIngresando Informacion del Empleado %d: ", i+1);
        p[i] = capturar_info();
    }
    // Desplegando empleados
    for(i=0; i<n; i++){
        printf("\nDesplegando Informacion del Empleado %d: ", i+1);
        desplegar_info(p[i]);
    }
    // Buscando Empleado
    printf("\nIngrese el empleado a buscar: ");
    fgets(noEmpleado, 5, stdin);
    noEmpleado[strcspn(noEmpleado, "\n")] = 0;
    desplegar_empleado(p, n, noEmpleado);

    // Imprimiendo el Empleado con el Salario Mayor
    int indice = salario_mayor(p, n);
    printf("\nEl empleado con el salario mayor es: %s %s %s", p[indice].nombre, p[indice].ape_pat, p[indice].ape_mat);

    // Imprimiendo el Empleado con Mayor Antiguedad
    int indice_antiguedad = mayor_antiguedad(p, n);
    printf("\nEl empleado con la antiguedad mayor es: %s %s %s", p[indice_antiguedad].nombre, p[indice_antiguedad].ape_pat, p[indice_antiguedad].ape_mat);

    return 0;
}
