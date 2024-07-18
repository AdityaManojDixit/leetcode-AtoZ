#include<iostream>
#include<string>
#include<algorithm>
#include <cstring>
using namespace std;

int LCString(string x, string y, int n, int m){

    int t[n+1][m+1];
    for(int i =0; i<n+1; i++){
        t[i][0] = 0;
    }
    for(int j =0; j<m+1; j++){
        t[0][j] = 0;
    }

    for(int i=1; i<n+1; i++){
        for(int j =1; j<m+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = 0;
            }
        }
    }

    int max = -1e9;
    for(int i=1; i<n+1; i++){
        for(int j =1; j<m+1; j++){
            if(t[i][j] > max){
                max = t[i][j];
            }
        }
    }

    return max;
}

int main(){
    
    string x = "abcdgh";
    string y = "abedfhr";
    int n = x.length();
    int m = y.length();
    cout<<"Tabulation: "<<LCString( x,  y,  n,  m)<<endl;
}