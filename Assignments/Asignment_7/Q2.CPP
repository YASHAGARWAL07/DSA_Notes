#include<iostream>
using namespace std;

struct Node
{
	int key;
	Node *next;
};

struct open_hash_table
{
private:
	Node **table; 
	int size;
public:
	open_hash_table(int s)
	{
		size = s;
		table = new Node*[size];
		for(int i = 0; i < size; i++)
			table[i] = NULL;
	}

	int find_index(int r)
	{
		return r % size;
	}

	void insertItem(int k)
	{
		int i = find_index(k);
		
		Node *temp = table[i];
		while(temp != NULL)
		{
			if(temp->key == k)
			{
				cout << "Key " << k << " is already present." << endl;
				return;
			}
			temp = temp->next;
		}

		Node *newNode = new Node;
		newNode->key = k;
		newNode->next = table[i]; 
		table[i] = newNode;     
		cout << "Inserted " << k << " at index " << i << endl;
	}

	void searchItem(int k)
	{
		int i = find_index(k);
		Node *temp = table[i]; 

		while(temp != NULL)
		{
			if(temp->key == k)
			{
				cout << "Key " << k << " found at index " << i << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Key " << k << " not found." << endl;
	}

	void deleteItem(int k)
	{
		int i = find_index(k);
		Node *temp = table[i];
		Node *prev = NULL;

		while(temp != NULL && temp->key != k)
		{
			prev = temp;
			temp = temp->next;
		}

		if(temp == NULL)
		{
			cout << "Key " << k << " not found. Cannot delete." << endl;
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
		cout << "Key " << k << " deleted from index " << i << endl;
	}
};


int main()
{
	open_hash_table t2(10);
	t2.insertItem(5);
	t2.insertItem(15); 
	t2.insertItem(25); 

	t2.searchItem(15);
	t2.searchItem(16); 

	t2.deleteItem(15);
	t2.searchItem(15); 
	t2.searchItem(25); 

	t2.deleteItem(16); 
	
	return 0;
}