#include<iostream>
#include<vector>

using namespace std;

int subsetSum(vector<int> a, int n, int sum)
{
   
    int tab[n + 1][sum + 1];
 
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;
     
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    }
 
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < sum+1; ++j) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
 
    return tab[n][sum];
}

int main(){
    
    vector<int> num = { 1, 0, 8 ,5 ,1, 4 };
    int sum = 18;
    cout<<"Tabulation :"<<  subsetSum(num, 6,  sum);
    return 0;
}
