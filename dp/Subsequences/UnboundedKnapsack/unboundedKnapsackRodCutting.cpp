#include<iostream>
#include<cstring>
#include<vector>
using namespace std;


int unboundedKnapsackTab(int length[], int price[], int N, int n){
    int t[n+1][N+1]; //RowsIndices: 0->n, ColumnsIndices: 0->w
    //Initialization
    for(int i=0; i<n+1; i++){         
        for(int j=0; j<N+1; j++){
            if(i==0 || j ==0) //Base Case
            { 
                t[i][j] = 0; 
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j = 1; j<N+1; j++){
            if(length[i-1] <= j){
                t[i][j] = max(price[i-1] + t[i][j-length[i-1]] , t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < N+1; ++j) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return t[n][N]; //Final result stored in bottom-right t[n][w] grid. 
}

int main(){
    int length[] = { 1,2,3,4,5,6,7,8 }; 
    int price[] = { 1,5,8,9,10,17,17,20 };
    int N = 8; 
    cout<<"Tabulation :"<< unboundedKnapsackTab(length, price, N, 8);
    return 0;
}