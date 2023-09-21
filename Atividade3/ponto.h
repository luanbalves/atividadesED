#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float X;
    float Y;
} Ponto;

float calcularAreaPoligono(Ponto A, Ponto B, Ponto C);

#endif
