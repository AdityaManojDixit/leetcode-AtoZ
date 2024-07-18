#include<iostream>
#include<map>
#include<utility>
using namespace std;
#define ll long long


ll gridTravel(ll m, ll n){
    pair<ll,ll> p;
    static map<pair<ll,ll>,ll> mp;

    if(m==0 || n==0) return 0;
    if( m == 1 && n == 1) return 1;

    p = make_pair(m,n);

    if(mp.find(p) != mp.end()) return mp[p];

    mp[p] = gridTravel(m-1,n ) + gridTravel(m, n-1);

    return mp[p];
}
int main(){
    
    cout<<gridTravel(18,18);
    return 0;
}