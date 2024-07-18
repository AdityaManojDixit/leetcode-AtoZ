#include<bits/stdc++.h>
using namespace std;
//By default all members of structure are PUBLIC.
//Structure in CPP provides backward compatiability like C so that CPP can also behave like C.
//All concepts of classes are applicable on structures.
//Member functions can directly access any data member of the class.

struct ComplexStruct{
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
};

class ComplexClass{
    private:
        int a,b;
    public:
        //Any function defined within class is by default INLINE.
        void set_data(int x, int y);
        void show_data(){
            cout<<"a:"<<a<<endl;
            cout<<"b:"<<b<<endl;
        }
};

void ComplexClass :: set_data(int x, int y){
    a = x;
    b = y;
}

int main(){
  ComplexStruct cst1;
  ComplexClass cc1;
  //c1.a & c1.b cant be accessed as they are private members.
  cst1.set_data(5,6); //c1 -> Noun, set_data() -> Verb/Action
  cst1.show_data();

  cc1.set_data(3,4);
  return 0;
}