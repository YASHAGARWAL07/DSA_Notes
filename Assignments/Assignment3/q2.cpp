#include <iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;
};

struct KV_DList {
private:
    // Helper function to find node by key
    Node* findKey(int key) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->key == key)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    Node *head;

public:
    KV_DList() {
        head = NULL;
    }

    // Insert (key, value) - key must be unique
    void insert(int key, int value) {
        if (findKey(key) != NULL) {
            cout << "Error: Key " << key << " already exists!\n";
            return;
        }

        Node *temp = new Node;
        temp->key = key;
        temp->value = value;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            Node *temp2 = head;
            while (temp2->next != NULL)
                temp2 = temp2->next;
            temp2->next = temp;
            temp->prev = temp2;
        }
        cout << "Inserted (" << key << ", " << value << ")\n";
    }

    // Search by key → return value
    int search(int key) {
        Node *node = findKey(key);
        if (node != NULL)
            return node->value;
        cout << "Key " << key << " not found!\n";
        return -1;
    }

    // Remove node by key
    void remove(int key) {
        Node *temp = findKey(key);
        if (temp == NULL) {
            cout << "Key " << key << " not found!\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        cout << "Removed (" << temp->key << ", " << temp->value << ")\n";
        delete temp;
    }

    // Display list
    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << "(" << temp->key << ", " << temp->value << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    KV_DList kv;

    kv.insert(1, 100);
    kv.insert(2, 200);
    kv.insert(3, 300);
    kv.display();

    cout << "Search key 2 → value = " << kv.search(2) << endl;
    cout << "Search key 5 → value = " << kv.search(5) << endl;

    kv.remove(2);
    kv.display();

    kv.insert(2, 250);
    kv.display();

    return 0;
}