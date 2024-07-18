#include<bits/stdc++.h>
using namespace std;
//No. of time an array is rotated depends on index of min element (pivot)
//Linear Search = O(n)
//Binary Search = O(logn)
//Min element will always lie in unsorted array.
int bs(vector<int> arr, int s, int e,int n) {
  int start = s;
  int end = e;
  while(s<=e){
    int mid = s + (e-s)/2;
    int next = (mid + 1)%n;
    int prev = (mid + n - 1)%n;
    if(arr[mid] < arr[prev] && arr[mid] < arr[next]) return mid;
    else if(arr[start] <= arr[mid]){
      s = mid + 1;
    }
    else if(arr[mid] <= arr[end]) {
      e = mid - 1;
    }
  }
}


int main(){
  
  vector<int> arr = {2,5,6,8,11,12,15,18};
  int n = arr.size();
  int index_min = bs(arr, 0, n-1,n);
  int res;
  (n-index_min == n)?res=0:res=n-index_min;
  cout<<res;

  return 0;
}