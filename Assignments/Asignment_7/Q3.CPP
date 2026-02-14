#include<iostream>
#include<string> 
using namespace std;

struct StudentNode
{
	int rollNo; 
	string name;
	string branch;
	float cgpa;
	StudentNode *next; 
};

struct StudentHashMap
{
private:
	StudentNode **table; 
	int size;

	int hashFunction(int r)
	{
		return r % size; 
	}

public:
	StudentHashMap(int s)
	{
		size = s;
		table = new StudentNode*[size];
		for(int i = 0; i < size; i++)
			table[i] = NULL;
	}

	void insertStudent(int r, string n, string b, float c)
	{
		int i = hashFunction(r);

		StudentNode *temp = table[i];
		while(temp != NULL)
		{
			if(temp->rollNo == r)
			{
				cout << "Roll No. " << r << " is already present. Cannot add." << endl;
				return;
			}
			temp = temp->next;
		}

		StudentNode *newNode = new StudentNode;
		newNode->rollNo = r;
		newNode->name = n;
		newNode->branch = b;
		newNode->cgpa = c;
		
		newNode->next = table[i]; 
		table[i] = newNode;       
		cout << "Inserted " << n << " (Roll: " << r << ")" << endl;
	}

	void searchStudent(int r)
	{
		int i = hashFunction(r);
		StudentNode *temp = table[i]; 

		while(temp != NULL) 
		{
			if(temp->rollNo == r)
			{
				cout << "\n--- Student Found ---" << endl;
				cout << "Roll No: " << temp->rollNo << endl;
				cout << "Name: " << temp->name << endl;
				cout << "Branch: " << temp->branch << endl;
				cout << "CGPA: " << temp->cgpa << endl;
				return;
			}
			temp = temp->next;
		}

		cout << "\nStudent with Roll No. " << r << " not found." << endl;
	}

	void deleteStudent(int r)
	{
		int i = hashFunction(r);
		StudentNode *temp = table[i];
		StudentNode *prev = NULL; 

		while(temp != NULL && temp->rollNo != r)
		{
			prev = temp;
			temp = temp->next;
		}

		if(temp == NULL)
		{
			cout << "\nStudent with Roll No. " << r << " not found. Cannot delete." << endl;
			return;
		}

		if(prev == NULL)
		{
			table[i] = temp->next;
		}
		else
		{
			prev->next = temp->next;
		}

		delete temp; 
		cout << "\nSuccessfully deleted student with Roll No. " << r << endl;
	}

	void displayAll()
	{
		cout << "\n======= All Students in Database =======\n";
		for(int i = 0; i < size; i++) 
		{
			cout << "Index " << i << ": ";
			StudentNode *temp = table[i]; 
			if(temp == NULL)
			{
				cout << "[]" << endl;
			}
			else
			{
				while(temp != NULL) 
				{
					cout << "[Roll: " << temp->rollNo << ", Name: " << temp->name << "] -> ";
					temp = temp->next;
				}
				cout << "NULL" << endl;
			}
		}
		cout << "========================================\n";
	}
};

int main()
{
	StudentHashMap studentDB(10);
	
	cout << "--- Inserting Students ---" << endl;
	studentDB.insertStudent(2024020, "Yash Agarwal", "CSE", 8.9); 
	studentDB.insertStudent(2024001, "Aman", "CSE", 9.1);
	studentDB.insertStudent(2024011, "Priya", "CSE", 9.2); 
	studentDB.insertStudent(2024005, "Vijay", "ECE", 8.5);
	studentDB.insertStudent(2024030, "Neha", "CSE", 8.8);  

	studentDB.displayAll();

	cout << "\n--- Searching Students ---";
	studentDB.searchStudent(2024020); 
	studentDB.searchStudent(2024011); 
	studentDB.searchStudent(2024099); 

	cout << "\n--- Deleting Students ---";
	studentDB.deleteStudent(2024011); 
	studentDB.deleteStudent(2024099); 

	studentDB.displayAll();

	return 0;
}