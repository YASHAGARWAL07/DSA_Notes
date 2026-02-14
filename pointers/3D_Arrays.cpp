#include<iostream>
using namespace std;

int main()
{
    // x = layers, y = rows, z = columns
    int x, y, z;
    cout<<"Enter the value of l , r. c : ";
    cin >> x >> y >> z;

    // ptr will store addresses of 2D blocks
    int ***ptr = new int**[x];

    // Allocate memory for each 2D block
    for(int i = 0; i < x; i++)
    {
        ptr[i] = new int*[y];

        // Allocate memory for each row
        for(int j = 0; j < y; j++)
        {
            ptr[i][j] = new int[z];
        }
    }

    // Input values
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            for(int k = 0; k < z; k++)
                cin >> ptr[i][j][k];

    // Print 3D array
    for(int i = 0; i < x; i++)
    {
        cout << "Layer " << i << endl;
        for(int j = 0; j < y; j++)
        {
            for(int k = 0; k < z; k++)
                cout << ptr[i][j][k] << " ";
            cout << endl;
        }
    }

    // Free memory (VERY IMPORTANT)
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
            delete[] ptr[i][j];   // delete columns

        delete[] ptr[i];          // delete rows
    }

    delete[] ptr;                 // delete layers

    /*
      Notes:
      int ***ptr          -> dynamic 3D array
      ptr[i]              -> 2D block
      ptr[i][j]           -> 1D row
      ptr[i][j][k]        -> element
      Memory allocated in heap
      delete order: inner → outer
    */

    return 0;
}
