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
Nodo *lista = NULL; // crear puntero lista y se inicializa en nulo
int dato;

// prototipos
void menu();
void submenu1();
void submenu2();
void insertainicio(Nodo **, int);
void insertafinal(Nodo **, int);
void mostrasLista(Nodo *);
void sumaPar(Nodo *);
void sumaImpar(Nodo *);

int main()
{
    menu();

    cout << "\n---> Fin del algoritmo <---\n";
    cout << "\n";
    return 0;
}

// metodos a utilizar

void menu() // metodo que imprime el menu principal
{
    int opcion;

    do
    {
        cout<<endl;
        cout << "\t  ---> MENU PRINCIPAL <---";
        cout << endl <<"|-------------------------------------------|";
        cout << endl <<"|                * LISTA *                  |";
        cout << endl <<"|-------------------------------------------|";
        cout << endl << "| 1.Insertar elementos | 3.Calculos         |";
        cout << endl << "| 2.Imprimir lista     | 4.Salir del menu   |";
        cout << endl <<"|-------------------------------------------|";
        cout << "\n\nQue opcion deseas?: ";
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1:
            submenu1();
            cout << "\n";
            break;
        case 2:
            cout << "\n--> Los elementos de la lista son: \n";
            mostrasLista(lista);
            cout <<"\n\n";
            system("pause");
            break;
        case 3:
            submenu2();
            cout << "\n";
            break;
        case 4: // salir
            cout << "\n...Saliendo del programa...\n\n";
            opcion = 4;
            system("pause");
            break;
        default:
            cout << "\nLa opcion ingresada NO es valida, ingrese una nueva opcion!\n";
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 4);
}

void submenu1() // submenu de ingresar datos para llamar dentro del menu
{
    int submenu_opcion;

    do
    {
        cout << "\n";
        cout << "\t---> SUBMENU <---\n\n";
        cout << "1.Ingresar un elemento al inicio de la lista.\n";
        cout << "2.Ingresar un elemento al final de la lista.\n";
        cout << "3.Salir del SUBMENU.\n";
        cout << "\nQue opcion deseas?: ";
        cin >> submenu_opcion;
        system("cls");
        switch (submenu_opcion)
        {
        case 1:
            cout << "\n---> Para insertar al inicio.\n";
            cout << "\nDijite un numero entero: ";
            cin >> dato;
            insertainicio(&lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 2:
            cout << "\n---> Para insertar al final.\n";
            cout << "\nDijite un numero entero: ";
            cin >> dato;
            insertafinal(&lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 3:
            submenu_opcion = 3;
            cout << "\n...Saliendo del SUBMENU...\n\n";
            system("pause");
            break;
        default:
            cout << "\nLa opcion ingresada NO es valida, ingrese una nueva opcion!\n";
            system("pause");
            break;
        }
        system("cls");
    } while (submenu_opcion != 3);
}

void submenu2() // submenu para hace calculos y para llamar dentro del menu
{
    int submenu_opcion;

    do
    {
        cout << "\n";
        cout << "\t---> SUBMENU <---\n\n";
        cout << "1.Calcular e imprimir la suma de los valores que sean pares y su promedio\n";
        cout << "2.Calcular e imprimir la suma de los valores que sean impares y su promedio\n";
        cout << "3.Salir del SUBMENU.\n";
        cout << "\nQue opcion deseas?: ";
        cin >> submenu_opcion;
        switch (submenu_opcion)

        {
        case 1:
            sumaPar(lista);
            cout << "\n";
            system("pause");
            break;
        case 2:
            sumaImpar(lista);
            cout << "\n";
            system("pause");
            break;
        case 3:
            submenu_opcion = 3;
            cout << "\n...Saliendo del SUBMENU...\n\n";
            system("pause");
            break;
        default:
            cout << "\nLa opcion ingresada NO es valida, ingrese una nueva opcion!\n";
            system("pause");
            break;
        }
        system("cls");
    } while (submenu_opcion != 3);
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
    cout << "\n\tElemento " << n << " insertado al inicio de la lista!\n";
}

// insertar un elemento al final de la lista
void insertafinal(Nodo **lista, int n)
{
    Nodo *nodoInicio;
    int p;

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
    cout << "\n\tElemento " << n << " insertado al final de la lista !\n";
}

void mostrasLista(Nodo *lista) // imprime la lista
{
    Nodo *actual = new Nodo();
    actual = lista;

    while (actual != NULL)
    {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    if (lista == NULL)
    {
        cout << "\n\n\tLa lista esta vacia, NO se puede imprimir nada.\n\n";
    }
}

// suma pares
void sumaPar(Nodo *lista)
{
    int sumapar = 0;
    int contadorPar = 0;
    float promedioPar = 0;
    while (lista != NULL)
    {
        if (lista->dato % 2 == 0)
        {
            contadorPar = contadorPar + 1;
            sumapar = sumapar + lista->dato;
            lista = lista->siguiente;
        }
        else
        {
            lista = lista->siguiente;
        }
        
    }
    promedioPar = sumapar;
    promedioPar = (promedioPar / contadorPar);
    cout << "\nEl valor de sumapar es " << sumapar;
    cout << " Y el promedio de las sumas es " << promedioPar;
}

// suma impares
void sumaImpar(Nodo *lista)
{
    int sumaImpar = 0;
    int contadorImpar = 0;
    float promedioImpar = 0;
    while (lista != NULL)
    {
        if (lista->dato % 2 != 0)
        {
            contadorImpar = contadorImpar + 1;
            sumaImpar = sumaImpar + lista->dato;
            lista = lista->siguiente;
        }
        else
        {
            lista = lista->siguiente;
        }
        }
        promedioImpar = sumaImpar;
        promedioImpar = (promedioImpar / contadorImpar);
        cout << "\nEl valor de sumapar es " << sumaImpar;
        cout << " Y su promedio es " << promedioImpar;
}
