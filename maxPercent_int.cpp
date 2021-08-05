#include<iostream>
#include <ctime>
#include <stdbool.h>
using namespace std;



int main(){
    srand(time(NULL));
    int a[40];
    cout<<"Điểm của 40 sinh viên:\n";

    for (int i=0; i<40; i++){
        a[i]= rand()% 10;
        cout<<a[i]<<"\t";
    }
    
    int count[11]={0};
    for (int i=0; i<40; i++){
        count[a[i]]++;
    }
    int max =count[0];
    int mode=0;
    for (int i =0; i<11; i++){
        if(count[i]>max){
            max= count[i];
            mode =i;
        }
    }
    cout<<"\nSố điểm có tỉ lệ lớn nhất: "<<mode<< ": "<<max*100.0/40<<"%";


    return 0;
}