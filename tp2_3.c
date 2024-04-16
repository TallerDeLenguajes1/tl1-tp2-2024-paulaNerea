#include <stdio.h>
#include <stdlib.h>

#define N 5 
#define M 7 

int main(){
    int i,j, mt[N][M], *puntero;
    puntero = &mt[0][0]; //le asigno la posicion de memoria del primer elemento del array

    for(i = 0;i<N; i++){ 
        for(j = 0;j<M; j++) { 
            *(puntero + i * M + j)=1+rand()%100; //*puntero es un array de una dimension
            printf("%d ", *(puntero + i * M + j)); 
        } printf("\n"); 
    }

    /*

    for(i = 0;i<N; i++){ 
        for(j = 0;j<M; j++) { 
            mt[i][j]=1+rand()%100; 
            printf("%d ", mt[i][j]); 
        } printf("\n"); 
    }

    */

    return 0;
}
