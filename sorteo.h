#ifndef SORTEO_H_INCLUDED
#define SORTEO_H_INCLUDED

struct Sorteo;
typedef struct Sorteo * SorteoPtr;

// Constructor
SorteoPtr crearSorteo();

// Operaciones con Sorteo
void mostrarSorteo(SorteoPtr sorteo);
int verificarAciertos(SorteoPtr sorteo);
void marcarAciertos(SorteoPtr sorteo, int *numerosJugador);
void guardarNumerosTxt(
    SorteoPtr sorteo,
    int *numerosCarton,
    char *fechaEmisionCarton,
    char *direccionCarton
);

// Auxiliares
void abrirMenuPrincipal();
char *verificarPremio(int aciertos);
void mostrarResultado(char *premio);
void buscarJugadasRequeridas(int aciertos);

// Destructor
void destruirSorteo(SorteoPtr sorteo);

#endif // SORTEO_H_INCLUDED
