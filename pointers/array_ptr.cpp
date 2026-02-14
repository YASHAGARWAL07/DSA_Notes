#include<iostream>
using namespace std;

int main(){

    // Array: continuous memory, arr = base address
    int arr[5] = {1,2,3,4,5};

    // arr and &arr[0] both give address of first element
    cout << arr << endl;
    cout << &arr[0] << endl;

    // Access value
    cout << arr[0] << endl;

    // Pointer storing address of first element
    int *ptr = arr;   // same as &arr[0]

    // ptr -> address, *ptr -> value
    cout << ptr << endl;
    cout << *ptr << endl;

    // Address of pointer variable
    cout << &ptr << endl;

    // Pointer arithmetic (moves by sizeof(int))
    cout << arr + 1 << endl;     // address of arr[1]
    cout << *(arr + 1) << endl;  // value of arr[1]

    // Loop using array
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Loop using pointer
    for(int i = 0; i < 5; i++){
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    // Pointer increment
    int *p = arr;
    for(int i = 0; i < 5; i++){
        cout << *p << " ";
        p++;   // move to next element
    }
    cout << endl;

    /*
      Important points:
      arr[i] == *(arr + i)
      arr == &arr[0]
      ptr++ allowed, arr++ not allowed
      ptr1 - ptr2 gives number of elements
    */

    return 0;
}
