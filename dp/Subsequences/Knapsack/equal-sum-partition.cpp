#include<iostream>
using namespace std;


bool subsetSum(int arr[], int sum, int n){
    bool t[n+1][sum+1];

    for(int i =0 ; i<n+1; i++){
        for(int j =0; j<sum+1; j++){
            if(i==0){
                t[i][j] = false;
            }
            if(j==0){
                t[i][j] = true;
            }
        }
    }

    for(int i = 1; i<n+1; i++){
        for(int j =1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j - arr[i-1]] | t[i-1][j];
            }
            else if(arr[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}
bool equalPartition(int n, int arr[]){
    int sum =0;
    for(int i =0;i<n; i++){
        sum = sum + arr[i];
    }
    if(sum %2 != 0){
        return false; //Sum of array is odd hence cannot be divided into 2 equal parts.
    }
    else if( sum %2 == 0){
       return subsetSum(arr, sum/2 , n);
    }
}
int main(){
    
    int arr[] = { 1,3,5,1};
    cout<<"Tabulation :"<<  equalPartition(4, arr);
    return 0;
}
