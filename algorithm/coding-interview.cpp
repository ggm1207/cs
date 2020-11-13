#include <iostream>

using namespace std;

// 1.1
bool is_all_char_unique(string str){
    bool is_unique[256] = { 0 };
    for (int i=0; i < str.length(); i++) {
        if (is_unique[(int)str[i]])
            return false;
        is_unique[(int)str[i]] = true;
    }
    return true;
}

// 1.2
void reverse(char * str){
    int n = 0;
    char temp;
    while(*(str + n)){
        n++;
    }
    for (int i=0; i<n/2; i++) {
        temp = *(str + i);
        *(str + i) = *(str + n - (i + 1));
        *(str + n - (i + 1)) = temp;
    }
}


int main(void){
    string ex1 = "abcdefg";
    string ex2 = "abcdeff";

    cout << is_all_char_unique(ex1) << endl;
    cout << is_all_char_unique(ex2) << endl;

    char ex3[7] = {'1', '2', '3', '4', '5', '6', '7'};

    cout << ex3 << endl;
    reverse(ex3);
    cout << ex3 << endl;


    return 0;
}
