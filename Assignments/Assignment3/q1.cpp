#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct dlist
{
private:
    Node *head;

public:
    dlist()
    {
        head = NULL;
    }

    // Append element at end
    void append(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *temp2 = head;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp->prev = temp2;
            temp2->next = temp;
        }
    }

    // Insert at beginning
    void insert_at_beg(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = head;
        temp->prev = NULL;
        if (head != NULL)
            head->prev = temp;
        head = temp;
    }

    // Insert at position (0-based index)
    void insert_at_spec(int data, int pos)
    {
        if (head == NULL || pos == 0)
        {
            insert_at_beg(data);
            return;
        }
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;

        Node *temp2 = head;
        for (int i = 0; i < pos - 1 && temp2->next != NULL; i++)
            temp2 = temp2->next;

        temp->next = temp2->next;
        if (temp2->next != NULL)
            temp2->next->prev = temp;
        temp->prev = temp2;
        temp2->next = temp;
    }

    // Delete from last
    void delete_from_last()
    {
        if (head == NULL)
        {
            cout << "Empty\n";
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        if (temp->prev != NULL)
            temp->prev->next = NULL;
        else
            head = NULL;
        cout << "Deleted " << temp->data << "\n";
        delete temp;
    }

    // Delete from beginning
    void delete_from_beg()
    {
        if (head == NULL)
        {
            cout << "Empty\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        cout << "Deleted " << temp->data << "\n";
        delete temp;
    }

    // Delete specific element
    void del_at_spec(int data)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                cout << "Deleted " << temp->data << "\n";
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Element not found\n";
    }

    // Display forward
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display in reverse
    void displayReverse()
    {
        if (head == NULL)
        {
            cout << "Empty\n";
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Count elements
    int count()
    {
        int c = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }

    // Find element -> return 0-based index, -1 if not found
    int find(int data)
    {
        Node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == data)
                return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    // Copy linked list into new list
    dlist copyList()
    {
        dlist newList;
        Node *temp = head;
        while (temp != NULL)
        {
            newList.append(temp->data);
            temp = temp->next;
        }
        return newList;
    }
};

int main()
{
    dlist l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.insert_at_beg(0);
    cout << "List: ";
    l1.display();

    l1.insert_at_spec(5, 2); // inserting at index 2
    cout << "After inserting 5 at index 2: ";
    l1.display();

    l1.delete_from_beg();
    l1.delete_from_last();
    cout << "After deletions: ";
    l1.display();

    l1.del_at_spec(2);
    cout << "After deleting 2: ";
    l1.display();

    cout << "Reverse: ";
    l1.displayReverse();

    cout << "Count = " << l1.count() << endl;

    int pos = l1.find(3);
    if (pos != -1)
        cout << "Element 3 found at index " << pos << endl;
    else
        cout << "Element 3 not found" << endl;

    dlist l2 = l1.copyList();
    cout << "Copied List: ";
    l2.display();

    return 0;
}