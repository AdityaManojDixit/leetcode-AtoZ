#include<bits/stdc++.h>
using namespace std;
//Smallest index such that element at index i.e. arr[index] >= key
int lb(vector<int> arr, int x,int n){
    int s = 0;
    int e = n - 1;
    int result = n;
    while(s<=e){
        int mid = s + (e-s)/2;
        if( arr[mid] >= x){
            result = mid; //Store index in result as it may be an ans.
            e = mid -1; //Look out for smaller index
        }
        else if( arr[mid] < x){ //Element smaller than key
            s = mid + 1; //Look out for greater index such that element >= key
        }
    }
    return result; 
}
int main(){
  vector<int> arr= {3,5,8,15,19};
  int n = arr.size();
  int x = 9;
  cout<< lower_bound( arr.begin(), arr.end(), x ) - arr.begin();
  cout<< endl;
  cout<< lb(arr, x, n);
  return 0;
}