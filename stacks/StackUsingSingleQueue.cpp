#include<bits/stdc++.h>
using namespace std;

//Theory:
// We are using a single queue
// Steps:-
// 1) Push into the queue
// 2) Push() front() elements of queue back into the queue for q.size()-1 no. of times. 

// Time Complexity: push() : O(n) 
//Space Complexity : O(n)

queue<int> q;

void push(int x){
    q.push(x);
    
    for(int i =0; i<q.size()-1; i++){
        q.push(q.front());
        q.pop();
    }
}

void pop(){
    if(q.empty()) {cout<<"Underflow"<<endl; return;} 
    q.pop();
}

int top(){
    if(q.empty()) {cout<<"Underflow"<<endl; return -1;} 
    return q.front();
}

void print_stack(){
    queue<int> temp = q;
    if(temp.empty()) {cout<<"Underflow"<<endl; return;} 
    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main(){
  push(5);
  push(3);
  push(2);
  push(1);
  pop();
  push(8);
  print_stack();
  cout<<"Top:"<<top()<<endl;
  return 0;
}