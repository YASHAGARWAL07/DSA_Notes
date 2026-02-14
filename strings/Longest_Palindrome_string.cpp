//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 #include<iostream>
 using namespace std;

 int longestPalindrome(string s) {
        vector<int>upper(26,0);   // for upercase letters
        vector<int>lower(26,0);   // for lowercase letters

        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'a') 
            lower[s[i] - 'a']++;
            else
            upper[s[i] - 'A']++;
        }
        int count = 0;
        int odd = 0;

        for(int i=0; i<26; i++){
            //lower
            if(lower[i] % 2 == 0)
            count += lower[i];
            else{
            count += lower[i] - 1;
            odd = 1;
            }
            // upper
            if(upper[i] % 2 == 0)
            count += upper[i];
            else{
            count += upper[i] - 1;
            odd = 1;
            }
        }

        return count + odd;    // odd will be added because there can a middle char if any of the upper or lower had a odd count
    }
 int main(){
    string s = "abccccdd";
    cout<< "longest = "<<longestPalindrome(s);
    return 0;
 }
 