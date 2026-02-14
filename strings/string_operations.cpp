#include <iostream>
using namespace std;

int main(){
    string s1 = "Rohit";
    string s2 = "Mohit";
    cout << s1<< endl;
    cout<< s2 << endl;

    // we can use push_back function to append a single char in string.
    // we can use pop_back() function to remove last element from the string.

    s2.push_back('B');

    // Correct Ways to Append to a String

//- Method 1: Using push_back() (ONLY ONE CHARACTER)
   s2.push_back('B');  // char, not string

//- Method 2: Using append() (BEST for strings)
s2.append(" Bajaj");

//- Method 3: Using + operator (MOST COMMON)
string s3 = s2 + " Bajaj";

//- Working Code

    // Append string
    s2.append(" Bajaj");

    cout << s2 << endl;

    return 0;
}
