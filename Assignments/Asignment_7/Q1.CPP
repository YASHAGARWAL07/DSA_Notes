#include<iostream>
#include<string>
using namespace std;

struct DataItem
{
	int data;
	int status; // 1 = empty, 0 = occupied, 2 = deleted
};

struct closed_hash_table
{
private:
	DataItem *table;
	int size;

public:
	closed_hash_table(int s)
	{
		size = s;
		table = new DataItem[size];
		for(int i = 0; i < size; i++)
			table[i].status = 1; 
	}

	int find_index(int key)
	{
		return key % size;
	}

	void insertItem(int key)
	{
		int i = find_index(key);
		int original_index = i;

		while(table[i].status == 0) 
		{
			if(table[i].data == key)
			{
				cout << "Key " << key << " already exists." << endl;
				return;
			}
			
			i = (i + 1) % size; 

			if(i == original_index)
			{
				cout << "Hash table is full. Cannot insert " << key << endl;
				return;
			}
		}

		table[i].data = key;
		table[i].status = 0; 
		cout << "Inserted " << key << " at index " << i << endl;
	}

	void searchItem(int key)
	{
		int i = find_index(key);
		int original_index = i;

		while(table[i].status != 1) 
		{
			if(table[i].status == 0 && table[i].data == key)
			{
				cout << "Key " << key << " found at index " << i << endl;
				return;
			}

			i = (i + 1) % size; 

			if(i == original_index)
			{
				break;
			}
		}

		cout << "Key " << key << " not found." << endl;
	}

	void deleteItem(int key)
	{
		int i = find_index(key);
		int original_index = i;

		while(table[i].status != 1) 
		{
			if(table[i].status == 0 && table[i].data == key)
			{
				table[i].status = 2; 
				cout << "Key " << key << " deleted from index " << i << endl;
				return;
			}

			i = (i + 1) % size; 

			if(i == original_index)
			{
				break;
			}
		}
		
		cout << "Key " << key << " not found. Cannot delete." << endl;
	}
};


int main()
{
	closed_hash_table t1(10);
	t1.insertItem(5);
	t1.insertItem(15); 
	t1.insertItem(25); 
	
	t1.searchItem(15);
	t1.searchItem(16);

	t1.deleteItem(15);
	t1.searchItem(15); 
	t1.searchItem(25); 

	t1.insertItem(35); 
	t1.searchItem(35);

	return 0;
}