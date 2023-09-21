#include "ponto.h"

float calcularAreaPoligono(Ponto A, Ponto B, Ponto C) {
    return 0.5 * (A.X * B.Y + B.X * C.Y + C.X * A.Y - B.X * A.Y - C.X * B.Y - A.X * C.Y);
}
