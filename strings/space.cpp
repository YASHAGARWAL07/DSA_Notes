#include <iostream>
using namespace std;

int main(){
    string s1 = "Yash Agarwal";
    // string s2;
    // cout<<"Enter : ";
    // cin >> s2;
    // cout<< s2<<endl;

    // what if user give a  line or paragragh , then we have to read the spaces as well
    string s3;
    cout<<"Enter : ";
    cin.ignore();
    getline(cin,s3);
    cout<<s3;

    // if we have to give " " in between, there we have to use the / opertaor before " "
    //cout << "Hii how are \"u\"";

}
