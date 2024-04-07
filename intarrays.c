#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "intarrays.h"

void llenarArrayAleatoriosSR(int numeros[], int tam) {
    for(int i=0; i<tam; i++) {
        numeros[i] = rand() % 100;

        for(int j=0; j<i; j++) {
            if(numeros[i] == numeros[j]) {
                numeros[i] = rand() % 100;
                j = -1;
            }
        }

    }
}

void llenarArrayAleatorios(int numeros[], int tam) {
    for(int i=0; i<tam; i++) {
        numeros[i] = rand() % 100;
    }
}

void mostrarArray(int numeros[], int tam) {
    for(int i=0; i<tam; i++) {
        printf("[%d]", numeros[i]);
    }
}



void ordenamientoBurbujaAsc(int numeros[], int tam) {
    int aux;
    for(int i=0; i<tam; i++) {
        for(int j=0; j<tam-1; j++) {
            if(numeros[j] > numeros[j+1]) {
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
}
