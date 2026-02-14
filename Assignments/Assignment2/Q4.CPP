#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
};

struct list {
    node* l;

    list() {
        l = NULL;
    }

    void insert_sorted(int v) {
        node* temp = new node;
        temp->val = v;
        temp->next = NULL;

        if (l == NULL || v < l->val) {
            temp->next = l;
            l = temp;
            return;
        }

        node* temp2 = l;
        while (temp2->next != NULL && temp2->next->val < v) {
            temp2 = temp2->next;
        }

        temp->next = temp2->next;
        temp2->next = temp;
    }

    void display() {
        node* temp2 = l;
        while (temp2 != NULL) {
            cout << temp2->val << " ";
            temp2 = temp2->next;
        }
        cout << endl;
    }

    void merge_sorted(list l2) {
        node* temp1 = l;
        node* temp2 = l2.l;

        if (temp1 == NULL) {
            l = temp2;
            return;
        }
        if (temp2 == NULL) {
            return;
        }

        node* newHead = NULL;
        node* tail = NULL;

        // pick the very first node
        if (temp1->val < temp2->val) {
            newHead = temp1;
            temp1 = temp1->next;
        } else {
            newHead = temp2;
            temp2 = temp2->next;
        }
        tail = newHead;

        // merge until one list ends
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val < temp2->val) {
                tail->next = temp1;
                temp1 = temp1->next;
            } else {
                tail->next = temp2;
                temp2 = temp2->next;
            }
            tail = tail->next;
        }

        // attach the remaining nodes
        if (temp1 != NULL) {
            tail->next = temp1;
        } else if (temp2 != NULL) {
            tail->next = temp2;
        }

        // update list head
        l = newHead;
    }
};

int main() {
    list l1, l2;
    l1.insert_sorted(7);
    l1.insert_sorted(1);
    l1.insert_sorted(9);
    l1.insert_sorted(16);
    cout << "List 1: ";
    l1.display();

    l2.insert_sorted(13);
    l2.insert_sorted(2);
    l2.insert_sorted(11);
    l2.insert_sorted(18);
    cout << "List 2: ";
    l2.display();

    l1.merge_sorted(l2);
    cout << "Merged list: ";
    l1.display();

    return 0;
}