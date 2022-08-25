#include <stdio.h>
void main()
{
    int a;
    printf("Input Integer: ");
    scanf_s("%d", &a);
    a /= 2;
    printf("%d", a);
}