#include<bits/stdc++.h>
using namespace std;
//Assuming all elements in array are unique
int srsa(vector<int> arr, int x, int n){
    int s = 0;
    int e = n-1; 
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == x) return mid;
        else if(arr[s] <= arr[mid]){
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
    return -1;
}


int main(){
  vector<int> arr = {7,8,9,1,2,3,4,5,6};
  int n = arr.size();
  int x = 1;
  cout<<srsa(arr, x,n);
  return 0;
}