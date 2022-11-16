#include <iostream>
#include <conio.h>  //sirve para usar un getch();
#include <stdlib.h> //sirve para usar system("cls"); o sea limpia pantalla clearscreen
using namespace std;

/*pila implementada con array */
typedef int TipoDato; // otra forma de llamar un entero
#define MaxTamaPila 5 // constante tamaño del vector

typedef struct
{
    TipoDato listapila[MaxTamaPila]; // se crea la pila y tiene tantos espacios, en este caso 5
    int cima;                        // entero que indica cuantos elementos tiene la pila
} Pila;                              // la pila tiene dos campos  el vector con su capacidad y cima que es el que se va a mover de -1 si esta vacio hasta MaxTamaPila -1  si esta llena

// prototipos
void menu();
/*Operaciones sobre la pila*/
void CrearPila(Pila *P);
void Insertar(Pila *P, const TipoDato elemento);
TipoDato Quitar(Pila *P);
void pilaLimpia(Pila *P);

/* Operación de acceso a Pila*/
TipoDato Cima(Pila *P); // es para fijarme cual es el elemento que esta en la cima

/* Verificación del estado de la Pila*/
int PilaVacia(Pila *P); // No elementos
int PilaLlena(Pila *P); // full

/*Buscar elemento en la pila*/
void buscaElemento(Pila *P, TipoDato elemento);
void contadorPila(Pila *P);

void impresion(Pila *P);

// inicializar variables globales
int cantidad;
Pila P;
int x, n, z, opcion;
bool encontrado = false;
TipoDato aux;
int main()
{

    CrearPila(&P);
    menu();
    cout << "\n---> Fin del Algoritmo <---\n\n";
    return 0;
}

void menu() // metodo que imprime el menu principal
{
    int opcion;

    do
    {
        cout << "\n";
        cout << "\t---> MENU PRINCIPAL <---\n\n";
        cout << "1.Insertar en la pila.\n";
        cout << "2.Quitar de la pila.\n";
        cout << "3.Imprimir el elemento de la cima.\n";
        cout << "4.Obtener tamanno actual de la pila.\n";
        cout << "5.Pila vacia?\n";
        cout << "6.Pila llena?\n";
        cout << "7.Limpiar pila\n";
        cout << "8.Buscar un elemento en la pila.\n";
        cout << "9.Impresion de datos.\n";
        cout << "10.Salir del programa.\n";
        cout << "\n\nQue opcion deseas?: ";
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1: // inserta en la pila
            /*do{
                cout << "\nCuantos elementos deseas ingresar?: \n";
                cin >> cantidad;
                if(cantidad > MaxTamaPila){
                    cout<<"\nNo se puede ingresar esa cantidad de elementos, el tamanno de la pila es de "<<MaxTamaPila<<"\n";
                    system("pause");
                }else{
                    cin >> cantidad;    //quiero intentar evitar que meta mas elementos de los que tiene espacio la pila
                }
                system("cls");
            }while(cantidad <= MaxTamaPila);*/
            cout << "\nCuantos elementos deseas ingresar?: \n";
            cin >> cantidad;
            do
            {
                cout << "\nDigite un numero para ingresarlo a la pila: ";
                cin >> x;
                Insertar(&P, x);
                system("cls");
                cantidad--;
            } while (cantidad != 0);
            cout << "\n";
            break;
        case 2: // quitar un elemento de la pila
            if (PilaVacia(&P))
            {

                cout << "\nLa pila esta vacia, no hay elemento para eliminar.\n";
                system("pause");
            }
            else
            {
                aux = Quitar(&P);
                cout << "\n\t---> El elemento " << aux << " eliminado de la pila.\n";
                system("pause");
            }
            cout << "\n\n";
            break;
        case 3: // imprime el elemento de la cima
            if (PilaVacia(&P))
            {
                cout << "\nLa pila esta vacia, no hay elemento en la cima.\n";
                cout << "\n";
                system("pause");
            }
            else
            {
                cout << "\n\t---> El elemento en la cima es ";
                cout << Cima(&P);
                cout << "\n\n";
                system("pause");
            }
            cout << "\n\n";
            break;
        case 4: // obtiene el tamaño actual de la pila
            if (PilaVacia(&P))
            {
                cout << "\nLa pila esta vacia.\n";
                system("pause");
            }
            else
            {
                contadorPila(&P);
                system("pause");
            }
            cout << "\n\n";
            break;
        case 5: // pila vacia?
            if (PilaVacia(&P))
            {
                cout << "\n\t---> La pila esta vacia. \n\n";
                system("pause");
            }
            else
            {
                cout << "\n\t---> La pila si tiene elementos. \n\n";
                system("pause");
            }
            cout << "\n\n";
            break;
        case 6: // pila llena?
            if (PilaLlena(&P))
            {
                cout << "\n\t---> La pila esta llena. \n";
            }
            else
            {
                cout << "\n\t---> La pila NO esta llena. \n";
            }
            cout << "\n\n";
            system("pause");
            break;
        case 7: // limpiar toda la pila
            pilaLimpia(&P);
            cout << "\n\t---> La pila esta limpia completamente. \n";
            system("pause");
            cout << "\n\n";
            break;
        case 8: // busca un elemento en la pila
            cout << "\nCual elemento desear buscar?: ";
            cin >> z;
            buscaElemento(&P, z);
            system("pause");
            cout << "\n\n";
            break;
        case 9:
            impresion(&P);
            system("pause");
            break;
        case 10: // salir
            cout << "\n...Saliendo del programa...\n\n";
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

void Insertar(Pila *P, const TipoDato elemento)
{
    /* si la pila esta llena, termina el programa*/
    if (P->cima == MaxTamaPila - 1) // miembro ingresa a cima y dice que tiene
    {
        cout << "\n\t***** La pila ya esta completamente llena *****\n\n";
        system("pause");
        // es para salir de la funcion, como un break
    }
    else if (P->cima != MaxTamaPila - 1)
    {
        /*incrementar puntero cima y copiar elemento en listapila */
        P->cima++; // p-> es el operador miembro es para acceder a lista pila
        P->listapila[P->cima] = elemento;
        // voy a acceder a la cima por medio del miembro
        cout << "\n\t--> El elemento " << elemento << " se inserto correctamente a la pila.\n\n";
        system("pause");
    }
}
TipoDato Quitar(Pila *P) // quitar un elemento de la pila
{
    TipoDato aux;

    /*si la pila está vacia, termina el programa*/
    if (P->cima == -1) // no hay elementos
    {
        cout << "\nSe intenta sacar un elemento pero la pila esta vacia\n";
        // es para salir de la funcion, como un break
    }
    else if ((P->cima != -1))
    {
        /*guardar elemento de la cima */

        // aqui lo que dice es, coja el vector y coja lo que tiene cima
        aux = P->listapila[P->cima]; // aux guarda el valor que saco de la pila, es para almacenar el valor
        /*decrementar cima y devolver valor del elemento */
        P->cima--;
    }

    // controla la cantidad de elementos que hay en la pila
    return aux;
}

/* verificar pila vacia*/
int PilaVacia(Pila *P)
{
    /*devuelve el valor lógico resultante de expresión cima == -1;*/
    return P->cima == -1;
}

/* verificar pila llena*/
int PilaLlena(Pila *P)
{
    /*devuelve el valor lógico resultante de expresión cima == MaxTamaPila-1;*/
    return P->cima == MaxTamaPila - 1;
}

void pilaLimpia(Pila *P)
{
    /*devuelve el valor lógico resultante de expresión cima == MaxTamaPila-1;*/

    P->cima = -1; // reinicia a -1 a cima
}

// crea la pila vacia para inicializar
void CrearPila(Pila *P)
{
    P->cima = -1;
}

TipoDato Cima(Pila *P) // imprime el elemento de la cima
{
    return (P->listapila[P->cima]); // devuelve el valor que esté en la cima!
}

void buscaElemento(Pila *P, TipoDato elemento)
{
    TipoDato aux;
    encontrado = false;
    if (P->cima == -1) // no hay elementos
    {
        cout << "\nSe intenta buscar un elemento pero la pila esta vacia.\n";
    }
    else if (P->cima != -1)
    {
        for (int i = P->cima; i > -1; i--)
        {
            aux = P->listapila[i];
            if (aux == elemento)
            {
                encontrado = true;
            }
        }
        if (encontrado == true)
        {
            cout << "\nEl elemento " << elemento << " SI esta en la lista\n\n";
        }
        else
        {
            cout << "\nEl elemento NO esta en la lista\n\n";
        }
    }
    else
    {
        cout << "\nError pila no creada.";
    }
}

void impresion(Pila *P)
{
    if (P->cima == -1) // no hay elementos
    {
        cout << "\nNo se puede imprimir, la pila esta vacia.\n";
    }else{
    cout << "\nLos elementos son: \n\n";
    for (int i = P->cima; i > -1; i--)
    {
            cout << "|" << P->listapila[i] << "|" << endl;
    }
    }
    cout << endl;
}

void contadorPila(Pila *P)
{
    aux = 0;
    for (int i = P->cima; i > -1; i--)
    {
        aux = aux + 1;
    }
    cout << "\nLa pila tiene " << aux << " elementos\n\n";
}