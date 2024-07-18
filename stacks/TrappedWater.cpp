#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;

int trap(vector<int>& height){
    int n = height.size();
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);
    int trappedWater = 0;
    for(int i = 0; i<n; i++){
        int rightMax = i;
        for(int j = i; j<n; j++){
            if(height[j]>height[i]){
                rightMax = j;
            }
        }
        suffixMax[i] = height[rightMax];
    }

    for(int i = 0; i<n; i++){
        int leftMax = i;
        for(int j = i; j>=0; j--){
            if(height[j]>height[i]){
                leftMax = j;
            }
        }
        prefixMax[i] = height[leftMax];
    }
    prefixMax[0] = height[0];
    suffixMax[n-1] = height[n-1]
    for(int i = 0 ; i<n-1; i++){
        trappedWater += min(prefixMax[i], suffixMax[i]) - height[i];
    }
    
    return trappedWater;  
}

int main(){
    vector<int> height = {4,2,0,3,2,5};
    cout<<trap(height);
    
}