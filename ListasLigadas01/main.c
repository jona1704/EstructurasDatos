#include "lista.h"

/* Para definir un nodo en C 
   necesitamos una estructura 
   autoreferenciada */
   
/* Recordar: Lo siguiente no es valido: */
/*struct ejemplo{
	int x;
	struct ejemplo y;
};*/

/* Recordar: Lo siguiente SI es valido: */
/*struct ejemplo{
	int x;
	struct ejemplo * y;
}; // Estructura Autoreferenciada*/


int main(int argc, char *argv[]) {
	// Listas ligadas con memoria dinamica
	// Nodos se construyen con memoria dinamica
	/*Nodo * n1 = (Nodo *) malloc(sizeof(Nodo));
	assert(n1 != NULL);
	n1->dato = 9;
	n1->siguiente = NULL; // Inicialmente siguiente siempre apunta a NULL
	
	Nodo * n2 = (Nodo *) malloc(sizeof(Nodo));
	assert(n2 != NULL);
	n2->dato = 5;
	n2->siguiente = NULL; // Inicialmente siguiente siempre apunta a NULL
	
	Nodo * n3 = (Nodo *) malloc(sizeof(Nodo));
	assert(n3 != NULL);
	n3->dato = 3;
	n3->siguiente = NULL; // Inicialmente siguiente siempre apunta a NULL
	
	// Conectar nodos
	n1->siguiente = n2;
	n2->siguiente = n3;
	
	// En una lista ligada existe un nodo especial al que vamos a llamar head o cabecera
	// La cabecera debe de apuntar siempre al primer nodo
	Nodo * cabecera = n1; // Cabecera es una copia del primer nodo
	//n4 = n3;
	
	// Reglas: La cabecera siempre debe apuntar al primer nodo de la lista
	
	// La cabecera nunca debe perder la referencia al primer nodo
	// Vamos a emplear otra variable auxiliar (temp)
	Nodo * temp = cabecera;
	while(temp != NULL){
		printf("%d ", temp->dato);
		temp = temp->siguiente;
	}
	
	// Destruir nodos
	free(n1);
	free(n2);
	free(n3); */
	
	Nodo * n1 = crearNodo(9);
	Nodo * n2 = crearNodo(5);
	Nodo * n3 = crearNodo(3);
	
	// Conectar nodos
	n1->siguiente = n2;
	n2->siguiente = n3;
	// Declaramos la cabecera
	Nodo * cabecera = n1;
	// Insertar nuevos nodos
	cabecera = insertar_inicio(cabecera, 8);
	cabecera = insertar_inicio(cabecera, 9);
	
	desplegar(cabecera);
	
	destruir(n1);
	destruir(n2);
	destruir(n3);
	
	return 0;
}
