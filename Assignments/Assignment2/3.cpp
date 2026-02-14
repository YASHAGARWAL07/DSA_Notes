#include <iostream>
using namespace std;
struct node
{
    int value;
    node *next;
};
struct list
{
    node *l;
    // Constructor
    list()
    {
        l = NULL;
    }

    void append(int v)
    {
        node *temp = new node;
        temp->value = v;
        temp->next = NULL;
        if (l == nullptr)
        {
            l = temp;
        }
        else
        {
            node *temp2 = l;
            while (temp2->next != 0)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }

    void display()
    {
        node *temp2 = l;
        cout << "The list is : ";
        while (temp2->next != 0)
        {
            cout << temp2->value << " ";
            temp2 = temp2->next;
        }
        cout << temp2->value << " ";
        cout << endl;
    }
    // adding element in the beginning
    void app_beg(int v)
    {
        node *temp = new node;
        temp->value = v;
        temp->next = l;
        l = temp;
    }
    void app_spec(int v, int n)
    { // n is the position
        node *temp = new node;
        temp->value = v;
        node *temp2 = l;
        if (n == 1)
        {
            temp->next = l;
            l = temp;
        }
        int i = 1;
        while (i < n - 1)
        {
            temp2 = temp2->next;
            i++;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }

    void reverse()
    {
        node *previous = NULL;
        node *current = l;
        node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        l = previous;
    }
    void count_ele()
    {
        node *temp = l;
        int count = 0;
        while (temp != 0)
        {
            count++;
            temp = temp->next;
        }

        cout << "The no. of elments in list are : " << count << endl;
    }
    void search(int v)
    {
        node *temp = l;
        int index = 1;
        while (temp != 0)
        {
            if (temp->value == v)
            {
                cout << "The given element " << v << " is at index : " << index << endl;
                break;
            }
            else
            {
                temp = temp->next;
                index++;
            }
        }
    }
    void delete_ele(int v)
    {
        node *temp = l;
        while (temp->value != v)
        {
            temp = temp->next;
        }
        // node *temp2 = temp->next;
        node *temp2 = l; // temp2 is for linking the two lists
        while (temp2->next != temp)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp->next;

        free(temp);
    }

    void del_first()
    {
        node *temp = l;
        l = temp->next;
        free(temp);
    }
    void del_last()
    {
        if (l == NULL)
        {
            cout << "The list is already empty";
            return;
        } // empty list

        // if only one node exists
        if (l->next == NULL)
        {
            delete l;
            l = NULL;
            cout << "Now the list is empty";
            return;
        }
        // go to second last node
        node *temp = l;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = NULL;
        free(temp2);
    }

    list copy_list()
    {
        list l2;
        node *temp = l;
        while (temp != NULL)
        {
            l2.append(temp->value);
            temp = temp->next;
        }
        return l2;
    }
    void merge_list(list l2)
    {
        node *temp = l;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *temp2 = l2.l;
        temp->next = temp2;
    }
};

int main()
{
    list l1;
    l1.append(48);
    l1.append(52);
    l1.append(76);
    l1.append(96);

    cout << "\nORIGINAL LIST : ";
    l1.display();

    l1.app_beg(56);
    l1.app_spec(45, 3);
    l1.app_spec(34, 1);

    cout << "\nAFTER INSERTIONS : ";
    l1.display();

    cout << "\nREVERSE LIST : ";
    l1.reverse();
    l1.display();
    cout << endl;

    l1.count_ele();
    l1.search(45);
    l1.search(34);

    l1.delete_ele(52);
    cout << "\nAFTER DELETING 52 : ";
    l1.display();

    l1.del_first();
    cout << "\nAFTER DELETING FIRST : ";
    l1.display();

    l1.del_last();
    cout << "\nAFTER DELETING LAST : ";
    l1.display();

    // copy list
    list l2 = l1.copy_list();
    cout << "\nCOPIED LIST : ";
    l2.display();

    // merge list
    cout << "\nMERGED LIST (l1 + l2): ";
    l1.merge_list(l2);
    l1.display();

    return 0;
}
