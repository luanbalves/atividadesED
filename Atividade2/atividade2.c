#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *arr[20] = {
    "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga",
    "abacate", "kiwi", "cereja", "morango", "pêssego", "goiaba", "melancia",
    "framboesa", "amora", "caqui", "figo", "papaya"
};

int trocas = 0;
int comparacoes = 0;

void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

void quicksort(int inicio, int fim) {
    if (inicio < fim) {
        int i = inicio;
        int j = fim;
        char *sup = arr[(i + j) / 2];

        do {
            while (strcmp(arr[i], sup) < 0) {
                i++;
                comparacoes++;
            }
            while (strcmp(arr[j], sup) > 0) {
                j--;
                comparacoes++;
            }
            if (i <= j) {
                trocar(&arr[i], &arr[j]);
                i++;
                j--;
            }
        } while (i <= j);

        quicksort(inicio, j);
        quicksort(i, fim);
    }
}

int main() {
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    
    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("(%d) %s\n", i + 1, arr[i]);
    }
    
    quicksort(0, tamanho - 1);
    
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("(%d) %s\n", i + 1, arr[i]);
    }
    
    printf("\nNúmero de trocas: %d\n", trocas);
    printf("Número de comparações: %d\n", comparacoes);
    
    int indiceMediana = tamanho / 2;
    printf("Mediana: %s\n", arr[indiceMediana]);
    
    FILE *arquivo = fopen("saida.txt", "w");
    if (arquivo == NULL) {
        perror ("Erro ao abrir o arquivo");
        return 1;
    }
    
    fprintf(arquivo, "Número de trocas: %d\n", trocas);
    fprintf(arquivo, "Número de comparações: %d\n", comparacoes);
    fprintf(arquivo, "Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "(%d) %s\n", i + 1, arr[i]);
    }
    
    fclose(arquivo);
    
    return 0;
}
