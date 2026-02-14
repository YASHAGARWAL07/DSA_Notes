#include<iostream>
using namespace std;

int main(){

    // Char array: stored as characters + '\0' at end
    char arr[] = "Hello";

    // Pointer to char array
    char *p = arr;   // same as &arr[0]

    // Print array and pointer
    cout << arr << endl;   // prints full string
    cout << p << endl;     // prints full string

    // Address of first character
    cout << (void*)arr << endl;
    cout << (void*)p << endl;

    // Access characters
    cout << arr[0] << endl;      // 'H'
    cout << *(arr + 1) << endl;  // 'e'
    cout << p[2] << endl;        // 'l'

    // Loop using index
    for(int i = 0; arr[i] != '\0'; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Loop using pointer
    for(char *q = arr; *q != '\0'; q++){
        cout << *q << " ";
    }
    cout << endl;

    // Pointer increment
    char *r = arr;
    cout << *r << endl;   // 'H'
    r++;
    cout << *r << endl;   // 'e'

    // Modify character using pointer
    *r = 'a';   // Hello -> Hallo
    cout << arr << endl;

    /*
      Important points:
      arr == &arr[0]
      arr[i] == *(arr + i) == p[i]
      char pointer prints string until '\0'
      Use (void*) to print address
    */

    return 0;
}
