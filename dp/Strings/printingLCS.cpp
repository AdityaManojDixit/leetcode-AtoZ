#include<iostream>
#include<string>
#include<algorithm>
#include <cstring>
using namespace std;

static int t[1001][1001];
    
int LCSRecursive(string x, string y, int n, int m){
    if(n==0 || m ==0 ){
        return 0;      //Length of common LCS if any of string is empty             
    } 

    if(x[n-1] == y[m-1]){
        return 1 + LCSRecursive(x,y,n-1, m-1); //Adding last matched character to length 
    }
    else{
        return max(LCSRecursive(x,y,n, m-1), LCSRecursive(x,y,n-1, m)); //Not adding 1 as last char didn't matched
    }
}

int LCSMemo(string x, string y, int n, int m){
    
    if(n==0 || m ==0 ) return 0;      //Length of common LCS if any of string is empty             
    if(t[n][m] != -1) return t[n][m];
    

    if(x[n-1] == y[m-1]){
        t[n][m] = 1 + LCSRecursive(x,y,n-1, m-1); //Adding last matched character to length
        return t[n][m]; 
    }
    else{
        t[n][m] = max(LCSRecursive(x,y,n, m-1), LCSRecursive(x,y,n-1, m)); //Not adding 1 as last char didn't matched
        return t[n][m];
    }
}

int LCSTab(string x, string y, int n, int m){
    
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
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }

    return t[n][m];
}

int main(){
    memset(t,-1, sizeof(t));
    string x = "abcdgh";
    string y = "abedfhr";
    int n = x.length();
    int m = y.length();
    cout<<"Recursion: "<<LCSRecursive( x,  y,  n,  m)<<endl;
    cout<<"Memoisation: "<<LCSMemo( x,  y,  n,  m)<<endl;
    cout<<"Tabulation: "<<LCSTab( x,  y,  n,  m)<<endl;
}