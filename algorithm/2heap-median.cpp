#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Median{
    private:
        priority_queue<int, vector<int>, less<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
    public:
        void push(int item);
        float get_median();
};

void Median::push(int item){
    if(max_heap.size() == 0){  // init when Median.size() < 2
        max_heap.push(item);
    } else if (min_heap.size() == 0){
        if(item < max_heap.top()){
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(item);
        } else {
            min_heap.push(item);
        }
    } else {
        int min_v = max_heap.top();
        int max_v = min_heap.top();

        if (item > max_v)
            min_heap.push(item);
        else  
            max_heap.push(item);

        if(min_heap.size() < max_heap.size() - 1){
            while(min_heap.size() < max_heap.size()){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        } else if (min_heap.size() - 1> max_heap.size()){
            while(min_heap.size() > max_heap.size()){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }
}

float Median::get_median(){
    if(max_heap.size() == min_heap.size())
        return ((float)(min_heap.top() + max_heap.top())) / 2.0;
    else if (max_heap.size() < min_heap.size())
        return (float)min_heap.top();
    else
        return (float)max_heap.top();
}

int main(void){
    Median m = Median();
    m.push(1);
    cout << m.get_median() << endl;
    m.push(2);
    cout << m.get_median() << endl;
    m.push(3);
    cout << m.get_median() << endl;
    m.push(4);
    cout << m.get_median() << endl;
    m.push(5);
    cout << m.get_median() << endl;
    m.push(6);
    cout << m.get_median() << endl;


    return 0;
}
