/*
 * MSSV: 19110398
 * Ho va ten: Le Dinh Nguyen
 * Assignment 2 - Connected Components
 * Created at: 2/12/2021
 * IDE: VsCode
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

#define max 100
void create_array(int arrayv[], int num);
void print_array(int arrayv[], int num);
bool OpenFile(string t, ifstream &f);
void resetfile(ifstream &f);
void kiemtrasodinh(ifstream &f, int &dinh);
void filldata(ifstream &f, int arrayv[], int dinh);
void kiemtralienthong(int array[], int dinh, int dske[]);
void tieptuckiemtralienthong(int dske[], int dinh); // tiep tuc cai kiem tra lien thong (function ngay tren 1 dong)
void deleteloop(int s[][max], int dong, int cot);
void swap(int &a, int &b);
void swaprow(int array[][max], int Cot, int K1, int K2);
void selectionSort(int arr[][max], int cot);
void swap(int &a, int &b);
void swaprow(int array[][max], int Cot, int K1, int K2);
void xuatketqua(int kq[][max], int dong, int cot, int dinh);
void lienketlienthong(int s2[][max], int dong, int cot, int sr[][max], int &srrow, int &srcol, int &bgt);
void deleteArray(int a[], int &n, int val);
void kiemtralienthong2(int s2[][max], int dong, int cot, int sr[][max], int &srrow, int &srcol, int &bgt);
void create_array(int arrayv[], int num)
{
    for (int i = 0; i < num; i++) // so dong
    {
        for (int j = 0; j < num; j++) // so cot
        {
            arrayv[i * num + j] = 0;
            //    dong 	| 	cot   (luu y)
            // cout << arrayv[i * num + j] << "\t";
        }
    }
}

void print_array(int arrayv[], int num)
{
    for (int i = 0; i < num; i++) // so dong
    {
        for (int j = 0; j < num; j++) // so cot
        {
            //      		dong | cot   (luu y)
            cout << arrayv[i * num + j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

bool OpenFile(string t, ifstream &f)
{
    f.open(t);
    if (f.is_open()) // kiem tra xem file co open duoc ko?
        return true;
    else
        return false;
}

void resetfile(ifstream &f) // dua con tro len vi tri dau tien trong file input
{
    f.clear();
    f.seekg(0, ios::beg);
}

void kiemtrasodinh(ifstream &f, int &dinh)
{
    int x, dem = 0;
    while (f >> x)
    {
        dem++;
    }
    for (int i = 1; i < dem; i++)
    {
        int result = 0;
        result = dem / i;
        if (result == i)
        {
            dinh = result;
            break;
        }
    }
    resetfile(f); // dua con tro len vi tri dau tien trong file input
}

void filldata(ifstream &f, int arrayv[], int dinh)
{
    for (int i = 0; i < dinh; i++) // so dong
    {
        for (int j = 0; j < dinh; j++) // so cot
        {
            f >> arrayv[i * dinh + j];
        }
    }
    resetfile(f);
}

void kiemtralienthong(int array[], int dinh, int dske[]) // buoc 3: code lai lan 5
{
    int countnums;
    int num = 0;
    int e = 0, r = 0;
    int *result = new int[dinh * dinh];
    // kiem tra xem 1 dinh ket noi voi cac dinh nao khac
    for (int i = 0; i < dinh; i++) // so dong
    {
        countnums = 1;
        dske[e * dinh + 0] = ++num;
        r = 1;
        for (int j = 0; j < dinh; j++) // so cot
        {
            result[i * dinh + j] = 0; // khoi tao gia tri cho mang rong
            if (array[i * dinh + j] == 1)
            {
                result[i * dinh + j] = countnums;
                // cout << result[i * dinh + j];
                dske[e * dinh + r] = 0;
                dske[e * dinh + r] = result[i * dinh + j];
                r++;
            }
            countnums++;
        }
        e++;
    }

    delete[] result;
    tieptuckiemtralienthong(dske, dinh);
}

void tieptuckiemtralienthong(int dske[], int dinh)
{
    int a[max][max], n = 0, m = 0;
    for (int i = 0; i < dinh; i++) // so dong
    {                              // cho cac cap dinh xep voi nhau
        m = 1;
        for (int j = 1; j < dinh; j++) // so cot
        {
            if (dske[i * dinh + j] != 0)
            {
                a[n][0] = dske[i * dinh + 0];
                a[n][m] = dske[i * dinh + j];
                n++;
            }
        }
        m++;
    }

    // luu lai ma tran vua duoc chuyen doi
    int luu[max][max], d = 0, c = 0, big = 0;
    for (int k = 1; k <= dinh; k++)
    {
        c = 0;
        for (int i = 0; i < n; i++) // dong
        {
            if (a[i][0] == k)
            {
                for (int j = 0; j < m; j++) // cot
                {
                    luu[d][c] = a[i][j];
                    c++;
                }
            }
            if (big <= c)
                big = c;
        }
        d++;
    }

    int temp[max], q = 0, b = 0, k = 1, sd, sc, bgt;
    int special[max][max];
    lienketlienthong(luu, d, big, special, sd, sc, bgt);

    int sr[max][max], srrow, srcol, biggest;
    lienketlienthong(special, sd, bgt, sr, srrow, srcol, biggest);

    int mangthu3[max][max], dong3, cot3, bgt3;
    kiemtralienthong2(sr, srrow, biggest, mangthu3, dong3, cot3, bgt3);

    xuatketqua(mangthu3, dong3, bgt3, dinh);

    // int mangthu4[max][max], dong4, cot4, bgt4;
    // test(mangthu3, dong3, bgt3, mangthu4, dong4, cot4, bgt4);
    // xuatketqua(mangthu4, dong4, bgt4, dinh);
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swaprow(int array[][max], int Cot, int K1, int K2)
{ // sap xep thu tu cac dong
    for (int i = 0; i < Cot; i++)
        swap(array[K1][i], array[K2][i]);
}

void selectionSort(int arr[][max], int cot)
{ // kiem tra de sap xep cac dong
    for (int i = 0; i < cot; i++)
    {
        int min_tomo = i;
        for (int j = i + 1; j < cot; j++)
        {
            if (arr[min_tomo][0] > arr[j][0] && arr[min_tomo][0] != 0 && arr[j][0] != 0)
            {
                min_tomo = j;
            }
        }
        swaprow(arr, cot, min_tomo, i);
    }
}

void deleteloop(int x[][max], int dong, int cot)
{ // xoa cac phan tu lap trong 1 thanh phan
    int t, tam;
    for (int i = 0; i < dong; i++)
    {
        t = cot;
        for (int j = 0; j < t; j++)
        {
            for (int k = j + 1; k < t; ++k)
            {
                if (x[i][j] == x[i][k])
                {
                    for (int l = k; l < t; l++)
                    {
                        x[i][l] = x[i][l + 1];
                    }
                    t--;
                    k--;
                }
                // sap xep thu tu trong 1 thanh phan
                if (x[i][j] > x[i][k] && x[i][j] != 0 && x[i][k] != 0)
                {
                    tam = x[i][j];
                    x[i][j] = x[i][k];
                    x[i][k] = tam;
                }
            }
        }
    }
}

void xuatketqua(int kq[][max], int dong, int cot, int dinh)
{
    int conlai[max], sodinh = dinh, sum = 0, tp = 1;
    // tao ra 1 mang de kiem tra thanh phan nao dung 1 minh
    for (int k = 0; k < sodinh; k++)
        conlai[k] = k + 1;

    cout << endl;
    sum = dong;
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (kq[i][j] != 0)
            { // neu trong thanh phan co nhung phan tu trong mang tren thi loai tru ra
                deleteArray(conlai, sodinh, kq[i][j]);
            }
        }
    }

    for (int k = 0; k < sodinh; k++)
        sum += 1;

    cout << "So luong thanh phan lien thong: " << sum << endl;
    for (int i = 0; i < dong; i++)
    {
        cout << "Thanh phan " << tp << ": ";
        for (int j = 0; j < cot; j++)
        {
            if (kq[i][j] != 0)
            { // in ra cac thanh phan lien thong
                cout << kq[i][j] << " ";
                deleteArray(conlai, sodinh, kq[i][j]);
            }
        }
        tp++;
        cout << endl;
    }

    for (int k = 0; k < sodinh; k++)
    { // cac thanh phan dung 1 minh
        cout << "Thanh phan " << tp << ": ";
        cout << conlai[k] << " " << endl;
        tp++;
    }
}

void lienketlienthong(int s2[][max], int dong, int cot, int sr[][max], int &srrow, int &srcol, int &bgt)
{
    srrow = 0;
    srcol = 0;
    bgt = 0;
    for (int i = 1; i <= dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (s2[i - 1][j] != 0)
            {
                sr[srrow][srcol] = s2[i - 1][j]; // luu lai thanh phan thu i
                srcol++;
            }
        }
        bool ch = true;
        for (int z = 0; z < srcol; z++)
        { // kiem tra xem cac thanh phan duoi co bi trung lap ko
            if (sr[srrow][z] == s2[i][0])
            { // neu co thi thoat ra input tiep tuc
                ch = true;
                break;
            }
            else
            { // ko co thi tiep tuc
                ch = false;
                continue;
            }
        }
        if (bgt <= srcol)
            bgt = srcol;
        if (ch == false)
        { // xuong 1 hang trong new array o tren
            srrow++;
            srcol = 0;
        }
    }
    deleteloop(sr, srrow, bgt);
    selectionSort(sr, bgt);
}

void kiemtralienthong2(int s2[][max], int dong, int cot, int sr[][max], int &srrow, int &srcol, int &bgt)
{
    int frow = 0;
    srcol = 0;
    bgt = 0;
    int save;
    int line = 0;
    for (int i = 1; i <= dong; i++)
    { // buoc nay giong nhu ham o tren
        for (int j = 0; j < cot; j++)
        {
            if (s2[i - 1][j] != 0)
            {
                sr[frow][srcol] = s2[i - 1][j];
                srcol++;
            }
        }
        save = srcol;
        bool ch = true;
        for (int z = 0; z < save; z++)
        {
            for (int x = i; x < dong; x++)
            { // neu array duoc luu so sanh voi cac thanh phan ben duoi
                if (sr[frow][z] == s2[x][0])
                { // neu bang nhau thi nhap tiep tren cung 1 array
                    for (int y = 0; y < cot; y++)
                    {
                        if (s2[x][y] != 0)
                        {
                            sr[frow][srcol] = s2[x][y];
                            srcol++;
                        }
                    }
                    line++;
                    ch = true;
                    break;
                }
                else
                {
                    ch = false;
                    continue;
                }
            }
        }
        if (bgt <= srcol)
            bgt = srcol;
        if (ch == false)
        {
            frow++;
            srcol = 0;
        }
    }

    // cout << "Dang kiem tra: " << endl;
    srrow = frow - line + 1;
    deleteloop(sr, frow, bgt);
    selectionSort(sr, bgt);
    // cout << "dong: " << srrow << "\n"
    //      << "cot: " << bgt << endl;
    // for (int i = 0; i < srrow; i++)
    // {
    //     for (int j = 0; j < bgt; j++)
    //     {
    //         if (sr[i][j] != 0)
    //         {
    //             cout << sr[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

void deleteArray(int a[], int &n, int val)
{
    int i;
    int count = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] == val)
            count++;
        else
            a[i - count] = a[i];
    }
    n -= count;
}

int main()
{
    // doc file input test.txt
    ifstream filess;

    // buoc 1
    OpenFile("input_dothi.txt", filess); // open file input

    // khai bao cac gia tri
    int soluongdinh;
    int row, col;

    kiemtrasodinh(filess, soluongdinh);

    // xu ly phan mang

    col = row = soluongdinh;

    int *array = new int[row * col];
    int *dske = new int[row * col];
    create_array(array, soluongdinh); // khoi tao mang dua tren so luong dinh

    // buoc 2
    // setup code voi ma tran ke (luu y cho file input voi ma tran ke)
    filldata(filess, array, soluongdinh); // input tu file vao mang 2 chieu

    //print_array(array, soluongdinh); // in mang 2 chieu ra man hinh console

    // buoc 3
    create_array(dske, soluongdinh);

    kiemtralienthong(array, soluongdinh, dske);

    // buoc 4
    // xuat ket qua

    delete[] array;
    delete[] dske;
    filess.close();

    return 1;
}

// End coding 13/12/2021