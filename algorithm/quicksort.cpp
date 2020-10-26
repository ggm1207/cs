#include <iostream>
#include <random>

#define MAX_LEN 10000

using namespace std;

int arr[MAX_LEN];

inline void SWAP(int &a, int &b){
    if( a != b ){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

int quick(int left, int right){
    int idx = left+1;
    for (int i=left+1; i<right; i++) {
        if (arr[i] < arr[left])
            SWAP(arr[idx++], arr[i]);
    }
    SWAP(arr[left], arr[idx-1]);
    return idx - 1;
}

void quicksort(int left, int right){
    if (right - left > 1){
        int pivot = quick(left, right);
        quicksort(left, pivot);
        quicksort(pivot + 1, right);
    }
}

int main(void){
    for (int i=0; i<MAX_LEN; i++) arr[i] = rand();
    quicksort(0, MAX_LEN);
    for (int i=0; i<MAX_LEN-1; i++) {
        if (i % 18 == 0) cout << endl;
        cout << arr[i] << " ";
        if (arr[i] > arr[i+1])
            cout << "something wrong" << endl;
    }

    return 0;
}
