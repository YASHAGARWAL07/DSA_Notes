#include <iostream>
#include <unordered_map> 
using namespace std;

/*
    Roman Numeral to Integer

    Rule:
    - If current Roman value >= next value → ADD
    - If current Roman value < next value → SUBTRACT

    Example:
    "IV"  → 5 - 1 = 4
    "VI"  → 5 + 1 = 6
*/

int RomanToint(string s) {

    //Mapping Roman characters to their integer values
    unordered_map<char,int> hash;
    hash['I'] = 1;
    hash['V'] = 5;
    hash['X'] = 10;
    hash['L'] = 50;
    hash['C'] = 100;
    hash['D'] = 500;
    hash['M'] = 1000;

    int first = 0;      // points to current character
    int second = 1;     // points to next character
    int ans = 0;

    // second < s.size() to avoid out-of-bounds access
    while (second < s.size()) {
        if (hash[s[first]] >= hash[s[second]])
            ans += hash[s[first]];
         else
            ans -= hash[s[first]];
        
        first++,  second++;
    }

    // IMP: Last Roman numeral is always added
    ans += hash[s[first]];

    return ans;
}

int main() {
    string s1 = "VI";
    cout << RomanToint(s1);
    return 0;
}
