int main() {
float x, y, z;
float *pX, *a;
pX = NULL;
a = NULL;
if(pX != NULL) {
x = *pX;
}
else {
x = 20;
}
y = x*3;
z = y/x;
a = &z;
pX = &y;
printf(“Saída: %.1f\n”, (*a - y + *pX));
return 0;
}