//para la segunda rama
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main(){
    int i;
    int *pEntero;
    int vt[N];
    pEntero = vt;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        *pEntero = 1+rand()%100;
        printf("%d ", *pEntero);
        pEntero++;
    }
    return 0;
}