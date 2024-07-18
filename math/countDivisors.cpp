#include<iostream>
#include<vector>
using namespace std;
int main(){
    //TC : O(nlogn)
    int n;
    cin>>n;
    vector<int> ans(n+1);
    for(int i = 1; i<=n; i++){
        for(int j= i;j<=n; j+=i){
            ans[j]++;
        }
    }
    for(auto i : ans){
        cout<<i<<endl;
    }
}