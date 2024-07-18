#include<iostream>
using namespace std;

void printNameKTimes(int i , int k){
    if(i>k){ 
        return;
    }
    cout<<"Aditya"<<endl;
    printNameKTimes(i+1,k);
}

int main(){
    int k;
    cin>>k;
    printNameKTimes(1,k);
} 