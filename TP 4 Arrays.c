#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Librerias/pila.h"

void menu (int *);
int cargaEnterosManual(int A[], int);
int cargaEnterosAuto(int A[]);
int cargaRealesAuto(float A[]);
int cargaCaracteresAuto(char A[]);
void mostrarArrayReales(float A[], int);
void mostrarArrayEnteros(int A[], int);
void mostrarArrayCaracteres(char A[], int);
void arrayToPila(int A[], int, Pila *);
int sumaEnteros(int A[], int);
float sumaReales(float A[], int);
int encontrarCaracter(char A[], char, int);
void insertar(char A[], int, char);
void ordenacionInsercion(char A[], int);
void agregarCaracter(char A[], int *, char);
char maximoCaracter(char A[], int);
void invertirArray(int A[], int);
int posicionMenor (int A[], int, int);
void ordenacionSeleccion (int A[], int);
void intercalarArrays(char A[], int, char A2[], int, char A3[], int *);

int main()
{
    srand(time(NULL));
    int busqueda,
        opcion,
        validos=0,
        validos2=0,
        validos3=0,
        Array1[25],
        Array6[25];
    float Array2[100];
    char Array3[25],
         Array4[25],
         Array5[50],
         c;
    Pila datos1;
         inicpila(&datos1);

    menu (&opcion);
    switch(opcion){
        case 1:
            printf("\n::::::Suma de enteros de un Array::::::");
            printf("\n\n");
            validos = cargaEnterosManual(Array1, 25);
            system("cls");
            printf("::::::Suma de enteros de un Array::::::");
             printf("\n\n");
            printf("Array de %d enteros: ", validos);
            mostrarArrayEnteros(Array1, validos);
            printf("\n\n");
            printf("La suma de sus elementos es: %d", sumaEnteros(Array1, validos));
            printf("\n\n");
            printf(":::::::::::::::::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 2:
            printf("\n::::::Suma de reales de un Array::::::");
            printf("\n\n");
            validos = cargaRealesAuto(Array2);
            printf("::Array de %d reales::", validos);
            printf("\n\n");
            mostrarArrayReales(Array2, validos);
            printf("\n\n");
            printf("La suma de sus elementos es: %.2f", sumaReales(Array2, validos));
            printf("\n\n");
            printf(":::::::::::::::::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 3:
            printf("\n::::::Pasar enteros de un Array a una Pila::::::\n");
            printf("\n\n");
            validos = cargaEnterosAuto(Array1);
            printf("Array de %d enteros: ", validos);
            mostrarArrayEnteros(Array1, validos);
            printf("\n\nPila vacia: \n");
            mostrar(&datos1);
            arrayToPila(Array1, validos, &datos1);
            printf("\n");
            printf(":::::::::::::::::::::::::::::::::::::::");
            printf("\n\n");
            system("pause"); system("cls");
            printf("\n::::::Pasar enteros de un Array a una Pila::::::\n");
            printf("\n\n");
            printf("Array de %d enteros: ", validos);
            mostrarArrayEnteros(Array1, validos);
            printf("\n\nPila con datos:\n");
            mostrar(&datos1);
            printf("\n");
            printf(":::::::::::::::::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 4:
            printf("\n::::::Busqueda de caracteres::::::\n");
            printf("\n\n");
            validos = cargaCaracteresAuto(Array3);
            printf("Array de %d caracteres: ", validos);
            mostrarArrayCaracteres(Array3, validos);
            printf("\n\n");
            printf("Intente recordar una letra. ");
            printf("\n\n");
            printf(":::::::::::::::::::::::::::::::::::::::");
            printf("\n\n");
            system("pause"); system("cls");
            printf("\n::::::Busqueda de caracteres::::::\n");
            printf("\nLetra: ");
            fflush(stdin);
            scanf("%c", &c);
            printf("\n\n");
            busqueda = encontrarCaracter(Array3, c, validos);
            if(busqueda==0){
                printf("La letra \"%c\" no se ha encontrado.", c);
            } else {
                printf("La letra \"%c\" se ha encontrado.", c);
            }
            printf("\n\n");
            printf(":::::::::::::::::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 5:
            printf("\n::::::Insertar caracter en Array ordenado::::::");
            printf("\n\n");
            validos = cargaCaracteresAuto(Array3);
            printf("Array de %d caracteres: ", validos);
            mostrarArrayCaracteres(Array3, validos);
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            printf("Ingresar un caracter a insertar: ");
            fflush(stdin);
            scanf("%c", &c);
            agregarCaracter(Array3, &validos, c);
            system("cls");
            printf("\n::::::Insertar caracter en Array ordenado::::::\n");
            printf("\nArray de %d caracteres: ", validos);
            mostrarArrayCaracteres(Array3, validos);
            ordenacionInsercion(Array3, validos);
            printf("\n\n");
            printf("Array ordenado de %d caracteres: ", validos);
            mostrarArrayCaracteres(Array3, validos);
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 6:
            printf("\n::::::Mostrar el maximo caracter en el Array::::::");
            printf("\n\n");
            validos = cargaCaracteresAuto(Array3);
            printf("Array de %d caracteres: ", validos);
            mostrarArrayCaracteres(Array3, validos);
            printf("\n\n");
            printf("Maximo caracter: %c", maximoCaracter(Array3, validos));
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 7:
            printf("\n::::::Verificar si el Array es capicua::::::");
            printf("\n\n");
            validos = cargaEnterosManual(Array1, 25);
            system("cls");
            printf("\n::::::Verificar si el Array es capicua::::::");
            printf("\n\n");
            printf("Array de %d enteros: ", validos);
            mostrarArrayEnteros(Array1, validos);
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            if(verificarCapicua(Array1, validos)==0){
                printf("El arreglo es capicua");
            } else {
                printf("El arreglo no es capicua");
            }
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 8:
            printf("\n::::::Invertir los elementos de un Array::::::");
            printf("\n\n");
            validos = cargaEnterosAuto(Array1);
            printf("Array de %d enteros: ", validos);
            mostrarArrayEnteros(Array1, validos);
            invertirArray(Array1, validos);
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            printf("Array invertido de %d enteros: ", validos);
            mostrarArrayEnteros(Array1, validos);
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 9:
            printf("\n::::::Ordenar un Array por seleccion::::::");
            printf("\n\n");
            validos = cargaEnterosAuto(Array1);
            printf("Array de %d enteros: ", validos);
            mostrarArrayEnteros(Array1, validos);
            ordenacionSeleccion(Array1, validos);
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            printf("Array ordenado de %d enteros: ", validos);
            mostrarArrayEnteros(Array1, validos);
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 10:
            printf("\n::::::Intercalar dos Array ordenados::::::");
            printf("\n\n");
            validos = cargaCaracteresAuto(Array3);
            validos2 = cargaCaracteresAuto(Array4);
            ordenacionInsercion(Array3, validos);
            ordenacionInsercion(Array4, validos2);
            printf("1er Array ordenado de %d caracteres: ", validos);
            mostrarArrayCaracteres(Array3, validos);
            printf("\n\n");
            printf("2do Array ordenado de %d caracteres: ", validos2);
            mostrarArrayCaracteres(Array4, validos2);
            intercalarArrays(Array3, validos, Array4, validos2, Array5, &validos3);
            printf("\n\n");
            printf("Array intercalado de %d caracteres: ", validos3);
            mostrarArrayCaracteres(Array5, validos3);
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");
            break;
        case 11:
            printf("\n::::::Sumar acumulando elementos de un Array::::::");
            printf("\n\n");
            validos = cargaEnterosManual(Array1, 25);
            system("cls");
            printf("\n::::::Sumar acumulando elementos de un Array::::::");
            printf("\n\n");
            printf("Vector de %d enteros: ", validos);
            mostrarArrayEnteros(Array1, validos);
            acumularVector(Array1, validos, Array6, &validos2);
            printf("\n\n");
            printf("Vector de %d enteros acumulados: ", validos2);
            mostrarArrayEnteros(Array6, validos2);
            printf("\n\n");
            printf("::::::::::::::::::::::::");
            printf("\n\n");

            break;
    }

    return 0;
}

//------------------ Funciones -----------------------

void menu(int *opcion)
{
    printf("***************** TP N4 - ARRAYS *****************\n");
    printf("**************************************************\n");
    printf("* 1  * Suma de enteros de un Array               *\n");
    printf("**************************************************\n");
    printf("* 2  * Suma de reales de un Array                *\n");
    printf("**************************************************\n");
    printf("* 3  * Pasar enteros de un Array a una Pila      *\n");
    printf("**************************************************\n");
    printf("* 4  * Busqueda en Array de caracteres           *\n");
    printf("**************************************************\n");
    printf("* 5  * Insertar caracter en Array ordenado       *\n");
    printf("**************************************************\n");
    printf("* 6  * Mostrar el maximo caracter en un Array    *\n");
    printf("**************************************************\n");
    printf("* 7  * Verificar si un Array es capicua          *\n");
    printf("**************************************************\n");
    printf("* 8  * Invertir los elementos de un Array        *\n");
    printf("**************************************************\n");
    printf("* 9  * Ordenar un Array por seleccion            *\n");
    printf("**************************************************\n");
    printf("* 10 * Invertir los elementos de un Array        *\n");
    printf("**************************************************\n");
    printf("* 11 * Sumar acumulando elementos de un Array    *\n");
    printf("**************************************************\n");
    printf("**************************************************\n");
    printf("      Seleccionar ejercicio: ");
    scanf("%d", opcion);
    system("cls");
}
int cargaEnterosManual(int A[], int dimension)
{
    char control = 's';
    int i=0;

    printf("::Carga manual de Array::");

    while(i<dimension && control == 's'){
        printf("\n\nIngrese un valor: ");
        scanf("%d", &A[i]);
        printf("\nDesea continuar? (s/n)");
        fflush(stdin);
        control = getch();
        i++;
    }
    return i;
}
int cargaEnterosAuto(int A[])
{
    int i;
    for(i=0; i<rand() % 12+3; i++){
        A[i] = rand() % 201 - 100;
    }
    return i;
}
int cargaRealesAuto(float A[])
{
    int i;
    for(i=0; i<100; ++i){
        A[i] = (rand() % 10000) / 100.0f;
    }
    return i;
}
int cargaCaracteresAuto(char A[])
{
    int i;
    for (i=0; i < rand() % 10+5; i++) {
        A[i] = rand() % 26 + 'a';
    }
    return i;
}
void mostrarArrayReales(float A[], int dimension)
{
    for(int i=0; i<dimension; ++i){
        printf("º%.2f", A[i]);
    }
}
void mostrarArrayEnteros(int A[], int dimension)
{
    for (int i=0; i<dimension; i++){
        printf("º%d", A[i]);
    }
}
void mostrarArrayCaracteres(char A[], int dimension)
{
    for(int i=0; i<dimension; i++){
        printf("º%c", A[i]);
    }
}
void arrayToPila(int A[], int dimension, Pila *datos1)
{
    for(int i=0; i<dimension; i++){
        apilar(datos1, A[i]);
    }
}
int sumaEnteros(int A[], int dimension)
{
    int suma=0;
    for(int i=0; i<dimension; ++i){
        suma += A[i];
    }
    return suma;
}
float sumaReales(float A[], int dimension)
{
    float suma=0;
    for(int i=0; i<dimension; ++i){
        suma += A[i];
    }
    return suma;
}
int encontrarCaracter(char A[], char caracter, int dimension)
{
    int i=0,
        busqueda=0;
    while(i<dimension && busqueda!=1){
        if(A[i]==caracter){
            busqueda=1;
        }
        i++;
    }
    return busqueda;
}
void insertar(char A[], int u, char caracter)
{
    int i;
    for (i = u - 1; i >= 0 && A[i] > caracter; i--)
    {
        A[i + 1] = A[i];
    }
    A[i + 1] = caracter;
}
void ordenacionInsercion(char A[], int dimension)
{
    int u;
    for (u = 1; u < dimension; u++)
    {
        insertar(A, u, A[u]);
    }
}
void agregarCaracter(char A[], int *dimension, char caracter)
{
        A[*dimension] = caracter;
        (*dimension)++;
}
char maximoCaracter(char A[], int dimension)
{
    char maximo = A[0];
    for(int i=1; i<dimension; i++){
        if(maximo<A[i]){
            maximo = A[i];
        }
    }
    return maximo;
}
int verificarCapicua(int A[], int dimension)
{
    int diferencia = 0;
    for(int i=0, j=dimension-1; i<j; i++, j--){
        if(A[i]!=A[j]){
            diferencia = 1;
            break;
        }
    }
    return diferencia;
}
void invertirArray(int A[], int dimension)
{
    for (int i = 0; i < dimension / 2; i++)
    {
        int temp = A[i];
        A[i] = A[dimension - 1 - i];
        A[dimension - 1 - i] = temp;
    }
}
int posicionMenor (int A[], int posicion, int dimension)
{
    int menor = A[posicion];
    int posMenor = posicion;
    int i = posicion +1;
    while (i<dimension)
    {
        if (menor > A[i])
        {
            menor = A[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}
void ordenacionSeleccion (int A[], int dimension)
{
    int posmenor;
    int aux;
    int i = 0;
    while (i<dimension-1)
    {
        posmenor = posicionMenor(A,i,dimension);
        aux = A[posmenor];
        A[posmenor]=A[i];
        A[i]= aux;
        i++;
    }
}
void intercalarArrays(char A[], int dimension, char A2[], int dimension2, char A3[], int *dimension3)
{
    int i = 0, j = 0, k = 0;
    while (i < dimension && j < dimension2) {    // Intercalamos los elementos de los dos arreglos en el tercero
        if (A[i] <= A2[j]) {
            A3[k++] = A[i++];
        } else {
            A3[k++] = A2[j++];
        }
    }
    while (i < dimension) {                      // Copiamos los elementos restantes del primer arreglo
        A3[k++] = A[i++];
    }
    while (j < dimension2) {                     // Copiamos los elementos restantes del segundo arreglo
        A3[k++] = A2[j++];
    }
    *dimension3 = k;                             // Actualizamos el valor de los elementos validos en el arreglo resultante
}
void acumularVector(int A[], int dimension, int A2[], int *dimension2)
{
    int i = 0,
        suma = A[i];
    for(i; i < dimension; i++){
        A2[i] = suma;
        suma += A[i+1];
    }
    *dimension2 = i;
}
