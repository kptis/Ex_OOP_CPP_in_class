#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5
void randMang(int a[], int x);
void xuatMang(int a[], int x);
void quick_sort_incre(int a[], int l, int r);
//C2:

/*
#include<iostream>
using namespace std;
 
// sap xep lai mang  theo quick sort
void quick_sort ( int a[] , int l , int r )
{
     
       if ( l > r ) return ;
       int x = a[(l+r)/2];
       int i = l , j = r;
       while ( i < j )
       {
            while ( a[i] < x && i <=r ) i++;
            while ( a[j] > x && j >= l ) j--;
            if ( i <=j )
            {
                swap(a[i],a[j]);
                i++; j--;
            }
        }
    if ( l< j ) quick_sort(a,l,j);
    if ( i < r) quick_sort(a,i,r);
}
 
int main()
{
     
        int a[9] = { 2 ,5,1,1,3,3,1,2,6};
        quick_sort(a,0,8);
        int count =1, result = 1;
        // dung de tim so lan xuat hien nhieu nhat
       
        for ( int i = 0 ; i < 9 ; i++)
        {
             if ( a[i] != a[i+1] ) count = 1; // neu ma a[i] ! =a[i+1] thi van de bien count =1;
             else count++; // khong thi tang no len
             
         // so sanh voi bien ket qua
         
           if ( result < count )
           {
                result = count;
           }
       
        }
        int count1=1;
        cout << "\nCac so xuat hien nhieu nhat la: " ;
        // duyet lai 1 lan nua de xem co nhung phan tu nao cung xuat hien voi so lan max
       
        for ( int i = 0 ; i < 9; i++)
        {
            if ( a[i] != a[i+1]) count1=1;
            else count1++;
            if ( count1== result)
            {
                cout << a[i] << " , ";
            }
        }
        cout << " \n So lan xuat hien: " << result ;
        cin.get();
        return 0;
}
*/

int main()
{
    int a[n];
    randMang(a, n);
    printf("\n");
    xuatMang(a, n);
    int count = 1, max = 1;
    quick_sort_incre(a, 0, n - 1);
    printf("\n");
    xuatMang(a, n);
    //Tim so lan xh max
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1])
            count = 1;
        else
            count++;

        if (max < count)
            max = count;
    }
    printf("\n");
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
            printf("%d\t ", a[i]);
        }
    }
    printf("Xuat hien voi so lan max = %d", max);

    return 0;
}
void randMang(int a[], int x)
{
    srand(time(NULL));
    for (int i = 0; i < x; i++)
    {
        a[i] = rand() % 100;
    }
}
void xuatMang(int a[], int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("%d\t", a[i]);
    }
}

void quick_sort_incre(int a[], int l, int r)
{

    if (l > r)
        return;
    int x = a[(l + r) / 2];
    int i = l, j = r;
    while (i < j)
    {
        while (a[i] < x && i <= r)
            i++;
        while (a[j] > x && j >= l)
            j--;
        if (i <= j)
        {
            int tmp = a[i];
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