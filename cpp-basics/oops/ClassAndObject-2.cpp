#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
        int a,b;
    public:
        void set_data(int x, int y){
            a = x;
            b = y;
        }       
        void show_data(){
            cout<<"a:"<<a<<endl;
            cout<<"b:"<<b<<endl;
        }
        Complex add(Complex c){
            Complex temp;
            temp.a = a + c.a;
            temp.b = b + c.a;
            return temp;
        }
};


int main(){
  Complex c1,c2,c3;
  c1.set_data(2,3);
  c2.set_data(5,7);
  //c3=c1+c2; //Addition of Non Primitive Data Types will produce error!
  c3 = c1.add(c2);
  return 0;
}