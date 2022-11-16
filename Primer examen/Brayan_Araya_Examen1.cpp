#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define m 4
#define n 4
int main()
{ 
    system("cls");//limpia la terminal
    int matriz[m][n] = {{2, 3, -4, 6},
                        {-5, 1, 3, 4},
                        {1, -5, 7, 0},
                        {8, 2, -9, -5}};

    int menu;
    int suma = 0;
    float promedio = 0.0;
    int contador;
    int sumaFilas[4] = {};
    int sumaColumnas[4] = {};
    int sumaPar = 0;
    int sumaImpar = 0;
    int contadorPar;
    int contadorInpar;

    // imprime la matriz
    printf("---> Su matriz es: \n\n");
    for (int i = 0; i < m; i++) // para las filas
    {
        for (int j = 0; j < n; j++) // para columnas
            printf("\t\t%d", matriz[i][j]);
        printf("\n");
    }

    do
    {
        printf("\n\n---> Menu <---\n1.Calcular la suma de los elementos de la matriz.\n2.Calcular la suma y promedio de los elementos que sean positivos.\n3.Calcular la suma y promedio de los elementos que sean negativos.\n4.Calcular la suma de cada fila y el promedio por fila.\n5.Calcular e imprimir la suma de cada columna y el promedio por columna.\n6.Imprimir la suma y el promedio de los valores que sean pares.\n7.Salir\n\nSeleccione una opcion: ");
        scanf("%d", &menu); // el numero que indique el usuario se lee y se almacena el la variable menu
        switch (menu)
        {
        case 1: // sumar todos los elementos dentro de la matriz
            suma = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                    suma = suma + matriz[i][j];
            }
            printf("\n");
            printf("La suma de los elementos de la matriz es:%d ", suma);
            printf("\n");
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        case 2: // sumar solamente los elementos positivos y imprimir su promedio
            contador = 0;
            suma = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matriz[i][j] >= 0)
                    {
                        contador += 1;

                        suma = suma + matriz[i][j];
                        promedio = suma;
                    }
                }
                printf("\n");
            }
            promedio = (promedio / contador);
            printf("valor final del contador: %d\n", contador);
            printf("La suma de los numeros positivos es: %d\n", suma);
            printf("El promedio de los numeros positivos es: %.2f", promedio);
            printf("\n");
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        case 3: // sumar solamente los elementos negativos y imprimir su promedio
            contador = 0;
            suma = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matriz[i][j] < 0)
                    {
                        contador += 1;
                        ;
                        suma = suma + matriz[i][j];
                        promedio = suma;
                    }
                }
                printf("\n");
            }
            promedio = (promedio / contador);
            printf("valor final del contador: %d\n", contador);
            printf("La suma de los numeros negativos es: %d\n", suma);
            printf("El promedio de los numeros negativos es: %.2f", promedio);
            printf("\n");
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        case 4: // Calcular la suma de cada fila y el promedio por fila.
            printf("\n");
            for (int i = 0; i < n; i++)
            {
                suma = 0;
                for (int j = 0; j < m; j++)
                {
                    suma = suma + matriz[i][j];
                    sumaFilas[i] = suma;
                    promedio = suma;
                }
                promedio = (promedio / 4);
                printf("La suma de la fila es %d\n", sumaFilas[i]);
                printf("Y su promedio es %.2f\n", promedio);
                printf("\n");
            }

            printf("\n");
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        case 5: // Calcular la suma de cada columna y el promedio por fila.
            printf("\n");
            for (int j = 0; j < n; j++)
            {
                suma = 0;
                for (int i = 0; i < m; i++)
                {
                    suma = suma + matriz[i][j];
                    sumaColumnas[j] = suma;
                    promedio = suma;
                }
                promedio = (promedio / 4); // se guarda el promedio en la varaiable
                printf("La suma de la columna es %d\n", sumaColumnas[j]);
                printf("Y su promedio es %.2f\n", promedio);
                printf("\n");
            }
            printf("\n");
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        case 6: // calcular e imprimir la suma y el promedio de los valores que sean pares y impares
            contadorPar = 0;
            contadorInpar = 0;
            for (int i = 0; i < 4; i++)
            {
                if (sumaFilas[i] % 2 == 0)
                {
                    sumaPar = (sumaPar + sumaFilas[i]);
                    contadorPar = contadorPar + 1;
                    printf("Suma para tiene esto %d\n", sumaFilas[0]);
                }
                else
                {
                    if (sumaFilas[i] % 2 != 0)
                    {
                        sumaImpar = (sumaImpar + sumaFilas[i]);
                        contadorInpar = contadorInpar +1;

                    }
                }
            }
            printf("La suma de los numeros pares es %d \n", sumaPar);
            printf("La suma de los numeros impares es %d \n", sumaImpar);
            printf("\n");
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        case 7:
            menu = 7;
            break;

        default:
            printf("\n----> Numero ingresado NO valido! <----\n");
            printf("\nPresione una tecla para continuar...\n");
            getch();
            break;
        }
    } while (menu != 7);
    printf("\n********************\n");
    printf("*Fin del algoritmo.*\n");
    printf("********************");

    return 0;
}
