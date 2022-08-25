#include <stdio.h>
void main()
{
    unsigned int x,v,a;
    printf("Input Edge of the Cube: ");
    scanf_s("%d", &x);
    a = 6 * x * x;
    v = x * x * x;
    printf("A of Cube: %d\n", a);
    printf("V of Cude: %d\n", v);
}