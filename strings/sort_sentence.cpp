//A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.
//A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

//For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
//Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

#include <iostream>
using namespace std;

  string sortSentence(string s) {

        vector<string> ans(10);

        for (int i = 0; i < s.size(); i++) {
            string word;
            int count = 0;

            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                count++;
                i++;
            }

            int pos = word[count - 1] - '0'; // convert char → index
            word.pop_back();                 // remove digit
            ans[pos] = word;
        }

        string sorted;
        for (int i = 1; i < 10; i++) {
            if (!ans[i].empty())
                sorted += ans[i] + " ";
        }

        sorted.pop_back(); // remove last space
        return sorted;
    }

    int main(){
        string s1 = "is2 sentence4 This1 a3";
        string s2 = "Myself2 Me1 I4 and3";
        cout<< sortSentence(s1)<<endl;
        cout<< sortSentence(s2)<<endl;
        return 0;
    }