#include<iostream>
#include<vector>
using namespace std;

string sort(string s) {
    vector<int>count(26,0);
    for(int i=0; i<s.size(); i++){
        count[s[i]-'a']++;
    }
    
    string ans;
    for(int i=0; i<26; i++){
        while(count[i]){
        ans+= i + 'a';
        count[i]--;
        }
    }
    return ans;
}
int main (){

    string s1 = "Yash Agarwal";
    string s2 = sort(s1);
    cout<<s2;
   return 0;
};
