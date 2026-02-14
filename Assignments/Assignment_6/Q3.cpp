#include<iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

struct queue_ll{
    Node *front, *rear;

    // (a) constructor to create the queue
    queue_ll(){
        front = rear = nullptr;
    }

    // (b) check if it is empty or not
    bool is_empty(){
        return front == nullptr;
    }

    // (c) Enqueue the element 
    void enqueue (int d)
    {
        Node* newNode = new Node();
        newNode->data = d;
        newNode->next = nullptr;
        
        // If the queue is empty, the new node is both front and rear
        if (is_empty()) {
            front = rear = newNode;
        } else {
            // Add the new node at the end of the queue and change rear
            rear->next = newNode;
            rear = newNode;
        }
        cout << d << " is added to the queue." << endl;
    }
    
    // (d) Dequeue the element 
    void dequeue()
    {
        if(is_empty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        
        // Store the previous front and move front one node ahead
        Node* temp = front;
        int t = temp->data;
        cout << t << " is dequeued." << endl;
        
        front = front->next;

        // If front becomes NULL after dequeuing, then the queue is empty
        // so we should also set rear to NULL
        if (front == nullptr) {
           rear = nullptr;
        }
        
        delete temp; // free the memory of the old front node
    }

    // (e) display the element at front
    void element_at_front()
    {
        if(is_empty())
        {
            cout << "No element is present at front." << endl;
            return;
        }
        cout << "Element_at_front is " << front->data << endl;
    }

    // This corresponds to part 'g' in your assignment sheet
    // (g) display all the elements in the queue
    void display()
    {
        if(is_empty())
        {
            cout << "Queue is empty, so no element to display." << endl;
        }
        else
        {
            cout << "Queue elements: ";
            Node* temp = front;
            while(temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        
        // Displaying front and rear data for clarity
        if (!is_empty()) {
            cout << "front points to " << front->data << endl;
            cout << "rear points to " << rear->data << endl;
        } else {
            cout << "front is NULL" << endl;
            cout << "rear is NULL" << endl;
        }
    }
};

int main (){
    cout << "--- Linked List Queue ---" << endl;
    queue_ll q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    cout << endl;
    
    q1.display();
    cout << endl;

    q1.element_at_front();
    cout << endl;

    q1.dequeue();
    q1.dequeue();
    q1.display();
    cout << endl;
    
    q1.dequeue();
    q1.dequeue();
    q1.display(); // Should be empty now
    cout << endl;
    
    q1.dequeue(); // Trying to dequeue from an empty queue
    
    return 0;
}

