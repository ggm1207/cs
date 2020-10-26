#include <iostream>
#include <random>

#define MAX_LEN 10000

using namespace std;

int arr[MAX_LEN];
int tmp[MAX_LEN];

void merge(int left, int mid, int right){
    int l = left, m = mid, pos = left;
    while(l < mid && m < right){
        if (arr[l] < arr[m])
            tmp[pos++] = arr[l++];
        else
            tmp[pos++] = arr[m++];
    }

    if(l == mid)
        while(m < right)
            tmp[pos++] = arr[m++];
    else
        while(l < mid)
            tmp[pos++] = arr[l++];

    for (int i=left; i<right; i++) {
        arr[i] = tmp[i]; 
    }

}

void mergesort(int left, int right){
    if (right - left > 1){
        int mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid, right);
        merge(left, mid, right);
    }
}



int main(void){
    for (int i=0; i<MAX_LEN; i++) arr[i] = rand();
    mergesort(0, MAX_LEN);
    for (int i=0; i<MAX_LEN-1; i++) {
        if (arr[i] > arr[i+1])
            cout << "something wrong" << endl;
    }

    return 0;
}
