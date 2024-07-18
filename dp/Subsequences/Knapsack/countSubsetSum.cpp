#include<iostream>
using namespace std;

int countSubsetSum(int arr[], int sum, int n){
    
    int t[n+1][sum+1];

    for(int i =0 ; i<n+1; i++){
        for(int j =0; j<sum+1; j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j] = 1;
            }
        }
    }

    for(int i = 1; i<n+1; i++){
        for(int j =1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
            }
            else if(arr[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }

    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < sum+1; ++j) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return t[n][sum];
}

int main(){
    
    int arr[] = { 1, 0, 8 ,5 ,1, 4 };
    int sum = 18;
    cout<<"Tabulation :"<<  countSubsetSum(arr, sum, 6);
    return 0;
}
