#include <stdio.h>

int flag = 1;

double Check(double x, int n) {
    if (n == 1) return 1;
    if (n == 2) return 1 - x / 2;
    double res = 1 - x / 2;
    double fi_1 = -1 * x / 2;

    if (flag) {
        printf("f[2] = %f\n", fi_1);
    }
    for (int i = 3; i <= n; ++ i) {
        fi_1 = -1 * fi_1 * x * (2 * i - 3) / ( 2 * i );
        if (flag) {
            printf("f[%d] = %f\n", i,  fi_1);
        }
        res += fi_1;
    }

    return res;
}

int main() {
    Check(0.5, 8);
    flag = 0;
    printf("Check(0.5, 1) : %f\n", Check(0.5, 1));
    printf("Check(0.5, 2) : %f\n", Check(0.5, 2));
    printf("Check(0.5, 3) : %f\n", Check(0.5, 3));
    printf("Check(0.5, 4) : %f\n", Check(0.5, 4));
    printf("Check(0.5, 5) : %f\n", Check(0.5, 5));
    printf("Check(0.5, 100) : %f\n", Check(0.5, 100000));

}
