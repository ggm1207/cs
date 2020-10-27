#include <iostream>
#define element int

using namespace std;

inline void SWAP(int &a, int &b){
    if (a != b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

class Heap{
    private:
        int * arr;
        int length = 0;
        int array_capacity;
    public:
        Heap(int capacity);
        void heappush(int item);
        void display();
        int heappop();
        bool is_full();
        bool is_empty();
        // is_empty, is_full 있어야 됨.
};

Heap::Heap(int capacity){
    Heap::arr = (element*)malloc(sizeof(element) * capacity);
    Heap::array_capacity = capacity;
}

bool Heap::is_full(){
    return Heap::array_capacity == Heap::length;
}

bool Heap::is_empty(){
    return Heap::length == 0;
}

void Heap::display(){
    for (int i=0; i<Heap::length; i++)
        cout << Heap::arr[i] << " ";
    cout << endl;
}

void Heap::heappush(int item){
    if(Heap::is_full())
        throw -1;

    int & length = Heap::length;
    int * arr = Heap::arr;
    
    arr[length] = item;
    int idx = length + 1;
    int p_idx;
    length += 1;

    // upheap    
    while(idx != 1){
        p_idx = idx / 2;
        if (arr[p_idx-1] < arr[idx-1]){
            SWAP(arr[p_idx-1], arr[idx-1]);
            idx = p_idx;
        }
    }
}

int Heap::heappop(){
    if(Heap::is_empty())
        throw -1;

    int item = Heap::arr[0];
    int idx = 1;
    int l_idx = 2, r_idx = 3;
    int * arr = Heap::arr;

    SWAP(arr[--Heap::length], arr[0]);

    while(l_idx <= Heap::length && r_idx - 1 < Heap::length){
        if(arr[r_idx-1] < arr[l_idx-1]){  // left 
            if (arr[l_idx-1] > arr[idx-1]){
                SWAP(arr[l_idx-1], arr[idx-1]); 
                idx = l_idx;
            } else break;
        } else { // right
            if (arr[r_idx-1] > arr[idx-1]){
                SWAP(arr[r_idx-1], arr[idx-1]);
                idx = r_idx;
            } else break;
        }
        l_idx = idx * 2;
        r_idx = l_idx + 1;
    }

    return item;
}


int main(void){
    Heap h = Heap(13);
    
    //h.heappush(1);
    //h.heappush(3);
    //h.heappush(5);

    for (int i=0; i<10; i++) {
        h.heappush(i * 3 + 1);
    }

    h.display();

    for (int i=0; i<10; i++) {
        cout << h.heappop() << " ";
        //h.heappop();
        //h.display();
    }
}
