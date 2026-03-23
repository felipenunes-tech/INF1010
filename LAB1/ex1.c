//Felipe Nunes 2320615
//Cristiano Ferreira 2320397

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *vet, int tamanhoVet){

    int i;
    for(i = 0; i<tamanhoVet; i++){
        for (int j = 0; j<(9-i); j++){
            if(vet[j] > vet[j+1]){
                int temp =vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }

    } 
}

int main(){

    int vet[10];
    int tamanhoVet = sizeof(vet)/sizeof(vet[0]);

    srand(time(NULL));

    printf("Before\n");
    for (int i = 0; i < tamanhoVet; i++){
        vet[i] = rand() % 101; 
        printf(" Vet[%d]: %d |", i, vet[i]);
    }
    
    bubbleSort(vet, tamanhoVet);

    printf("\nAfter\n");
    for (int i = 0; i < tamanhoVet; i++){
        printf(" Vet[%d]: %d ", i, vet[i]);
    }

    return 0;
}
