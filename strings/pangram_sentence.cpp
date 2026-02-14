//A pangram is a sentence where every letter of the English alphabet appears at least once.
//Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
#include<iostream>
using namespace std;

 bool checkIfPangram(string sentence) {
        vector<int>alpha(26,0);
        for(int i=0; i<sentence.size(); i++){
            alpha[sentence[i] - 'a'] = 1;
        }
        for(int i=0; i<26; i++){
            if(alpha[i]==0) return false;
        }
        return true;
    }

int main(){
    string s1 = "thequickbrownfoxjumpsoverthelazydog";
    cout << checkIfPangram(s1);

    return 0;
}
