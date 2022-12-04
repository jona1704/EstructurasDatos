#!/usr/bin/env python
# coding: utf-8

# In[8]:


class Info:
    def __init__(self,nombre=None, edad=None, calf=None):
        self.nombre = nombre
        self.edad = edad
        self.calf = calf


# In[9]:


class Nodo:
   def __init__(self, dato=None):
        self.dato = dato
        self.siguiente = None


# In[16]:


class ListaLigada:
    def __init__(self):
        self.cabecera = None

    def getInfo(self):
        _nombre = input("Ingrese el nombre del Alumno: ")
        _edad = input("Ingrese la edad del Alumno: ")
        _calf = input("Ingrese la calificacion del Alumno: ")
        info = Info(_nombre, _edad, _calf)
        return info
        
        
    def insertar_inicio(self):
        dato = self.getInfo()
        nuevo = Nodo(dato)
        if self.cabecera is None:
            self.cabecera = nuevo
        else:
            nuevo.siguiente = self.cabecera
            self.cabecera = nuevo
    
    def insertar_final(self):
        dato = self.getInfo()
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
    
    def insertar_intermedio(self, pos):
        dato = self.getInfo()
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
            print("")
            while temp is not None:
                print("Nombre: " + str(temp.dato.nombre) + " ")
                print("Edad: " + str(temp.dato.edad) + " ")
                print("Calificación: " + str(temp.dato.calf) + " ")
                print("")
                temp = temp.siguiente
            print("");


# In[18]:


lista = ListaLigada()
lista.insertar_inicio()
lista.insertar_inicio()
lista.insertar_final()
lista.insertar_final()
lista.insertar_final()
lista.insertar_intermedio(1)
lista.insertar_intermedio(4)
lista.desplegar()
n = lista.no_nodos()
print("Numero de nodos: " + str(n))
lista.borrar_inicio()
lista.borrar_final()
lista.borrar_intermedio(2)
lista.desplegar()
n = lista.no_nodos()
print("Numero de nodos: " + str(n))






