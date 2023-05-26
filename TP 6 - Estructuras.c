#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Estructura de datos ---
typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

// --- Prototipado ---
int cargarDatosAlumnos(stAlumno alumno[], int dimension);
int agregarAlumnos(stAlumno alumno[], int *validos, int dimension);
// ---
void mostrarDatosAlumnos(stAlumno alumno[], int validos);
void mostrarDatosPorMatricula(stAlumno alumno[], int validos, int matricula);
void mostrarDatosPorGenero(stAlumno alumno[], int validos, char genero);
// ---
int posicionMatricula(stAlumno alumno[], int validos, int matricula);
int posicionMenorMatricula(stAlumno alumno[], int validos, int pos);
// ---
void ordenarPorSeleccionMatricula(stAlumno alumno[], int validos);
void ordenarPorInsercionNombre(stAlumno alumno[], int validos);
// ---
int contarCantidadGenero(stAlumno alumno[], int validos, char genero);

// ...
void presentacion(char *control);
void menu(int *opcion);

int main()
{
    stAlumno alumno[50];
    int validos,
        opcion,
        matricula;
    char genero,
         control = '\0';

    presentacion(&control);
    system("cls");
    printf("\n**********************************************************\n");
    printf("\n***************                             **************\n");
    printf("\n***************                             **************\n");
    printf("\n***************                             **************\n");
    printf("\n***************    PRIMER CARGA DE DATOS    **************\n");
    printf("\n***************                             **************\n");
    printf("\n***************                             **************\n");
    printf("\n***************                             **************\n");
    printf("\n**********************************************************\n");
    printf("\n            ");system("pause");system("cls");
    validos = cargarDatosAlumnos(alumno, 50);
    system("cls");

    while(control != 27){
        system("cls");
        menu(&opcion);

        switch(opcion){
        case 1:
            system("cls");
            agregarAlumnos(alumno, &validos, 50);
            break;
        case 2:
            mostrarDatosAlumnos(alumno, validos);
            break;
        case 3:
            system("cls");
            printf("Matricula :");
            scanf("%d", &matricula);
            mostrarDatosPorMatricula(alumno, validos, matricula);
            printf("\n\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf("Genero :");
            fflush(stdin);
            scanf("%c", &genero);
            mostrarDatosPorGenero(alumno, validos, genero);
            printf("\n\n");
            system("pause");
            break;
        case 5:
            system("cls");
            ordenarPorSeleccionMatricula(alumno, validos);
            printf("\nSe ordenaron los alumnos por numero de matricula.\n\n");
            system("pause");
            break;
        case 6:
            system("cls");
            ordenarPorInsercionNombre(alumno, validos);
            printf("\nSe ordenaron los alumnos por Nombre.\n\n");
            system("pause");
            break;
        case 7:
            system("cls");
            printf("Genero :");
            fflush(stdin);
            scanf("%c", &genero);
            printf("\nHay %d alumnos del genero %c\n\n", contarCantidadGenero(alumno, validos, genero), genero);
            system("pause");
            break;
        }
        system("cls");
        presentacion(&control);
    }

    system("cls");
    return 0;
}

// --- Funciones ---
int cargarDatosAlumnos(stAlumno alumno[], int dimension)
{
    int i = 0,
        g = 0;
    char control = '\0';

    while(i < dimension && control != 27){
        printf("\nDatos del alumno %d: ", i+1);
        printf("\nMatricula: ");
        scanf("%d", &alumno[i].matricula);
        printf("\nNombre: ");
        fflush(stdin);
        gets(&alumno[i].nombre);
        while(g==0){
            printf("\nGenero: ");
            scanf("%c", &alumno[i].genero);
            if(alumno[i].genero == 'm' || alumno[i].genero == 'f' || alumno[i].genero == 'o'){
                g++;
            } else {
                system("cls");
                printf("\nPor favor indique genero: m, f, o\n");
            }
        }
        g = 0;
        printf("\n\n[ENTER PARA CONTINUAR] [ESC PARA SALIR]");
        fflush(stdin);
        control = getch();
        system("cls");
        i++;
    }
    return i;
}
int agregarAlumnos(stAlumno alumno[], int *validos, int dimension)
{
    int i = *validos,
        g = 0;
    char control = '\0';

    while(i < dimension && control !=27){
        printf("\nDatos del alumno %d: ", i+1);
        printf("\nMatricula: ");
        scanf("%d", &alumno[i].matricula);
        printf("\nNombre: ");
        fflush(stdin);
        gets(&alumno[i].nombre);
        while(g==0){
            printf("\nGenero: ");
            scanf("%c", &alumno[i].genero);
            if(alumno[i].genero == 'm' || alumno[i].genero == 'f' || alumno[i].genero == 'o'){
                g++;
            } else {
                system("cls");
                printf("\nPor favor indique genero: m, f, o\n");
            }
        }
        g = 0;
        printf("\n\n[ENTER PARA CONTINUAR] [ESC PARA SALIR]");
        fflush(stdin);
        control = getch();
        system("cls");
        i++;
    }
    *validos = i;
    ordenarPorSeleccionMatricula(alumno, *validos);
    return *validos;
}
// ---
void mostrarDatosAlumnos(stAlumno alumno[], int validos)
{
    char control;
    int i = 0;

    while(i < validos && control != 27){
        system("cls");
        printf("\nMatricula: %d", alumno[i].matricula);
        printf("\nNombre: %s", alumno[i].nombre);
        printf("\nGenero: %c", alumno[i].genero);
        i++;
        printf("\n\n[ENTER PARA CONTINUAR] [ESC PARA SALIR]");
        fflush(stdin);
        control = getch();
    }

}
void mostrarDatosPorMatricula(stAlumno alumno[], int validos, int matricula)
{
    int pos = posicionMatricula(alumno, validos, matricula);

    if(pos != -1){
        printf("\nMatricula: %d", alumno[pos].matricula);
        printf("\nNombre: %s", alumno[pos].nombre);
        printf("\nGenero: %c", alumno[pos].genero);
    } else {
        printf("\nLa matricula solicitada no existe.");
    }
}
void mostrarDatosPorGenero(stAlumno alumno[], int validos, char genero)
{
    for(int i = 0; i < validos; i++){
        if(alumno[i].genero == genero){
            printf("\nMatricula: %d", alumno[i].matricula);
            printf("\nNombre: %s", alumno[i].nombre);
            printf("\nGenero: %c", alumno[i].genero);
            printf("\n\n   ---   \n");
        }
    }
}
// ---
int posicionMatricula(stAlumno alumno[], int validos, int matricula)
{
    int posicion = -1;
    for(int i = 0; i < validos && posicion == -1; i++){
        if(alumno[i].matricula == matricula){
            posicion = i;
        }
    }
    return posicion;
}
int posicionMenorMatricula(stAlumno alumno[], int validos, int pos)
{
    int posMenor = pos;
    stAlumno menor = alumno[pos];

    for(int i = pos+1; i < validos; i++){
        if(alumno[i].matricula < menor.matricula){
            posMenor = i;
            menor = alumno[i];
        }
    }
    return posMenor;
}
// ---
void ordenarPorSeleccionMatricula(stAlumno alumno[], int validos)
{
    for(int i = 0; i < validos - 1; i++){
        int posMenor = posicionMenorMatricula(alumno, validos, i);

        // Intercambiar el alumno actual con el alumno en la posición posMenor
        if(i != posMenor){
            stAlumno temp = alumno[i];
            alumno[i] = alumno[posMenor];
            alumno[posMenor] = temp;
        }
    }
}
void ordenarPorInsercionNombre(stAlumno alumno[], int validos)
{
    for (int i = 1; i < validos; i++) {
        stAlumno temp = alumno[i];
        int j = i - 1;
        while (j >= 0 && strcmp(alumno[j].nombre, temp.nombre) > 0) {
            alumno[j + 1] = alumno[j];
            j--;
        }
        alumno[j + 1] = temp;
    }
}
// ---
int contarCantidadGenero(stAlumno alumno[], int validos, char genero)
{
    int contador = 0;

    for(int i = 0; i < validos; i++){
        if(alumno[i].genero == genero){
            contador++;
        }
    }
    return contador;
}

// ....
void presentacion(char *control)
{
    printf("\n**********************************************************\n");
    printf("\n***************                             **************\n");
    printf("\n***************                             **************\n");
    printf("\n***************                             **************\n");
    printf("\n*************** TP 6 - ESTRUCTURAS DE DATOS **************\n");
    printf("\n***************                             **************\n");
    printf("\n***************                             **************\n");
    printf("\n***************                             **************\n");
    printf("\n**********************************************************\n");
    printf("\n          [ENTER PARA CONTINUAR] [ESC PARA SALIR]");
    fflush(stdin);
    *control = getch();
}
void menu(int *opcion)
{
    printf("\n**********************************************************\n");
    printf("\n***************            MENU           ****************\n");
    printf("\n**********************************************************\n");
    printf("\n*********** 1 * Agregar alumnos               ************\n");
    printf("\n*********** 2 * Mostrar todos los alumnos     ************\n");
    printf("\n*********** 3 * Buscar por matricula          ************\n");
    printf("\n*********** 4 * Mostrar por genero            ************\n");
    printf("\n*********** 5 * Ordenar alumnos por matricula ************\n");
    printf("\n*********** 6 * Ordenar alumnos por nombre    ************\n");
    printf("\n*********** 7 * Contar alumnos por genero     ************\n");
    printf("\n**********************************************************\n");
    printf("\n***********     Seleccione una opcion         ************\n");
    printf("\n**********************************************************\n");
    scanf("%d", opcion);
}
