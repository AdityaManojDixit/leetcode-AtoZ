#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2= nums2.size();
    vector<int> ans;
    stack<int> st;
    map<int,int>;

    reverse(nums2.begin(), nums2.end());
    for(int i = 0; i<n2; i++){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }

        if(st.empty() == false){
            mp.insert({nums2[i],st.top()});
        }
        else if (st.empty()){
            mp.insert({nums2[i],-1})
        }
        st.push(nums2[i]);
    }
    for(int i =0; i<n1; i++){ 
        ans.push_back(mp[nums1[i]]);
    }

    
    return ans;
}

int main(){
    vector<int>
    
}