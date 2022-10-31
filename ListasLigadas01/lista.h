// Interfaz

// Definir un nodo
struct nodo{
	int dato;
	struct nodo * siguiente;
};

typedef struct nodo Nodo;

Nodo * crearNodo(int); // Apuntador a nodo porque se crea con memoria dinamica
Nodo * insertar_inicio(Nodo *, int dato);
void desplegar(Nodo *);
void destruir(Nodo *);
