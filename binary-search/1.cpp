#include<bits/stdc++.h>
using namespace std;
//Given Sorted Array
//Find index of key

int bs(vector<int> arr, int l, int r, int key)
{
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == key) return mid;
        if(arr[mid]<key){
            l = mid + 1;
        }
        else if (arr[mid] > key) {
            r = mid -1;
        }
    }
    return -1;
}

int bsr(vector<int> arr, int l, int r, int key){
    if(l>r) return -1;
    int mid = l + (r-l)/2;
    if(arr[mid] == key) return mid;
    else if(arr[mid] < key) {
        return bs(arr, mid+1, r, key);
    }
    else if (arr[mid] > key) {
        return bs(arr, l, mid-1, key);
    }
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8};
  int key = 2;
  int n = arr.size();

  cout<<bs(arr, 0, n-1, key);
  cout<<bsr(arr, 0, n-1, 5);

  return 0;
}