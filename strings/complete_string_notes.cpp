#include <iostream>
#include <algorithm>   // for sort, reverse
using namespace std;

int main() {

    /*--------------------------------------------------
      1. String Declaration and Initialization
    --------------------------------------------------*/
    string s1 = "Rohit";
    string s2("Mohit");

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    /*--------------------------------------------------
      2. String Input
    --------------------------------------------------*/
    string word, line;

    // Single word input
    cout << "\nEnter a single word: ";
    cin >> word;
    cout << "You entered: " << word << endl;

    // Clear buffer before getline
    cin.ignore();

    // Full line input
    cout << "Enter a full line: ";
    getline(cin, line);
    cout << "You entered: " << line << endl;

    /*--------------------------------------------------
      3. Length of String
    --------------------------------------------------*/
    cout << "\nLength of s1: " << s1.length() << endl;
    cout << "Size of s1: " << s1.size() << endl;

    /*--------------------------------------------------
      4. Accessing Characters
    --------------------------------------------------*/
    cout << "\nFirst character of s1: " << s1[0] << endl;
    cout << "Second character of s1 using at(): " << s1.at(1) << endl;

    /*--------------------------------------------------
      5. push_back() and pop_back()
    --------------------------------------------------*/
    string temp = s2;
    temp.push_back('B');
    cout << "\nAfter push_back: " << temp << endl;

    temp.pop_back();
    cout << "After pop_back: " << temp << endl;

    /*--------------------------------------------------
      6. append() and + operator
    --------------------------------------------------*/
    string a = s2;
    a.append(" Bajaj");
    cout << "\nUsing append(): " << a << endl;

    string b = s2 + " Bajaj";
    cout << "Using + operator: " << b << endl;

    /*--------------------------------------------------
      7. String Comparison
    --------------------------------------------------*/
    string x = "abc";
    string y = "abd";

    if (x == y)
        cout << "\nStrings are equal" << endl;
    else
        cout << "\nStrings are not equal" << endl;

    cout << "Result of compare(): " << x.compare(y) << endl;

    /*--------------------------------------------------
      8. Substring
    --------------------------------------------------*/
    string str = "Programming";
    string sub = str.substr(0, 7);
    cout << "\nSubstring: " << sub << endl;

    /*--------------------------------------------------
      9. Find in String
    --------------------------------------------------*/
    string sentence = "Hello World";
    int pos = sentence.find("World");

    if (pos != string::npos)
        cout << "\n\"World\" found at index: " << pos << endl;
    else
        cout << "\n\"World\" not found" << endl;

    /*--------------------------------------------------
      10. Erase, Insert, Replace
    --------------------------------------------------*/
    string edit = "HelloWorld";

    edit.insert(5, " ");
    cout << "\nAfter insert: " << edit << endl;

    edit.erase(5, 1);
    cout << "After erase: " << edit << endl;

    edit.replace(5, 5, " C++");
    cout << "After replace: " << edit << endl;

    /*--------------------------------------------------
      11. Reverse and Sort
    --------------------------------------------------*/
    string rev = "hello";
    reverse(rev.begin(), rev.end());
    cout << "\nReversed string: " << rev << endl;

    string sortStr = "dcba";
    sort(sortStr.begin(), sortStr.end());
    cout << "Sorted string: " << sortStr << endl;

    /*--------------------------------------------------
      12. Palindrome Check
    --------------------------------------------------*/
    string pal = "madam";
    string palCopy = pal;
    reverse(palCopy.begin(), palCopy.end());

    if (pal == palCopy)
        cout << "\nPalindrome string" << endl;
    else
        cout << "\nNot a palindrome" << endl;

    /*--------------------------------------------------
      13. Case Conversion
    --------------------------------------------------*/
    string caseStr = "HeLLo";
    for (char &c : caseStr) {
        c = tolower(c);
    }
    cout << "\nLowercase: " << caseStr << endl;

    for (char &c : caseStr) {
        c = toupper(c);
    }
    cout << "Uppercase: " << caseStr << endl;

    /*--------------------------------------------------
      14. String to Number and Number to String
    --------------------------------------------------*/
    string numStr = "123";
    int num = stoi(numStr);
    cout << "\nString to int: " << num << endl;

    int value = 456;
    string valueStr = to_string(value);
    cout << "Int to string: " << valueStr << endl;

    /*--------------------------------------------------
      15. Iterating Through String
    --------------------------------------------------*/
    cout << "\nCharacters in s1: ";
    for (char c : s1) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
