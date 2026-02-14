#include<iostream>
using namespace std;

int main()
{
    // n = rows, m = columns
    int n, m;
    cout << "Enter no. of rows and columns : ";
    cin >> n >> m;

    // ptr will store addresses of rows
    int **ptr = new int*[n];

    // Allocate memory for each row (columns)
    for(int i = 0; i < n; i++)
    {
        ptr[i] = new int[m];
    }

    // Input values
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> ptr[i][j];

    // Print 2D array
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << ptr[i][j] << " ";
        cout << endl;
    }

    // Free memory (IMPORTANT)
    for(int i = 0; i < n; i++)
        delete[] ptr[i];   // delete columns

    delete[] ptr;          // delete rows

    /*
      Notes:
      int **ptr        -> pointer to pointer
      ptr[i]           -> 1D array (row)
      ptr[i][j]        -> element
      Memory allocated in heap
      delete[] is mandatory
    */

    return 0;
}
