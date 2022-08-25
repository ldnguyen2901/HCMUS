#include <stdio.h>
void main()
{
    unsigned int n,x,y;
    printf("Input Seconds: ");
    scanf_s("%d", &n);
    x = n;
    y = n;
    x = x / 60;
    y = y % 60;
    n = n - 60;
    printf("Test: %d minutes %d seconds", x,y);
}