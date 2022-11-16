#include <stdio.h>
#include <stdlib.h> //importamos las librerias a utilizar.
#include <conio.h>
using namespace std;
int main()
{ 
    system("cls");
    int surcusal_A[12] = {}; // Declaramos el vector de 12 posiciones para sucursal A
    int surcusal_B[12] = {}; // Declaramos el vector de 12 posiciones para sucursal B
    int surcusal_C[12] = {}; // Declaramos el vector de 12 posiciones para sucursal C
    int mesMax[3] = {};      // Declaramos un vector de 3 posiciones para declarar los maximos en cada sucursarl [1][2][3] = [sucursal A][sucursal B][Sucursal C]
    int mesMin[3] = {};      // Declaramos un vector de 3 posiciones para declarar los menores en cada sucursarl [1][2][3] = [sucursal A][sucursal B][Sucursal C]
    int posMayor[3] = {};    // Declaramos un vector de 3 posiciones para declarar las posiciones en cada sucursarl [1][2][3] = [sucursal A][sucursal B][Sucursal C]
    int posMenor[3] = {};    // Declaramos un vector de 3 posiciones para declarar las posiciones en cada sucursarl [1][2][3] = [sucursal A][sucursal B][Sucursal C]
    char meses[12] = {};     // para darle nombre a los meses
    int suma = 0;            // Declaramos esta variable suma para hacer dicha suma de todas las ventas de una sucursal a base de los 12 meses
    int menu = 0;            // la variable menu para el switch
    int total_venta[3] = {}; // Esta variable para sacar el total
    float promedio[3] = {};  // Esta variable para sacar los promedios de todos los meses de una sucursal
    printf("\n********************************************************************\n");
    printf("* Bienvenido a las sucursales de nuestra tienda Master of puppets! *");
    printf("\n********************************************************************\n");
    do
    {
        printf("\n\n---> Menu <---\n1.Cargar el Vector de Sucursal A\n2.Cargar el Vector de Sucursal B\n3.Cargar el Vector de Sucursal C\n4.Ventas por Sucursal\n5.Ventas Generales\n6.Salir\n\nSeleccione una opcion: ");
        scanf("%d", &menu); // el numero que indique el usuario se lee y se almacena el la variable menu
        switch (menu)       // se lee el numero y se ejecuta el case del switch correspondiente...
        {
        case 1: // pertenece a los datos de la sucursal A
            printf("\n----> Surcusal A seleccionada.\n");
            // Limpiamos la variable suma
            suma = 0;
            // Utilizamos un bucle for para almacenar los datos y recorrer cada posicion del vector
            for (int i = 0; i < 12; i++)
            {
                printf("\nDigite las ventas del mes %d: ", (i + 1));
                scanf("%d", &surcusal_A[i]); // lee el dato a ingresar en la posicion i
                suma += surcusal_A[i];       // Aqui se suman los datos ingresados en cada posicion
                if (i == 0)                  // condicional para asignar los datos iniciales desde la primera posicion
                {
                    mesMax[0] = surcusal_A[i]; // Aqui se guardara el primer valor ingresado como maximo
                    mesMin[0] = surcusal_A[i]; // Aqui se guardara el primer valor ingresado como minimo
                }
                else
                {
                    if (mesMax[0] < surcusal_A[i]) // si el valor de mes max en esa posicion es menor que el valor de sucursal en esa posicion...
                    {
                        mesMax[0] = surcusal_A[i]; //.. entonces se le asigna a mes max en esa posicion el valor actual de sucursal A
                        posMayor[0] = i;           // aqui se guarda la posicion por la que pasa sucursal A
                    }
                    else
                    {
                        if (mesMin[0] > surcusal_A[i]) // pero si el valor de mesmin en esa posicion es mayor que el valor de sucursal en esa posicion...
                        {
                            mesMin[0] = surcusal_A[i]; // entonces se le asigna a mesmin en esa posicion el valor actual de sucursal A
                            posMenor[0] = i;           // aqui se guarda la posicion por la que pasa sucursal A
                        }
                    }
                }
            }
            total_venta[0] = suma; // Se almacena el total de ventas de todos los meses.
            promedio[0] = suma;
            promedio[0] = (promedio[0] / 12); // Se suman las doce ventas y se divide entre el total de meses que es 12.
            break;
        case 2:
            printf("\n----> Surcusal B seleccionada.\n");
            // Limpiamos la variable suma
            suma = 0;
            // Utilizamos un bucle for para almacenar los datos
            for (int i = 0; i < 12; i++)
            {
                printf("\nDigite la venta del mes %d: ", (i + 1));
                scanf("%d", &surcusal_B[i]);
                suma += surcusal_B[i]; // Aqui se guarda los datos que se van ingresando en el vector de la sucursal
                if (i == 0)
                {
                    mesMax[1] = surcusal_B[i]; // Aqui se guardara el primer valor ingresado como maximo
                    mesMin[1] = surcusal_B[i]; // Aqui se guardara el primer valor ingresado como minimo
                }
                else
                {
                    if (mesMax[1] < surcusal_B[i])
                    {
                        mesMax[1] = surcusal_B[i]; // si el valor de la sucursal es mayor se guarda en la variable mesMax
                        posMayor[1] = i;           // Esta variable lo que hace es guardar en posMenor[1] la posicion del dato menor
                    }
                    else
                    {
                        if (mesMin[1] > surcusal_B[i])
                        {
                            mesMin[1] = surcusal_B[i]; // si el valor de la sucursal es menor se guarda en la variable mesMin
                            posMenor[1] = i;           // Esta variable lo que hace es guardar en posMenor[1] la posicion del dato menor
                        }
                    }
                }
            }
            printf("%d", mesMin[1]);
            total_venta[1] = suma; // Se almacena el total de ventas de todos los meses.
            promedio[1] = suma;
            promedio[1] = (promedio[1] / 12); // Se suman las doce ventas y se divide entre el total de meses que es 12.
            break;
        case 3:
            printf("\n----> Surcusal C seleccionada.\n");
            // Limpiamos la variable suma
            suma = 0;
            // Utilizamos un bucle for para almacenar los datos
            for (int i = 0; i < 12; i++)
            {
                printf("\nDigite la venta del mes %d: ", (i + 1));
                scanf("%d", &surcusal_C[i]);
                suma += surcusal_C[i]; // Aqui se guarda los datos que se van ingresando en el vector de la sucursal
                if (i == 0)
                {
                    mesMax[2] = surcusal_C[i]; // Aqui se guardara el primer valor ingresado como maximo
                    mesMin[2] = surcusal_C[i]; // Aqui se guardara el primer valor ingresado como minimo
                }
                else
                {
                    if (mesMax[2] < surcusal_C[i])
                    {
                        mesMax[2] = surcusal_C[i]; // si el valor de la sucursal es mayor se guarda en la variable mesMax
                        posMayor[2] = i;           // Esta variable lo que hace es guardar en posMenor[2] la posicion del dato menor
                    }
                    else
                    {
                        if (mesMin[2] > surcusal_C[i])
                        {
                            mesMin[2] = surcusal_C[i]; // si el valor de la sucursal es menor se guarda en la variable mesMin
                            posMenor[2] = i;           // Esta variable lo que hace es guardar en posMenor[2] la posicion del dato menor
                        }
                    }
                }
            }
            printf("%d", mesMin[2]);
            total_venta[2] = suma; // Se almacena el total de ventas de todos los meses.
            promedio[2] = suma;
            promedio[2] = (promedio[2] / 12); // Se suman las doce ventas y se divide entre el total de meses que es 12.
            break;
        case 4: // impresion de los resultados por sucursal individualmente.
            printf("\n---> Datos de ventas de la sucursal A <---\n");
            printf("El mes %d fue el de mayor venta, con un total de %d ventas.\n", posMayor[0] + 1, mesMax[0]); // se imprime la posicion y la venta maxima del mes
            printf("El mes %d fue el de menor venta, con un total de %d ventas.\n", posMenor[0] + 1, mesMin[0]); // se imprime la posicion y la venta minima del mes
            printf("El promedio de las ventas anuales fue de %.2f%\n", promedio[0]);                             // promedio de las ventas anuales
            printf("\nPresione una tecla para continuar...\n");
            getch(); // una espera hasta el el usuario presiona una tecla
            printf("\n---> Datos de ventas de la sucursal B <---\n");
            printf("El mes %d fue el de mayor venta, con un total de %d ventas.\n", posMayor[1] + 1, mesMax[1]); // se imprime la posicion y la venta maxima del mes
            printf("El mes %d fue el de menor venta, con un total de %d ventas.\n", posMenor[1] + 1, mesMin[1]); // se imprime la posicion y la venta minima del mes
            printf("El promedio de las ventas anuales fue de %.2f%\n", promedio[1]);                             // promedio de las ventas anuales
            printf("\nPresione una tecla para continuar...\n");
            getch();
            printf("\n---> Datos de ventas de la sucursal C <---\n");
            printf("El mes %d fue el de mayor venta, con un total de %d ventas.\n", posMayor[2] + 1, mesMax[2]); // se imprime la posicion y la venta maxima del mes
            printf("El mes %d fue el de menor venta, con un total de %d ventas.\n", posMenor[2] + 1, mesMin[2]); // se imprime la posicion y la venta minima del mes
            printf("El promedio de las ventas anuales fue de %.2f%\n", promedio[2]);                             // promedio de las ventas anuales
            printf("\n");
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        case 5:
            printf("\n");
            printf("\n---> Ventas Generales <---\n");                                        // Se hace un condicional para comparar todas las posiciones del vector total_venta para ver cual vendio mas, solo entra a uno
            if (total_venta[0] > total_venta[1] && total_venta[0] > total_venta[2]) // si el total de ventas 0 es mayor que las ventas 1 y 2, se ejecuta el condicional
            {
                printf("La sucursal A fue la que mas vendio de las tres sucursales.\n");
            }
            else
            {
                if (total_venta[1] > total_venta[0] && total_venta[1] > total_venta[2]) // si el total de ventas 1 es mayor que las ventas 0 y 2, se ejecuta el condicional
                {
                    printf("La sucursal B fue la que mas vendio de las tres sucursales.\n");
                }
                else
                {
                    if (total_venta[2] > total_venta[0] && total_venta[2] > total_venta[1]) // si el total 2 de ventas es mayor que las ventas 0 y 1, se ejecuta el condicional
                    {
                        printf("La sucursal C fue la que mas vendio de las tres sucursales.\n");
                    }
                }
            }                                                                       // Se hace un condicional para comparar todas las posiciones del vector total_venta para ver cual vendio menos
            if (total_venta[0] < total_venta[1] && total_venta[0] < total_venta[2]) // si el total de ventas 0 es menor que las ventas 1 y 2, se ejecuta el condicional
            {
                printf("La sucursal A fue la que menos vendio de las tres sucursales.\n");
            }
            else
            {
                if (total_venta[1] < total_venta[0] && total_venta[1] < total_venta[2]) // si el total de ventas 1 es menor que las ventas 0 y 2, se ejecuta el condicional
                {
                    printf("La sucursal B fue la que menos vendio de las tres sucursales.\n");
                }
                else
                {
                    if (total_venta[2] < total_venta[0] && total_venta[2] < total_venta[1]) // si el total de ventas 2 es menor que las ventas 0 y 1, se ejecuta el condicional
                    {
                        printf("La sucursal C fue la que menos vendio de las tres sucursales.\n");
                    }
                }
            }
            // sucursal que obtuvo el promedio de ventas m�s alto anualmente
            if (promedio[0] > promedio[1] && promedio[0] > promedio[2]) // Lo que va haciendo es ir verificando si cada posicion es mayor que otra
            {
                printf("La sucursal A fue la que obtuvo el promedio mas alto anualmente de las tres sucursales.\n");
            }
            else
            {
                if (promedio[1] > promedio[0] && promedio[1] > promedio[2]) // Aca seria lo mismo, verificar cada posicion para ver cual es mayor
                {
                    printf("La sucursal B fue la que obtuvo el promedio mas alto anualmente de las tres sucursales.\n");
                }
                else
                {
                    if (promedio[2] > promedio[0] && promedio[2] > promedio[1]) // Aca seria lo mismo, verificar cada posicion para ver cual es mayor
                    {
                        printf("La sucursal C fue la que obtuvo el promedio mas alto anualmente de las tres sucursales.\n");
                    }
                }
            }
            // cual sucursal fue la que mas vendio, en que mes lo hizo y cuanto fue lo que vendio.
            if (mesMax[0] > mesMax[1] && mesMax[0] > mesMax[2])
            {
                printf("La sucursal A fue la que mas vendio de las tres sucursales, lo hizo en el mes %d con un total de %d ventas\n", posMayor[0] + 1, mesMax[0]);
            }
            else
            {
                if (mesMax[1] > mesMax[0] && mesMax[1] > mesMax[2]) // se compara el valor mas grande de cada mes en el vector de 3 posiciones
                {
                    printf("La sucursal B fue la que mas vendio de las tres sucursales, lo hizo en el mes %d con un total de %d ventas\n", posMayor[1] + 1, mesMax[1]);
                }
                else
                {
                    if (mesMax[2] > mesMax[0] && mesMax[2] > mesMax[1])
                    {
                        printf("La sucursal C fue la que mas vendio de las tres sucursales, lo hizo en el mes %d con un total de %d ventas\n", posMayor[2] + 1, mesMax[2]);
                    }
                }
            }
            // cual sucursal fue la que menos vendio, en que mes lo hizo y cuanto fue lo que vendio.
            if (mesMin[0] < mesMin[1] && mesMin[0] < mesMin[2])
            {
                printf("La sucursal A fue la que menos vendio de las tres sucursales, lo hizo en el mes %d con un total de %d ventas\n", posMenor[0] + 1, mesMin[0]);
            }
            else
            {
                if (mesMin[1] < mesMin[0] && mesMin[1] < mesMin[2]) // se compara el valor mas pequeño de cada mes en el vector de 3 posiciones
                {
                    printf("La sucursal B fue la que menos vendio de las tres sucursales, lo hizo en el mes %d con un total de %d ventas\n", posMenor[1] + 1, mesMin[1]);
                }
                else
                {
                    if (mesMin[2] < mesMin[0] && mesMin[2] < mesMin[1])
                    {
                        printf("La sucursal C fue la que menos vendio de las tres sucursales, lo hizo en el mes %d con un total de %d ventas\n", posMenor[2] + 1, mesMin[2]);
                    }
                }
            }
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        case 6:
            break;
        default:
            printf("\n----> Numero ingresado NO valido! <----\n");// si el usuario ingresa un numero que no esta entre 1 - 6, se imprime un error! y vuelve a mostrar el menu inicial
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        }
    } while (menu != 6); //mientras el usuario ingrese un numero diferente a 6 el ciclo do se sigue ejecutando, si es igual a 6 se termina
    printf("\n********************\n");
    printf("*Fin del algoritmo.*\n");//imprime mensaje de despedida, una vez seleccionada la opcion salir.
    printf("********************");
    return 0;
}
