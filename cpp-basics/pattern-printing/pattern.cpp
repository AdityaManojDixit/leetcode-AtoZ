#include<bits/stdc++.h>
using namespace std;
char arr[20][20];
void change_row(int n){
    for(int i = 0 ; i<20; i++){
        arr[n][i] = '_';
    }
}

void change_col(int n){
    for(int i = 0 ; i<20; i++){
        arr[i][n] = '|';
    }
}

void make_parabola(){
    int x;
    int y = x*x + 2*x + 4;
    for(x = 0 ; x<20 ; x++){
        if(y == 0){
            arr[x][y] = '%';
        }
    }
}

void print(){
for(int i = 0; i<20; i++){
    for(int j = 0; j<20; j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(){
  
  memset(arr, '*', sizeof(arr));
    make_parabola();
    print();
  
 
  return 0;
}