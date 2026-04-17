#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>q;       //Max Heap
    q.push(10);
    q.push(7);
    q.push(27);
    q.push(18);
    q.push(54);
    q.push(15);

    cout<<q.top()<<" ";

    //Delete
    q.pop();
    cout<<q.top();
    return 0;
}
