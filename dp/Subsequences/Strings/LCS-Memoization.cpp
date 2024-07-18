#include<iostream>
#include<string>
#include<cstring>
using namespace std;

static int dp[1000][1000];

int LCS(string s1, string s2, int n, int m){
    if(n==0 || m == 0){
        return 0;
    }
    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n-1] == s2[m-1]){
        dp[n][m] = 1 + LCS(s1, s2, n-1, m-1);
        return dp[n][m];
    }
    else{
        dp[n][m] = max(LCS(s1, s2, n, m-1), LCS(s1, s2, n-1, m));
        return dp[n][m];
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    string s1 = "abcde";
    string s2 = "ace";
    int n = s1.length();
    int m = s2.length();
    cout<<"Length: "<<LCS( s1, s2, n, m)<<endl;
}