#include <iostream>
#include <stack>

using namespace std;
int arr_size = 5;


int bad_maze[5][5] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 1},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 1, 0}
};

typedef struct Pos{
    int y, x;
} Pos;

int m[2][4] = {
    {1, -1, 0, 0},
    {0, 0, 1, -1}
};

bool is_possible_to_nn(int y, int x){

    int maze[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0}
    };

    stack<Pos> s1;
    Pos s = {y, x};
    s1.push(s);
    Pos cur_pos;
    int my, mx;

    while(s1.size()){
        cur_pos = s1.top(); s1.pop();
        y = cur_pos.y; x = cur_pos.x;

        if (y == arr_size-1 && x == arr_size-1){
            return true;
        }

        maze[y][x] = 1;
        for (int i=0; i<4; i++) {
            my = y + m[0][i];
            mx = x + m[1][i];

            if(my < 0 || my >= arr_size || mx < 0 || mx >= arr_size)
                continue;

            if(maze[my][mx] == 0){
                Pos n = {my, mx};
                s1.push(n);
            }
        }
    }

    return false;
}

int main(void){
    cout << is_possible_to_nn(0, 0) << endl;

    return 0;
}
