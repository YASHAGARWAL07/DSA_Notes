#include <iostream>
using namespace std;
void rotate_clockwise(string &s){
    char c = s[s.size()-1];
    int idx = s.size()-2;

    while(idx >= 0){
        s[idx + 1] = s[idx];
        idx--;
    }
    s[0] = c;
   }

int main(){
    string s1 = "Yash Agarwal";
    string s2 = "alYash Agarw";

    //Checking whether s2 is 2 times clockwise rotated s1 or not
   rotate_clockwise(s1);
   rotate_clockwise(s1);

   if(s1 == s2) cout<< true;
    else cout<< false;

    return 0;
}
