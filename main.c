
#include <stdio.h>
#include <math.h>

/*Cuerpo ppal del programa*/

#include "general.h"


int main() {
    int i,numero;
    unsigned int NELEM;
    short int tipo,proceso,seguir=1,seguir1=1,pantalla=1;
    struct datos ale,ord,inv;
    
    /*bucle repetir tabla diferente*/
    
    while (seguir1==1){
        
        seguir=1;
        
        printf("Introduce el numero de elementos que quieres que tenga tu tabla(maximo 30.000):\n \n NOTA:Para usar shell la tabla tiene que ser de minimo 4 elementos\n");
        scanf("%d",&NELEM);
        printf("\nComo de grande quieres que sea el dato?. Introduce:\n1 para pequeno\n2 para mediano\n3 para grande\n");
        scanf("%hd",&tipo);
        printf("\n\n");
        
        if (tipo==1){
            
            struct pequeno *tablaord=(struct pequeno *)malloc(sizeof(struct pequeno)*NELEM);
            struct pequeno *tablaale=(struct pequeno *)malloc(sizeof(struct pequeno)*NELEM);
            struct pequeno *tablainv=(struct pequeno *)malloc(sizeof(struct pequeno)*NELEM);
            struct pequeno *copia=(struct pequeno *)malloc(sizeof(struct pequeno)*NELEM);
            int * vector=(int*)malloc(sizeof(int)*NELEM);
            
            if((tablaord!=NULL)&&(tablaale!=NULL) && (tablainv!=NULL)&&(copia!=NULL)){
                
                /*aleatorizar tabla*/
                for(i=0;i<NELEM;i++)
                    vector[i]=0;
                printf("La tabla aleatoria es:\n");
                
                for(i=0;i<NELEM;i++){
                    do{
                        numero=rand()%NELEM;
                    }while(vector[numero]!=0);
                    
                    tablaale[i].clave= numero;
                    vector[numero]=1;
                    if(pantalla)
                        printf("%u.",tablaale[i].clave);
                }
                printf("\n\n");
                
                /*ordenar la tabla ordenada*/
                
                printf("La tabla ordenada es:\n");
                
                for(i=0;i<NELEM;i++)
                    tablaord[i].clave=tablaale[i].clave ;
                pqsort(tablaord,NELEM);
                if(pantalla){
                    for(i=0;i<NELEM;i++)
                        printf("%u.",tablaord[i].clave);
                    printf("\n\n");
                }
                /*invertir la tabla invertida*/
                
                printf("La tabla ordenada invertida es:\n");
                
                for(i=0;i<NELEM;i++)
                    tablainv[i].clave= tablaale[i].clave;
                pburbuja(tablainv,NELEM);
                pinvertir(tablainv,NELEM);
                if(pantalla){
                    for(i=0;i<NELEM;i++)
                        printf("%u.",tablainv[i].clave);
                    printf("\n\n");
                }
                printf("Que metodo quieres usar?. Introduce:\n\n1 para burbuja\n2 para insercion\n3 para seleccion\n4 para shell\n5 para monticulo\n6 para quicksort\n");
                scanf("%hd",&proceso);
                
                /* bucle repetir proceso diferente*/
                
                while(seguir==1){
                    
                    if(proceso==1){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=pburbuja(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",tablaale[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=pburbuja(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",tablaale[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=pburbuja(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                    }
                    
                    if(proceso==2){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale= pinsercion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=pinsercion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=pinsercion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    if(proceso==3){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=pseleccion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=pseleccion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=pseleccion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    if(proceso==4){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=pshell(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=pshell(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=pshell(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    if(proceso==5){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=pmonticulo(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=pmonticulo(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=pmonticulo(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                            
                        }
                    }
                    if(proceso==6){
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=pqsort(copia, NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=pqsort(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=pqsort(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    
                    
                    /*datos*/
                    
                    printf("\n\nTIEMPO\n\n%f milisegundos en la ordenada\n%f milisegundos en la aleatoria\n%f en la inversa\n\n",ord.tiempo,ale.tiempo,inv.tiempo);
                    printf("COMPARACIONES\n\n%lu en la ordenada\n%lu en la aleatoria\n%lu en la inversa\n\nCOMPARACIONES TEORICAS\n\n%f  sugiere la formula teorica para el metodo empleado\n\n",ord.comp,ale.comp,inv.comp,ale.NumCompTeorica);
                    printf("SUSTITUCIONES\n\n%lu en la ordenada\n%lu en la aleatoria\n%lu en la inversa \n\nSUSTITUCIONES TEORICAS\n\n%f  sugiere la formula teorica para el metodo empleado\n\n",ord.sust,ale.sust,inv.sust,ale.NumSusTeorica);
                    printf("Si quiere probar otro proceso presione 1,sino presione 0\n");
                    scanf("%hd",&seguir);
                    if(seguir){
                        printf("Introduce:\n1 para burbuja\n2 para insercion\n3 para seleccion\n4 para shell\n5 para monticulo\n6 para quicksort\n");
                        scanf("%hd",&proceso);
                    }
                    
                    
                }
                free(copia);
                free(tablaale);
                free(tablainv);
                free(tablaord);
                
            }
            else printf("Ha ocurrido un error\n");
        }
        /* tipo de dato mediano*/
        
        if (tipo==2){
            
            struct mediano *tablaord=(struct mediano *)malloc(sizeof(struct mediano)*NELEM);
            struct mediano *tablaale=(struct mediano *)malloc(sizeof(struct mediano)*NELEM);
            struct mediano *tablainv=(struct mediano *)malloc(sizeof(struct mediano)*NELEM);
            struct mediano *copia=(struct mediano *)malloc(sizeof(struct mediano)*NELEM);
            int * vector=(int*)malloc(sizeof(int)*NELEM);
            
            if((tablaord!=NULL)&&(tablaale!=NULL) && (tablainv!=NULL)&&(copia!=NULL)){
                
                /*aleatorizar tabla*/
                
                printf("La tabla aleatoria es:\n");
                
                for(i=0;i<NELEM;i++){
                    do{
                        numero=rand()%NELEM;
                    }while(vector[numero]!=0);
                    
                    tablaale[i].clave= numero;
                    vector[numero]=1;
                    if(pantalla)
                        printf("%u.",tablaale[i].clave);
                }
                
                printf("\n\n");
                
                /*ordenar la tabla ordenada*/
                
                printf("La tabla ordenada es:\n");
                
                for(i=0;i<NELEM;i++)
                    tablaord[i].clave=tablaale[i].clave ;
                mqsort(tablaord,NELEM);
                if(pantalla){
                    for(i=0;i<NELEM;i++)
                        printf("%u.",tablaord[i].clave);
                    printf("\n\n");
                }
                /*invertir la tabla invertida*/
                
                printf("La tabla ordenada invertida es:\n");
                
                for(i=0;i<NELEM;i++)
                    tablainv[i].clave= tablaale[i].clave;
                mburbuja(tablainv,NELEM);
                minvertir(tablainv,NELEM);
                if(pantalla){
                    for(i=0;i<NELEM;i++)
                        printf("%u.",tablainv[i].clave);
                    printf("\n\n");
                }
                
                printf("Que metodo quieres usar?. Introduce:\n\n1 para burbuja\n2 para insercion\n3 para seleccion\n4 para shell\n5 para monticulo\n6 para quicksort\n");
                scanf("%hd",&proceso);
                
                /* bucle repetir proceso diferente*/
                
                while(seguir==1){
                    
                    if(proceso==1){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=mburbuja(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=mburbuja(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=mburbuja(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                    }
                    
                    if(proceso==2){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale= minsercion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=minsercion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=minsercion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    if(proceso==3){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=mseleccion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=mseleccion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=mseleccion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    if(proceso==4){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=mshell(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=mshell(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=mshell(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    if(proceso==5){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=mmonticulo(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=mmonticulo(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=mmonticulo(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                            
                        }
                    }
                    if(proceso==6){
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=mqsort(copia, NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=mqsort(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=mqsort(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    pantalla=0;
                    
                    /*datos*/
                    
                    printf("\n\nTIEMPO\n\n%f milisegundos en la ordenada\n%f milisegundos en la aleatoria\n%f en la inversa\n\n",ord.tiempo,ale.tiempo,inv.tiempo);
                    printf("COMPARACIONES\n\n%lu en la ordenada\n%lu en la aleatoria\n%lu en la inversa\n\nCOMPARACIONES TEORICAS\n\n%f  sugiere la formula teorica para el metodo empleado\n\n",ord.comp,ale.comp,inv.comp,ale.NumCompTeorica);
                    printf("SUSTITUCIONES\n\n%lu en la ordenada\n%lu en la aleatoria\n%lu en la inversa \n\nSUSTITUCIONES TEORICAS\n\n%f  sugiere la formula teorica para el metodo empleado\n\n",ord.sust,ale.sust,inv.sust,ale.NumSusTeorica);
                    printf("Si quiere probar otro proceso presione 1,sino presione 0\n");
                    scanf("%hd",&seguir);
                    if(seguir){
                        printf("Introduce:\n1 para burbuja\n2 para insercion\n3 para seleccion\n4 para shell\n5 para monticulo\n6 para quicksort\n");
                        scanf("%hd",&proceso);
                    }
                    
                    
                }
                free(copia);
                free(tablaale);
                free(tablainv);
                free(tablaord);
                
            }
            else printf("Ha ocurrido un error\n");
        }
        
        /* tipo de dato grande*/
        
        if(tipo==3){
            
            struct grande *tablaord=(struct grande *)malloc(sizeof(struct grande)*NELEM);
            struct grande *tablaale=(struct grande *)malloc(sizeof(struct grande)*NELEM);
            struct grande *tablainv=(struct grande *)malloc(sizeof(struct grande)*NELEM);
            struct grande *copia=(struct grande *)malloc(sizeof(struct grande)*NELEM);
            int * vector=(int*)malloc(sizeof(int)*NELEM);
            
            if((tablaord!=NULL)&&(tablaale!=NULL) && (tablainv!=NULL)&&(copia!=NULL)){
                
                /*aleatorizar tabla*/
                
                for(i=0;i<NELEM;i++){
                    do{
                        numero=rand()%NELEM;
                    }while(vector[numero]!=0);
                    
                    tablaale[i].clave= numero;
                    vector[numero]=1;
                    if(pantalla)
                        printf("%u.",tablaale[i].clave);
                }
                printf("\n\n");
                
                printf("La tabla aleatoria es:\n");
                
                
                printf("\n\n");
                
                /*ordenar la tabla ordenada*/
                
                printf("La tabla ordenada es:\n");
                
                for(i=0;i<NELEM;i++)
                    tablaord[i].clave=tablaale[i].clave ;
                gqsort(tablaord,NELEM);
                for(i=0;i<NELEM;i++)
                    printf("%u.",tablaord[i].clave);
                printf("\n\n");
                
                /*invertir la tabla invertida*/
                
                printf("La tabla ordenada invertida es:\n");
                
                for(i=0;i<NELEM;i++)
                    tablainv[i].clave= tablaale[i].clave;
                gburbuja(tablainv,NELEM);
                ginvertir(tablainv,NELEM);
                for(i=0;i<NELEM;i++)
                    printf("%u.",tablainv[i].clave);
                printf("\n\n");
                
                printf("Que metodo quieres usar?. Introduce:\n\n1 para burbuja\n2 para insercion\n3 para seleccion\n4 para shell\n5 para monticulo\n6 para quicksort\n");
                scanf("%hd",&proceso);
                
                /* bucle repetir proceso diferente*/
                
                while(seguir==1){
                    
                    if(proceso==1){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=gburbuja(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=gburbuja(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=gburbuja(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                    }
                    
                    if(proceso==2){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale= ginsercion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=ginsercion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=ginsercion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    if(proceso==3){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=gseleccion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=gseleccion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=gseleccion(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    if(proceso==4){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=gshell(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=gshell(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=gshell(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    if(proceso==5){
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=gmonticulo(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=gmonticulo(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=gmonticulo(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                            
                        }
                    }
                    if(proceso==6){
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaale[i];
                        ale=gqsort(copia, NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablaord[i];
                        ord=gqsort(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                        for(i=0;i<NELEM;i++)
                            copia[i]=tablainv[i];
                        inv=gqsort(copia,NELEM);
                        if(pantalla){
                            for(i=0;i<NELEM;i++)
                                printf("%u.",copia[i].clave);
                            printf("\n");
                        }
                        
                    }
                    pantalla=0;
                    
                    /*datos*/
                    
                    printf("\n\nTIEMPO\n\n%f milisegundos en la ordenada\n%f milisegundos en la aleatoria\n%f en la inversa\n\n",ord.tiempo,ale.tiempo,inv.tiempo);
                    printf("COMPARACIONES\n\n%lu en la ordenada\n%lu en la aleatoria\n%lu en la inversa\n\nCOMPARACIONES TEORICAS\n\n%f  sugiere la formula teorica para el metodo empleado\n\n",ord.comp,ale.comp,inv.comp,ale.NumCompTeorica);
                    printf("SUSTITUCIONES\n\n%lu en la ordenada\n%lu en la aleatoria\n%lu en la inversa \n\nSUSTITUCIONES TEORICAS\n\n%f  sugiere la formula teorica para el metodo empleado\n\n",ord.sust,ale.sust,inv.sust,ale.NumSusTeorica);
                    printf("Si quiere probar otro proceso presione 1,sino presione 0\n");
                    scanf("%hd",&seguir);
                    if(seguir){
                        printf("Introduce:\n1 para burbuja\n2 para insercion\n3 para seleccion\n4 para shell\n5 para monticulo\n6 para quicksort\n");
                        scanf("%hd",&proceso);
                    }
                    
                    
                }
                free(copia);
                free(tablaale);
                free(tablainv);
                free(tablaord);
                
            }
            else printf("Ha ocurrido un error\n");
        }
        
        printf("Si quiere probar con otro tipo de dato presione 1,sino presione 0\n");
        scanf("%hd",&seguir1);
        
    }
    
    return 0;
}
