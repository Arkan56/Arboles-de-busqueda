#include "NodoAVL.h"

// Constructor de NodoAVL
template <class T>
NodoAVL<T>::NodoAVL()
{
    hijoIzq = nullptr;
    hijoDer = nullptr;
    altura = 1; // Inicialmente, la altura es 1 para el nodo recién creado
}

// Destructor de NodoAVL (vacío ya que no se necesita realizar ninguna acción especial en la destrucción)
template <class T>
NodoAVL<T>::~NodoAVL()
{

}

// Método para obtener el dato almacenado en el nodo
template <class T>
const T& NodoAVL<T>::obtenerDato() const
{
    return dato;
}

// Método para establecer el dato en el nodo
template <class T>
void NodoAVL<T>::fijarDato(const T& dato)
{
    this->dato = dato;
}

// Método para obtener el puntero al hijo izquierdo del nodo
template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoIzq()
{
    return hijoIzq;
}

// Método para obtener el puntero al hijo derecho del nodo
template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoDer()
{
    return hijoDer;
}

// Método para establecer el puntero al hijo izquierdo del nodo
template <class T>
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T>* nodo)
{
    hijoIzq = nodo;
}

// Método para establecer el puntero al hijo derecho del nodo
template <class T>
void NodoAVL<T>::fijarHijoDer(NodoAVL<T>* nodo)
{
    hijoDer = nodo;
}

// Método para obtener la altura del nodo
template <class T>
int NodoAVL<T>::obtenerAltura() const {
    return altura;
}

// Método para actualizar la altura del nodo en función de la altura de sus hijos
template <class T>
void NodoAVL<T>::actualizarAltura() {
    int alturaIzq = (hijoIzq != nullptr) ? hijoIzq->obtenerAltura() : 0;
    int alturaDer = (hijoDer != nullptr) ? hijoDer->obtenerAltura() : 0;
    altura = 1 + max(alturaIzq, alturaDer);
}
