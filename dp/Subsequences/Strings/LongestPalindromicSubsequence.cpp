#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int LCS(string s1, string s2, int n, int m){
    
    int dp[n+1][m+1];
    for(int i = 0 ; i<n+1; i++){
        dp[i][0] = 0;
    }
    for(int j = 0 ; j<m+1; j++){
        dp[0][j] = 0;
    }

    for(int i = 1 ; i<n+1; i++){
        for(int j = 1 ; j<m+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int longestPalindromeSubseq(string a) {
    int n = a.length();
    string rev_a = a;
    reverse(rev_a.begin(), rev_a.end());
    return LCS(a, rev_a, n, n);
}

int main() {
    
    string a = "agbcba";
    cout<<"Length: "<<longestPalindromeSubseq(a)<<endl;
}






