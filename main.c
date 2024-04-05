#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "carton.h"

int main() {

    srand(time(0));
    int numbers[80];

    llenarArrayAleatoriosSR(numbers, 80);
    ordenamientoBurbujaAsc(numbers, 80);
    mostrarArray(numbers, 80);

    return 0;
}

