#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool canSum(int n, vector<int> arr){
    static map<int,bool> mp;
    if(n==0) return true;
    if(n<0) return false;
    if(mp.find(n) != mp.end()) return mp[n];
    for(auto it : arr){
        int rem = n - it;
        if(canSum(rem,arr) == true){
            mp[rem] = true;
            return true;
        }
    }
    mp[n] = false;
    return false;
}

int main(){
    vector<int> arr = {2,3};
    cout<<canSum(7,arr);
}