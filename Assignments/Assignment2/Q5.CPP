#include <iostream>
using namespace std;

struct node {
    int real;
    int imag;
    node* next;
};

struct list {
    node* l;

    list() {
        l = NULL;
    }

    void append(int r, int i) {
        node* temp = new node;
        temp->real = r;
        temp->imag = i;
        temp->next = NULL;

        if (l == NULL) {
            l = temp;
        } else {
            node* temp2 = l;
            while (temp2->next != NULL) {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }

    void delete_last() {
        if (l == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (l->next == NULL) {
            delete l;
            l = NULL;
            return;
        }

        node* temp = l;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void display() {
        node* temp = l;
        while (temp != NULL) {
            cout << temp->real << "+" << temp->imag << "i ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    list l;
    l.append(5, 7);
    l.append(3, 8);
    l.append(6, -4);
    cout << "List: ";
    l.display();

    l.delete_last();
    cout << "After deleting last: ";
    l.display();

    return 0;
}