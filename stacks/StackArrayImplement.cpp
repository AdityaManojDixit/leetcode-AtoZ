#include<iostream>
using namespace std;
#define MAX_SIZE 100
int arr[MAX_SIZE];
int top = -1;

void pop(){
    if(top == -1) {
        cout<<"Underflow Condition";
        return;
    }
    
    top = top - 1;
}

void push(int data){
    if(top == MAX_SIZE-1) {
        cout<<"Overflow Condition";
        return;
    }
    
    arr[++top] = data; 
}

void Top(){
    if(top == -1) {
        cout<<"Underflow Condition";
        return;
    }

    cout<<arr[top];
}

bool isEmpty(){
    if(top == -1)
        cout<<"Stack Empty!"<<endl;
    else 
        cout<<"Stack Not Empty!"<<endl;
}

void printStack(){
    for(int i = top; i >=0; i--){
        cout<<"->"<<arr[i]<<endl;
    }
}

int main(){
    push(5);
    push(4);
    push(3);
    pop();  


    ggf zz
    printStack();
    
    return 0;
}
