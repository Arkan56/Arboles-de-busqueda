#ifndef NodoAVL_H
#define NodoAVL_H

#include <iostream>
using namespace std;

template <class T>
class NodoAVL
{
protected:
    T dato;                   // Dato almacenado en el nodo
    NodoAVL<T> *hijoIzq;     // Puntero al hijo izquierdo
    NodoAVL<T> *hijoDer;     // Puntero al hijo derecho
    int altura;              // Altura del subárbol con raíz en este nodo

public:
    // Constructor
    NodoAVL();

    // Destructor
    ~NodoAVL();

    // Métodos para establecer y obtener el dato del nodo

    // Establece el valor de dato en el nodo.
    void fijarDato(const T& dato);

    // Obtiene el valor almacenado en el nodo.
    const T& obtenerDato() const;

    // Métodos para establecer y obtener los hijos del nodo

    // Obtiene el puntero al hijo izquierdo del nodo.
    NodoAVL<T>* obtenerHijoIzq();

    // Obtiene el puntero al hijo derecho del nodo.
    NodoAVL<T>* obtenerHijoDer();

    // Establece el puntero al hijo izquierdo del nodo.
    void fijarHijoIzq(NodoAVL<T>* nodo);

    // Establece el puntero al hijo derecho del nodo.
    void fijarHijoDer(NodoAVL<T>* nodo);

    // Métodos para obtener y actualizar la altura del nodo

    // Obtiene la altura del nodo.
    int obtenerAltura() const;

    // Actualiza la altura del nodo en función de la altura de sus hijos.
    void actualizarAltura();
};

#include "NodoAVL.hxx"

#endif
