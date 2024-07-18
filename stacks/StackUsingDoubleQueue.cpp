#include<bits/stdc++.h>
using namespace std;

// Theory:
// We will use 2 queues Q1 & Q2
// Steps:-

// Push(x)
// 1) Add x to Q2
// 2) Move elements of Q1 to Q2 (Element by element)
// 3) Swap all elements of Q1 & Q2

// Pop()
// 1) Remove top of Q1

// Time Complexity: push() : O(n) | pop(): O(n)
queue<int> q1;
queue<int> q2;

void push(int x){
    
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    q1.swap(q2);
}
void pop(){
    if(q1.empty()) cout<<"Underflow"<<endl;
    q1.pop();
}
int top(){
    return q1.front();
}

void print_stack(){
    queue<int> temp = q1;

    if(temp.empty()) cout<<"Underflow"<<endl;

    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main(){
    print_stack();
    push(3);
    push(4);
    push(1);
    push(2);
    pop();
    pop();
    pop();
    push(4);
    push(1);
    print_stack();

    int tops = top();
    cout<<"Top:"<<tops<<endl;
  
  return 0;
}