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

// 1.3
bool is_one_string_sub_permutation(string str1, string str2){
    string s_str, l_str; // short, long

    s_str = str2;
    l_str = str1;

    if (str1.length() < str2.length()){
        s_str = str1;
        l_str = str2;
    }

    int ascii[256] = { 0 };

    for (int i=0; i<l_str.length(); i++)
        ascii[(int)l_str[i]]++;

    for (int i=0; i<s_str.length(); i++)
        if (--ascii[(int)s_str[i]] < 0)
            return false;
         
    return true;
}

// 1.4
string change_space_to_percent20(string str1){
    string s = "";
    char prev = 'a', cur;
    
    for (int i=0; i<str1.length(); ++i) {
        cur = str1[i];
        
        if (cur != ' ')
            s += cur;
        else if (prev != ' ' && cur == ' ')
            s += "%20";
                
        prev = cur;
    }

    return s;
}

int main(void){
    string ex1 = "abcdefg";
    string ex2 = "abcdeff";

    cout << "\n1.1 result" << endl;
    cout << is_all_char_unique(ex1) << endl;
    cout << is_all_char_unique(ex2) << endl;

    char ex3[7] = {'1', '2', '3', '4', '5', '6', '7'};

    cout << "\n1.2 result" << endl;
    cout << ex3 << endl;
    reverse(ex3);
    cout << ex3 << endl;

    cout << "\n1.3 result" << endl;
    cout << is_one_string_sub_permutation(ex1, ex2) << endl; // expect return 0
    cout << is_one_string_sub_permutation("abc", "bcd") << endl; // expect return 0
    cout << is_one_string_sub_permutation("abc", "abcd") << endl; // expect return 1

    cout << "\n1.4 result" << endl;
    cout << change_space_to_percent20("space check") << endl;
    cout << change_space_to_percent20(" space check") << endl;
    cout << change_space_to_percent20(" space check ") << endl;

    return 0;
}
