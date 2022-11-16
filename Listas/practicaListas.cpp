#include <iostream>
#include <conio.h>  //sirve para usar un getch();
#include <stdlib.h> //sirve para usar system("cls"); o sea limpia pantalla clearscreen
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente; // puntero siguiente
};

// variables globales
Nodo *lista = NULL; // crear puntero lista
int dato;

// Prototipos de Funciones
void menu();
void insertainicio(Nodo **, int);
void insertafinal(Nodo **, int);
void insertarNuevaLista(Nodo *&, int);
void mostrasLista(Nodo *);
void buscarLista(Nodo *, int);
void eliminarNodo(Nodo *&, int);
void eliminarLista(Nodo *&, int &);
void calcularMayorMenor(Nodo *);
int suma(Nodo *);

int main()
{
    menu();

    cout << "\n---> Fin del algoritmo <---\n";
    cout << "\n";
    return 0;
}

// metodos a utilizar
void menu()
{
    int opcion;

    do
    {
        cout << "\n";
        cout << "\t---> MENU <---\n";
        cout << "1.Ingresar un elemento al principio de la lista\n";
        cout << "2.Ingresar un elemento al final de la lista\n";
        cout << "3.Insertar nuevos elementos a la lista, para ordenarlos correctamente \n";
        cout << "4.Mostrar los elementos de la lista\n";
        cout << "5.Buscar un elemento en lista\n";
        cout << "6.Eliminar un elemento de la lista\n";
        cout << "7.Eliminar todos los elementos de la lista, dejarla vacia\n";
        cout << "8.Mostrar el numero mayor y el menor de la lista\n";
        cout << "9.Imprimir la suma de todos los elementos de la lista\n";
        cout << "10.Salir del menu\n";
        cout << "\nQue opcion deseas?: ";

        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "\n---> Para insertar al inicio\n";
            cout << "\nDijite un numero entero: ";
            cin >> dato;
            insertainicio(&lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 2:
            cout << "\nDigite un numero para insertar al final: ";
            cin >> dato;
            insertafinal(&lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout << "Los nuevos elementos ingresados a la lista se acomodaran de menor a mayor, se recomienda borrar toda la lista anterior primero.\n";
            cout << "\nDijite un numero para agregar a la lista: ";
            cin >> dato;
            insertarNuevaLista(lista, dato); // se le pasan el puntero(lista) y dato nuevo
            cout << "\n";
            system("pause");
            break;
        case 4:
            cout << "\n--> Los elementos de la lista son: \n";
            mostrasLista(lista);
            cout << "\n\n";
            system("pause");
            break;
        case 5:
            cout << "\nQue numero deseas buscar en la lista?: ";
            cin >> dato;
            buscarLista(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 6:
            cout << "\nCual elemento de la lista deseas eliminar?: "; // puede dar error porque si uso las primeras 2 opcione para generar la lista no la puedo eliminar
            // porque los datos para eliminar se tiene que generar con la tercera opcion(osea datos ordenados)
            cin >> dato;
            eliminarNodo(lista, dato);
            cout << "\n\tEl elemento " << dato << " ha sido eliminado correctamente.\n";
            cout << "\n";
            system("pause");
            break;
        case 7:
            while (lista != NULL)
            { // mientras no sea el final de la lista, siga sacando todos los elementos
                eliminarLista(lista, dato);
                cout << dato << " -> ";
            }
            cout << "\n";
            system("pause");
            break;
        case 8:
            calcularMayorMenor(lista);
            cout << "\n";
            system("pause");
            break;
        case 9:
            int suma(Nodo * lista);
            cout << "\nLa suma de la lista es: " << suma(lista);
            cout << endl;
            cout << "\n";
            system("pause");
            break;

        case 10: // salir
            cout << "\nSaliendo del programa...\n";
            opcion = 10;
            system("pause");
            break;
        default:
            cout << "\nLa opcion ingresada NO es valida, ingrese una nueva opcion!\n";
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 10);
}

// insertar solamente al principio de la lista
void insertainicio(Nodo **lista, int n)
{
    Nodo *nodoInicio;
    nodoInicio = (Nodo *)malloc(sizeof(Nodo));
    nodoInicio->dato = n;
    nodoInicio->siguiente = NULL;

    if (*lista == NULL) // si no hay nodos
        *lista = nodoInicio;
    else
    {
        nodoInicio->siguiente = *lista; // si hay nodos lo conecto al primero
        *lista = nodoInicio;
    }
    cout << "\tElemento " << n << " insertado al inicio de la lista!\n";
}
// insertar un elemento al final de la lista
void insertafinal(Nodo **lista, int n)
{
    Nodo *nodoInicio;
    int k;

    nodoInicio = (Nodo *)malloc(sizeof(Nodo));
    nodoInicio->dato = n;
    nodoInicio->siguiente = NULL;

    if (*lista == NULL)
        *lista = nodoInicio;
    else
    {
        Nodo *p;
        p = *lista;
        // ciclo para llegar al final de la lista
        while (p->siguiente != NULL)
        {
            p = p->siguiente;
        }
        p->siguiente = nodoInicio; // conecto el �ltimo nodo al nuevo
    }
    cout << "\tElemento " << n << " insertado al final de la lista !\n";
}

void insertarNuevaLista(Nodo *&lista, int n) // insertar elementos en una nueva lista para que se ordenen de menor a mayor
{
    Nodo *nuevo_nodo = new Nodo(); // se crea un nuevo nodo y se reseva memoria de tipo nodo
    nuevo_nodo->dato = n;          // En el nuevo nodo en su parte dato, se le asigna el valor de n

    // ahora se crean auxiliares
    Nodo *aux1 = lista;
    Nodo *aux2; // cuando entramos al while este hace que nuestras lista quede ordenada

    while ((aux1 != NULL) && (aux1->dato < n))
    { // mientras que la lista no haya llegado a su fin y si el elemento que se va a insertar se va a insertar de forma ordenada o no
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1)
    { // para saber si se ingresa el elemento al principi, en medio o al final
        lista = nuevo_nodo;
    }
    else
    {
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1; // esto acomoda la lista de menor a mayor
    cout << "\n";
    cout << "\tElemento " << n << " insertado correctamente.\n";
}

// para mostrar cada elemento de la lista ordenado (se ordeno previamente en insertar lista) o se usa el metodo de insertar inicio y final, pero se imprime desordenado
void mostrasLista(Nodo *lista)
{
    Nodo *actual = new Nodo();
    actual = lista;

    while (actual != NULL)
    {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
}
// buscar un elemento en la lista
void buscarLista(Nodo *lista, int n)
{
    bool bandera = false;
    Nodo *actual = new Nodo();
    actual = lista;

    while ((actual != NULL) && (actual->dato <= n))
    {
        if (actual->dato == n)
        {
            bandera = true;
        }
        actual = actual->siguiente;
    }
    if (bandera == true)
    {
        cout << "\nElemento " << n << " SI ha sido encontrado en la lista. \n";
    }
    else
    {
        cout << "El elemento " << n << " NO ha sido encontrado en la lista.\n";
    }
}
// para eliminar un elemento de una lista sea el primero, el del medio o ultimo
void eliminarNodo(Nodo *&lista, int n)
{
    // primer paso preguntar si la lista No está vacia
    if (lista != NULL)
    {
        // se crean dos punteros
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;

        // para recorrer la lista se utiliza un while
        while ((aux_borrar != NULL) && (aux_borrar->dato != n))
        { // se entra e el while si todo esto se cumple
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }

        // el elemento no fue encontrado
        if (aux_borrar == NULL)
        {
            cout << "\nElemento NO encontrado en la lista.\n";
        }
        // El primer elemento es el que vamos a eliminar.
        else if (anterior == NULL)
        {
            lista = lista->siguiente;
            delete aux_borrar;
        }
        // El elemento está en la lista pero no está de primero.
        else
        {
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}
// eliminar todos los elementos de la lista
void eliminarLista(Nodo *&lista, int &n)
{
    Nodo *aux = lista;
    n = aux->dato;
    lista = aux->siguiente;
    delete aux;
} // calcular el elemento mayor y menor de la lista
void calcularMayorMenor(Nodo *lista)
{
    int mayor = 0, menor = 9999;
    while (lista != NULL)
    { // recorre la lsita
        if ((lista->dato) > mayor)
        { // calculando el elemento
            mayor = lista->dato;
        }
        if ((lista->dato) < menor)
        { // calcula el elemento menor de la lista
            menor = lista->dato;
        }
        lista = lista->siguiente; // avanzamos una posicion de la lista
    }
    cout << "\nEl mayor elemento es: " << mayor << endl;
    cout << "El menor elemento es: " << menor << endl;
}
int suma(Nodo *lista)
{
    int s = 0;
    while (lista != NULL)
    {
        s = s + lista->dato;
        lista = lista->siguiente;
    }
    return s;
}
