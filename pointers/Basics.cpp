#include<iostream>
using namespace std;
int main(){
    int a = 20;
    int b = 40;

    int *p = &a;            // here it shows that p is a ponter pointing to the integer value stored at address of a 

    cout<<p<<endl;          //shows address of a stored in p
    cout<<*p <<endl;        // shows value of a stored at that address which is kept in p

    cout<< &p << endl;      // prints address of p

    return 0;
}
