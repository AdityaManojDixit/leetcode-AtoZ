#include<iostream>
#include<cstring>
#include<vector>
using namespace std;



int subsetSumToK(int n, int sum, vector<int> &arr) {
    static vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

    if(sum == 0) return 1;
    if(n == 0 && sum!= 0) return 0;
    if(dp[n][sum] != -1) return dp[n][sum];

    if(arr[n-1] <= sum){
        dp[n][sum] =  subsetSumToK(n-1, sum - arr[n-1], arr) | subsetSumToK(n-1, sum, arr);
        return dp[n][sum];
    }
    else if(arr[n-1] > sum){
        dp[n][sum] = subsetSumToK(n-1, sum, arr);
        return dp[n][sum];
    }
    
}


int main(){
    vector<int> arr = { 2,3,7,8,10 };
    int sum = 1;
    cout<< subsetSumToK(5, sum, arr); 
    
    return 0;
}