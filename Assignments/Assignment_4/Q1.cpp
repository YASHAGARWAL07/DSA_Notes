#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct clist
{
    node *head;
    node *rear;
    // constructor fxn
    clist()
    {
        head = NULL;
        rear = NULL;
    }
    void append(int v)
    {
        node *temp = new node;
        temp->data = v;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            rear = temp;
            rear->next = head;
        }
        rear->next = temp;
        temp->next = head;
        rear = temp;
    }
    void insert_at_beg(int v)
    {
        node *temp = new node;
        temp->data = v;
        temp->next = head;
        head = temp;
        rear->next = head;
    }
    void insert_at_spec(int v, int idx)
    {
        if (head == NULL || idx == 1)
        {
            insert_at_beg(v);
            return;
        }
        node *temp2 = head;
        int n = 0;
        while (n < idx - 1 && temp2->next != NULL)
        {
            temp2 = temp2->next;
            n++;
        }
        node *temp = new node;
        temp->data = v;
        temp->next = temp2->next;
        temp2->next = temp;
        if (temp2 == rear)
        {
            rear = temp;
            rear->next = head;
        }
    }
    void display()
    {
        node *temp = head;
        while (temp != rear)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
    void delete_from_end()
    {
        if (head == NULL)
        {
            cout << "List is empty.";
            return;
        }
        if (head == rear)
        {
            delete (head);
            head = rear = NULL;
            cout << "deleted successfully. Now the list is empty." << endl;
            return;
        }
        node *temp = head;
        while (temp->next != rear)
        {
            temp = temp->next;
        }
        temp->next = head;
        rear->next = NULL;
        delete (rear);
        rear = temp;
    }
    void delete_from_start()
    {
        if (head == NULL)
        {
            cout << "List is empty.";
            return;
        }
        if (head == rear)
        {
            delete (head);
            head = rear = NULL;
            cout << "deleted successfully. Now the list is empty.";
            return;
        }
        rear->next = head->next;
        node *temp = head;
        head = head->next;
        delete temp;
    }
    void delete_at_spec(int idx)
    {
        if (head == NULL)
        {
            cout << "List is empty.";
            return;
        }
        else if (head == rear)
        {
            delete_from_start();
            return;
        }
        node *temp = head;
        int n = 0;
        while (n <= idx - 1 && temp->next != head)
        {
            temp = temp->next;
            n++;
        }
        node *temp2 = temp->next;
        temp->next = temp2->next;
        if (temp2 == rear)
        {
            rear = temp;
            rear->next = head;
        }
        temp2->next = NULL;
        delete temp2;
    }
    clist copy_clist(clist l)
    {
        clist cl;
        if (l.head == NULL)
        {
            return cl;
        }
        node *temp = l.head;
        while (temp->next != head)
        {
            cl.append(temp->data);
            temp = temp->next;
        }
        cl.append(temp->data);
        return cl;
    }
};
int main()
{
    clist l1;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.append(40);
    l1.insert_at_beg(50);
    l1.insert_at_beg(60);
    l1.insert_at_spec(70, 4);
    cout << "List before deletion : ";
    l1.display();
    l1.delete_from_end();
    cout << "List After deletion from end : ";
    l1.display();
    l1.delete_from_start();
    cout << "List after deletion from start : ";
    l1.display();
    l1.delete_at_spec(3);
    cout << "List after deletion on spec index : ";
    l1.display();
    clist cl = l1.copy_clist(l1);
    cout << "copied list is : ";
    cl.display();
    cout << endl;
    return 0;
}
