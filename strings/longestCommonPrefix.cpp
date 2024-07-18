string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs[0].length();
        int m = strs.size();
        for(int i =0; i<n; i++){

            char ch = strs[0][i];
            bool match = true;
            for(int j = 1; j<m; j++){
                if(ch != strs[j][i] || strs[j].size()< i+1 ){
                    match = false;
                    break;
                }
            }
            if(match == true) ans.push_back(ch);
            else break;
        }
        return ans;
} //Time Complexity : O(n*m)