#include <iostream>
#include <conio.h>  //sirve para usar un getch();
#include <stdlib.h> //sirve para usar system("cls"); o sea limpia pantalla clearscreen
using namespace std;

struct Nodo //se llama la estructura para crear nodos
{
    int dato;
    Nodo *siguiente; // puntero siguiente
};

// variables globales
Nodo *lista = NULL; // crear puntero lista
int dato;

// Prototipos de Funciones
void menu();
void submenu1();
void submenu2();
void insertainicio(Nodo **, int);
void insertafinal(Nodo **, int);
void mostrasLista(Nodo *);
void eliminarNodo(Nodo *&, int);
void calcularMayorMenor(Nodo *);
int suma(Nodo *);

int main()
{
    menu();

    cout << "\n---> Fin del algoritmo <---\n";//mensaje final
    cout << "\n";
    return 0;
}

// metodos a utilizar
void menu() //menu principal
{
    int opcion;

    do
    {
        cout << "\n";
        cout << "\t---> MENU <---\n";
        cout << "1.Insertar elementos\n";
        cout << "2.Eliminar un elemento de la lista\n";
        cout << "3.Imprimir la lista\n";
        cout << "4.Calculos\n";
        cout << "5.Salir del menu\n";
        cout << "\nQue opcion deseas?: ";

        cin >> opcion;//guarda la opcion seleccionada por el usuario
        switch (opcion)
        {
        case 1:
            submenu1();//llama al metodo submenu1
            cout << "\n";
            break;
        case 2://elimina el elemento selecionado por el usuario de la lista.
            cout << "\nCual elemento de la lista deseas eliminar?: "; // puede dar error porque si uso las primeras 2 opcione para generar la lista no la puedo eliminar
            // porque los datos para eliminar se tiene que generar con la tercera opcion(osea datos ordenados)
            cin >> dato;
            eliminarNodo(lista, dato);
            cout << "\n";
            system("pause");
            break;
        case 3://imprime cada elemento de la lista
            cout << "\n--> Los elementos de la lista son: \n";
            mostrasLista(lista);
            cout << "\n\n";
            system("pause");
            break;
        case 4://llama al submenu2
            submenu2();
            cout << "\n";
            break;
        case 5: // salir
            cout << "\nSaliendo del programa...\n";
            opcion = 5;
            system("pause");
            break;
        default://si la opcion igresada no esta dentro del rango [1 - 5]: imprime el mensaje
            cout << "\nLa opcion ingresada NO es valida, ingrese una nueva opcion!\n";
            system("pause");
            break;
        }
        system("cls");//limpia la terminal
    } while (opcion != 5);
}
void submenu1() // submenu de ingresar datos para llamar dentro del menu
{
    system("cls");
    int submenu_opcion;

    do
    {
        cout << "\n";
        cout << "\t---> SUBMENU <---\n\n";
        cout << "1.Ingresar un elemento al inicio de la lista.\n";
        cout << "2.Ingresar un elemento al final de la lista.\n";
        cout << "3.Salir del SUBMENU.\n";
        cout << "\nQue opcion deseas?: ";
        cin >> submenu_opcion;//guarda opcion
        system("cls");
        switch (submenu_opcion)
        {
        case 1://inserta al inico
            cout << "\n---> Para insertar al inicio.\n";
            cout << "\nDijite un numero entero: ";
            cin >> dato;
            insertainicio(&lista, dato);//llamada del metodo que inserta al inicio
            cout << "\n";
            system("pause");
            break;
        case 2://inserta al final
            cout << "\n---> Para insertar al final.\n";
            cout << "\nDijite un numero entero: ";
            cin >> dato;
            insertafinal(&lista, dato); // llamada del metodo que inserta al final
            cout << "\n";
            system("pause");
            break;
        case 3://sale del submenu
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
    } while (submenu_opcion != 3);//se ejecuta hasta que la opcion sea 3
}
// submenu para calculos
void submenu2() // submenu para hace calculos y para llamar dentro del menu
{
    system("cls");
    int submenu_opcion;

    do
    {
        cout << "\n";
        cout << "\t---> SUBMENU <---\n\n";
        cout << "1.Calcular e imprimir la suma los nodos de la lista\n";
        cout << "2.Calcular e imprimir el elemento mayor y el menor de la lista\n";
        cout << "3.Salir del SUBMENU.\n";
        cout << "\nQue opcion deseas?: ";
        cin >> submenu_opcion;
        system("cls");
        switch (submenu_opcion)

        {
        case 1:
            suma(lista);
            cout << "\nLa suma de la lista es: " << suma(lista);
            cout << "\n";
            system("pause");//muestra un mensaje y continua hasta que se toque una tecla
            break;
        case 2:
            calcularMayorMenor(lista);
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
    Nodo *nodoInicio;//crea puntero
    nodoInicio = (Nodo *)malloc(sizeof(Nodo));
    nodoInicio->dato = n;//iguala
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
    int k;

    nodoInicio = (Nodo *)malloc(sizeof(Nodo));//crea nodo
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
        p->siguiente = nodoInicio; // conecto el ultimo nodo al nuevo
    }
    cout << "\n\tElemento " << n << " insertado al final de la lista !\n";
}

// para mostrar cada elemento de la lista 
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
            cout << "\n\tEl elemento " << n << " ha sido eliminado correctamente.\n";
        }
        // El elemento está en la lista pero no está de primero.
        else
        {
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            cout << "\n\tEl elemento " << n << " ha sido eliminado correctamente.\n";
        }
    }
}
//calcula el mayor y menor de los elementos en la lista
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
//devulve un entero de la suma total de suma de los elementos dentro de la lista
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