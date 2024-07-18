#include<bits/stdc++.h>
using namespace std;

//Time Complexity (reduced to): O(1) amortized (in most of the cases)
//Space Complexity : O(2n)

stack<int> input;
stack<int> output;

void push(int x){
    input.push(x);
}

void pop(){
    if(!output.empty()){
        output.pop();
    }
    else{
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        output.pop();
    }

}

int top(){
    if(!output.empty()){
        return output.top();
    }
    else{
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }
}

void print_queue(){
    if(!input.empty()){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    } 
    stack<int> temp = output;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}


int main(){
  push(5);
  push(3);
  push(1);
  push(9);
  pop();
  pop();
  push(8);
  pop();
  pop();
  print_queue();
  return 0;
}