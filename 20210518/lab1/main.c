#include "recursion_solve.h"
#include "sum_formulation.h"

#include <stdio.h>
int main() {
    int n = 5;

    // toward different variant
    int vari = 8;
    for (double x = 1.9; x > 0.1; x -= 0.1) {
        Init(n, TAIL, vari, x);
        Run();
        printf("tail recursion (n = 5, variant = %d, x = %f): result is %f\n", vari, x, result());

        Init(n, NONTAIL, vari, x);
        Run();
        printf("nontail recursion (n = 5, variant = %d, x = %f): result is %f\n", vari, x, result());

        Init(n, COMBINE, vari, x);
        Run();
        printf("combine recursion (n = 5, variant = %d, x = %f): result is %f\n", vari, x, result());

        printf("\n");

    }
}
