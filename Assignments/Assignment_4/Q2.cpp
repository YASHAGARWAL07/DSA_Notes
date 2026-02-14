#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
};
struct dclist
{
    node *head;
    node *rear;
    // constructor
    dclist()
    {
        head = NULL;
        rear = NULL;
    }
    void append(int v)
    {
        node *temp = new node;
        temp->data = v;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = rear = temp;
            head->prev = rear;
            head->next = head;
            return;
        }
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
        rear->next = head;
        return;
    }
    void insert_at_beg(int v)
    {
        node *temp = new node;
        temp->data = v;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;
            rear = temp;
            temp->next = head;
            temp->prev = rear;
            return;
        }
        temp->next = head;
        temp->prev = rear;
        head->prev = temp;
        rear->next = temp;
        head = temp;
        return;
    }
    void display()
    {
        node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data;
        return;
    }
    void insert_at_spec(int v, int idx)
    {
        if (head == NULL || idx == 0)
        {
            insert_at_beg(v);
            return;
        }

        node *temp = head;
        int count = 0;

        do
        {
            if (count == idx - 1)
            {
                node *temp2 = new node;
                temp2->data = v;

                temp2->next = temp->next;
                temp2->prev = temp;
                temp->next->prev = temp2;
                temp->next = temp2;

                if (temp == rear)
                    rear = temp2; // if inserting at end
                return;
            }
            temp = temp->next;
            count++;
        } while (temp != head);

        cout << "Invalid index" << endl;
    }
    void delete_from_last()
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }
        node *temp = rear->prev;
        temp->next = head;
        node *temp2 = rear;
        rear = temp;
        head->prev = rear;
        temp2->next = NULL;
        temp2->prev = NULL;
        delete (temp2);
        return;
    }
    void delete_from_start()
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }
        if (head == rear)
        {
            node *temp = head;
            head = rear = NULL;
            delete temp;
            cout << "List is now empty";
            return;
        }
        node *temp = head;
        head = temp->next;
        rear->next = head;
        head->prev = rear;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    void delete_from_spec(int idx)
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        node *temp = head;
        int count = 0;

        // Move until exact index is reached
        while (count < idx && temp->next != head)
        {
            temp = temp->next;
            count++;
        }

        if (count != idx) // index too large
        {
            cout << "Invalid index";
            return;
        }

        if (temp == head)
        {
            delete_from_start();
            return;
        }
        if (temp == rear)
        {
            delete_from_last();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    dclist copy(dclist l)
    {
        dclist cl;
        if (l.head == NULL)
        {
            return cl;
        }
        if (l.head == l.rear)
        {
            cl.append(l.head->data);
            return cl;
        }
        node *temp = l.head;
        while (temp->next != l.head)
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
    dclist l1;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.append(40);
    l1.append(50);
    l1.insert_at_beg(60);
    cout << "The list is : ";
    l1.display();
    l1.insert_at_spec(70, 4);
    cout << "\nUpdate List is : ";
    l1.display();
    l1.delete_from_last();
    cout << "\nUpdate List is : ";
    l1.display();
    l1.delete_from_start();
    cout << "\nUpdate List is : ";
    l1.display();
    l1.delete_from_spec(4);
    cout << "\nUpdate List is : ";
    l1.display();
    dclist cl = l1.copy(l1);
    cout << "\nCopied List is : ";
    cl.display();
    cout << endl;
    return 0;
}
