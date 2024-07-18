#include<bits/stdc++.h>
using namespace std;
//Assuming array has duplicate elements
bool srsa(vector<int> arr, int x, int n){
    int s = 0;
    int e = n-1;

    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == x) return true;

        if(arr[s] == arr[mid] && arr[mid] == arr[e]){ //Corner case when start == mid == end. Hence unalbe to find sorted subspace.
          s = s + 1; //Shrink subspace from start until start == end
          e = e - 1; //Shrink subspace from end until start == end
          continue;
        }

        if(arr[s] <= arr[mid]){
            //left sorted
            if(arr[s] <= x && x <= arr[mid])
                e = mid - 1;
            else 
                s = mid + 1;

        }
        else if(arr[mid] <= arr[e]){
            //right sorted
            if(arr[mid] <= x && x <= arr[e])
                s = mid + 1;
            else 
                e = mid -1;
        }
    }
    return false;
}


int main(){
  vector<int> arr = {3,3,1,2,3,3,3,3,3};
  int n = arr.size();
  int x = 2;
  cout<<srsa(arr, x,n);
  return 0;
}