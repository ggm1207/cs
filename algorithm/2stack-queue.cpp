#include <iostream>
#include <stack>

using namespace std;

class Queue{
    private:
        stack<int> s1;
        stack<int> s2;
        int length = 0;

    public:
        void enQueue(int item);
        int deQueue();
        bool is_empty();
};

void Queue::enQueue(int item){
    Queue::s1.push(item);
    Queue::length++;
}

bool Queue::is_empty(){
    return length == 0;
}

int Queue::deQueue(){
    if(Queue::is_empty()) throw -1;
    int item;

    Queue::length--;
    if(Queue::s2.size() == 0){
        while(Queue::s1.size()){
            Queue::s2.push(Queue::s1.top());
            Queue::s1.pop();
        }
        item = Queue::s2.top(); 
        Queue::s2.pop();
        return item;
    } else {
        item = Queue::s2.top(); 
        Queue::s2.pop();
        return item;
    }
}
    
int main() {
    Queue q = Queue();
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    q.deQueue();
    
    for (int i=0; i<4; i++) {
        cout << q.deQueue() << " ";
        q.enQueue(4);
    }

    return 0; 
}
