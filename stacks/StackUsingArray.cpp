#include<bits/stdc++.h>
using namespace std;
vector<int> st(5);
int top = -1;
int n = 5;


void push(int num){
    if(top == n-1 ) {
        cout<<"Overflow"<<endl;
        return;
    }
    top++;
    st[top] = num;
}

void pop(){
    if(top == -1){
        cout<<"UNderflow"<<endl;
        return;
    }
    top--;
   
}

void print(){
    if(top == -1){
        cout<<"UNderflow"<<endl;
        return;
    }
    for(int i = 0; i<=top; i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
}

int main(){
  

  
  push(5);
  push(3);
  push(1);
  push(2);
  push(4);
  print();
  pop();
  print();

  return 0;
}