#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    stack<int> st;
    string s;
    cout<<"Enter string"<<endl;
    cin>>s;
    for(int i = 0; i <s.length(); i++)
    if( s[i] =='(' ||  s[i] =='{' ||  s[i] =='['){
        st.push(s[i]);
    }
    else if( s[i] =='}' ||  s[i] == ']' ||  s[i] ==')'){
        if(st.top() == -1){
            cout<<"Unbalanced";
        }
        if( s[i] == '}' && st.top()=='{'){
            st.pop();
        }
        else if( s[i] ==']' && st.top()=='['){
            st.pop();
        }
        else if( s[i] ==')' && st.top()=='('){
            st.pop();
        }
    }
    return 0;
}