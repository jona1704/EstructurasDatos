#!/usr/bin/env python
# coding: utf-8

# In[9]:


class Nodo:
   def __init__(self, dato=None):
        self.dato = dato
        self.siguiente = None


# In[53]:


class ListaLigada:
    def __init__(self):
        self.cabecera = None
        
    def insertar_inicio(self, dato):
        nuevo = Nodo(dato)
        if self.cabecera is None:
            self.cabecera = nuevo
        else:
            nuevo.siguiente = self.cabecera
            self.cabecera = nuevo
    
    def insertar_final(self, dato):
        nuevo = Nodo(dato)
        if self.cabecera is None:
            self.cabecera = nuevo
        else:
            temp = self.cabecera
            while temp.siguiente is not None:
                temp = temp.siguiente
            temp.siguiente = nuevo
            
    def no_nodos(self):
        if self.cabecera is None:
            return 0;
        else:
            temp = self.cabecera
            cont = 0;
            while temp is not None:
                temp = temp.siguiente
                cont = cont+1
            return cont
    
    def insertar_intermedio(self, pos, dato):
        nuevo = Nodo(dato)
        noNodos = self.no_nodos()
        if (pos<-1) or (pos>noNodos+1):
            print("Posición Invalida")
            return
        elif self.cabecera is None:
            self.cabecera = nuevo
        elif (pos == 0):
            nuevo.siguiente = self.cabecera
            self.cabecera = nuevo
        else:
            temp = self.cabecera
            i = 0
            while (i<pos-1):
                temp = temp.siguiente
                i = i+1
            nuevo.siguiente = temp.siguiente
            temp.siguiente = nuevo
    
    def borrar_inicio(self):
        if self.cabecera is None:
            print("\nLista Vacia")
        else:
            temp = self.cabecera
            self.cabecera = self.cabecera.siguiente
            temp = None
    
    def borrar_final(self):
        if self.cabecera is None:
            print("\nLista Vacia")
        else:
            temp = self.cabecera
            while temp.siguiente is not None:
                prev = temp
                temp = temp.siguiente
            if temp is self.cabecera:
                self.cabecera = None
            else:
                prev.siguiente = None
            temp = None
    
    
    def borrar_intermedio(self, pos):
        if self.cabecera is None:
            print("\nLista Vacia")
        else:
            noNodos = self.no_nodos()
            if (pos<-1) or (pos>noNodos):
                print("Posición Invalida")
                return
            else:
                if (pos == 0):
                    temp = self.cabecera
                    self.cabecera = self.cabecera.siguiente
                    temp = None
                else:
                    i = 0
                    temp = self.cabecera
                    while (i<pos-1):
                        temp = temp.siguiente
                        i = i+1
                    borrado = temp.siguiente
                    temp.siguiente = borrado.siguiente
                    borrado = None
 
    def desplegar(self):
        temp = self.cabecera
        if temp is None:
            print("Lista Vacia")
        else:
            while temp is not None:
                print(str(temp.dato) + " ", end = " ")
                temp = temp.siguiente
            print("");


# In[54]:


lista = ListaLigada()
lista.insertar_inicio(3)
lista.insertar_inicio(5)
lista.insertar_inicio(4)
lista.insertar_inicio(23)
lista.insertar_inicio(18)
lista.desplegar()
lista.insertar_final(18)
lista.insertar_final(23)
lista.insertar_final(4)
lista.insertar_final(23)
lista.insertar_final(3)
lista.desplegar()
lista.insertar_intermedio(0, 29)
lista.insertar_intermedio(11, 29)
lista.insertar_intermedio(6, 29)
lista.desplegar()
n = lista.no_nodos()
print("Numero de nodos: " + str(n))
lista.borrar_inicio()
lista.borrar_inicio()
lista.borrar_inicio()
lista.desplegar()
lista.borrar_final()
lista.borrar_final()
lista.borrar_final()
lista.desplegar()
lista.borrar_intermedio(1)
lista.borrar_intermedio(5)
lista.borrar_intermedio(2)
lista.desplegar()
n = lista.no_nodos()
print("Numero de nodos: " + str(n))





