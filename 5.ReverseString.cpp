

// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
 

void reverseStr(string &str)
{
    int n = str.length();
 
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
 
// Driver program
int main()
{
    string str = "Learn Object Oriented Programming";
    reverseStr(str);
    cout << str;
    return 0;
}