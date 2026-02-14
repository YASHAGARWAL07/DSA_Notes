#include<iostream>
using namespace std;

struct deque_arr{
    int *data;
    int size;
    int front , rear;

    // (a) constructor to create the deque
    deque_arr(int s){
        data = new int[s];
        size = s;
        front = rear = -1;
    }

    // Helper function to check if deque is empty
    bool is_empty(){
        return front == -1;
    }

    // Helper function to check if deque is full
    bool is_full(){
        return (rear + 1) % size == front;
    }

    // (b) Insert an element at the rear
    void insert_at_rear(int d) {
        if (is_full()) {
            cout << "Deque is full. Cannot insert " << d << " at rear." << endl;
            return;
        }
        if (is_empty()) { // If deque is initially empty
            front = rear = 0;
        } else {
            rear = (rear + 1) % size; // Move rear circularly
        }
        data[rear] = d;
        cout << d << " is inserted at rear." << endl;
    }

    // Insert an element at the front (corresponds to part d in your assignment)
    void insert_at_front(int d) {
        if (is_full()) {
            cout << "Deque is full. Cannot insert " << d << " at front." << endl;
            return;
        }
        if (is_empty()) { // If deque is initially empty
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size; // Move front circularly backwards
        }
        data[front] = d;
        cout << d << " is inserted at front." << endl;
    }

    // (c) Delete an element from the rear
    void delete_from_rear() {
        if (is_empty()) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }
        int t = data[rear];
        cout << t << " is deleted from rear." << endl;
        if (front == rear) { // If there was only one element
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size; // Move rear circularly backwards
        }
    }

    // Delete an element from the front (corresponds to part e in your assignment)
    void delete_from_front() {
        if (is_empty()) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }
        int t = data[front];
        cout << t << " is deleted from front." << endl;
        if (front == rear) { // If there was only one element
            front = rear = -1;
        } else {
            front = (front + 1) % size; // Move front circularly forward
        }
    }

    // (f) display the element at front
    void element_at_front() {
        if(is_empty()) {
            cout << "No element is present at front." << endl;
            return;
        }
        cout << "Element_at_front is " << data[front] << endl;
    }

    // (g) display the element at rear
    void element_at_rear() {
        if(is_empty()) {
            cout << "No element is present at rear." << endl;
            return;
        }
        cout << "Element_at_rear is " << data[rear] << endl;
    }

    // (h) display all the elements in the deque
    void display() {
        if(is_empty()) {
            cout << "Deque is empty, so no element to display." << endl;
        } else {
            cout << "Deque elements: ";
            int i = front;
            while(true) {
                cout << data[i] << " ";
                if(i == rear) break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
        cout << "front = " << front << endl;
        cout << "rear = " << rear << endl;
    }
};

int main() {
    cout << "--- Double Ended Queue (Deque) ---" << endl;
    deque_arr d1(5);

    d1.insert_at_rear(10);
    d1.insert_at_rear(20);
    d1.insert_at_front(5);
    d1.insert_at_rear(30);
    d1.insert_at_front(1);
    cout << endl;

    d1.display();
    d1.insert_at_rear(100); // Should be full
    cout << endl;

    d1.element_at_front();
    d1.element_at_rear();
    cout << endl;
    
    cout << "Deleting from both ends:" << endl;
    d1.delete_from_front();
    d1.delete_from_rear();
    d1.display();
    cout << endl;
    
    d1.delete_from_rear();
    d1.delete_from_front();
    d1.display();
    cout << endl;

    d1.delete_from_front();
    d1.display(); // Should be empty
    cout << endl;

    d1.delete_from_rear(); // Trying to delete from empty deque

    return 0;
}

