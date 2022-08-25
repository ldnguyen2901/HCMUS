#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
int main()
{
    int sobimat = 0, sodudoan = 0, bodem = 1, choitiep=1;
    const int max = 100, min = 1;

    while (choitiep != 0)
    {
        system("cls");
        //Khoi tao sobimat
        srand(time(NULL));
        sobimat = (rand() % (max - min + 1)) + min;
        //Khoi tao bodem
        bodem = 1;
        do
        {
            printf("Nhap so du doan: ");
            scanf_s("%d", &sodudoan);
            if (sodudoan < sobimat)
            {
                printf("lon hon\n");
                bodem += 1;
            }
            else if (sodudoan > sobimat)
            {
                printf(" nho hon\n");
                bodem += 1;
            }
            else
                printf("Chuc mung ban da doan dung so bi mat sau %d lan\n", bodem);
        } while (sodudoan != sobimat);
        printf(" Cam on ban da tham gia tro choi\n");
        printf(" Ban co muon tham gia tiep khong (1/0)\n");
        printf("Moi nhap so khac voi so 0 de choi tiep :  ");
        scanf_s("%d", &choitiep);
    }
    system("pause");
    return 0;
}