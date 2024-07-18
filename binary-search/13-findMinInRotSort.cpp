#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//Assuming array has unique elements
int findMin(vector<int> arr, int n){
    int s = 0;
    int e = n-1;
    int mini = INT_MAX;
    while(s<=e){
        int mid = s + (e-s)/2;

        if(arr[s] <= arr[mid]){ //<= because if low and mid point at same element.In case only two elements are left in searchspace.
            //left half sorted
            mini = min(mini, arr[s]); //taking min from sorted subspace
            s = mid + 1; //eliminating sorted subspace
        }
        else if(arr[mid] <= arr[e]){ //<= because if low and mid point at same element.In case only two elements are left in searchspace.
            //right half sorted
            mini = min(mini, arr[mid]); //taking min from sorted subspace
            e = mid - 1; //eliminating sorted subspace
        }
    }
    return mini;
}

int main(){
  vector<int> arr = {7,8,9,0,2,3,4,5,6};
  int n = arr.size();
  cout<<findMin(arr,n);
  return 0;
}