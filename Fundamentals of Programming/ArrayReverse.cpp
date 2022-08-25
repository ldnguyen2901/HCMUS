#include <stdio.h>
void array_input(int arr[], int* pn, int max_size)
{
	scanf_s("%d", pn);
	while (*pn < 0 || *pn > max_size) {
		printf("Nhap so phan tu trong khoang tu %d den %d: ", 0, max_size);
		scanf_s("%d", pn);
	}
	for (int i = 0; i < *pn; i++)
		scanf_s("%d", &arr[i]);
}

void array_output(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%4d", arr[i]);
}

void swap(int* p, int* q)
{
	int t = *p;
	*p = *q;
	*q = t;
}

/*
void array_reverse(int arr[], int n)
{
	int i, j;
	for (i = 0, j = n - 1; i < j; i++, j--)
		swap(&arr[i], &arr[j]);
}
*/

void array_reverse(int arr[], int n)
{
	int i, j;
	for (i = 0, j = n - 1; i < j; i++, j--)
		swap(arr+i, arr+j);
}

void array_reverse_recursive(int arr[], int n)
{
	if (n > 1)
	{
		swap(arr, arr + n - 1);
		array_reverse_recursive(arr + 1, n - 2);
	}
}

#define dim(a) (sizeof(a)/sizeof(a[0]))

int main()
{
	int a[20], na;
	printf("Nhap mang a (so phan tu va cac phan tu): ");
	array_input(a, &na, dim(a));
	array_output(a, na);
	puts("");
	array_reverse_recursive(a, na);
	array_output(a, na);
	printf("\n");
	return 0;
}
