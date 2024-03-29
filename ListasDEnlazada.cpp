#include <iostream>

using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

// Variable global, donde se establece que la lista esta vacia
struct Nodo *lista = nullptr;

// Declaración de funciones
void InsertarInicio(int);
void InsertarFinal(int);
void InsertarIntermedio(int, int);
void Imprimir();
void EliminarInicio();
void EliminarFinal();
void EliminarIntermedio(int);
void EliminarNodo(int);
void Eliminar(int);

int main()
{

    InsertarInicio(45);
    InsertarInicio(15);
    InsertarInicio(78);
    InsertarInicio(1);
    InsertarFinal(100);
    InsertarFinal(101);
    InsertarFinal(103);
    InsertarIntermedio(500, 4);
    Imprimir(); // 1 78 500 15 45 100
    cout << "-------------------" << endl;
    // EliminarFinal();
    EliminarNodo(500);
    Imprimir();

    return 0;
}

// Insertar nodos al inicio de la lista
void InsertarInicio(int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal = lista;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    // Si la lista esta vacia
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // conexion del nuevo nodo con la lista
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        // asignar el nuevonodo a la cabeza de la lista
        lista = nuevoNodo;
    }
}

// Insertar nodos al final de la lista
void InsertarFinal(int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal = lista;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    // Si la lista esta vacia
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        // conexiones de nuevonodo a temporal
        temporal->siguiente = nuevoNodo;
        nuevoNodo->anterior = temporal;
    }
}

// Insertar intermedio
void InsertarIntermedio(int n, int posicion)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    // Conexiones del nuevoNodo con la lista
    temporal2 = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
    temporal2->anterior = nuevoNodo;
    nuevoNodo->siguiente = temporal2;
    nuevoNodo->anterior = temporal;
}

// Borrar el primer nodo de la lista
void EliminarInicio()
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        if (temporal->siguiente != nullptr)
        {
            lista = lista->siguiente;
            delete temporal;
            temporal = nullptr;
            lista->anterior = nullptr;
        }
        else
        {
            delete lista;
            lista = nullptr;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}

// Borrar el ultimo nodo de la lista
void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        if (temporal->siguiente != nullptr)
        {
            while (temporal->siguiente != nullptr)
            {
                temporal = temporal->siguiente;
            }

            temporal2 = temporal->anterior;
            temporal2->siguiente = nullptr;
            delete temporal;
            temporal = nullptr;
        }
        else
        {
            delete lista;
            lista = nullptr;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}

void EliminarIntermedio(int posicion)
{
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    struct Nodo *temporal3;
    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        temporal3 = temporal->siguiente;
        posicion--;
    }
    // Conexiones del nuevoNodo con la lista
    temporal2->siguiente = temporal3;
    temporal3->anterior = temporal2;
    delete temporal;
    temporal = nullptr;
}

void Eliminar(int pos) {
    struct Nodo *aux = lista;
    int i = 1;
    while (aux != nullptr && i < pos) {
        aux = aux->siguiente;
        i++;
    }
    if (aux != nullptr) {
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        delete aux;
    } else {
        cout << "No se encontro";
    }
}

void EliminarNodo(int val) {
    struct Nodo *aux = lista;
    while (aux != nullptr && aux->elemento != val) {
        aux = aux->siguiente;
    }

    if (aux != nullptr) {
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        delete aux;
    } else {
        cout << "No se encontro";
    }
}


void Imprimir()
{
    struct Nodo *temporal = lista;
    if (temporal != nullptr)
    {
        // Imprimir cuando se inserta al final de la lista
        while (temporal != nullptr)
        {
            cout << "Lista " << temporal->elemento << " Direccion " << temporal << " Dir siguiente " << temporal->siguiente << " Dir anterior " << temporal->anterior << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}
