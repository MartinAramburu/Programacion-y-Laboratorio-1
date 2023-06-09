#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 100
#define MAX_CONTENIDOS 100
#define MAX_MENSAJES 100

// Estructura de Usuario
typedef struct {
    int idUsuario;
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[30];
    char genero;
    int listadoIdsContenidosGuardados[50];
    int validosContenidos;
    int puntaje;
    int nivel;
    int rol;
    int activo;
} stUsuario;

// Estructura de Contenido
typedef struct {
    int idContenido;
    char titulo[30];
    char descripcion[300];
    char categoria[30];
    int likes;
    int puntosPorCompartir;
    int activo;
} stContenido;

// Estructura de Mensajería
typedef struct {
    int idUsuarioEmisor;
    int idUsuarioReceptor;
    int idContenidoEnviado;
    char mensaje[300];
    int leido;
} stMensajeria;

// Variables globales
stUsuario usuarios[MAX_USUARIOS];
stContenido contenidos[MAX_CONTENIDOS];
stMensajeria mensajes[MAX_MENSAJES];
int cantidadUsuarios = 0;
int cantidadContenidos = 0;
int cantidadMensajes = 0;

// Funciones de utilidad:
// Busca un usuario por Username. Si lo encuentra devuelve su posicion, si no lo encuentra devuelve -1.
int buscarUsuarioPorUsername(const char *username)
{
    int flag = -1;
    for (int i = 0; i < cantidadUsuarios; i++) {
        if (strcmp(usuarios[i].userName, username) == 0) {
            flag = i;
        }
    }
    return flag;
}

// Busca contenido por Id. Si lo encuentra devuelve su posicion, si no lo encuentra devuelve -1.
int buscarContenidoPorId(int idContenido)
{
    int flag = -1;
    for (int i = 0; i < cantidadContenidos && flag == -1; i++) {
        if (contenidos[i].idContenido == idContenido) {
            flag = i;
        }
    }
    return flag;
}

// Funciones de Usuarios
void altaUsuario() {
    // Implementar lógica para dar de alta un usuario
    // Puedes pedir los datos necesarios al usuario y asignar un nuevo ID
}

void bajaUsuario() {
    // Implementar lógica para dar de baja un usuario
    // Puedes buscar el usuario por su username y marcarlo como inactivo
}

void modificarUsuario() {
    // Implementar lógica para modificar un usuario
    // Puedes buscar el usuario por su username y permitir al usuario cambiar los datos
}

void consultarUsuario() {
    // Implementar lógica para consultar un usuario
    // Puedes buscar el usuario por su username y mostrar los datos
}

void listarUsuarios() {
    // Implementar lógica para listar todos los usuarios
    // Puedes recorrer el arreglo de usuarios y mostrar los datos de cada uno
}

// Funciones de Contenido
void altaContenido() {
    // Implementar lógica para dar de alta un contenido
    // Puedes pedir los datos necesarios al usuario y asignar un nuevo ID
}

void bajaContenido() {
    // Implementar lógica para dar de baja un contenido
    // Puedes buscar el contenido por su ID y marcarlo como inactivo
}

void modificarContenido() {
    // Implementar lógica para modificar un contenido
    // Puedes buscar el contenido por su ID y permitir al usuario cambiar los datos
}

void consultarContenido() {
    // Implementar lógica para consultar un contenido
    // Puedes buscar el contenido por su ID y mostrar los datos
}

void listarContenidos() {
    // Implementar lógica para listar todos los contenidos
    // Puedes recorrer el arreglo de contenidos y mostrar los datos de cada uno
}

// Funciones de Mensajería
void enviarMensaje() {
    // Implementar lógica para enviar un mensaje
    // Puedes pedir los datos necesarios al usuario y agregar un nuevo mensaje al arreglo
}

void leerMensajes() {
    // Implementar lógica para leer los mensajes de un usuario
    // Puedes buscar los mensajes donde el usuario sea el receptor y mostrarlos
}

// Funciones de persistencia
void cargarUsuariosDesdeArchivo() {
    // Implementar lógica para cargar los usuarios desde el archivo "usuarios.dat"
    // Puedes utilizar funciones de lectura de archivos binarios
}

void guardarUsuariosEnArchivo() {
    // Implementar lógica para guardar los usuarios en el archivo "usuarios.dat"
    // Puedes utilizar funciones de escritura de archivos binarios
}

void cargarContenidosDesdeArchivo() {
    // Implementar lógica para cargar los contenidos desde el archivo "contenidos.dat"
    // Puedes utilizar funciones de lectura de archivos binarios
}

void guardarContenidosEnArchivo() {
    // Implementar lógica para guardar los contenidos en el archivo "contenidos.dat"
    // Puedes utilizar funciones de escritura de archivos binarios
}

void cargarMensajesDesdeArchivo() {
    // Implementar lógica para cargar los mensajes desde el archivo "mensajes.dat"
    // Puedes utilizar funciones de lectura de archivos binarios
}

void guardarMensajesEnArchivo() {
    // Implementar lógica para guardar los mensajes en el archivo "mensajes.dat"
    // Puedes utilizar funciones de escritura de archivos binarios
}

// Función principal - Main
int main() {
    // Cargar datos desde archivos
    cargarUsuariosDesdeArchivo();
    cargarContenidosDesdeArchivo();
    cargarMensajesDesdeArchivo();

    // Menú principal
    int opcion;
    do {
        printf("== MENÚ PRINCIPAL ==\n");
        printf("1. Iniciar sesión\n");
        printf("2. Registrarse\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Iniciar sesión
                // ...
                break;
            case 2:
                // Registrarse
                // ...
                break;
            case 3:
                // Salir
                // ...
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 3);

    // Guardar datos en archivos antes de salir
    guardarUsuariosEnArchivo();
    guardarContenidosEnArchivo();
    guardarMensajesEnArchivo();

    return 0;
}
