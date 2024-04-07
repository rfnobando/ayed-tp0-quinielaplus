#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

struct Carton;
typedef struct Carton * CartonPtr;

// Constructores
CartonPtr crearCartonAutomatico();
CartonPtr crearCartonPorTeclado();

// Operaciones con Carton
void mostrarCarton(CartonPtr carton);

// Auxiliares
void asignarFechaActual(char fechaEmision[15]);
void asignarDireccion(char direccion[30]);
char *formatearPosicion(int pos);

// Getters
int *getNumeros(CartonPtr carton);
char *getFechaEmision(CartonPtr carton);
char *getDireccion(CartonPtr carton);

// Destructor
void destruirCarton(CartonPtr carton);


#endif // CARTON_H_INCLUDED
