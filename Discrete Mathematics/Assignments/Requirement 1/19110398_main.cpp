#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;

int array[][2] = {0, 0, 1, 0, 0, 1, 1, 1};
// {1, 2, 3, 4, 5, 6, 7, 8};
// {0, 0, 0, 1, 1, 0, 1, 1};

bool phudinh(int a) // phep phu dinh ~
{
    return !a;
}

bool va(int p, int q) //phep va (and) ^
{
    int z = (p == true && q == true ? true : false);
    return z;
}

bool hoac(int p, int q) //phep hoac, hay (or) v
{
    int z = (p == true || q == true ? true : false);
    return z;
}

bool keotheo(int p, int q) //phep keo theo ->
{
    int z;
    int a = phudinh(p);
    return z = hoac(a, q);
}

bool iff(int p, int q) //keo theo 2 chieu
{
    int z;
    return z = va(keotheo(p, q), keotheo(q, p));
}

char transforms(int var)
{
    return (var == 1 ? 'T' : var == 0 ? 'F': ' ');
}

int D2B(int n)
{
    int Bn[32]; //Bn is binary number
    int i = 0;
    for (; n > 0; n /= 2, i++)
        Bn[i] = n % 2;
    int result = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        result *= 10;
        result += Bn[j];
    }
    return result;
}

void OutputAll(int n)
{
    cout << "p\tq\t~p\tp^q\tpvq\tp->q\tp<->q\n";
    for (int i = 0; i < n; i++)
    {
        int pmuq = 0;
        int nguoclai = 0;
        int pvq = 0;
        int motchieu = 0;
        int tuongduong = 0;

        nguoclai = phudinh(array[i][2]);
        pmuq = va(array[i][0], array[i][1]);
        pvq = hoac(array[i][0], array[i][1]);
        motchieu = keotheo(array[i][0], array[i][1]);
        tuongduong = iff(array[i][0], array[i][1]);

        cout << transforms(array[i][0]) << "\t" << transforms(array[i][1]) << "\t"
             << transforms(nguoclai) << "\t" << transforms(pmuq) << "\t" << transforms(pvq) << "\t"
             << transforms(motchieu) << "\t\t" << transforms(tuongduong)
             << endl;
    }
    cout << endl;
}

void printTruthTable(char o[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(o, "~") == 0)
        {
            cout << "p\tq\t~p" << endl;
            for (int i = 0; i < 4; i++)
            {
                int nguoclai = 0;
                nguoclai = phudinh(array[i][0]);
                cout << transforms(array[i][0]) << "\t" << transforms(array[i][1]) << "\t"
                     << transforms(nguoclai) << endl;
            }
            cout << endl;
            break;
        }

        else if (strcmp(o, "v") == 0)
        {
            cout << "p\tq\tpvq" << endl;
            for (int i = 0; i < 4; i++)
            {
                int pvq = 0;
                pvq = hoac(array[i][0], array[i][1]);
                cout << transforms(array[i][0]) << "\t" << transforms(array[i][1]) << "\t"
                     << transforms(pvq) << endl;
            }
            cout << endl;
            break;
        }
        else if (strcmp(o, "^") == 0)
        {
            cout << "p\tq\tp^q" << endl;
            for (int i = 0; i < 4; i++)
            {
                int pmuq = 0;
                pmuq = va(array[i][0], array[i][1]);
                cout << transforms(array[i][0]) << "\t" << transforms(array[i][1]) << "\t"
                     << transforms(pmuq) << endl;
            }
            cout << endl;
            break;
        }
        else if (strcmp(o, "->") == 0)

        {
            cout << "p\tq\tp->q" << endl;
            for (int i = 0; i < 4; i++)
            {
                int motchieu = 0;
                motchieu = keotheo(array[i][0], array[i][1]);
                cout << transforms(array[i][0]) << "\t" << transforms(array[i][1]) << "\t"
                     << transforms(motchieu) << endl;
            }
            cout << endl;
            break;
        }
        else if (strcmp(o, "<->") == 0)
        {
            cout << "p\tq\tp<->q" << endl;
            for (int i = 0; i < 4; i++)
            {
                int tuongduong = 0;
                tuongduong = iff(array[i][0], array[i][1]);
                cout << transforms(array[i][0]) << "\t" << transforms(array[i][1]) << "\t"
                     << transforms(tuongduong) << endl;
            }
            cout << endl;
            break;
        }
        else
            cout << "ok " << i << endl;
    }
    cout << endl;
}

int Line(int soluongbien)
{
    int row_temp = 2;
    for (int m = 0; m < soluongbien - 1; m++)
        row_temp *= 2;
    return row_temp;
}

void create_array(int array[], int col, int row)
{

    cout << "So luong bien: " << col << endl;
    row = Line(col);
    cout << "Co " << row << " Dong" << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i * col + j] = 0;
            //      hang | cot   (luu y)
            //cout << array[i * col + j] << "\t";
        }
        //cout << endl;
    }
    cout << endl;
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        int temp = 0;
        temp = D2B(count);
        for (int j = 0; j < col; j++)
        {
            array[i * col + j] = temp % 2; //xuat nguoc
            temp /= 10;
            cout << array[i * col + j] << "\t";
        }
        cout << endl;
        count++;
    }
    cout << endl;
}

void OutputAutoTruthTableBasic(int array[], int soluongbien, int lines)
{
    int pvq;
    for (int i = 0; i < lines; i++)
    {
        //pvq = 0;
        for (int j = 0; j < soluongbien; j++)
        {
            //test phep OR

            //pvq = hoac(array[i * soluongbien + j - 1], array[i * soluongbien + j]);

            cout << array[i * soluongbien + j] << "\t";

            // cout << endl;
        }
        pvq = hoac(array[i * soluongbien + j], array[i * soluongbien + j]);
        for (int t = 1; t < soluongbien ; t++)
        {
            pvq = hoac(array[i * soluongbien + j-1], array[i * soluongbien + j]);
        }
        cout << "pvq" << endl;
    }
    cout << endl;
}

int main()
{
    // dang thuc thi in bang chan tri voi n bien
    int soluongbien = 2;         //cai nay la col nha
    int row = Line(soluongbien); // tao hang tuong duong voi so luong bien

    int *array = new int[row * soluongbien];

    create_array(array, soluongbien, row);

    OutputAutoTruthTableBasic(array, soluongbien, row); //dang tiep tuc, chua hoan thanh

    delete[] array;

    //in bang chan tri theo 2 bien
    OutputAll(4);
    char options[][5] = {"~", "v", "^", "->", "<->"};
    for (int i = 0; i < 5; i++)
        printTruthTable(options[i]);
}