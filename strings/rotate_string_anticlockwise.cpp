#include <iostream>
using namespace std;
void rotate_anticlockwise(string &s){
    char c = s[0];
    int idx = 1;

    while(idx < s.size()){
        s[idx -1] = s[idx];
        idx++;
    }
    s[s.size()-1] = c;
   }

int main(){
    string s1 = "Yash Agarwal";
    string s2 = "sh AgarwalYa";

    //Checking whether s2 is 2 place anticlockwise rotated s1 or not
   rotate_anticlockwise(s1);
   rotate_anticlockwise(s1);

   if(s1 == s2) cout<< true;
    else cout<< false;

    return 0;
}
