#include<bits/stdc++.h>
using namespace std;
int fun(int a , int b){
    if(b==0) return 1;
    int temp = fun(a,b/2);
    int result = temp * temp;
    if(b%2 != 0) return result * a;
    return result;
   
}
int main(){
  cout<<fun(5,3);
  return 0;
}