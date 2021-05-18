#ifndef _H_RECUSION_SOLVE_H_
#define _H_RECUSION_SOLVE_H_

typedef enum Mode { TAIL, NONTAIL, COMBINE } Mode; // choose the mode of recursive
typedef int Variant;

//////////////////////////////////////////////
/////// Use Process             //////////////
/////// 1. init(n, mode, vari, x)  //////////////
/////// 2. run()                //////////////
/////// 3. ret = result()       //////////////
/////////////////////////////////////////////
extern void Init(int n, Mode mode, Variant vari, double x);
extern void Run(); 
extern double result();


#endif
