#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string printSCS(string s1, string s2, int n, int m){
    
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
    
    int i=n,j=m;
    string res = "";
    while(i>0 && j>0)
    {
        cout<<"i: "<<i<<" j: "<<j<<endl;
        if(s1[i-1]==s2[j-1])
        {
            res.push_back(s1[i-1]);
            cout<<"Included: "<<s1[i-1]<<endl;
            cout<<"String: "<<res<<endl;
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                res.push_back(s1[i-1]);
                cout<<"Included: "<<s1[i-1]<<endl; 
                cout<<"String: "<<res<<endl;
                i--;
            } else{
                res.push_back(s2[j-1]);
                cout<<"Included: "<<s2[j-1]<<endl; //We are not adding s2[j] but s2[j-1] because j is size and index is j-1!!
                cout<<"String: "<<res<<endl;
                j--;
            }
        }
    }
    while(i>0) 
    {
        res.push_back(s1[i-1]);
        cout<<"Included: "<<s1[i-1]<<endl;
        cout<<"String: "<<res<<endl;
        i--;
    }
    while(j>0) 
    {
        res.push_back(s2[j-1]);
        cout<<"Included: "<<s2[j-1]<<endl;
        cout<<"String: "<<res<<endl;
        j--;
        
    }
    reverse(res.begin(),res.end()); 
    return res;
    
}



int main() {
    
    string s1 = "acbcf";
    string s2 = "abcdaf";
    int n = s1.length();
    int m = s2.length();
    cout<<"Shortest Common Supersequence: "<<printSCS( s1, s2, n,m)<<endl; 
}