#include <bits/stdc++.h>
using namespace std;

char* xoakhoangtrangthua(char * str)
{
    int j=0; 
    int n=strlen(str);
    for (int i=0; i<n; i++)
    {
        if (str[i]!=' ')
        {
            str[j++]= str[i];
        } 
        else if (j>0 && str[i+1]!=' ')  //them 1 dau cach giua 2 tu 
        {
            str[j++]=str[i];
        }
    }                        //[chu cai khac][dau cach][ky tu \0](str[i+1]='\0'   !=  ' ')
    if (str[j-1]== ' ')     //dau cach thua o cuoi chuoi them vao do exception tu else if
    {
        str[j-1]='\0';
    }
    else
    {
        str[j]='\0';        //Ket thuc chuoi 
    }
    return str;
}
void reverseWords(string s)
{
     
    // temporary vector to store all words
    vector<string> tmp;
        // add each character to form a word ended after encountering space 
        string str = "";
    for (int i = 0; i < s.length(); i++)
    {
         
        // Check if we encounter space
        // push word (str) to vector
        // and make str NULL
        if (s[i] == ' ')
        {
            tmp.push_back(str);
            str = "";
        }
 
        // Else add character to
        // str to form current word
        else
            str += s[i];
    }
   
    // Last word remaining __first word of the sentence__, no space else, add it to vector
    tmp.push_back(str);
 
    // print from last to first in vector
    for (int i = tmp.size() - 1; i >= 0; i--)
        cout << tmp[i] << " ";
}
 
// Driver Code
int main()
{
    char s[] = "     Learn    Object    Oriented     Programing    ";
    reverseWords(xoakhoangtrangthua(s));
    return 0;
}