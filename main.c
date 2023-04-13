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
int calculoResta(int, int);
int calculoDivision(int, int);
int calculoMultiplicacion(int, int);
void calculadora(int, int);
int invertirNumero(int *);
void cargaValores(int *, int *);

int main()
{
    int opcion, num1, num2, num3;

    menu(&opcion);
    switch(opcion){
    case 1:
        printf("1. Desarrollar una funcion que devuelva un valor RANDOM en el rango de 0 a 100.\n");
        printf("\nNumero random: %d\n", numRandom());
        break;
    case 2:
        printf("2. Diseñe una funcion que reciba 3 numeros enteros y muestre el mayor y el menor.");
        num1 = numRandom();
        num2 = numRandom();
        num3 = numRandom();
        printf("\n\nNumeros random: %d - %d - %d", num1, num2, num3);
        printf("\n\nEl mayor de los tres: %d\n", elMayorDeTres(num1, num2, num3));
        printf("\nEl menor de los tres: %d\n", elMenorDeTres(num1, num2, num3));
        break;
    case 3:
        printf("3. Diseñe una funcion que reciba un numero entero N y realice la suma de los numeros enteros positivos menores que N y lo retorne. N es un dato ingresado por el usuario en el main.");
        printf("\n\nIngrese un numero natural: ");
        scanf("%d", &num1);
        printf("\n\nEnteros sumados : %d\n\n",sumaEnteros(num1));
        break;
    case 4:
        printf("4. Desarrollar una funcion que muestre la tabla de multiplicar de un número entero recibido por parámetro.");
        printf("\n\nIngrese un numero: ");
        scanf("%d", &num1);
        tablaMultiplicar(num1);
        printf("\n");
        break;
    case 5:
        printf("5. Realice una pequeña calculadora, utilizando funciones (una funcion de suma, una de multiplicacion, una de resta, una de division…)");
        printf("\n\nNumero 1: ");
        scanf("%d", &num1);
        printf("\nNumero 2: ");
        scanf("%d", &num2);
        system("cls");
        calculadora(num1, num2);
        break;
    case 6:
        printf("6. Realizar una funcion que reciba un numero positivo entero por parametro por referencia, y cambie su signo a negativo.");
        num1=numRandom();
        printf("\n\nNumero positivo: %d", num1);
        printf("\nNumero negativo: %d", invertirNumero(&num1));
        break;
    case 7:
        printf("7. Realizar una funcion que reciba dos numeros enteros por parametro por referencia y cargue sus valores el usuario dentro de la funcion.");
        cargaValores(&num1, &num1);
        printf("Valores: %d y %d", num1, num2);
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
    printf("* 7 * Enteros por Parametro->Referencia     *\n");
    printf("*********************************************\n");
    printf("*********************************************\n");
    printf("      Seleccionar ejercicio: ");
    scanf("%d", opcion);
    system("cls");
}

int numRandom()
{
    srand(time(NULL));
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

int calculoResta(int a, int b)
{
    return a-b;
}

int calculoDivision(int a, int b)
{
    if(b==0){
        printf("\nError: Imposible dividir por cero.\n\n");
        return NULL;
    } else {
        return a/b;
    }
}

int calculoMultiplicacion(int a, int b)
{
    return a*b;
}

void calculadora(int a, int b)
{
    int operacion=0, c;
    printf("Seleccione una operacion:\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n\nOperacion: ");
    scanf("%d", &operacion);
    switch(operacion){
    case 1:
        printf("\n%d + %d = %d\n\n", a, b, calculoSuma(a, b));
        break;
    case 2:
        printf("\n%d - %d = %d\n\n", a, b, calculoResta(a, b));
        break;
    case 3:
        printf("\n%d * %d = %d\n\n", a, b, calculoMultiplicacion(a, b));
        break;
    case 4:
        c = calculoDivision(a, b);
        if(c!=0){
            printf("\n%d / %d = %d\n\n", a, b, c);
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
