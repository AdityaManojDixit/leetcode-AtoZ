#include<bits/stdc++.h>
using namespace std;

int bsfo(vector<int> arr, int s, int e, int key){
    int result = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if( arr[mid] == key){
            result = mid;
            e = mid - 1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        else if( arr[mid] > key){
            e = mid -1;
        }
    }
    return result;
}

int bslo(vector<int> arr, int s, int e, int key){
    int result = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if( arr[mid] == key){
            result = mid;
            s = mid +1;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        else if( arr[mid] > key){
            e = mid -1;
        }
    }
    return result;
}

int main(){
  vector<int> arr = {1,2,10,10,10,10,10,10,10,10,10,10,12,13,14};
  int key = 10;
  int n = arr.size();
  int fo = bsfo(arr, 0, n-1, key);
  int lo = bslo(arr, 0, n-1, key);
  int res = lo - fo + 1;
  cout<<res;

  return 0;
}