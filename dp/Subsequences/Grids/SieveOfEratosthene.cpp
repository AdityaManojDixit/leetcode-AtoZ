#include<iostream>
#include<vector>
using namespace std;
//Sieve of Eratosthenes
void printPrimes(int n)
{
    vector<int> isPrime(n+1,1);
    isPrime[0] = isPrime[1] = 0;
    for(int i =2; i*i<=n; i++){
        if(isPrime[i] ){
            for(int j = i*i; j<=n; j+=i){
                isPrime[j] = 0;
            }
        }
    }
    for(int i =0; i<=n; i++){
        if(isPrime[i] == 1)
        cout<<i<<" ";
    }

}

int main(){
    printPrimes(5);
    return 0;
}