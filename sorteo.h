#ifndef SORTEO_H_INCLUDED
#define SORTEO_H_INCLUDED

struct Sorteo;
typedef struct Sorteo * SorteoPtr;

SorteoPtr crearSorteo();
void mostrarSorteo(SorteoPtr sorteo);

// Auxiliares
void abrirMenuPrincipal();

int verificarAciertos(SorteoPtr sorteo);
char *verificarPremio(int aciertos);
void marcarAciertos(SorteoPtr sorteo, int *numerosJugador);

void guardarNumerosTxt(
    SorteoPtr sorteo,
    int *numerosCarton,
    char *fechaEmisionCarton,
    char *direccionCarton
);

void mostrarResultado(char *premio);
void buscarJugadasRequeridas(int aciertos);

#endif // SORTEO_H_INCLUDED
