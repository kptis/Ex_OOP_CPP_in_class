//Bai tap Cpp 20210803
#include <iostream>
#include <ctime>
#include <stdbool.h>
#include <fstream>
#include <iomanip> //setw()
#include <string>

// #include <bit/stdc++.h>

using namespace std;
void writeFileText(string fileName, int n)
{
    // if (fileName != NULL)
    // {
    srand(time(NULL));
    fstream file_mark;
    file_mark.open(fileName, ios::out);
    file_mark << n << "\n";

    for (int i = 0; i < n; i++)
    {
        file_mark << (1+rand() % 4) * 2.3 << "\n";
    }
    file_mark.close();

    cout << "Successfully write file " << fileName << endl;
    // }
}
void writeFileBin(string fileName, int n)
{
    ofstream file_mark_bin(fileName, ofstream::binary);
    file_mark_bin.write((char *)&n, sizeof(int));
    double a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = (1+rand() % 4) * 2.3;
        file_mark_bin.write((char *)&a[i], sizeof(double));
    }
    file_mark_bin.close();
    cout << "Successfully write file " << fileName << endl;
}

void ReadFileBin(double mark[], int *n, string fileName)
{
    ifstream inFile(fileName, ifstream::binary);
    int i = 0;
    inFile.seekg(0, ios::beg); // dua contro ve vi tri dau file
    // inFile.seekg(4, ios::beg);
    inFile.read((char *)n, sizeof(int));
    while (!inFile.eof())
    {
        inFile.read((char *)&mark[i++], sizeof(double));
    }
    inFile.close();
}

void quick_sort_incre(double a[], int l, int r)
{

    if (l > r)
        return;
    double x = a[(l + r) / 2];
    int i = l, j = r;
    while (i < j)
    {
        while (a[i] < x && i <= r)
            i++;
        while (a[j] > x && j >= l)
            j--;
        if (i <= j)
        {
            double tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    if (l < j)
        quick_sort_incre(a, l, j);
    if (i < r)
        quick_sort_incre(a, i, r);
}

void maxPercent(string fileName, int n, double a[])
{
    //Tim so lan xh max
    //a[]: mang diem cua sinh vien
    ofstream result;
    result.open(fileName, ios::out);
    result << "Statistic for marks with the highest rates:\n";
    quick_sort_incre(a, 0, n-1);
    int max = 0;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1])
            count = 1;
        else
            count++;

        if (max < count)
            max = count; // tim ra max
    }
    cout<< max<<endl;

    int _count = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1])
        {
            _count = 1;
        }
        else
            _count++;

        if (_count == max)
        {
            result << setw(5) << a[i] << setw(9) << max * 100.0 / 40 << "%\n"
                   << endl;
        }
    }
    // printf("Xuat hien voi so lan max = %d", max);
    //
    cout << "Successfully write file " << fileName << endl;
    result.close();
}

int main()
{
    double marks[50];
    int numOfMarks = 40;
    string inputTxt = "Marks.txt";
    string inputBin = "Marks.bin";
    string outputFile = "MaxPercent.txt";
    writeFileText(inputTxt, numOfMarks);
    writeFileBin(inputBin, numOfMarks);
    int n;
    ReadFileBin(marks, &n, inputBin);
    maxPercent(outputFile, n, marks);
    return 0;
}