#include<iostream>
using namespace std;

struct circular_queue_arr{
    int *data;
    int size;
    int front , rear;

    // (a) constructor to create an array
    circular_queue_arr(int s){
        data = new int[s];
        size = s;
        front = rear = -1;
    }

    // (b) check if it is empty or not
    bool is_empty(){
        return front == -1;
    }

    // (c) check if it is full or not
    bool is_full(){
        // Condition for a full circular queue
        return (rear + 1) % size == front;
    }

    // (d) Enqueue the element 
    void enqueue (int d)
    {
        if(is_full())
        {
            cout << "Queue is full. " << d << " cannot be added." << endl;
            return;
        }
        if (is_empty()) { // If queue is initially empty
            front = 0;
        }
        rear = (rear + 1) % size; // Move rear circularly
        data[rear] = d;
        cout << d << " is added to the queue." << endl;
    }
    
    // (e) Dequeue the element 
    void dequeue()
    {
        if(is_empty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        int t = data[front];
        cout << t << " is dequeued." << endl;
        if(front == rear) // If there was only one element
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size; // Move front circularly
        }
    }

    // (f) display the element at front
    void element_at_front()
    {
        if(is_empty())
        {
            cout << "No element is present at front." << endl;
            return;
        }
        cout << "Element_at_front is " << data[front] << endl;
    }

    // (g) display the element at rear
    void element_at_rear()
    {
        if(is_empty())
        {
            cout << "No element is present at rear." << endl;
            return;
        }
        cout << "Element_at_rear is " << data[rear] << endl;
    }

    // (h) display all the elements in the queue
    void display()
    {
        if(is_empty())
        {
            cout << "Queue is empty, so no element to display." << endl;
        }
        else
        {
            cout << "Queue elements: ";
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

int main (){
    cout << "--- Circular Queue ---" << endl;
    circular_queue_arr q1(4);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    cout << endl;
    
    q1.display();
    q1.enqueue(50); // This should show queue is full
    cout << endl;

    q1.element_at_front();
    q1.element_at_rear();
    cout << endl;

    q1.dequeue();
    q1.dequeue();
    q1.display();
    cout << endl;

    cout << "Enqueuing new elements to demonstrate wrap-around:" << endl;
    q1.enqueue(50);
    q1.enqueue(60);
    q1.display();
    cout << endl;
    
    q1.enqueue(70); // Should be full again
    cout << endl;


    return 0;
}

