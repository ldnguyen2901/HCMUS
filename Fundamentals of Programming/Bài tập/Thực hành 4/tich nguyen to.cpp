#include<stdio.h>
#include<conio.h>
int main()
{
	int N;
	scanf_s("%d", &N);
	for (int i = 2; i <= N; i++){
		int ngt = 2;
		int a = i;
		int dem = 0;
		printf("%d = ", a);
		while (a > 1){
			if (a%ngt == 0){
				dem++;
				if ((a/ngt) % ngt != 0){
					printf("%d", ngt);
					if (dem > 1)printf("^%d ", dem);
					if (dem == 1)printf(" ");
					if (a / ngt > 1)printf("x ");
				}
				a /= ngt;
			}
			else {
				ngt++;
				dem = 0;
			}
		}
		printf("\n");
	}


	printf("\n");
	getchar();
	return 0;
}

