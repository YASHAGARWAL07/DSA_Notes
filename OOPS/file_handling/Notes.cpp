/************************************************************
        FILE HANDLING IN C++  (Complete Notes) Lecture 77 (coder Army)
************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*
============================================================
1. WHAT IS FILE HANDLING?
============================================================

File handling allows us to:
- Store data permanently
- Read data from files
- Write data to files
- Append data

Without files:
Data is lost after program execution.

With files:
Data is stored permanently on disk.
*/


/*
============================================================
2. HEADER FILE REQUIRED
============================================================

#include <fstream>

This header provides:
- ifstream  → for reading
- ofstream  → for writing
- fstream   → for reading + writing
*/


/*
============================================================
3. FILE STREAM CLASSES HIERARCHY
============================================================

ios_base
   ↓
ios
   ↓
istream        ostream
   ↓              ↓
ifstream        ofstream
        ↓
      fstream

ifstream  → Read
ofstream  → Write
fstream   → Read + Write
*/


/*
============================================================
4. WRITING INTO A FILE (ofstream)
============================================================
*/

void writeExample()
{
    ofstream fout;

    fout.open("data.txt");   // Open file in write mode

    if(!fout)
    {
        cout << "File not opened!" << endl;
        return;
    }

    fout << "Hello World\n";
    fout << "File Handling in C++\n";

    fout.close();   // Always close file

    cout << "Data written successfully!\n";
}


/*
============================================================
5. READING FROM A FILE (ifstream)
============================================================
*/

void readExample()
{
    ifstream fin;
    fin.open("data.txt");

    if(!fin)
    {
        cout << "File not opened!" << endl;
        return;
    }

    string line;

    while(getline(fin, line))
    {
        cout << line << endl;
    }

    fin.close();
}


/*
============================================================
6. READ CHARACTER BY CHARACTER
============================================================
*/

void readCharExample()
{
    ifstream fin("data.txt");

    char ch;

    while(fin.get(ch))
    {
        cout << ch;
    }

    fin.close();
}


/*
============================================================
7. FILE OPEN MODES
============================================================

ios::in      → Read
ios::out     → Write
ios::app     → Append
ios::binary  → Binary mode
ios::ate     → Go to end after opening
ios::trunc   → Delete previous data (default for ofstream)

Example:
fout.open("data.txt", ios::app);
*/


/*
============================================================
8. APPEND MODE
============================================================
*/

void appendExample()
{
    ofstream fout("data.txt", ios::app);

    fout << "Appended line\n";

    fout.close();
}


/*
============================================================
9. USING fstream (Read + Write)
============================================================
*/

void fstreamExample()
{
    fstream file;

    file.open("data2.txt", ios::out | ios::in | ios::trunc);

    file << "Hello Yash\n";

    file.seekg(0);   // Move pointer to beginning

    string line;
    getline(file, line);

    cout << line << endl;

    file.close();
}


/*
============================================================
10. IMPORTANT FILE FUNCTIONS
============================================================

open("filename")
close()
get()
getline()
seekg()   → move input pointer
seekp()   → move output pointer
tellg()   → current read position
tellp()   → current write position
eof()     → end of file check
*/


/*
============================================================
11. COMMON MISTAKES (VERY IMPORTANT)
============================================================

1) Forgetting to close file
2) Not checking if file opened successfully
3) Using while(!eof()) incorrectly
   Correct way:
   while(getline(fin, line))
4) Not including <fstream>
*/


/*
============================================================
12. DIFFERENCE BETWEEN >> AND getline()
============================================================

>>       → Reads single word (stops at space)
getline  → Reads entire line (including spaces)
*/


/*
============================================================
13. PRACTICAL EXAM IMPORTANT PROGRAM
   Take 5 numbers from user,
   store in file,
   sort them,
   write sorted data.
============================================================
*/

void practicalExample()
{
    int arr[5];

    cout << "Enter 5 numbers:\n";
    for(int i=0; i<5; i++)
        cin >> arr[i];

    ofstream fout("numbers.txt");

    fout << "Original Data:\n";
    for(int i=0; i<5; i++)
        fout << arr[i] << " ";

    // Simple Bubble Sort
    for(int i=0; i<4; i++)
        for(int j=0; j<4-i; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);

    fout << "\nSorted Data:\n";
    for(int i=0; i<5; i++)
        fout << arr[i] << " ";

    fout.close();
}


/*
============================================================
14. VIVA QUESTIONS
============================================================

Q1: Which header is required?
Ans: <fstream>

Q2: Which class is used for reading?
Ans: ifstream

Q3: Which class is used for writing?
Ans: ofstream

Q4: How to append data?
Ans: ios::app mode

Q5: Difference between text and binary mode?
Ans:
Text → Normal readable
Binary → Raw memory data
*/


/*
============================================================
MAIN FUNCTION
============================================================
*/

int main()
{
    writeExample();
    readExample();
    appendExample();
    readCharExample();
    fstreamExample();

    return 0;
}

/************************************************************
                    END OF FILE HANDLING NOTES
************************************************************/
