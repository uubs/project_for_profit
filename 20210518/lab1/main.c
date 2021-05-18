#include "recursion_solve.h"
#include "sum_formulation.h"

#include <stdio.h>
int main() {
    Init(500, TAIL, 2, 0.5);
    Run();
    printf("result is %f\n", result());

    Init(500, NONTAIL, 2, 0.5);
    Run();
    printf("result is %f\n", result());

    Init(500, COMBINE, 2, 0.5);
    Run();
    printf("result is %f\n", result());
    
    printf("\n");
}
