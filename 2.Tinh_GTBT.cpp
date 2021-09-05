#include <iostream>
#include <iomanip>

using namespace std;
int luythua(int x, int n)
{
    if (x == 0 || x == 1)
        return x;
    if (n == 0)
        return 1;
    return x * luythua(x, n - 1);
}
double tinhtong(int x, int n)
{
    double sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += (double)luythua(x, i) / (i + 1);
    }
    return sum;
}
int main()
{
    int x = 2;
    int n = 2;
    cout << "Ket qua: " << setprecision(3) << tinhtong(x, n) << endl;

    return 0;
}