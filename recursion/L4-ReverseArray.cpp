//Recursion using Single and Two Pointers
#include<iostream>
#include<vector>
using namespace std;

void reverseArrayIterative(vector<int> arr, int n){
    int i = 0;
    int j = n-1;
    while(i<=j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    for(auto i : arr){
        cout<<i<<" ";
    }
}

void reverseRecursionTwoPointers(vector<int> &arr , int l, int r){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    reverseRecursionTwoPointers(arr , l+1, r-1);
}

void reverseRecursionSinglePointer(vector<int> &arr, int i, int n){
    if(i >= n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    reverseRecursionSinglePointer(arr, i+1, n);
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    // reverseArrayIterative(arr,n);
    // cout<<endl;
    // reverseRecursionTwoPointers(arr , 0, n-1);
    // for(auto i : arr){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
     
    for(auto i : arr){
        cout<<i<<" ";
    }
}