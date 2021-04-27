#include <stdlib.h>
#include <stdio.h>
#include "vetor.h"
#define MAX 10

//int vetor[MAX]; //global
int main()
{
//int vetor[MAX]; //automatico
int *vetor = calloc(MAX,sizeof(int)); // dinamico

fill(vetor,MAX,20);
int i;
for(i = 0; i<MAX-1;i++ ) {
    printf("%d, ",vetor[i]);
}
printf("%d",vetor[i]);

int encontrar;
printf("\nColoque o valor que deseja encontrar:");
scanf("%d",&encontrar);

int indice = find(vetor,MAX,encontrar);
if(indice == -1) printf("\nO valor que pediu nao se encontra no array");
else printf("\nO valor que pediu encontrasse no indice %d",indice);


//procura no segmento
int max,min;
printf("\n\nQual é o limite inferior?:");
scanf("%d",&min);
printf("\nQual e o limite superior?:");
scanf("%d",&max);

indice = find(vetor+min,MAX-max,encontrar);
if(indice == -1) puts("\nO valor que pediu nao se encontra no array");
else printf("\nO valor que pediu encontrasse no indice %d",indice+min);

scanf("%d",&encontrar);
    return 0;
}
