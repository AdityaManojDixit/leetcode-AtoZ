#include<bits/stdc++.h>
using namespace std;

//Using Parameterization
void sumOfNP(int i,int sum){ //Passing sum as parameter
    if(i<1){
        cout<<sum<<endl;
        return;
    }
    sumOfNP(i-1,sum+i); 
}

//Using Functional
int sumOfNF(int i){
    if(i == 0){
        return 0;
    }
    return i + sumOfNF(i-1);
}

int main(){
    int n = 5;

    sumOfNP(n,0); //15
    cout<<sumOfNF(n); //15

    return 0;
}