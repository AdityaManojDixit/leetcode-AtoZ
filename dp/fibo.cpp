#include<iostream>
#include<map>
using namespace std;



long long int fibo(long long int n){

    static map<long long int,long long int> mp;

    if(mp.find(n) != mp.end()) return mp[n];
    if(n<=2) return 1;

    mp[n] = fibo(n-1) + fibo(n-2);

    return mp[n];  
}
int main(){
    
    cout<<fibo(50);
    return 0;
}