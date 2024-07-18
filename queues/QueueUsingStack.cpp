#include<bits/stdc++.h>
using namespace std;
//Theory:
// We will be using two stacks st1 & st2
// Steps:-

// push()
// 1) Move contents of St1 into st2
// 2)Push into st1
// 3) Move contents of st2 into st1

// pop()
// 1) st1.pop()

//TC : O(N), SC: O(2N)

stack<int> st1;
stack<int> st2;

void push(int x){
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
    st1.push(x);
    while(!st2.empty()){
        st1.push(st2.top());
        st2.pop();
    }
}

void pop(){
    if(st1.empty()) {cout<<"Queue is empty"<<endl; return;}
    st1.pop();
}

int front(){
    return st1.top();
}

void print_queue(){
    stack<int>temp = st1;
    
    while(!st1.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main(){
    
    push(5);
    push(4);
    push(3);
    pop();
    
  print_queue();
    return 0;
}