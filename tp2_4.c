#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 6
#define M 10

struct compu {
    char nom[15];
    int velocidad;//entre 1 y 3 Gherz
    int anio;//entre 2000 y 2017
    int cantidad;//entre 1 y 4
    char *tipo_cpu; //valores del arreglo tipos
};
typedef struct compu pc;

void cargarDatos(pc *pModelo, char tipos[N][M]);
void mostrarUnDato(pc *pModelo);
void mostrarTodo(pc *pModelo);
void modeloMasAntiguo(pc *pModelos);
void pcMasRapida(pc *pModelos);

int main(){
    int i, j;
    pc modelos[5], *pModelos;
    pModelos=modelos;
    //char *pTipos;
    char tipos[N][M]={"Intel","AMD","Celeron","Athlon","Core","Pentium"};
    //pTipos=tipos;
    //srand(time(NULL));
    //generacion tabla con los tipo de procesadores
    /*
    for (i = 0; i < N; i++)
    {
        printf("%s ", tipos[i]);
        for (j = 0; j < M; j++)
        {
            tipos[i][j]=rand()%1000+1;
            printf("%d ", tipos[i][j]);
        }
        printf("\n");
    }*/
    //ingreso de los datos de la pc
    cargarDatos(pModelos, tipos);
    printf("\n********************");
    //muestra de los datos cargados en el arreglo
    printf("\nLos caracteristicas de las distintas PC son:\n");
    mostrarTodo(pModelos);
    //muetra la computadora mas antigua en el arreglo
    printf("\n********************");
    printf("\nComputadora mas actigua de la lista");
    modeloMasAntiguo(pModelos);
    //computadora con mayor velocidad
    printf("\n********************");
    printf("\nComputadora mas rapida");
    pcMasRapida(pModelos);

    return 0;
}

void cargarDatos(pc *pModelos, char tipos[N][M])
{
    //struct compu nuevo;
    int i, j, t;
    srand(time(NULL));
    printf("Ingrese los datos de la pc:\n");
    /*
    for (i = 0; i < N; i++)
    {
        printf("%s ", ipos[i]);
        for (j = 0; j < M; j++)
        {
            pTipos=rand()%1000+1;
            printf("%d ", pTipos);
        }
        printf("\n");
    }*/
    for (int i = 0; i < 5; i++)
    {
        printf("\nNombre: ");
        fflush(stdin);
        gets(pModelos->nom);
        pModelos->velocidad = 1+rand()%3;
        printf("\nVelocidad procesador: %d Gherz",pModelos->velocidad);
        pModelos->anio = rand()%7+2015;
        printf("\nAño del modelo: %d",pModelos->anio);
        pModelos->cantidad = 1+rand()%4;
        printf("\nCantidad nucleos: %d", pModelos->cantidad);
        t = rand()%6;
        pModelos->tipo_cpu=&tipos[t];
        printf("\nTipo de CPU: %s", pModelos->tipo_cpu);
        //strcpy(tipos[t], pModelos->(tipo_cpu);
        printf("\n........................");
        pModelos++;
    }
}
void mostrarUnDato(pc *pModelo)
{
    printf("\nNombre: ");
    puts((*pModelo).nom);
    printf("\nVelocidad procesador: %d Gherz",(*pModelo).velocidad);
    printf("\nAño del modelo: %d",(*pModelo).anio);
    printf("\nCantidad nucleos: %d", (*pModelo).cantidad);
    printf("\nTipo de CPU: ");
    puts((*pModelo).tipo_cpu);
}

void mostrarTodo(pc *pModelo)
{
    for (int i = 0; i < 5; i++)
    {
        mostrarUnDato(pModelo);
        pModelo++;
        printf("\n................");
    }
}
void modeloMasAntiguo(pc *pModelos)
{
    pc *pAux;
    int i, auxAnio, auxIndice;
    pAux=pModelos;
    auxAnio=pAux->anio;
    for (i = 0; i < 5; i++)
    {
        if (pAux->anio < auxAnio)
        {
            auxAnio=pAux->anio;
            auxIndice = i;
        }
        pAux++;        
    }
    for (i = 0; i < 5; i++)
    {
        if (i==auxIndice)
        {
            mostrarUnDato(pModelos);
        }
        pModelos++;
    }    
}
void pcMasRapida(pc *pModelos)
{
    pc *pAux;
    int i, auxVelocidad, auxIndice;
    pAux=pModelos;
    auxVelocidad=pAux->velocidad;
    for (i = 0; i < 5; i++)
    {
        if (pAux->velocidad > auxVelocidad)
        {
            auxVelocidad=pAux->velocidad;
            auxIndice = i;
        }
        pAux++;        
    }
    for (i = 0; i < 5; i++)
    {
        if (i==auxIndice)
        {
            mostrarUnDato(pModelos);
        }
        pModelos++;
    }    
}
