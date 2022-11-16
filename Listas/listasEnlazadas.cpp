#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h> //esta libreria se usa para el new Nodo
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};
// prototipo de funciones
void menu();
void insertar_lista(Nodo *&, int);
void mostrar_lista(Nodo *);
void buscar_lista(Nodo *, int);
void eliminar_nodo(Nodo *&, int);

Nodo *lista = NULL;

int main()
{
    menu();
    getch();
    return 0;
}
void menu()
{
    int opcion;
    int dato;

    do
    {
        cout << "\t. : MENU: \n";
        cout << "1. Insertar elementos en lista\n";
        cout << "2. Mostrar elementos de la lista\n";
        cout << "3. Buscar un elemento en la lista\n";
        cout << "4. Eliminar un nodo de la lista\n";
        cout << "5. salir \n";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Digite un numero: ";
            cin >> dato;
            insertar_lista(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 2:
            mostrar_lista(lista);
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout << "Digite un numero a buscar:  ";
            cin >> dato;
            buscar_lista(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 4:
            cout << "/nDigite el elemento que decea eliminar";
            cin >> dato;
            eliminar_nodo(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 5:
            opcion = 5;
            break;
        }
        system("cls");

    } while (opcion != 5);
}
void insertar_lista(Nodo *&lista, int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;
    while ((aux1 != NULL) && (aux1->dato < n))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;

    cout << "\tElemento  " << n << "insertado a lista correctamente\n";
}
void mostrar_lista(Nodo *lista)
{
    Nodo *actual = new Nodo();
    actual = lista;

    while (actual != NULL)
    {
        cout << actual->dato << "->";
        actual = actual->siguiente;
    }
}
void buscar_lista(Nodo *lista, int n)
{
    bool band = false;
    Nodo *actual = new Nodo();
    actual = lista;

    while ((actual != NULL) && (actual->dato <= n))
    {
        if (actual->dato == n)
        {
            band = true;
        }
        actual = actual->siguiente;
    }
    if (band == true)
    {
        cout << "Elemento  " << n << "si ha sido encontradoen en lista\n";
    }
    else
    {
        cout << "Elemento  " << n << "no ha sido encontrado en lista\n";
    }
}
void eliminar_nodo(Nodo *&lista, int n)
{
    // preguntar si la lista esta vacia
    if (lista != NULL)
    {
        Nodo *aux_borrar;
        Nodo *aux_anterior = NULL;

        aux_borrar = lista;

        // recorrer lista
        while ((aux_borrar != NULL) && (aux_borrar->dato != n))
        {
            aux_anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        // si el elemento no ha sido encontrado
        if (aux_borrar == NULL)
        {
            cout << "El elemento no ha sido encontrado";
        }
        // El primer elemento es el que vamos a eliminar
        else if (aux_anterior == NULL)
        {
            lista = lista->siguiente;
            delete aux_borrar;
        }
        // el elemento esta en la lista, pero no es el primer nodo
        else
        {
            aux_anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}