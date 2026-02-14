#include <iostream>
using namespace std;

struct Node
{
    int *arr;  // array to hold elements
    int count; // how many elements filled
    Node *next;

    Node(int capacity)
    {
        arr = new int[capacity];
        count = 0;
        next = nullptr;
    }
};

struct UnrolledLinkedList
{
    Node *head;
    int capacity;

    UnrolledLinkedList(int cap)
    {
        head = nullptr;
        capacity = cap;
    }

    // Add element
    void append(int val)
    {
        if (head == nullptr)
        {
            head = new Node(capacity);
            head->arr[head->count++] = val;
            return;
        }
        Node *cur = head;
        while (cur->next != nullptr)
            cur = cur->next;

        if (cur->count < capacity)
        {
            cur->arr[cur->count++] = val;
        }
        else
        {
            cur->next = new Node(capacity);
            cur->next->arr[cur->next->count++] = val;
        }
    }

    // Search
    bool search(int val)
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            for (int i = 0; i < cur->count; i++)
            {
                if (cur->arr[i] == val)
                    return true;
            }
            cur = cur->next;
        }
        return false;
    }

    // Display
    void display()
    {
        Node *cur = head;
        int idx = 1;
        while (cur != nullptr)
        {
            cout << "Node " << idx++ << ": ";
            for (int i = 0; i < cur->count; i++)
                cout << cur->arr[i] << " ";
            cout << "\n";
            cur = cur->next;
        }
    }

    // Delete
    void deleteElement(int val)
    {
        Node *cur = head, *prev = nullptr;
        while (cur != nullptr)
        {
            for (int i = 0; i < cur->count; i++)
            {
                if (cur->arr[i] == val)
                {
                    // shift left
                    for (int j = i; j < cur->count - 1; j++)
                    {
                        cur->arr[j] = cur->arr[j + 1];
                    }
                    cur->count--;

                    // remove empty node
                    if (cur->count == 0)
                    {
                        if (prev == nullptr)
                            head = cur->next;
                        else
                            prev->next = cur->next;
                        delete cur;
                    }
                    return;
                }
            }
            prev = cur;
            cur = cur->next;
        }
    }
};

int main()
{
    UnrolledLinkedList list(3);

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    cout << "Initial list:\n";
    list.display();

    list.deleteElement(20);
    cout << "After deleting 20:\n";
    list.display();

    cout << "Search 30: " << (list.search(30) ? "Found" : "Not found") << "\n";
    cout << "Search 100: " << (list.search(100) ? "Found" : "Not found") << "\n";

    return 0;
}