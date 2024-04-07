#include <stdio.h>
#include <stdlib.h>

#include "intarrays.h"
#include "carton.h"
#include "jugador.h"
#include "sorteo.h"

struct Sorteo {
    JugadorPtr jugador;
    int numeros[20];
};

// Constructor
SorteoPtr crearSorteo() {
    SorteoPtr sorteo = (SorteoPtr) malloc(sizeof(struct Sorteo));
    llenarArrayAleatorios(sorteo->numeros, 20);
    sorteo->jugador = crearJugador();

    return sorteo;
}

// Operaciones con Sorteo
void mostrarSorteo(SorteoPtr sorteo) {
    printf("Sorteo:\n");
    mostrarArray(sorteo->numeros, 20);
    printf("\n\n");
    mostrarJugador(sorteo->jugador);
}

int verificarAciertos(SorteoPtr sorteo) {
    int aciertos = 0;
    int *numerosJugador = getNumerosCarton(sorteo->jugador);

    for(int i=0; i<8; i++) {
        for(int j=0; j<20; j++) {
            if(sorteo->numeros[j] == numerosJugador[i]) {
                aciertos++;
            }
        }
    }

    return aciertos;
}

void marcarAciertos(SorteoPtr sorteo, int *numerosJugador) {
    printf("\nCarton con aciertos marcados:\n");
    for(int i=0; i<8; i++) {
        int bandera = 0;
        for(int j=0; j<20; j++) {
            if(sorteo->numeros[j] == numerosJugador[i]) {
                bandera = 1;
            }
        }
        if(bandera == 1) {
            printf("[*%d*]", numerosJugador[i]);
        } else {
            printf("[%d]", numerosJugador[i]);
        }
    }
    printf("\n");
}

void guardarNumerosTxt(
    SorteoPtr sorteo,
    int *numerosCarton,
    char *fechaEmisionCarton,
    char *direccionCarton
) {
    FILE *archivo = fopen("jugadas.txt", "a");

    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fprintf(archivo, "Fecha de emision: %s\n", fechaEmisionCarton);
    fprintf(archivo, "Direccion: %s\n", direccionCarton);
    fprintf(archivo, "Numeros: ");

    for(int i=0; i<8; i++) {
        int bandera = 0;
        for(int j=0; j<20; j++) {
            if(sorteo->numeros[j] == numerosCarton[i]) {
                bandera = 1;
            }
        }
        if(bandera == 1) {
            fprintf(archivo, "[*%d*]", numerosCarton[i]);
        } else {
            fprintf(archivo, "[%d]", numerosCarton[i]);
        }
    }
    fprintf(archivo, "\n\n");
    fclose(archivo);
}

// Auxiliares
void abrirMenuPrincipal() {
    int opcionElegida;

    printf("Bienvenido a Quiniela Plus!\n");
    printf("Seleccione una opcion y presione enter:\n");
    printf("1 - Jugar\n");
    printf("2 - Salir\n");
    scanf("%d", &opcionElegida);

    while(opcionElegida != 1 && opcionElegida != 2) {
        printf("Opcion incorrecta, elija 1 o 2: ");
        scanf("%d", &opcionElegida);
    }

    printf("\n");

    if(opcionElegida == 2) {
        system("cls");
        printf("Hasta luego!\n");
    }

    if(opcionElegida == 1) {
        int opcionFinal;
        SorteoPtr sorteo = crearSorteo();
        mostrarSorteo(sorteo);
        int aciertos = verificarAciertos(sorteo);
        marcarAciertos(sorteo, getNumerosCarton(sorteo->jugador));
        guardarNumerosTxt(
            sorteo,
            getNumerosCarton(sorteo->jugador),
            getFechaEmisionCarton(sorteo->jugador),
            getDireccionCarton(sorteo->jugador)
        );
        char *premio = verificarPremio(aciertos);
        printf("\nAciertos: %d", aciertos);
        mostrarResultado(premio);
        buscarJugadasRequeridas(aciertos);
        destruirSorteo(sorteo);

        printf("\nQueres volver al menu principal?\n");
        printf("1 - Si\n");
        printf("2 - No\n");
        scanf("%d", &opcionFinal);

        while(opcionFinal != 1 && opcionFinal != 2) {
            printf("Opcion incorrecta, elija 1 o 2: ");
            scanf("%d", &opcionFinal);
        }

        if(opcionFinal == 1) {
            system("cls");
            abrirMenuPrincipal();
        }

        if(opcionFinal == 2) {
            system("cls");
            printf("Hasta luego!\n");
        }

    }
}

char *verificarPremio(int aciertos) {
    switch(aciertos) {
        case 8: return "11 millones de pesos";
        case 7: return "20 mil pesos";
        case 6: return "500 pesos";
        case 5: return "50 pesos";
        default: return "nada";
    }
}

void mostrarResultado(char *premio) {
    if(strcmp("nada", premio) == 0) {
        printf("\nNo has ganado ningun premio.\n\n");
    } else {
        printf("\nHas ganado %s!\n\n", premio);
    }
}

void buscarJugadasRequeridas(int aciertos) {
    if(aciertos == 0) {
        printf("Con 0 aciertos es imposible ganar aunque se repita el mismo sorteo.\n");
    } else if(aciertos == 8) {
        printf("No hacen falta mas jugadas, ya tenes 8 aciertos.\n");
    } else {
        int contador = 1;
        int aciertosMult = aciertos;
        while(aciertosMult < 8) {
            aciertosMult += aciertos;
            contador++;
        }
        printf("Con %d jugadas iguales, tendrias 8 aciertos.\n", contador);
    }
}

// Destructor
void destruirSorteo(SorteoPtr sorteo) {
    destruirJugador(sorteo->jugador);
    free(sorteo);
}
