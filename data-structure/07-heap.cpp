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
    public:
        Heap(int capacity);
        void heappush(int item);
        void display();
        int heappop();
        // is_empty, is_full 있어야 됨.
};

Heap::Heap(int capacity){
    Heap::arr = (element*)malloc(sizeof(element) * capacity);
}

void Heap::display(){
    for (int i=0; i<Heap::length; i++)
        cout << Heap::arr[i] << " ";
    cout << endl;
}

void Heap::heappush(int item){
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
    int item = Heap::arr[0];
    int idx = 1;
    int l_idx = 2, r_idx = 3;
    int * arr = Heap::arr;
    while(l_idx <= Heap::length && r_idx <= Heap::length){
        if(arr[idx-1] < arr[l_idx-1]){
            SWAP(arr[idx-1], arr[l_idx-1]);
            idx = l_idx;
        } else if (arr[idx-1] < arr[r_idx-1]) {
            SWAP(arr[idx-1], arr[r_idx-1]);
            idx = r_idx;
        } else break;
        l_idx = idx * 2;
        r_idx = l_idx + 1;
    }
    SWAP(arr[Heap::length-1], arr[0]);
    Heap::length--;
    return item;
}


int main(void){
    Heap h = Heap(10);
    h.heappush(1);
    h.display();
    h.heappush(3);
    h.display();
    h.heappush(5);
    h.display();
    cout << h.heappop() << endl;
    cout << h.heappop() << endl;
    cout << h.heappop() << endl;
}
