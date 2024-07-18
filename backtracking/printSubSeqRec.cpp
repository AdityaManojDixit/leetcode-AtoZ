#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ans(100,-1);

void printSubSeqRec(string str, int n, int index = -1, string curr = "")
    {
        if (index == n)
            return;
        if(ans[index] != -1 ) ans.push_back(curr);
        if (!curr.empty()) {
            ans.push_back(curr);
        }

        for (int i = index + 1; i < n; i++) {
            curr += str[i];
            printSubSeqRec(str, n, i, curr);

            // backtracking
            curr = curr.erase(curr.size() - 1);
        }
        return;
    }



int main()
{
    string str = "abc";
    printSubSeqRec(str, str.length()); // Corrected: Call the recursive function
    for (auto it : ans) {
        cout << it << endl;
    }
    return 0;
}
