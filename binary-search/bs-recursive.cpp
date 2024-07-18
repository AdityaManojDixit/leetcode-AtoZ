#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int key)
{
    if(l > r) return -1;

    int mid = l + (r - l) / 2;

    if(arr[mid] == key) {
        return mid;
    }
    else if(arr[mid] < key) {
        return binarySearch(arr, mid+1, r, key);
    }
    else if (arr[mid] > key) {
        return binarySearch(arr, l , mid-1, key);
    }
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int query = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, query);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}



// Time Complexity: 
// Best Case: O(1)
// Average Case: O(log N)
// Worst Case: O(log N)
// Auxiliary Space: O(1), If the recursive call stack is considered then the auxiliary space will be O(logN).