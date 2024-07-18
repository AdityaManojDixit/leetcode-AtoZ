#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int dp[4][51]; //dp[n+1][W+1]
//vector<vector<int>>dp(n+1, vector<int>(W+1,-1));

int knapSackMemo(int wt[], int val[], int W, int n){
    
    if(dp[n][W] != -1){ return dp[n][W];}
    if(n==0 || W==0){ return 0; }

    if(wt[n-1] <= W){
        dp[n][W] = max(val[n-1] + knapSackMemo(wt,val,W-wt[n-1],n-1), knapSackMemo(wt,val,W,n-1));
        return dp[n][W];
    }
    else if( wt[n-1] > W){
        dp[n][W] = knapSackMemo(wt,val,W,n-1);
        return dp[n][W];
    }
}


int knapsackTab(int wt[], int val[], int w, int n){
    int t[n+1][w+1]; //RowsIndices: 0->n, ColumnsIndices: 0->w
    //Initialization
    for(int i=0; i<n+1; i++){         
        for(int j=0; j<w+1; j++){
            if(i==0 || j ==0) //Base Case
            { 
                t[i][j] = 0; 
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j = 1; j<w+1; j++){
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][w]; //Final result stored in bottom-right t[n][w] grid. 
}

int main(){
    memset(dp, -1, sizeof(dp));
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 };
    int w = 50; 
    cout<<"Memoisation :"<< knapSackMemo(wt,val,w,3)<<endl;
    cout<<"Tabulation :"<< knapsackTab(wt,val,w,3);
    return 0;
}