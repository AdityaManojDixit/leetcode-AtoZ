#include<bits/stdc++.h>
using namespace std;

//Using Parameterization
void factP(int n,int fact){
    if(n==0){
        cout<<fact<<endl;
        return;
    }
    factP(n-1, fact*n);
}
//Using Functional
int factF(int n){
    if(n==0) return 1;

    return n * factF(n-1);
}

int main(){
    int n = 3;
    factP(n,1); //6
    cout<<factF(n); //6
    return 0;
}