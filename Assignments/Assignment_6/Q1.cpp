#include<iostream>
using namespace std;

struct queue_arr{
    int *data;
    int size;
    int front , rear ;

    // (a) constructor to create an array
    queue_arr(int s){
        data = new int[s];
        size = s;
        front = rear = -1;
    }

    // (b) check if it is empty or not
    bool is_empty(){
        // Queue is empty if front is -1 or front has crossed rear
        return front == -1 || front > rear;
    }

    // (c) check if it is full or not
    bool is_full(){
        // Simple queue is full if rear is at the last index
        return rear == size - 1;
    }

    // (d) Enqueue the element 
    void enqueue (int d)
    {
        if(is_full())
        {
            cout << "Queue is full. " << d << " is not added." << endl;
            return;
        }
        
        if(is_empty()) // If it's the first element
        {
            front = 0;
        }
        
        rear = rear + 1;
        data[rear] = d;
        cout << d << " is added in queue." << endl;
    }
    
    // (e) Dequeue the element 
    void dequeue()
    {
        if(is_empty())
        {
            cout << "Queue is empty, cannot dequeue." << endl;
            return;
        }
        
        int t = data[front];
        cout << t << " is dequeued." << endl;
        
        if(front == rear) // If only one element was in the queue
        {
            // Reset the queue to empty state
            front = rear = -1;
        }
        else
        {
            // Move front one position ahead
            front = front + 1;
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

    // (h) display all the elements in the queue and front/rear values
    void display()
    {
        if(is_empty())
        {
            cout << "Queue is empty, so no element to display." << endl;
        }
        else
        {
            cout << "Queue elements: ";
            for(int i = front; i <= rear; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }
        cout << "front = " << front << endl;
        cout << "rear = " << rear << endl;
    }
};

int main (){
    cout << "--- Simple Queue ---" << endl;
    queue_arr q1(4);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50); // Should be full
    cout << endl;
    
    q1.display();
    cout << endl;

    q1.element_at_front();
    q1.element_at_rear();
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
    q1.element_at_front(); // Trying to get element from empty queue
    
    return 0;
}
