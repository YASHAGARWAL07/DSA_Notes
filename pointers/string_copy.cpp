#include<iostream>
using namespace std;

void five(char *str1, char *str2)
{
    // Copy characters from str2 to str1
    while((*str1 = *str2))
    {
        str1++;
        str2++;
    }
}

int main()
{
    char first[20] = "Mohit";
    char second[] = "Rohan";

    five(first, second);

    cout << first;   // Rohan
    return 0;
}
 