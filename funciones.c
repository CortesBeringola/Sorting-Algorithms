

#include "general.h"



/* Funciones ordenacion de tablas (g=dato grande / m="" mediano / p="" pequeno) */

/* Burbuja*/

struct datos gburbuja(struct grande *tabla,unsigned int NELEM ){
    int i,j;
    struct datos dev;
    struct grande aux;
    clock_t T1;
    clock_t T2;
    dev.comp=0;
    dev.sust=0;
    dev.NumCompTeorica=(NELEM*NELEM)/2.0;
    dev.NumSusTeorica=(3*(NELEM*NELEM))/4.0;
    T1=clock();
    for(i=0;i<NELEM-1;i++){
        
        for(j=NELEM-1;j>i;j--){
            dev.comp++;
            if(tabla[j-1].clave>tabla[j].clave){
                aux=tabla[j-1];
                tabla[j-1]=tabla[j];
                tabla[j]=aux;
                dev.sust++;
            }
        }
    }
    
    T2=clock();
    
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    
    return dev;
}

struct datos mburbuja(struct mediano *tabla,unsigned int NELEM ){
    int i,j;
    struct datos dev;
    struct mediano aux;
    clock_t T1;
    clock_t T2;
    dev.comp=0;
    dev.sust=0;
    dev.NumCompTeorica=(NELEM*NELEM)/2.0;
    dev.NumSusTeorica=(3*(NELEM*NELEM))/4.0;
    
    T1=clock();
    for(i=0;i<NELEM-1;i++){
        
        for(j=NELEM-1;j>i;j--){
            dev.comp++;
            if(tabla[j-1].clave>tabla[j].clave){
                aux=tabla[j-1];
                tabla[j-1]=tabla[j];
                tabla[j]=aux;
                dev.sust++;
            }
        }
    }
    
    T2=clock();
    
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    
    return dev;
}

struct datos pburbuja(struct pequeno *tabla,unsigned int NELEM ){
    int i,j;
    struct datos dev;
    struct pequeno aux;
    clock_t T1;
    clock_t T2;
    dev.comp=0;
    dev.sust=0;
    dev.NumCompTeorica=(NELEM*NELEM)/2.0;
    dev.NumSusTeorica=(3*(NELEM*NELEM))/4.0;
    T1=clock();
    for(i=0;i<NELEM-1;i++){
        
        for(j=NELEM-1;j>i;j--){
            dev.comp++;
            if(tabla[j-1].clave>tabla[j].clave){
                aux=tabla[j-1];
                tabla[j-1]=tabla[j];
                tabla[j]=aux;
                dev.sust++;
            }
        }
    }
    
    T2=clock();
    
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    
    return dev;
}

/* Quicksort */

void pquick(int iz,int de,struct pequeno *tabla,struct datos *dev){
    
    struct pequeno aux;
    int i=iz,j=de;
    int pivote=iz;
    
    do{
        while((tabla[i].clave<tabla[pivote].clave) && (i<de)){
            i++;
            dev->comp++;
        }
        while((tabla[j].clave>tabla[pivote].clave) && (j>iz)){
            j--;
            dev->comp++;
        }
        if(i<=j){
            aux=tabla[i];
            tabla[i]=tabla[j];
            tabla[j]=aux;
            i++;
            j--;
            dev->sust++;
        }
        
    }while(i<=j);
    if(iz<j)
        pquick(iz,j,tabla,dev);
    if(i<de)
        pquick(i,de,tabla,dev);
    
}

struct datos pqsort(struct pequeno *tabla,int NELEM){
    
    struct datos dev;
    clock_t T1,T2;
    
    dev.NumCompTeorica=NELEM*(log10(NELEM));
    dev.NumSusTeorica=NELEM*(log10(NELEM))/6;
    
    dev.comp=0;
    dev.sust=0;
    T1=clock();
    pquick(0,NELEM-1,tabla,&dev);
    T2=clock();
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    
    return dev;
}

void mquick(int iz,int de,struct mediano *tabla,struct datos *dev){
    
    struct mediano aux;
    int i=iz,j=de;
    int pivote=iz;
    
    do{
        while((tabla[i].clave<tabla[pivote].clave) && (i<de)){
            i++;
            dev->comp++;
        }
        while((tabla[j].clave>tabla[pivote].clave) && (j>iz)){
            j--;
            dev->comp++;
        }
        if(i<=j){
            aux=tabla[i];
            tabla[i]=tabla[j];
            tabla[j]=aux;
            i++;
            j--;
            dev->sust++;
        }
        
    }while(i<j);
    if(iz<j)
        mquick(iz,j,tabla,dev);
    if(i<de)
        mquick(i,de,tabla,dev);
    
}

struct datos mqsort(struct mediano *tabla,int NELEM){
    
    struct datos dev;
    clock_t T1,T2;
    
    dev.NumCompTeorica=NELEM*(log10(NELEM));
    dev.NumSusTeorica=NELEM*(log10(NELEM))/6;
    dev.comp=0;
    dev.sust=0;
    T1=clock();
    mquick(0,NELEM-1,tabla,&dev);
    T2=clock();
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    
    return dev;
}
void gquick(int iz,int de,struct grande *tabla,struct datos *dev){
    
    struct grande aux;
    int i=iz,j=de;
    int pivote=iz;
    
    do{
        while((tabla[i].clave<tabla[pivote].clave) && (i<de)){
            i++;
            dev->comp++;
        }
        while((tabla[j].clave>tabla[pivote].clave) && (j>iz)){
            j--;
            dev->comp++;
        }
        if(i<=j){
            aux=tabla[i];
            tabla[i]=tabla[j];
            tabla[j]=aux;
            i++;
            j--;
            dev->sust++;
        }
        
    }while(i<j);
    if(iz<j)
        gquick(iz,j,tabla,dev);
    if(i<de)
        gquick(i,de,tabla,dev);
    
}

struct datos gqsort(struct grande *tabla,int NELEM){
    
    struct datos dev;
    clock_t T1,T2;
    
    dev.NumCompTeorica=NELEM*(log10(NELEM));
    dev.NumSusTeorica=NELEM*(log10(NELEM))/6;
    dev.comp=0;
    dev.sust=0;
    T1=clock();
    gquick(0,NELEM-1,tabla,&dev);
    T2=clock();
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    
    return dev;
}



/* shell */

struct datos pshell (struct pequeno *tabla, unsigned int NELEM) {
    struct datos dev;
    struct pequeno aux;
    int i, j,k, paso,h[]={NELEM/4,NELEM/2,1};
    dev.NumCompTeorica=pow(NELEM,1.2);
    dev.NumSusTeorica=pow(NELEM,1.2);
    dev.comp=0;
    dev.sust=0;
    clock_t T1;
    clock_t T2;
    
    T1=clock();
    for(paso=0;paso<3;paso++)
        for(k=0;k<h[paso];k++)
            for(i=h[paso]+k; i<NELEM; i+=h[paso]){
                aux=tabla[i];
                for(j=i-h[paso];j>=0;j-=h[paso]){
                    dev.comp++;
                    if(tabla[j].clave>aux.clave)
                        tabla[j+h[paso]] = tabla[j];
                    
                    else break;
                    
                    dev.sust++;
                }
                
                tabla[j+h[paso]]= aux;
            }
    
    T2=clock();
    
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    
    
    return dev;
}


struct datos mshell (struct mediano *tablas, unsigned int NELEM) {
    struct datos dev;
    struct mediano aux;
    int i, j,k, paso, h[]={7,3,1};
    dev.NumCompTeorica=pow(NELEM,1.2);
    dev.NumSusTeorica=pow(NELEM,1.2);
    dev.comp=0;
    dev.sust=0;
    clock_t T1;
    clock_t T2;
    
    T1=clock();
    for(paso=0;paso<3;paso++)
        for(k=0;k<h[paso];k++)
            for(i=h[paso]+k; i<NELEM; i+=h[paso]) {
                aux=tablas[i];
                for(j=i-h[paso];j>=0;j-=h[paso]){
                    dev.comp++;
                    if(tablas[j].clave>aux.clave)
                        tablas[j+h[paso]] = tablas[j];
                    dev.sust++;
                    
                }
                tablas[j+h[paso]]= aux;
            }
    
    T2=clock();
    
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    
    return dev;
    
}



struct datos gshell (struct grande *tabla, unsigned int NELEM) {
    struct datos dev;
    struct grande aux;
    int i, j,k, paso, h[]={7,3,1};
    dev.NumCompTeorica=pow(NELEM,1.2);
    dev.NumSusTeorica=pow(NELEM,1.2);
    dev.comp=0;
    dev.sust=0;
    clock_t T1;
    clock_t T2;
    
    T1=clock();
    for(paso=0;paso<3;paso++)
        for(k=0;k<h[paso];k++)
            for(i=h[paso]+k; i<NELEM; i+=h[paso]) {
                aux=tabla[i];
                for(j=i-h[paso];j>=0;j-=h[paso])
                    dev.comp++;
                if(tabla[j].clave>aux.clave)
                    tabla[j+h[paso]] = tabla[j];
                dev.sust++;
                tabla[j+h[paso]]= aux; }
    
    T2=clock();
    
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    
    
    return dev;
}



/* funcion insercion */

struct datos pinsercion(struct pequeno *tabla, unsigned int NELEM) {
    struct pequeno aux;
    struct datos dev;
    int i,j;
    dev.NumCompTeorica=(NELEM*NELEM)/4.0;
    dev.NumSusTeorica=(NELEM*NELEM)/4.0;
    clock_t T1;
    clock_t T2;
    dev.comp=0;
    dev.sust=0;
    T1=clock();
    for(i=1;i<NELEM;i++){
        aux=tabla[i];
        for (j=i-1; j>=0;j--){
            dev.comp++;
            if(tabla[j].clave>aux.clave){
                tabla[j+1]= tabla[j];
                dev.sust++;
            }
            else
                break;
            
            tabla[j]= aux;
            
        }
        
    }
    T2=clock();
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    return dev;
}



struct datos minsercion(struct mediano *tabla, unsigned int NELEM) {
    int i,j;
    struct datos dev;
    struct mediano aux;
    dev.NumCompTeorica=(NELEM*NELEM)/4.0;
    dev.NumSusTeorica=(NELEM*NELEM)/4.0;
    clock_t T1;
    clock_t T2;
    dev.comp=0;
    dev.sust=0;
    T1=clock();
    for(i=0;i<NELEM;i++){
        aux=tabla[i];
        for (j=i-1; j>=0;j--){
            dev.comp++;
            if(tabla[j].clave>aux.clave){
                tabla[j+1]= tabla[j];
                dev.sust++;
            }
            else
                break;
            
            tabla[j]= aux;
        }
        
    }
    T2=clock();
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    return dev;
}


struct datos ginsercion(struct grande *tabla, unsigned int NELEM) {
    struct datos dev;
    struct grande aux;
    int i, j;
    dev.NumCompTeorica=(NELEM*NELEM)/4.0;
    dev.NumSusTeorica=(NELEM*NELEM)/4.0;
    clock_t T1;
    clock_t T2;
    dev.comp=0;
    dev.sust=0;
    T1=clock();
    for(i=0;i<NELEM;i++){
        aux=tabla[i];
        for (j=i-1; j>=0;j--){
            dev.comp++;
            if(tabla[j].clave>aux.clave){
                tabla[j+1]= tabla[j];
                dev.sust++;
            }
            else
                break;
            
            tabla[j]= aux;
            
        }
    }
    T2=clock();
    dev.tiempo=((double)(T2-T1))/CLOCKS_PER_SEC*1000;
    return dev;
}



/*montículo*/

struct datos pmonticulo(struct pequeno *tabla,unsigned int NELEM){
    int i;
    struct datos dev;
    struct pequeno aux;
    dev.comp=0;
    dev.sust=0;
    dev.NumCompTeorica=(NELEM/2*(log10(NELEM)));
    dev.NumSusTeorica=(NELEM/2*(log10(NELEM)));
    clock_t T1;
    clock_t T2;
    
    T1=clock();
    
    for (i=NELEM;i>=3;i--){
        pcriba(i,tabla,&dev);
        aux=tabla[i-1];
        tabla[i-1]=tabla[0];
        tabla[0]=aux;
        dev.sust++; /*numero sust*/};
    
    
    T2=clock();
    
    dev.tiempo=(double)(T2-T1)/CLOCKS_PER_SEC*1000;
    
    return dev;
}


void pcriba(int i,struct pequeno *tabla, struct datos *dev){
    struct pequeno aux;
    int b;
    int primeravez=0;
    
    for (b=i/2-1;b>=0;b--){
        
        if(i%2==0&&primeravez==0){
            dev->comp++;/*comp*/
            if(tabla[b].clave<tabla[2*b+1].clave){
                aux=tabla[2*b+1];
                tabla[2*b+1]=tabla[b];
                tabla[b]=aux;
                dev->sust++;/*numero de sust*/
                primeravez++;
            }
            primeravez++;
        }
        
        
        else{
            primeravez++;
            dev->comp++;/*comp*/
            if(tabla[b].clave<=tabla[2*b+1].clave&&tabla[2*b+1].clave<=tabla[2*b+2].clave){
                aux=tabla[2*b+2];
                tabla[2*b+2]=tabla[b];
                tabla[b]=aux;
                dev->sust++;/*numero de sust*/
                
            }
            else{
                if(tabla[b].clave<tabla[2*b+1].clave&&tabla[2*b+1].clave>tabla[2*b+2].clave){
                    aux=tabla[2*b+1];
                    tabla[2*b+1]=tabla[b];
                    tabla[b]=aux;
                    dev->sust++;/*numero de sust*/
                }
            }
        }
        
    }
}


struct datos mmonticulo(struct mediano *tabla,unsigned int NELEM){
    int i;
    struct datos dev;
    struct mediano aux;
    dev.comp=0;
    dev.sust=0;
    dev.NumCompTeorica=(NELEM/2*(log10(NELEM)));
    dev.NumSusTeorica=(NELEM/2*(log10(NELEM)));
    clock_t T1;
    clock_t T2;
    
    T1=clock();
    
    for(i=NELEM;i>=3;i--){
        mcriba(i,tabla,&dev);
        aux=tabla[i-1];
        tabla[i-1]=tabla[0];
        tabla[0]=aux;
        dev.sust++; /*numero sust*/};
    
    
    T2=clock();
    
    dev.tiempo=(double)(T2-T1)/CLOCKS_PER_SEC*1000;
    
    return dev;
}


void mcriba(int i,struct mediano *tabla, struct datos *dev){
    struct mediano aux;
    int b;
    int primeravez=0;
    
    for (b=i/2-1;b>=0;b--){
        dev->comp++;/*comp*/
        if(i%2==0&&primeravez==0){
            dev->comp++;/*comp*/
            if(tabla[b].clave<tabla[2*b+1].clave){
                aux=tabla[2*b+1];
                tabla[2*b+1]=tabla[b];
                tabla[b]=aux;
                dev->sust++;/*numero de sust*/
                primeravez++;
            }
            primeravez++;
        }
        
        
        else{primeravez++;
            dev->comp++;/*comp*/
            if(tabla[b].clave<tabla[2*b+1].clave&&tabla[2*b+1].clave<=tabla[2*b+2].clave){
                aux=tabla[2*b+2];
                tabla[2*b+2]=tabla[b];
                tabla[b]=aux;
                dev->sust++;/*numero de sust*/
                
            }
            dev->comp++;/*comp*/
            if(tabla[b].clave<tabla[2*b+1].clave&&tabla[2*b+1].clave>tabla[2*b+2].clave){
                aux=tabla[2*b+1];
                tabla[2*b+1]=tabla[b];
                tabla[b]=aux;
                dev->sust++;/*numero de sust*/
                
            }
        }
        
    }
}


struct datos gmonticulo(struct grande *tabla,unsigned int NELEM){
    int i;
    struct datos dev;
    struct grande aux;
    dev.comp=0;
    dev.sust=0;
    dev.NumCompTeorica=(NELEM/2*(log10(NELEM)));
    dev.NumSusTeorica=(NELEM/2*(log10(NELEM)));
    clock_t T1;
    clock_t T2;
    
    T1=clock();
    
    for(i=NELEM;i>=3;i--){
        gcriba(i,tabla,&dev);
        aux=tabla[i-1];
        tabla[i-1]=tabla[0];
        tabla[0]=aux;
        dev.sust++; /*numero sust*/};
    
    
    T2=clock();
    
    dev.tiempo=(double)(T2-T1)/CLOCKS_PER_SEC*1000;
    
    return dev;
}


void gcriba(int i,struct grande *tabla, struct datos *dev){
    struct grande aux;
    int b;
    int primeravez=0;
    
    for (b=i/2-1;b>=0;b--){
        dev->comp++;/*comp*/
        if(i%2==0&&primeravez==0){
            dev->comp++;/*comp*/
            if(tabla[b].clave<tabla[2*b+1].clave){
                aux=tabla[2*b+1];
                tabla[2*b+1]=tabla[b];
                tabla[b]=aux;
                dev->sust++;/*numero de sust*/
                primeravez++;
            }
            primeravez++;
        }
        
        
        else{primeravez++;
            dev->comp++;/*comp*/
            if(tabla[b].clave<tabla[2*b+1].clave&&tabla[2*b+1].clave<=tabla[2*b+2].clave){
                aux=tabla[2*b+2];
                tabla[2*b+2]=tabla[b];
                tabla[b]=aux;
                dev->sust++;/*numero de sust*/
                
            }
            dev->comp++;/*comp*/
            if(tabla[b].clave<tabla[2*b+1].clave&&tabla[2*b+1].clave>tabla[2*b+2].clave){
                aux=tabla[2*b+1];
                tabla[2*b+1]=tabla[b];
                tabla[b]=aux;
                dev->sust++;/*numero de sust*/
                
            }
        }
        
    }
}


/*selección*/

struct datos pseleccion(struct pequeno *tabla, unsigned NELEM){
    struct datos dev;
    struct pequeno aux;
    dev.comp=0;
    dev.sust=0;
    int i=0; int j=0; int menor=0;
    dev.NumCompTeorica=((NELEM*NELEM)/2);
    dev.NumSusTeorica=(NELEM*log(NELEM));
    
    clock_t T1;
    clock_t T2;
    
    
    T1=clock();
    for(i=0;i<NELEM-1;i++){
        menor=i;
        for(j=i+1;j<NELEM;j++){
            dev.comp++;   /*numero de comp*/
            if(tabla[j].clave<tabla[menor].clave)
                menor=j;}
        
        if(menor!=i){
            aux=tabla[i];
            tabla[i]=tabla[menor];
            tabla[menor]=aux;
            dev.sust++; /*numero de sust*/
            
        }
    }
    
    T2=clock();
    
    dev.tiempo=(double)(T2-T1)/CLOCKS_PER_SEC*1000;
    
    return dev;
    
}

struct datos mseleccion(struct mediano *tabla, unsigned NELEM){
    struct datos dev;
    struct mediano aux;
    dev.comp=0;
    dev.sust=0;
    int i=0; int j=0; int menor=0;
    dev.NumCompTeorica=((NELEM*NELEM)/2);
    dev.NumSusTeorica=(NELEM*log(NELEM));
    
    clock_t T1;
    clock_t T2;
    
    
    T1=clock();
    for(i=0;i<NELEM-1;i++){
        menor=i;
        for(j=i+1;j<NELEM;j++){
            dev.comp++;   /*numero de comp*/
            if(tabla[j].clave<tabla[menor].clave)
                menor=j;}
        
        if(menor!=i){
            aux=tabla[i];
            tabla[i]=tabla[menor];
            tabla[menor]=aux;
            dev.sust++; /*numero de sust*/
            
        }
    }
    
    T2=clock();
    
    dev.tiempo=(double)(T2-T1)/CLOCKS_PER_SEC*1000;
    
    return dev;
    
}


struct datos gseleccion(struct grande *tabla, unsigned NELEM){
    struct datos dev;
    struct grande aux;
    dev.comp=0;
    dev.sust=0;
    int i=0; int j=0; int menor=0;
    dev.NumCompTeorica=((NELEM*NELEM)/2);
    dev.NumSusTeorica=(NELEM*log(NELEM));
    
    clock_t T1;
    clock_t T2;
    
    
    T1=clock();
    for(i=0;i<NELEM-1;i++){
        menor=i;
        for(j=i+1;j<NELEM;j++){
            dev.comp++;   /*numero de comp*/
            if(tabla[j].clave<tabla[menor].clave)
                menor=j;}
        
        if(menor!=i){
            aux=tabla[i];
            tabla[i]=tabla[menor];
            tabla[menor]=aux;
            dev.sust++; /*numero de sust*/
            
        }
    }
    
    T2=clock();
    
    dev.tiempo=(double)(T2-T1)/CLOCKS_PER_SEC*1000;
    
    return dev;
    
}

/* Funciones inversion tabla*/

void pinvertir(struct pequeno *tabla,unsigned int NELEM){
    int i;
    struct pequeno aux;
    for(i=0;i<NELEM/2;i++){
        aux.clave=tabla[i].clave;
        tabla[i].clave=tabla[NELEM-i-1].clave;
        tabla[NELEM-i-1].clave=aux.clave;
        
    }
}
void minvertir(struct mediano *tabla,unsigned int NELEM){
    struct mediano aux;
    int i;
    for( i=0;i<NELEM/2;i++){
        aux.clave=tabla[i].clave;
        tabla[i].clave=tabla[NELEM-i-1].clave;
        tabla[NELEM-i-1].clave=aux.clave;
        
    }
}


void ginvertir(struct grande *tabla,unsigned int NELEM){
    int i;
    struct grande aux;
    for(i=0;i<NELEM/2;i++){
        aux.clave=tabla[i].clave;
        tabla[i].clave=tabla[NELEM-i-1].clave;
        tabla[NELEM-i-1].clave=aux.clave;
    }
    
}




