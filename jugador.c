#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "jugador.h"
#include "carton.h"
#include "intarrays.h"

struct Jugador {
    char nombre[20];
    int dni;
    CartonPtr carton;
};

// Constructor
JugadorPtr crearJugador() {
    JugadorPtr jugador = (JugadorPtr) malloc(sizeof(struct Jugador));
    char nombre[20];
    int dni;
    int opcionElegida;

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese su dni: ");
    scanf("%d", &dni);
    printf("\n");

    strcpy(jugador->nombre, nombre);
    jugador->dni = dni;

    printf("Seleccione una opcion y presione enter:\n");
    printf("1 - Crear carton con numeros aleatorios\n");
    printf("2 - Crear carton eligiendo los numeros\n");
    scanf("%d", &opcionElegida);

    while(opcionElegida != 1 && opcionElegida != 2) {
        printf("Opcion incorrecta, elija 1 o 2: ");
        scanf("%d", &opcionElegida);
    }

    printf("\n");

    if(opcionElegida == 1) {
        jugador->carton = crearCartonAutomatico();
    }

    if(opcionElegida == 2) {
        jugador->carton = crearCartonPorTeclado();
    }

    return jugador;
}

void mostrarJugador(JugadorPtr jugador) {
    printf("-------- Jugador --------\n");
    printf("Nombre: %s\n", jugador->nombre);
    printf("DNI: %d\n", jugador->dni);
    printf("\n");
    mostrarCarton(jugador->carton);
}

int *getNumerosCarton(JugadorPtr jugador) {
    return getNumeros(jugador->carton);
}

char *getFechaEmisionCarton(JugadorPtr jugador) {
    return getFechaEmision(jugador->carton);
}

char *getDireccionCarton(JugadorPtr jugador) {
    return getDireccion(jugador->carton);
}
