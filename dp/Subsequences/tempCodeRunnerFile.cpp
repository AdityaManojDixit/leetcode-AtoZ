#include <iostream>
#include<string>
using namespace std;

int search(const string& pat, const string& txt) {
    int M = pat.size();
    int N = txt.size();
    int count = 0;

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            count++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n;
        cin >> n;

        string str;
        cin >> str;

        string a = "pie";
        string b = "map";
        string c = "api";

        int count_a = search(a, str);
        int count_b = search(b, str);
        int count_c = search(c, str);
        int total = count_a + count_b;
        
        if(count_c != 0) 
            total = total -2;
        
        cout<<total<<endl;



        

        t--;
    }
}
