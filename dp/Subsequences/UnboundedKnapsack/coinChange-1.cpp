#include<iostream>
using namespace std;

int coinChange(int coin[], int N, int sum) {

    int t[N+1][sum+1];
    for(int j =0; j<sum+1; j++){
        t[0][j] = 0;
    }
    for(int i=0; i<N+1; i++){
        t[i][0] = 1;
    }

    for(int i = 1; i<N+1; i++){
        for(int j =1; j<sum +1; j++){
            if(coin[i-1] <= j){
                t[i][j] = t[i-1][j] + t[i][j-coin[i-1]];
            }
            else 
            {
                t[i][j] = t[i-1][j];
            }
        }
    }

    for (int i = 0; i < N+1; ++i) {
        for (int j = 0; j < sum+1; ++j) {
            cout << t[i][j] << " ";
        }
        cout << endl;
}

    return t[N][sum];   
}

int main(){
    int coin[] = { 1, 2,3 };
    int sum = 5;
    cout<<"Tabulation :"<<  coinChange(coin, 3, sum);
    return 0;
}