#include <iostream>
using namespace std;

int main(){
    string s1 = "Yash";
    string s2 = "Agarwal";
    string s3 = s1 + s2;
    string s4 = s1.append(s2);

    cout<<s3<<"\n"<<s4;
    return 0;
}