#include<bits/stdc++.h>
using namespace std;
vector<int> a(5);
int n = 5;
int front = 0;
int rear = 0;
int cnt = 0;

void push(int num){
  if(cnt == n){
    cout<<"Queue is Full!"<<endl;
    return;
  }
  a[rear%n] = num;
  rear++;
  cnt++;
}

void pop(){
  if(cnt == 0){
    cout<<"Queue is Empty!"<<endl;
    return;
  }
  a[front%n] = -1;
  front++;
  cnt--;
}

void print(){
  if(cnt == 0){
    cout<<"Queue is Empty!"<<endl;
    return;
  }
  for(int i = front; i<=rear-1; i++){
    cout<<a[i%n]<<" ";
  }
  cout<<endl;
}

int main(){
  print();
  push(5);
  push(3);
  push(1);
  push(2);
  push(8);
  pop();
  pop();
  pop();
  push(5);
  push(4);
  push(1);
  pop();

 
  print();
  cout<<"Front:"<<front<<endl<<"Rear:"<<rear<<endl<<"Count:"<<cnt<<endl;
  return 0;
}