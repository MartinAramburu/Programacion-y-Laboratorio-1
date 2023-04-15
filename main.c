#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(int *);
int numRandom();
int elMayorDeTres(int, int, int);
int elMenorDeTres(int, int, int);
int sumaEnteros(int);
void tablaMultiplicar(int);
int calculoSuma(int, int);
float calculoResta(int, int);
float calculoDivision(int, int);
int calculoMultiplicacion(int, int);
void calculadora(int, int);
int invertirNumero(int *);
void cargaValores(int *, int*);

int main()
{
    srand(time(NULL));
    int opcion, a, b, c;
    menu(&opcion);

    switch(opcion){
    case 1:
        printf("1. Desarrollar una funcion que devuelva un valor RANDOM en el rango de 0 a 100.\n");
        printf("\nNumero random: %d\n", numRandom());
        break;
    case 2:
        printf("2. Diseñe una funcion que reciba 3 numeros enteros y muestre el mayor y el menor.");
        a = numRandom();
        b = numRandom();
        c = numRandom();
        printf("\n\nNumeros random: %d - %d - %d", a, b, c);
        printf("\n\nEl mayor de los tres: %d\n", elMayorDeTres(a, b, c));
        printf("\nEl menor de los tres: %d\n", elMenorDeTres(a, b, c));
        break;
    case 3:
        printf("3. Diseñe una funcion que reciba un numero entero N y realice la suma de los numeros enteros positivos menores que N y lo retorne. N es un dato ingresado por el usuario en el main.");
        printf("\n\nIngrese un numero natural: ");
        scanf("%d", &a);
        printf("\n\nEnteros sumados : %d\n\n",sumaEnteros(a));
        break;
    case 4:
        printf("4. Desarrollar una funcion que muestre la tabla de multiplicar de un número entero recibido por parámetro.");
        printf("\n\nIngrese un numero: ");
        scanf("%d", &a);
        tablaMultiplicar(a);
        break;
    case 5:
        printf("5. Realice una pequeña calculadora, utilizando funciones (una funcion de suma, una de multiplicacion, una de resta, una de division…)");
        printf("\n\nNumero 1: ");
        scanf("%d", &a);
        printf("\nNumero 2: ");
        scanf("%d", &b);
        system("cls");
        calculadora(a, b);
        break;
    case 6:
        printf("6. Realizar una funcion que reciba un numero positivo entero por parametro por referencia, y cambie su signo a negativo.");
        a=numRandom();
        printf("\n\nNumero positivo: %d", a);
        printf("\nNumero negativo: %d", invertirNumero(&a));
        break;
    case 7:
        printf("7. Realizar una funcion que reciba dos numeros enteros por parametro por referencia y cargue sus valores el usuario dentro de la funcion.");
        cargaValores(&a, &b);
        printf("\nValores: %d y %d\n\n", a, b);
        break;
    }

    return 0;
}

void menu(int *opcion)
{
    printf("*********** TRABAJO PRACTICO 3-BIS **********\n");
    printf("*********************************************\n");
    printf("* 1 * Valor RANDOM                          *\n");
    printf("*********************************************\n");
    printf("* 2 * Mayor y Menor                         *\n");
    printf("*********************************************\n");
    printf("* 3 * Suma de Enteros                       *\n");
    printf("*********************************************\n");
    printf("* 4 * Tabla de Multiplicar                  *\n");
    printf("*********************************************\n");
    printf("* 5 * Pequeña Calculadora                   *\n");
    printf("*********************************************\n");
    printf("* 6 * Invertir numero positivo              *\n");
    printf("*********************************************\n");
    printf("* 7 * Enteros por Parametro-Referencia      *\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("      Seleccionar ejercicio: ");
    scanf("%d", opcion);
    system("cls");
}
int numRandom()
{
    return rand() % 101;
}
int elMayorDeTres(int a, int b, int c)
{
    int numero;
  if(a>b && a>c){
    numero = a;
  } else if(b>a && b>c){
    numero = b;
  } else {
    numero = c;
  }
  return numero;
}
int elMenorDeTres(int a, int b, int c)
{
    int numero;
  if(a<b && a<c){
    numero = a;
  } else if(b<a && b<c){
    numero = b;
  } else {
    numero = c;
  }
  return numero;
}
int sumaEnteros(int n)
{
    return (n*(n+1))/2;
}
void tablaMultiplicar(int a)
{
    int i;
    for(i=0; i<=10; i++){
        printf("\n%d * %d = %d", a, i, a*i);
    }
}
int calculoSuma(int a, int b)
{
    return a+b;
}
float calculoResta(int a, int b)
{
    return a-b;
}
float calculoDivision(int a, int b)
{
    return (float)a/b;
}
int calculoMultiplicacion(int a, int b)
{
    return a*b;
}
void calculadora(int a, int b)
{
    int operacion=0;
    printf("Seleccione una operacion:\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n\nOperacion: ");
    scanf("%d", &operacion);
    switch(operacion){
    case 1:
        printf("\n%d + %d = %d\n\n", a, b, calculoSuma(a, b));
        break;
    case 2:
        printf("\n%d - %d = %.f\n\n", a, b, calculoResta(a, b));
        break;
    case 3:
        printf("\n%d * %d = %d\n\n", a, b, calculoMultiplicacion(a, b));
        break;
    case 4:
        if(b!=0){
            printf("\n%d / %d = %.2f\n\n", a, b, calculoDivision(a, b));
        } else {
            printf("\nNo se puede dividir por 0.\n");
        }
        break;
    }
}
int invertirNumero(int *a)
{
    return -*a;
}
void cargaValores(int *a, int *b)
{
    printf("\n\nCargar primer valor: ");
    scanf("%d", a);
    printf("\nCargar segundo valor: ");
    scanf("%d", b);
}
//
