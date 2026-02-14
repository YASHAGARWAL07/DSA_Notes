#include<iostream>
using namespace std;

// --- Helper Queue Implementation using a Linked List ---
// This is the basic building block for our priority queue.
// Each priority level will have one of these queues.
struct queue_ll {
    struct Node {
        int data;
        Node* next;
    };
    Node *front, *rear;

    queue_ll() {
        front = rear = nullptr;
    }

    bool is_empty() {
        return front == nullptr;
    }

    void enqueue(int d) {
        Node* newNode = new Node();
        newNode->data = d;
        newNode->next = nullptr;
        if (is_empty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (is_empty()) {
            return -1; // Indicates queue is empty
        }
        Node* temp = front;
        int t = temp->data;
        front = front->next;
        if (front == nullptr) {
           rear = nullptr;
        }
        delete temp;
        return t;
    }

    void display() {
        if (is_empty()) {
            cout << "is empty.";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
// --- End of Helper Queue ---


// --- Priority Queue Implementation ---
struct my_priority_queue {
    // We will use integer values for priority:
    // 1 -> High
    // 2 -> Medium
    // 3 -> Low
    queue_ll high_priority_q;
    queue_ll medium_priority_q;
    queue_ll low_priority_q;

    // (a) constructor to create the priority queue
    my_priority_queue() {
        // The queues are already initialized by their own constructors
        cout << "Priority Queue created." << endl;
    }

    // (b) Enqueue the element with a given priority
    void enqueue(int priority, int d) {
        switch (priority) {
            case 1: // High
                high_priority_q.enqueue(d);
                cout << d << " is added to High priority queue." << endl;
                break;
            case 2: // Medium
                medium_priority_q.enqueue(d);
                cout << d << " is added to Medium priority queue." << endl;
                break;
            case 3: // Low
                low_priority_q.enqueue(d);
                cout << d << " is added to Low priority queue." << endl;
                break;
            default:
                cout << "Invalid priority level (" << priority << "). Please use 1, 2, or 3." << endl;
                break;
        }
    }

    // (c) Dequeue the element (always from the highest available priority)
    void dequeue() {
        if (!high_priority_q.is_empty()) {
            int t = high_priority_q.dequeue();
            cout << t << " (High Priority) is dequeued." << endl;
        } else if (!medium_priority_q.is_empty()) {
            int t = medium_priority_q.dequeue();
            cout << t << " (Medium Priority) is dequeued." << endl;
        } else if (!low_priority_q.is_empty()) {
            int t = low_priority_q.dequeue();
            cout << t << " (Low Priority) is dequeued." << endl;
        } else {
            cout << "Priority Queue is completely empty. Cannot dequeue." << endl;
        }
    }

    // (d) Display the elements according to their priorities
    void display() {
        cout << "\n--- Priority Queue Status ---" << endl;
        cout << "High Priority (1):   ";
        high_priority_q.display();
        cout << "\nMedium Priority (2): ";
        medium_priority_q.display();
        cout << "\nLow Priority (3):    ";
        low_priority_q.display();
        cout << "\n-----------------------------\n";
    }
};

int main() {
    cout << "--- Priority Queue ---" << endl;
    my_priority_queue pq1;

    // Enqueue items with different priorities
    pq1.enqueue(3, 100); // Low
    pq1.enqueue(1, 5);   // High
    pq1.enqueue(2, 50);  // Medium
    pq1.enqueue(1, 10);  // High
    pq1.enqueue(3, 200); // Low

    pq1.display();

    // Dequeue items - they should come out in priority order
    cout << "\n--- Dequeuing Elements ---" << endl;
    pq1.dequeue(); // Should be 5 (from High)
    pq1.dequeue(); // Should be 10 (from High)
    pq1.display();

    pq1.dequeue(); // Should be 50 (from Medium)
    pq1.display();
    
    pq1.dequeue(); // Should be 100 (from Low)
    pq1.dequeue(); // Should be 200 (from Low)
    pq1.display();
    
    pq1.dequeue(); // Should be empty

    return 0;
}

