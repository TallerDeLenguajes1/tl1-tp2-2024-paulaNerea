#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};//al ser una variable global, se podrá ver en todos lados del código

struct
{
    int velocidad;//entre 1 y 3 GHz 
    int anio;//entre 2015 y 2023 
    int cantidad;//entre 1 y 8 
    char *tipo_cpu; //valores del arreglo tipos
}typedef PC;

void cargar(PC *lista);
void mostrar(PC *lista);
void masVieja(PC *lista);
void masRapida(PC *lista);

int main(){
    srand(time(NULL));
    PC *lista;
    lista = malloc(5 * sizeof(PC));

    cargar(lista);
    mostrar(lista);
    masVieja(lista);
    masRapida(lista);

    return 0;
}

void cargar(PC *lista){
    int tipo;
    for (int i = 0; i < 5; i++)
    {
        lista->velocidad= rand() % 3 + 1;
        lista->anio= rand() % 9 + 2015;
        lista->cantidad= rand() % 8 + 1;

        tipo = rand() % 6; 
        lista->tipo_cpu= tipos[tipo];
        lista++;
    }    
}

void mostrar(PC *lista){
    for (int i = 0; i < 5; i++)
    {
        printf("\n=====> PC %d", i + 1);
        printf("\nVelocidad de procesamiento: %d GHz", (lista + i)->velocidad);
        printf("\nAnio de fabricacion: %d", (lista + i)->anio);
        printf("\nTipo de procesador: %s", (lista + i)->tipo_cpu);
        printf("\nCantidad de nucleos: %d\n", (lista + i)->cantidad);
    }
}

void masVieja(PC *lista){
    int menor = 2023, indiceVieja;
    for (int i = 0; i < 2; i++)
    {
        if ((lista + i)->anio <= menor)
        {
            menor = (lista + i)->anio;
            indiceVieja = i;
        }
    }

    printf("\nComputadora mas vieja");
    printf("\n=====> PC %d", indiceVieja + 1);
    printf("\nVelocidad de procesamiento: %d GHz", (lista + indiceVieja)->velocidad);
    printf("\nAnio de fabricacion: %d", (lista + indiceVieja)->anio);
    printf("\nTipo de procesador: %s", (lista + indiceVieja)->tipo_cpu);
    printf("\nCantidad de nucleos: %d\n", (lista + indiceVieja)->cantidad);
    
}

void masRapida(PC *lista){
    int mayor = 0, indiceMay;
    for (int i = 0; i < 5; i++)
    {
        if ((lista + i)->velocidad >= mayor)
        {
            mayor = (lista + i)->velocidad;
            indiceMay = i;
        }
    }

    printf("\nComputadora con mayor velocidad");
    printf("\n=====> PC %d", indiceMay + 1);
    printf("\nVelocidad de procesamiento: %d GHz", (lista + indiceMay)->velocidad);
    printf("\nAnio de fabricacion: %d", (lista + indiceMay)->anio);
    printf("\nTipo de procesador: %s", (lista + indiceMay)->tipo_cpu);
    printf("\nCantidad de nucleos: %d\n", (lista + indiceMay)->cantidad);
    
}