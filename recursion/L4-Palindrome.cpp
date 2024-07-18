//Recursion using Single and Two Pointers
#include<bits/stdc++.h>
using namespace std;

void checkPalindrome(string str, int n, int l, int r) {
    if(l>=r){
        cout<<"Palindrome";
        return;
    }
    if(str[l] == str[r]){
        checkPalindrome(str, n, l+1, r-1); 
    }
    else{
        cout<<"Not a Palindrome";
        return;
    }
}

void checkPalindromeSingle(string str, int n, int i) {
    if(i>=n/2){
        cout<<"Palindrome";
        return;
    }
    if(str[i] == str[n-1-i]){
        checkPalindromeSingle(str, n, i+1); 
    }
    else{
        cout<<"Not a Palindrome";
        return;
    }
}

int main(){
    string str;
    str = "popop";
    int n = str.length();
    checkPalindrome(str,n,0,n-1);
    checkPalindromeSingle(str,n,0);
}