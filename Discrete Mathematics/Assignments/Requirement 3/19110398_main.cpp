/*
 * MSSV: 19110398
 * Ho va ten: Le Dinh Nguyen
 * Assignment 3 - Shortest-Path Problems
 * Created at: 23/12/2021
 * IDE: VsCode
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

#define inf 999
#define max 100

bool OpenFile(string t, ifstream &f);
void resetfile(ifstream &f);
void print_array(int arrayv[], int num);
void laynhungdongladanhsachcanh(ifstream &f, int arraydsc[][3], int &soluongduongdi, bool loaidothi, int &start, int &end);
bool kiemtraloaidothi(ifstream &f, int &sodinh);
void vohuong(int arraydsc[][3], int soluongduongdi, int array[], int sodinh);
void cohuong(int arraydsc[][3], int soluongduongdi, int array[], int sodinh);
void Dijkstra(int array[], int sodinh, int start, int end, ofstream &fileout);
void output(int array[], int sodinh, int start, int end, int cost, ofstream &fileout);

bool OpenFile(string t, ifstream &f)
{
    f.open(t);
    if (f.is_open())
        return true;
    else
    {
        cout << "Could not Open File...!" << endl;
        exit(1);
    }
}

void resetfile(ifstream &f) // dua con tro len vi tri dau tien trong file input
{
    f.clear();
    f.seekg(0, ios::beg);
}

void create_array(int arrayv[], int num)
{
    for (int i = 0; i < num; i++) // so dong
    {
        for (int j = 0; j < num; j++) // so cot
        {
            arrayv[i * num + j] = inf;
            //    dong 	| 	cot   (luu y)
            // cout << arrayv[i * num + j] << "\t";
        }
    }
}

void print_array(int arrayv[][3], int num)
{
    for (int i = 0; i < num; i++) // so dong
    {
        for (int j = 0; j < num; j++) // so cot
        {
            cout << arrayv[i][j] << " ";
            //    dong 	| 	cot   (luu y)
            // cout << arrayv[i * num + j] << "\t";
        }
        cout << endl;
    }
}

void laynhungdongladanhsachcanh(ifstream &f, int arraydsc[][3], int &soluongduongdi, bool loaidothi, int &start, int &end)
{
    int x, demlan1 = 1, demlan2 = 1;
    int c = 0;
    soluongduongdi = 0;
    while (f >> x)
    {
        demlan1++;
    }
    resetfile(f);
    int dau = 2,
        cuoi = demlan1 - 2,
        xuonghang = 0;
    for (int i = 0; i < demlan1; i++)
    {
        f >> x;
        if (dau < demlan2 && demlan2 < cuoi)
        {
            arraydsc[soluongduongdi][c] = x;
            c++;
            xuonghang++;
            if (xuonghang % 3 == 0)
            {
                soluongduongdi++;
                c = 0;
            }
        }

        if (demlan2 == demlan1 - 2)
        {
            start = x;
        }

        if (demlan2 == demlan1 - 1)
        {
            end = x;
        }
        demlan2++;
    }
}

bool kiemtraloaidothi(ifstream &f, int &sodinh)
{
    int a;
    f >> a;
    f >> sodinh;
    resetfile(f);
    return a;
}

void vohuong(int arraydsc[][3], int soluongduongdi, int array[], int sodinh)
{
    for (int i = 0; i < soluongduongdi; i++)
    {
        array[(arraydsc[i][0] - 1) * sodinh + (arraydsc[i][1] - 1)] = arraydsc[i][2];
        array[(arraydsc[i][1] - 1) * sodinh + (arraydsc[i][0] - 1)] = arraydsc[i][2];
    }
    print_array(arraydsc,sodinh);
}

void cohuong(int arraydsc[][3], int soluongduongdi, int array[], int sodinh)
{
    for (int i = 0; i < soluongduongdi; i++)
    {
        array[(arraydsc[i][0] - 1) * sodinh + (arraydsc[i][1] - 1)] = arraydsc[i][2];
    }print_array(arraydsc,sodinh);
}

void printa(int ar[], int n)
{
    for (int i = 0; i < n; i++)
        cout << ar[i] << "\t";
    cout << endl;
}

void Dijkstra(int array[], int sodinh, int start, int end, ofstream &fileout)
{
    int *dodai = new int[sodinh];
    int *dinhcha = new int[sodinh];
    bool *done = new bool[sodinh];

    int ganday = start;
    int small_vitri = start;
    int cost, i = 0;
    int small;
    while (!(i >= sodinh))
    {
        dinhcha[i] = i;
        done[i] = false;
        dodai[i] = inf;
        i++;
    }
    dodai[start] = 0;
    dinhcha[start] = start;
    done[start] = true;

    for (; !(small_vitri == -2);)
    {
        int j = 0, k = 0;
        small = inf;
        small_vitri = -2;

        while (j < sodinh)
        {
            if (array[ganday * sodinh + j] != inf && done[j] == false)
            {
                if (!((dodai[ganday] + array[ganday * sodinh + j]) >= dodai[j]))
                {
                    dinhcha[j] = ganday;
                    dodai[j] = dodai[ganday] + array[ganday * sodinh + j];
                }
            }
            j++;
        }

        while (k < sodinh)
        {
            if (done[k] == false && small > dodai[k])
            {
                small_vitri = k;
                small = dodai[k];
            }
            k++;
        }

        if (small_vitri != -2)
        {
            ganday = small_vitri;
            done[small_vitri] = true;
        }
    }
    // for (int i = 0; i < sodinh; i++)
    //     cout << i << "\t";
    // cout << endl;
    // printa(dodai, sodinh);
    // printa(dinhcha, sodinh);

    cost = dodai[end];

    output(dinhcha, sodinh, start, end, cost, fileout);

    delete[] dodai;
    delete[] dinhcha;
    delete[] done;
}

void output(int array[], int sodinh, int start, int end, int cost, ofstream &fileout)
{
    int screen = array[end]; 
    int n = 0, save[n];
    save[n] = end; 
    if (end == start)
    {
        cout << "Tong chi phi di chuyen = " << 0 << endl;
        cout << "Duong di ngan nhat cua do thi la: " << start + 1 << " -> " << end + 1;
        fileout << "Tong chi phi di chuyen = " << 0 << endl;
        fileout << "Duong di ngan nhat cua do thi la: " << start + 1 << " -> " << end + 1;
    }
    else
    {
        cout << "Tong chi phi di chuyen = " << cost << endl;
        fileout << "Tong chi phi di chuyen = " << cost << endl;
        for (; start != save[n];) 
        {
            for (int i = sodinh - 1; i >= 0; i--) // hang thu tu
            {
                if (i == screen)
                {
                    n++;
                    save[n] = i;       
                    screen = array[i]; 
                }
            }
        }
        int muiten = n;
        cout << "Duong di ngan nhat cua do thi la: ";
        fileout << "Duong di ngan nhat cua do thi la: ";
        for (int k = n; k >= 0; k--)
        {
            cout << save[k] + 1;
            fileout << save[k] + 1;
            while (muiten > 0)
            {
                cout << " -> ";
                fileout << " -> ";
                muiten--;
                break;
            }
        }
    }
}
int main()
{
    ifstream filess;
    ofstream fileout("ket_qua_bai_3_19110398.txt");
    int loaidothi, sodinh, start, end;

    OpenFile("thong_tin_dinh.txt", filess);
    loaidothi = kiemtraloaidothi(filess, sodinh);
    int *array = new int[sodinh * sodinh];
    int arraydsc[max][3], soluongduongdi;
    create_array(array, sodinh);

    laynhungdongladanhsachcanh(filess, arraydsc, soluongduongdi, loaidothi, start, end);

    loaidothi == 1 ? cohuong(arraydsc, soluongduongdi, array, sodinh)
                   : vohuong(arraydsc, soluongduongdi, array, sodinh);

    // cout << "Start: " << start << endl
    //      << "End: " << end << endl;

    Dijkstra(array, sodinh, start - 1, end - 1, fileout);

    delete[] array;
    filess.close();
    return 0;
}