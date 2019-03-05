#ifndef general_h
#define general_h


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/* A continuación se definen los tipos de dato de nuestras tablas */

struct grande {
    
    unsigned int clave;
    float basura[70];
};

struct mediano {
    
    unsigned int clave;
    float basura[35];
};

struct pequeno {
    
    unsigned int clave;
};

/*structura que devuelven las funciones de ordenacion*/

struct datos {
    
    double tiempo;
    unsigned long int comp,sust;
    float NumCompTeorica, NumSusTeorica;
};

/*Prototipos*/

struct datos pburbuja(struct pequeno *tabla, unsigned int NELEM );
struct datos mburbuja(struct mediano *tabla, unsigned int NELEM );
struct datos gburbuja(struct grande *tabla, unsigned int NELEM );

void pquick(int iz,int de,struct pequeno *tabla,struct datos *dev);
void mquick(int iz,int de,struct mediano *tabla,struct datos *dev);
void gquick(int iz,int de,struct grande *tabla,struct datos *dev);

struct datos pqsort(struct pequeno *tabla,int NELEM);
struct datos mqsort(struct mediano *tabla,int NELEM);
struct datos gqsort(struct grande *tabla,int NELEM);

struct datos pinsercion(struct pequeno *tabla, unsigned int NELEM );
struct datos minsercion(struct mediano *tabla, unsigned int NELEM );
struct datos ginsercion(struct grande *tabla, unsigned int NELEM );

struct datos pshell(struct pequeno *tabla, unsigned int NELEM );
struct datos mshell(struct mediano *tabla, unsigned int NELEM );
struct datos gshell(struct grande *tabla, unsigned int NELEM );

struct datos pseleccion(struct pequeno *tabla, unsigned int NELEM );
struct datos mseleccion(struct mediano *tabla, unsigned int NELEM );
struct datos gseleccion(struct grande *tabla, unsigned int NELEM );

struct datos pmonticulo(struct pequeno *tabla, unsigned int NELEM );
struct datos mmonticulo(struct mediano *tabla, unsigned int NELEM );
struct datos gmonticulo(struct grande *tabla, unsigned int NELEM );

void pcriba(int iz,struct pequeno *tabla, struct datos *dev);
void mcriba(int iz,struct mediano *tabla, struct datos *dev);
void gcriba(int iz,struct grande *tabla, struct datos *dev);

void ginvertir(struct grande *tabla,unsigned int NELEM);
void minvertir(struct mediano *tabla,unsigned int NELEM);
void pinvertir(struct pequeno *tabla,unsigned int NELEM);




#endif
