#include<iostream>
using namespace std;

    string sortVowels(string s) {

        //The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. 
        //Consonants comprise all letters that are not vowels.
        // 3steps
        // 1. select the vowel
        // 2. sort the vowel
        // 3. place the vowel at the right position 

        vector<int> upper(26,0);
        vector<int> lower(26,0);

        for(int i=0; i<s.size(); i++){

            //upper
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){ 
        upper[s[i] -'A']++;
        s[i] = '#';
            }
            else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){ 
        lower[s[i] -'a']++;
        s[i] = '#';
            }
        }

        string vowel;
        //push elemts of upper in vowel string before lower bcz upper has low ASCII Value
        for(int i=0; i<26; i++){
            char c = 'A' + i; 
            while(upper[i]){
                vowel+=c;
                upper[i]--;
            }
        }

            //push lower in vowel
            for(int i = 0; i<26; i++){
                char c = 'a' + i;
            while(lower[i]){
                vowel += c;
                lower[i]--;
            }
        }
        int first = 0 , second = 0;  //first will be for traverse s string
                                    //second vowel wali string ko point kar rha h;
        while(second<vowel.size()){
            if(s[first] == '#'){
            s[first] = vowel[second];
            second++;
            }
            first++;
        }
        return s;
    }
    int main(){
        string s = "lEetcOde";
        cout<< endl<< sortVowels(s)<<endl;
};
