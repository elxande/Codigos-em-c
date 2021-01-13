#include <stdio.h>

int main(){
    float x, y, z[4];
    float *pX, *a;
    a = z;
    z[0] = 40;
    y = z[0]/10;
    z[1] = z[0]*y;
    z[2] = z[1] - 1;
    z[3] = 100;
    pX = a+2;
    x = *a + pX[1];
    printf("*a: %f\n", *a);
    printf("x: %f\n", x);
    printf("pX[0]: %f\n", pX[0]);
    z[2] = 5;
    printf("%f\n", (x - pX[0]));

    return 0;
}