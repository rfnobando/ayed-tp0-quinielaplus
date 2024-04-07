#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

struct Jugador;
typedef struct Jugador * JugadorPtr;

JugadorPtr crearJugador();
void mostrarJugador(JugadorPtr jugador);

int *getNumerosCarton(JugadorPtr jugador);
char *getFechaEmisionCarton(JugadorPtr jugador);


#endif // JUGADOR_H_INCLUDED
