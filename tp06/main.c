#include <stdio.h>
#include "calculadoraPosfixa.h"

int main() {
    
    printf("Resultado 1: %.2f\n", avaliarExpressaoPosfixada("3 4 + 5 *")); 
    printf("Resultado 2: %.2f\n", avaliarExpressaoPosfixada("7 2 * 4 +"));  
    printf("Resultado 3: %.2f\n", avaliarExpressaoPosfixada("8 5 2 4 + * +")); 
    printf("Resultado 4: %.2f\n", avaliarExpressaoPosfixada("6 2 / 3 + 4 *"));  
    printf("Resultado 5: %.2f\n", avaliarExpressaoPosfixada("9 5 2 8 * 4 + * +")); 
    printf("Resultado 6: %.2f\n", avaliarExpressaoPosfixada("2 3 + log 5 /"));
    printf("Resultado 7: %.2f\n", avaliarExpressaoPosfixada("10 log 3 ^ 2 +"));
    printf("Resultado 8: %.2f\n", avaliarExpressaoPosfixada("45 60 + 30 cos *"));   
    printf("Resultado 9: %.2f\n", avaliarExpressaoPosfixada("0.5 45 sen 2 ^ +")); 
    printf("Resultado 10: %.2f\n", avaliarExpressaoPosfixada("3 4 + 5 tan *")); 

    return 0;
}
