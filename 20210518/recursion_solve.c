#include "recursion_solve.h"

static int _n; // natural n
static Mode _mode; // recursive mode
static Variant _vari; // variants of individual tasks, 
static double _x; // _x satisfy the given limitation

// static double result_int; // store int result
static double _result; // store double result

// F(1) value for all variant
static double _F1[30] = {0}; // value in _F1[0] nosense
// F(2) value for all variant
static double _F2[30] = {0};

// Init F1 F2 value for different variants
static void InitF1F2() {
    _F1[1] = 1;
    _F2[1] = -1 * _x / 2;

    _F1[2] = 1;
    _F2[2] = -1 * _x / 3;
    
    _F1[3] = 1;
    _F2[3] = -1 * _x * (2 * 2 - 3) / (2 * 2 - 2);

    // ...
} 

// set initial natural n
// set recursive mode
// set recurrent formula
// set initial x value
void Init(int n, Mode mode, Variant vari, double x) {

    _n = n;
    _mode = mode;
    _vari = vari;
    _x = x;
    _result = 0.0;
    InitF1F2();
}

////////////////////////////////////////////////////////////
/////////Process different Variant   //////////////////////
//////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
static double ChooseVariant3ForTailRecursive(int i, double fi_1) {
    switch (_vari) {
        case 1:
            return -1 * fi_1 * _x * (2 * i - 3) / (2 * i);
            break;
        case 2:
            return -1 * fi_1 * _x * (3 * i - 7) / ( 3 * i - 3);
            break;
        case 3:
            return -1 * fi_1 * _x * (2 * i - 3) / (2 * i - 2);
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

static double ChooseVariantForTailRecursive(int this, double val, int idx) {
    switch (idx) {
        case 1:
            // return F(1)
            return _F1[_vari]; 
            break;
            
        case 2:
            return _F2[_vari];
            break;

        case 3:
            return ChooseVariant3ForTailRecursive(this, val);
            break;
        default:
            printf("error\n");
            exit(-1);
    }

}

////////////////////////////////////
// Tail recursive Implementation///
///////////////////////////////////
// for variant no-1
// TailRecursive(n, 2, -x/2)

static double ChooseVariantForTailRecursive(int this, double val, int idx); 

static void _TailRecursive(int n, int this, double val) {
    if (n == 1) {
        _result += ChooseVariantForTailRecursive(this, val, 1); // change 1
        return ;
    } else if (n == 2) {
        _result += ChooseVariantForTailRecursive(this, val, 1); 
        _result += ChooseVariantForTailRecursive(this, val, 2); // change 2
        return ;
    } else { // n != 1 , 2
        // this == 2
        // cal F(this + 1)
        val =  ChooseVariantForTailRecursive(this, val, 3); // change 3
        ++ this;
        _result += val;
        return _TailRecursive(n - 1, this, val);

    }
}


static void TailRecursive() {
    _result = 0.0;
    _TailRecursive(_n, 3, ChooseVariantForTailRecursive(0, 0, 2)); // change
}
////////////////////////////////////
// NONTail recursive Implementation///
///////////////////////////////////

static double ChooseVariantForNONTailRecursive(int this, double val, int idx) {
    return ChooseVariantForTailRecursive(this, val, idx);
}

static double _NONTailRecursive(int n) {
    if (n == 1) {
        _result += ChooseVariantForNONTailRecursive(0, 0, 1); // change 1
        return ChooseVariantForNONTailRecursive(0, 0, 1);
    } else if (n == 2) {
        _result += ChooseVariantForNONTailRecursive(0, 0, 1); 
        _result += ChooseVariantForNONTailRecursive(0, 0, 2); 
        return ChooseVariantForNONTailRecursive(0, 0, 2);// change2
    } else {
        double tmp = _NONTailRecursive(n - 1); // F(n - 1)
        tmp = ChooseVariantForNONTailRecursive(n, tmp, 3); // F(n) // change 3
        _result += tmp;
        return tmp;
    }
}

static void NONTailRecursive() {
    _result = 0.0;
    _NONTailRecursive(_n);
}
////////////////////////////////////
// Combined recursive Implementation///
///////////////////////////////////


// member - recursive descent - nontail recursion
// the sum - recursive returen - tail recursion


double CombinedNONTAILRecursive(int n) {
    if (n == 1) {
        return ChooseVariantForNONTailRecursive(0, 0, 1);
    } else if (n == 2) {
        return ChooseVariantForNONTailRecursive(0, 0, 2);// change2
    } else {
        double tmp = CombinedNONTAILRecursive(n - 1); // F(n - 1)
        tmp = ChooseVariantForNONTailRecursive(n, tmp, 3); // F(n) // change 3
        return tmp;
    }
}

void CombinedTAILRecursive(int n) {
    if (n == 1) {
        _result += ChooseVariantForNONTailRecursive(0, 0, 1); // change 1
        return ;
    } else if (n == 2) {
        _result += ChooseVariantForNONTailRecursive(0, 0, 1); 
        _result += ChooseVariantForNONTailRecursive(0, 0, 2); 
        return;
    } else { 
        double tmp = CombinedNONTAILRecursive(n); // F(n)
        _result += tmp;
        return CombinedTAILRecursive(n - 1);
    }
}


void Combined() {
    _result = 0.0;
    CombinedTAILRecursive(_n);
}

////////////////////////////////////////
//////////Run the Variants/////////////
//////////////////////////////////////
void Run() {
    switch(_mode) {
        case TAIL:
            TailRecursive();
            break;
        case NONTAIL:
            NONTailRecursive();
            break;
        case COMBINE:
            Combined();
            break;
    }
}

////////////////////////////////////////
//////////get the result/////////////
//////////////////////////////////////
double result() {
    return _result; 
}

