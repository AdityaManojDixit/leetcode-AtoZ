#include<iostream>
#include<vector>
#define ll long long
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        long long sum=0;
        int ct=0,sm=0;
        for(int i=0;i<x;i++){
            int a;
            cin>>a;
            if(a==2){ct++;}
            else sm++;
            sum+=a;
        }
        if(sum%2==0)
        {
                if(sm%2 ==0 && ct%2==0) cout<<"YES"<<endl;
                else if(ct%2!=0 && sm%2==0 && sm!=0) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
        
        }
        else cout<<"NO"<<endl;
    }   
return 0;
}