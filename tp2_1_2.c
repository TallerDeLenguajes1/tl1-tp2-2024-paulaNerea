#include <stdio.h>
#include <stdlib.h>

#define N 20

int main(){
    int i;
    double vt[N], *puntero;
    puntero = vt; //apunto al arreglo

    for(i = 0;i<N; i++)
    {
        *(puntero + i)=1+rand()%100;
        printf("%f  ", *(puntero + i)); 
    }

    return 0;
}