#include<bits/stdc++.h>
using namespace std;

int bsfo(vector<int> arr, int s, int e, int key) {
    int result = -1;
    while(s<=e){
        int mid = s + (e-s)/2;

        if(arr[mid] == key) {
            result = mid;
            e = mid-1;
        }
        else if(arr[mid]<key){
            s = mid + 1;
        }
        else if (arr[mid]>key){
            e = mid -1;
        }
    } 
    return result;
}
int bslo(vector<int> arr, int s, int e, int key) {
    int result = -1;
    while(s<=e){
        int mid = s + (e-s)/2;

        if(arr[mid] == key) {
            result = mid;
            s = mid + 1;
        }

        else if(arr[mid]<key){
            s = mid + 1;
        }
        else if(arr[mid]>key){
            e = mid -1;
        }
    } 
    return result;
}

int ub(vector<int> arr, int x,int n){
    int s = 0;
    int e = n - 1;
    int result = n;
    while(s<=e){
        int mid = s + (e-s)/2;
        if( arr[mid] > x){
            result = mid;
            e = mid -1;
        }
        else if( arr[mid] <= x){
            s = mid + 1;
        }
    }
    return result; 
}

int lb(vector<int> arr, int x,int n){
    int s = 0;
    int e = n - 1;
    int result = n;
    while(s<=e){
        int mid = s + (e-s)/2;
        if( arr[mid] >= x){
            result = mid;
            e = mid -1;
        }
        else if( arr[mid] < x){
            s = mid + 1;
        }
    }
    return result; 
}


int main(){
  vector<int> arr = {1,2,10,10,10,10,10,10,10,10,10,10,10,12,13,14};
  int key = 10;
  int n = arr.size();
//   cout<<bsfo(arr, 0, n-1, key)<<endl;
//   cout<<bslo(arr, 0, n-1, key);
    int lob = lb(arr, key , n);
    int uob = ub(arr, key , n);
    if(arr[lob] != key || lob == n){
        cout<<-1;
    }
    else{
        cout<<"lb:"<<lob;
        cout<<endl;
        cout<<"ub:"<<uob-1;
    }
  return 0;
}