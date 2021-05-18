#include "recursion_solve.h"
#include "sum_formulation.h"

#include <stdio.h>
int main() {
    int n = 5;

    // toward different variant
    for (int vari = 1; vari <= 3; ++ vari) {
        for (double x = 0.5; x > - 0.6; x -= 0.1) {
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
}
