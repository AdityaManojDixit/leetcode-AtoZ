#include<bits/stdc++.h>
using namespace std;

// Rules:
// 1) For Outer Loop : Count no of rows
// 2) For Inner Loop : Focus on columns and connect them somehow to the rows
// 3) Print the '*' inside inner for loop
// 4) Observe Symmetry in case of patterns (optional)

int main(){
  
  for(int i = 0; i<4; i++){
    for(int j = 0; j<4; j++){
        cout<<"*"<<" ";
    }
    cout<<endl;
  }  
  return 0;
}