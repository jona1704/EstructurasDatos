#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int suma(int a, int b){
	return a+b;
}

int resta(int a, int b){
	return a-b;
}

int mult(int a, int b){
	return a*b;
}

void puede_cambiar(int * a, int *b){
	a = b;
	printf("\nValor de x = %x", a);
}


void cambiar(int ** a, int *b){
	*a = b;
	printf("\nValor de x = %x", a);
}



int main(int argc, char *argv[]) {
	
	// Crear cadenas estaticamente
	/*char * arr[] = {"Uno", "Dos", "Tres", "Cuatro"};
	int i;
	for(i=0; i<4; i++){
		printf("\n%s", arr[i]);
	}
	
	for(i=0; i<4; i++){
		printf("\n%s", *(arr+i) );
	}*/
	
	// Crear cadenas dinamicamente
	/*char * arr_nuevo[4];
	char buffer[100];
	int i;
	for(i=0; i<4; i++){
		printf("Ingresa valor %d", i+1);
		scanf("%s", buffer);
		arr_nuevo[i] = (char*) malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(arr_nuevo[i], buffer);
	}
	
	for(i=0; i<4; i++){
		printf("\n%s", *(arr_nuevo+i) );
	}*/
	
	// Apuntador a funciones
	/*int(*fun_ptr_arr[])(int, int) = {suma, resta, mult};
	int a = 5;
	int b = 6;
	printf("El resultado es: %d", (*fun_ptr_arr[2])(a,b));*/
	
	// Apuntador a apuntador
	int a = 1;
	int b = 3;
	int c = 4;
	int * x = &a;
	int * y = &b;
	int * z = &c;
	int **p = &x;
	printf("\nDireccion de a: %x", &a);
	printf("\nDireccion de x: %x", x);
	printf("\nDireccion de x: %d", *x);
	printf("\nDireccion de z: %x", z);
	puede_cambiar(x, z);
	printf("\nDireccion de x: %x", x);
	cambiar(p, z);
	printf("\nDireccion de x: %x", x);
	
	printf("\n\n**p: %d", **p);
	printf("\n\n*p: %x", *p);
	printf("\n\np: %x", p);
	
	
}
	

