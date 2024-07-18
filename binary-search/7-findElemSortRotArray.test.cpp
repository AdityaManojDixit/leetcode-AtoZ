#include<bits/stdc++.h>
using namespace std;
//It should be guranteed that arry is rotated
//else it would give wrong answer on non-rotated sorted array
int fsmalle(vector<int> arr, int s, int e, int n) {
  int start = s;
  int end = e;
  if(arr[s] < arr[e]) return s;

  while(s<=e){
    int mid = s + (e-s)/2;
    int next = (mid + 1)%n;
    int prev = (mid-1+n)%n;
    if(arr[mid] < arr[prev] && arr[mid] <= arr[next]){
      return mid;
    }
    else if( arr[start] < arr[mid]){
      s = mid + 1;
    }
    else if( arr[mid] < arr[end]){
      e = mid - 1;
    }
  }
}

int main(){
  
  vector<int> arr = {  ,12,15,10,10,10,10};
  int n = arr.size();
  cout<<fsmalle(arr, 0, n-1,n);
  
  // int res;
  // (n-index_min == n)?res=0:res=n-index_min;
  // cout<<res;

  return 0;
}  