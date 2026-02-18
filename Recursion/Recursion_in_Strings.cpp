/************************************************************
        RECURSION IN STRINGS  - Complete Notes
************************************************************/

#include <iostream>
using namespace std;

/*
============================================================
1. CHECK PALINDROME USING RECURSION
============================================================
*/

bool checkPalindrome(string str, int start, int end)
{
    // base condition
    if(start >= end)
        return true;

    // not matching
    if(str[start] != str[end])
        return false;

    // recursive call
    return checkPalindrome(str, start + 1, end - 1);
}


/*
============================================================
2. COUNT VOWELS USING RECURSION
============================================================
*/

int countVowels(string str, int index)
{
    // base condition
    if(index == -1)
        return 0;

    if(str[index] == 'a' || str[index] == 'e' ||
       str[index] == 'i' || str[index] == 'o' ||
       str[index] == 'u' ||
       str[index] == 'A' || str[index] == 'E' ||
       str[index] == 'I' || str[index] == 'O' ||
       str[index] == 'U')
    {
        return 1 + countVowels(str, index - 1);
    }
    else
    {
        return countVowels(str, index - 1);
    }
}


/*
============================================================
3. LOWERCASE TO UPPERCASE USING RECURSION
============================================================
*/

void lowerToUpper(string &str, int index)
{
    // base condition
    if(index == -1)
        return;

    if(str[index] >= 'a' && str[index] <= 'z')
    {
        str[index] = 'A' + (str[index] - 'a');
    }

    lowerToUpper(str, index - 1);
}


/*
============================================================
4. UPPERCASE TO LOWERCASE USING RECURSION
============================================================
*/

void upperToLower(string &str, int index)
{
    // base condition
    if(index == -1)
        return;

    if(str[index] >= 'A' && str[index] <= 'Z')
    {
        str[index] = 'a' + (str[index] - 'A');
    }

    upperToLower(str, index - 1);
}


/*
============================================================
5. REVERSE A STRING USING RECURSION
============================================================
*/

void reverseString(string &str, int start, int end)
{
    // base condition
    if(start >= end)
        return;

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1);
}


/*
============================================================
MAIN FUNCTION (Testing)
============================================================
*/

int main()
{
    // 1. Palindrome
    string p = "naman";
    cout << "Is Palindrome: " 
         << checkPalindrome(p, 0, p.length() - 1) << endl;

    // 2. Count vowels
    string v = "RohitNegi";
    cout << "Vowel Count: "
         << countVowels(v, v.length() - 1) << endl;

    // 3. Lower to Upper
    string s1 = "rohit";
    lowerToUpper(s1, s1.length() - 1);
    cout << "Lower to Upper: " << s1 << endl;

    // 4. Upper to Lower
    string s2 = "ROHIT";
    upperToLower(s2, s2.length() - 1);
    cout << "Upper to Lower: " << s2 << endl;

    // 5. Reverse String
    string r = "rohit";
    reverseString(r, 0, r.length() - 1);
    cout << "Reversed: " << r << endl;

    return 0;
}

/************************************************************
                    END OF NOTES
************************************************************/
