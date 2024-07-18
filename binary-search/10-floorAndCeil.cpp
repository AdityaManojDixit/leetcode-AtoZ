#include<bits/stdc++.h>
using namespace std;
//Largest element <= key
int floor(vector<int> arr, int x,int n){
    int s = 0;
    int e = n-1;
    int ans = -1;
    while(s<= e){
        int mid = s + (e-s)/2;
        if(arr[mid] <= x ){ //Element smaller or equals key
            ans = arr[mid]; 
            s = mid+1; //Look out at greater index for largest Element smaller or equals key
        }
        else if(arr[mid] > x){
            e = mid -1;
        }
    }
    return ans;
}
//Smallest element >= key
int ceil(vector<int> arr, int x,int n){
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-e)/2;
        if(arr[mid] >= x){ //Element greater or equals key
            ans = arr[mid];
            e = mid -1; //Look out at smaller index for smallest element greater or equals key
        }
        else if(arr[mid] < x){
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
  vector<int> arr= {2,3,6,7,8,8,11,11,12,13};
  int n = arr.size();
  int x = 5;

  cout<< floor(arr, x, n);
  cout<< endl;
  cout<< ceil(arr, x, n);
  return 0;
}