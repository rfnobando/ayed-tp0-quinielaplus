#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

struct Carton;
typedef struct Carton * CartonPtr;

// Constructores
CartonPtr crearCartonAutomatico();
CartonPtr crearCartonPorTeclado();

// Operaciones con Carton
void mostrarCarton(CartonPtr carton);

// Auxiliar fecha de emision
void asignarFechaActual(char fechaEmision[15]);
void asignarDireccion(char direccion[30]);

// Auxiliar extra
char *formatearPosicion(int pos);

int *getNumeros(CartonPtr carton);
char *getFechaEmision(CartonPtr carton);


#endif // CARTON_H_INCLUDED
