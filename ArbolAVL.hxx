#include "ArbolAVL.h"


// Constructor y destructor
template <class T>
ArbolAVL<T>::ArbolAVL()
{
    raiz = nullptr;
}

template <class T>
ArbolAVL<T>::~ArbolAVL()
{
    // Implementa la liberación de memoria de los nodos
}


// Métodos para verificar y obtener información
template <class T>
bool ArbolAVL<T>::esVacio() const
{
    return raiz == nullptr;
}

template <class T>
const T& ArbolAVL<T>::obtenerDatoRaiz() const
{
    return raiz->obtenerDato();
}

template <class T>
int ArbolAVL<T>::altura() 
{
    return Altura_arbol(raiz);
}

template <class T>
int ArbolAVL<T>::tamano() 
{
    return calcularTamano(raiz);
}


// Métodos de impresión
template <class T>
void ArbolAVL<T>::imprimirArbolGrafico()
{
    if (raiz == nullptr) {
        std::cout << "Árbol vacío" << std::endl;
        return;
    }
    
    std::cout << "Árbol AVL:" << std::endl;
    imprimirArbolGrafico(raiz, 0, "R:");
}


// Métodos de búsqueda
template <class T>
bool ArbolAVL<T>::buscar(T& val) 
{
    return buscarRecursivo(raiz, val);
}


// Métodos de recorrido
template <class T>
void ArbolAVL<T>::preOrden() 
{
    preOrdenRecursivo(raiz);
}

template <class T>
void ArbolAVL<T>::inOrden() 
{
    inOrdenRecursivo(raiz);
}

template <class T>
void ArbolAVL<T>::inordenEnLista(std::list<T> &result)
{
    inOrdenRecursivoList(raiz, result);
}
template <class T>
void ArbolAVL<T>::posOrden() 
{
    posOrdenRecursivo(raiz);
}

template <class T>
void ArbolAVL<T>::nivelOrden() 
{
    if (esVacio()) {
        return;
    }

    std::queue<NodoAVL<T>*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        NodoAVL<T>* nodo = cola.front();
        cola.pop();

        // Visitar el nodo actual
        std::cout << nodo->obtenerDato() << " ";

        // Agregar los hijos a la cola (si existen)
        if (nodo->obtenerHijoIzq() != nullptr) {
            cola.push(nodo->obtenerHijoIzq());
        }
        if (nodo->obtenerHijoDer() != nullptr) {
            cola.push(nodo->obtenerHijoDer());
        }
    }
}


// Métodos de inserción y eliminación
template <class T>
bool ArbolAVL<T>::insert(const T& dato)
{
    T copiaNoConst = dato;
    bool status = buscar(copiaNoConst);

    if(status == true)
    {
        return false;
    }

    raiz = insertarRecursivo(raiz, dato);

    return true;
}

template <class T>
bool ArbolAVL<T>::erase(const T& dato)
{
    T copiaNoConst = dato;
    bool status = buscar(copiaNoConst);

    if(status == false)
    {
        return false;
    }

    raiz = eliminarRecursivo(raiz, dato);
    
    return true;
}


// Métodos privados para operaciones internas

    // Métodos para verificar y obtener información   
    template <class T>
    int ArbolAVL<T>::Altura_arbol(NodoAVL<T>* nodo) 
    {
        if (nodo == nullptr) {
            return -1; // Árbol vacío o nodo hoja
        } else {
            int alturaIzq = calcularAltura(nodo->obtenerHijoIzq());
            int alturaDer = calcularAltura(nodo->obtenerHijoDer());
            return 1 + std::max(alturaIzq, alturaDer); // La altura es el máximo entre las alturas de los hijos más 1
        }
    }

    template <class T>
    int ArbolAVL<T>::calcularTamano(NodoAVL<T>* nodo) 
    {
        if (nodo == nullptr) {
            return 0; // Árbol vacío
        } else {
            int tamanoIzq = calcularTamano(nodo->obtenerHijoIzq());
            int tamanoDer = calcularTamano(nodo->obtenerHijoDer());
            return 1 + tamanoIzq + tamanoDer; // El tamaño es 1 (el nodo actual) más los tamaños de los subárboles izquierdo y derecho
        }
    }


    // Métodos de impresión
    template <class T>
    void ArbolAVL<T>::imprimirArbolGrafico(NodoAVL<T>* nodo, int nivel, const std::string& prefijo)
    {
        if (nodo == nullptr) {
            return;
        }

        const int espaciado = 4;

        imprimirArbolGrafico(nodo->obtenerHijoDer(), nivel + 1, "D:");
        std::cout << std::string(espaciado * nivel, ' ') << prefijo << nodo->obtenerDato() << std::endl;
        imprimirArbolGrafico(nodo->obtenerHijoIzq(), nivel + 1, "I:");
    }


    // Métodos de búsqueda
    template <class T>
    bool ArbolAVL<T>::buscarRecursivo(NodoAVL<T>* nodo, T& val) 
    {
        if (nodo == nullptr) {
            return false; // El valor no se encontró en el árbol
        }

        if (val == nodo->obtenerDato()) {
            return true; // El valor se encontró en el nodo actual
        } else if (val < nodo->obtenerDato()) {
            // Si el valor es menor, buscar en el subárbol izquierdo
            return buscarRecursivo(nodo->obtenerHijoIzq(), val);
        } else {
            // Si el valor es mayor, buscar en el subárbol derecho
            return buscarRecursivo(nodo->obtenerHijoDer(), val);
        }
    }


    // Métodos de recorrido
    template <class T>
    void ArbolAVL<T>::preOrdenRecursivo(NodoAVL<T>* nodo) 
    {
        if (nodo != nullptr) {
            // Visitar el nodo actual
            std::cout << nodo->obtenerDato() << " ";
            // Recorrer el subárbol izquierdo
            preOrdenRecursivo(nodo->obtenerHijoIzq());
            // Recorrer el subárbol derecho
            preOrdenRecursivo(nodo->obtenerHijoDer());
        }
    }

    template <class T>
    void ArbolAVL<T>::inOrdenRecursivo(NodoAVL<T>* nodo) 
    {
        if (nodo != nullptr) {
            // Recorrer el subárbol izquierdo
            inOrdenRecursivo(nodo->obtenerHijoIzq());
            // Visitar el nodo actual
            std::cout << nodo->obtenerDato() << endl;
            // Recorrer el subárbol derecho
            inOrdenRecursivo(nodo->obtenerHijoDer());
        }
    }
    
    template <class T>
    void ArbolAVL<T>::inOrdenRecursivoList(NodoAVL<T>* nodo, std::list<T> &result) 
    {
        if (nodo != nullptr) {
            // Recorrer el subárbol izquierdo
            inOrdenRecursivoList(nodo->obtenerHijoIzq(), result);
            // Visitar el nodo actual
            result.push_back(nodo->obtenerDato());
            // Recorrer el subárbol derecho
            inOrdenRecursivoList(nodo->obtenerHijoDer(), result);
        }
    }

    template <class T>
    void ArbolAVL<T>::posOrdenRecursivo(NodoAVL<T>* nodo) 
{
    if (nodo != nullptr) {
        // Recorrer el subárbol izquierdo
        posOrdenRecursivo(nodo->obtenerHijoIzq());
        // Recorrer el subárbol derecho
        posOrdenRecursivo(nodo->obtenerHijoDer());
        // Visitar el nodo actual
        std::cout << nodo->obtenerDato() << " ";
    }
}


    // Métodos de inserción y eliminación
    template <class T>
    NodoAVL<T>* ArbolAVL<T>::insertarRecursivo(NodoAVL<T>* nodo, const T& dato)
    {
        if (nodo == nullptr) {
            NodoAVL<T>* nuevoNodo = new NodoAVL<T>();
            nuevoNodo->fijarDato(dato);
            return nuevoNodo;
        }

        if (dato < nodo->obtenerDato()) {
            nodo->fijarHijoIzq(insertarRecursivo(nodo->obtenerHijoIzq(), dato));
        } else if (dato > nodo->obtenerDato()) {
            nodo->fijarHijoDer(insertarRecursivo(nodo->obtenerHijoDer(), dato));
        } else {
            // El dato ya existe en el árbol, no permitimos duplicados.
            return nodo;
        }

        // Actualizar la altura del nodo actual
        nodo->actualizarAltura();

        // Realizar el balanceo
        balancear(nodo);

        return nodo;
    }

    template <class T>
    NodoAVL<T>* ArbolAVL<T>::eliminarRecursivo(NodoAVL<T>* nodo, const T& dato)
    {
        if (nodo == nullptr) {
            return nodo;
        }

        if (dato < nodo->obtenerDato()) {
            nodo->fijarHijoIzq(eliminarRecursivo(nodo->obtenerHijoIzq(), dato));
        } else if (dato > nodo->obtenerDato()) {
            nodo->fijarHijoDer(eliminarRecursivo(nodo->obtenerHijoDer(), dato));
        } else {
            // Encontramos el nodo que contiene el dato a eliminar
            if (nodo->obtenerHijoIzq() == nullptr || nodo->obtenerHijoDer() == nullptr) {
                NodoAVL<T>* temp = nodo->obtenerHijoIzq() ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();
                if (temp == nullptr) {
                    // Caso 1: Nodo con 0 o 1 hijo
                    temp = nodo;
                    nodo = nullptr;
                } else {
                    // Caso 2: Nodo con 1 hijo
                    *nodo = *temp; // Copiamos el contenido del hijo no nulo al nodo actual
                }
                delete temp;
            } else {
                // Caso 3: Nodo con 2 hijos, encontramos el sucesor inorden
                NodoAVL<T>* sucesor = nodo->obtenerHijoDer();
                while (sucesor->obtenerHijoIzq() != nullptr) {
                    sucesor = sucesor->obtenerHijoIzq();
                }
                nodo->fijarDato(sucesor->obtenerDato());
                nodo->fijarHijoDer(eliminarRecursivo(nodo->obtenerHijoDer(), sucesor->obtenerDato()));
            }
        }

        if (nodo == nullptr) {
            return nodo;
        }

        // Actualizar la altura del nodo actual
        nodo->actualizarAltura();

        // Realizar el balanceo
        balancear(nodo);

        return nodo;
    }

    template <class T>
    void ArbolAVL<T>::balancear(NodoAVL<T>*& nodo)
    {
        int factorEquilibrio = calcularFactorEquilibrio(nodo);

        // Caso izquierda-izquierda
        if (factorEquilibrio > 1 && calcularFactorEquilibrio(nodo->obtenerHijoIzq()) >= 0) {
            nodo = rotacionDerecha(nodo);
        }

        // Caso derecha-derecha
        if (factorEquilibrio < -1 && calcularFactorEquilibrio(nodo->obtenerHijoDer()) <= 0) {
            nodo = rotacionIzquierda(nodo);
        }

        // Caso izquierda-derecha
        if (factorEquilibrio > 1 && calcularFactorEquilibrio(nodo->obtenerHijoIzq()) < 0) {
            nodo->fijarHijoIzq(rotacionIzquierda(nodo->obtenerHijoIzq()));
            nodo = rotacionDerecha(nodo);
        }

        // Caso derecha-izquierda
        if (factorEquilibrio < -1 && calcularFactorEquilibrio(nodo->obtenerHijoDer()) > 0) {
            nodo->fijarHijoDer(rotacionDerecha(nodo->obtenerHijoDer()));
            nodo = rotacionIzquierda(nodo);
        }
    }

    template <class T>
    int ArbolAVL<T>::calcularAltura(NodoAVL<T>* nodo) const
    {
        if (nodo == nullptr) {
            return 0;
        }
        return nodo->obtenerAltura();
    }

    template <class T>
    int ArbolAVL<T>::calcularFactorEquilibrio(NodoAVL<T>* nodo) const
    {
        if (nodo == nullptr) {
            return 0;
        }
        return calcularAltura(nodo->obtenerHijoIzq()) - calcularAltura(nodo->obtenerHijoDer());
    }

    template <class T>
    NodoAVL<T>* ArbolAVL<T>::rotacionDerecha(NodoAVL<T>* nodo)
    {
        NodoAVL<T>* nuevoPadre = nodo->obtenerHijoIzq();
        NodoAVL<T>* temp = nuevoPadre->obtenerHijoDer();

        nuevoPadre->fijarHijoDer(nodo);
        nodo->fijarHijoIzq(temp);

        nodo->actualizarAltura();
        nuevoPadre->actualizarAltura();

        return nuevoPadre;
    }

    template <class T>
    NodoAVL<T>* ArbolAVL<T>::rotacionIzquierda(NodoAVL<T>* nodo)
    {
        NodoAVL<T>* nuevoPadre = nodo->obtenerHijoDer();
        NodoAVL<T>* temp = nuevoPadre->obtenerHijoIzq();

        nuevoPadre->fijarHijoIzq(nodo);
        nodo->fijarHijoDer(temp);

        nodo->actualizarAltura();
        nuevoPadre->actualizarAltura();

        return nuevoPadre;
    }

    template <class T>
    NodoAVL<T>* ArbolAVL<T>::rotacionDerechaIzquierda(NodoAVL<T>* nodo)
    {
        nodo->fijarHijoIzq(rotacionIzquierda(nodo->obtenerHijoIzq()));
        return rotacionDerecha(nodo);
    }

    template <class T>
    NodoAVL<T>* ArbolAVL<T>::rotacionIzquierdaDerecha(NodoAVL<T>* nodo)
    {
        nodo->fijarHijoDer(rotacionDerecha(nodo->obtenerHijoDer()));
        return rotacionIzquierda(nodo);
    }
