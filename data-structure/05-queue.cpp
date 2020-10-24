#include <iostream>
#include <algorithm>

#define element int

using namespace std;

typedef struct Queue{
    element *arr;
    int front = 0, rear = 0;
    int arr_size;
} Queue;

Queue* create(int arr_size);
bool is_queue_empty(Queue* q);
bool is_queue_full(Queue* q);
void Print(Queue* q);
bool enqueue(Queue* q, element e);
element dequeue(Queue* q);
element peek(Queue *q);

int main(void){
    element arr_size = 10;
    Queue *q;
    q = create(arr_size);

    //int * arr;
    //arr = (int*)malloc(sizeof(int) * 10);
    //*(arr + 1) = 3;
    
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    Print(q);
    cout << dequeue(q) << endl;
    Print(q);
    cout << peek(q) << endl;
    Print(q);
    return 0;
}

Queue* create(int arr_size){
    Queue *q;
    q = (Queue*)malloc(sizeof(Queue));
    q -> arr = (element*)malloc(sizeof(element) * (arr_size + 1));
    q -> arr_size = (arr_size + 1);
    return q;
}

void Print(Queue * q){
    cout << q -> front << " " << q -> rear << endl;
    for (int i = 0; i < q -> arr_size; ++i){
        cout << *(q -> arr + i) << " ";
    }
    cout << endl;
}

bool is_queue_empty(Queue* q){
    return (q -> front == q -> rear);
}

bool is_queue_full(Queue* q){
    return (q -> front == (q -> rear + 1) % q -> arr_size);
}

bool enqueue(Queue* q, element e){
    if (is_queue_full(q))
        return false;
    else {
        *(q -> arr + (q -> rear)) = e;
        q -> rear = (q -> rear + 1) % (q -> arr_size);
        cout << q -> rear << endl;
        return true;
    }
}

element dequeue(Queue* q){
    if (is_queue_empty(q))
        throw -1;
    else {
        q -> front++;
        element temp = *(q -> arr + q -> front % (q -> arr_size));
        return temp;
    }
}

element peek(Queue *q){
    if (is_queue_empty(q))
        throw -1;
    else {
        element temp = *(q -> arr + q -> front % (q -> arr_size));
        return temp;
    }
}
