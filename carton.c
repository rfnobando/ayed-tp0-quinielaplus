#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "carton.h"
#include "intarrays.h"

struct Carton {
    int numeros[8];
    char fechaEmision[15];
    char direccion[30];
};

// Constructores
CartonPtr crearCartonAutomatico() {
    CartonPtr carton = (CartonPtr) malloc(sizeof(struct Carton));
    asignarDireccion(carton->direccion);

    asignarFechaActual(carton->fechaEmision);
    llenarArrayAleatoriosSR(carton->numeros, 8);
    ordenamientoBurbujaAsc(carton->numeros, 8);

    return carton;
}

CartonPtr crearCartonPorTeclado() {
    CartonPtr carton = (CartonPtr) malloc(sizeof(struct Carton));
    asignarDireccion(carton->direccion);
    int aux;

    printf("Elija 8 numeros en cualquier orden, seran ordenados de menor a mayor al terminar:\n");

    for(int i=0; i<8; i++) {
        printf("Elija el %s numero: ", formatearPosicion(i));
        scanf("%d", &aux);

        while(aux < 0 || aux > 99) {
            printf("Elija un numero del 0 al 99 (inclusive): ");
            scanf("%d", &aux);
        }

        for(int j=0; j<i; j++) {
            if(carton->numeros[j] == aux) {
                printf("Los numeros no pueden repetirse, elija otro: ");
                scanf("%d", &aux);
                j = -1;
            }
        }

        carton->numeros[i] = aux;
    }

    printf("\n");

    asignarFechaActual(carton->fechaEmision);
    ordenamientoBurbujaAsc(carton->numeros, 8);

    return carton;
}

// Operaciones con Carton
void mostrarCarton(CartonPtr carton) {
    printf("-------- Carton --------\n");
    printf("Direccion: %s\n", carton->direccion);
    printf("Fecha de emision: %s\n", carton->fechaEmision);
    printf("Numeros: ");
    mostrarArray(carton->numeros, 8);
    printf("\n");
}

// Auxiliares
void asignarFechaActual(char fechaEmision[15]) {
    time_t fechaActual;
    struct tm* infoFecha;
    char fechaActualCadena[15];

    time(&fechaActual);
    infoFecha = localtime(&fechaActual);

    snprintf(
        fechaActualCadena,
        sizeof(fechaActualCadena),
        "%02d/%02d/%d",
        infoFecha->tm_mday,
        infoFecha->tm_mon + 1,
        infoFecha->tm_year + 1900
    );

    strcpy(fechaEmision, fechaActualCadena);
}

void asignarDireccion(char direccion[30]) {
    int aleatorio = rand() % 5;

    switch(aleatorio) {
        case 0:
            strcpy(direccion, "Calle Falsa 123");
            break;
        case 1:
            strcpy(direccion, "Av. Hipolito Yrigoyen 6805");
            break;
        case 2:
            strcpy(direccion, "Magallanes 4544");
            break;
        case 3:
            strcpy(direccion, "9 de Julio 530");
            break;
        case 4:
            strcpy(direccion, "Marco Avellaneda 1100");
            break;
        default:
            strcpy(direccion, "Calle Desconocida 111");
            break;
    }
}

char *formatearPosicion(int pos) {
    switch(pos) {
        case 0: return "primer";
        case 1: return "segundo";
        case 2: return "tercer";
        case 3: return "cuarto";
        case 4: return "quinto";
        case 5: return "sexto";
        case 6: return "septimo";
        case 7: return "octavo";
        default: return "indefinido";
    }
}


// Getters
int *getNumeros(CartonPtr carton) {
    return carton->numeros;
}

char *getFechaEmision(CartonPtr carton) {
    return carton->fechaEmision;
}

char *getDireccion(CartonPtr carton) {
    return carton->direccion;
}

// Destructor
void destruirCarton(CartonPtr carton) {
    free(carton);
}
