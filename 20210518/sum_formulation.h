#ifndef _H_SUM_FORMULATION_H_
#define _H_SUM_FORMULATION_H_

#include "recursion_solve.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double SumFormulation(int n, Variant vari, double x) {
    switch (vari) {
        case 1:
            return 0; 
            break;
        case 2:
            return 0;
            break;
        case 3:
            return 0;
            break;
            /*
               case 4:
               break;
               case 5:
               break;
               case 6:
               break;
               case 7:
               break;
               */
        default:
            printf("not defined \n");
            exit(-1);
    }
}

#endif
