#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    FILE *arquivo;
    int numeroVertices;
    float area = 0.0;

    arquivo = fopen("trianguloABC.txt", "r");
    
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    fscanf(arquivo, "%d", &numeroVertices);
    
    if (numeroVertices < 3) {
        printf("Um polígono deve ter pelo menos 3 vértices, portanto altere o valor de vertices.\n");
        fclose(arquivo);
        return 1;
    }
    
    Ponto *vertices = (Ponto *)malloc(numeroVertices * sizeof(Ponto));
    
    for (int i = 0; i < numeroVertices; i++) {
        fscanf(arquivo, "%f %f", &(vertices[i].X), &(vertices[i].Y));
    }
    
    fclose(arquivo);
    
    for (int i = 0; i < numeroVertices - 1; i++) {
        area += calcularAreaPoligono(vertices[0], vertices[i], vertices[i + 1]);
    }
    
    if (area < 0) {
        area = -area;
    }
    
    printf("A área do polígono é: %.2f\n", area);
    
    return 0;
}
