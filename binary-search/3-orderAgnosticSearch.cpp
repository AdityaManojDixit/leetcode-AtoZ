#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int l, int r, int key)
{
    bool flag;
    (arr[0]<arr[1])?flag=1:flag=0;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] == key) return mid;

        else if (arr[mid]<key) {
            (flag==1)?l = mid + 1:r = mid - 1;
        }
        else if (arr[mid] > key) {
            (flag==1)?r = mid -1:l = mid + 1;
        }
    }
    return -1;
}

int main(){
  vector<int> arr = {8,7,6,5,4,3,2,1};
  int key = 2;
  int n = arr.size();
  cout<<bs(arr, 0, n-1, key);
  return 0;
}