#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

struct Jugador;
typedef struct Jugador * JugadorPtr;

// Constructor
JugadorPtr crearJugador();

// Operaciones con Jugador
void mostrarJugador(JugadorPtr jugador);

// Getters
int *getNumerosCarton(JugadorPtr jugador);
char *getFechaEmisionCarton(JugadorPtr jugador);
char *getDireccionCarton(JugadorPtr jugador);

// Destructor
void destruirJugador(JugadorPtr jugador);

#endif // JUGADOR_H_INCLUDED
