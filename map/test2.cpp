#include "map.hpp"
#include "bonus2.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <queue>
#include <vector>

int main(void) {
    freopen("1.out", "w", stdout);
    int x = 1;
    int y[5] = {1, 2, 3, 4, 5};
    int z[3][3] = {{1, 2, 3},
                   {1, 2, 3},
                   {1, 2, 3}};
    std::queue<int> queue;
    std::vector<int> vector;
    std::vector<std::vector<int>> vector1;
    std::vector<std::vector<std::vector<int>>> vector2;
    std::vector<int> vector3[5];
    for (int i = 1; i <= 10; i++) {
        queue.push(10 - i);
        vector.push_back(10 - i);
    }
    for (int i = 1; i <= 10; i++)
        vector1.push_back(vector);
    for (int i = 1; i <= 10; i++)
        vector2.push_back(vector1);
    for (int i = 0; i < 5; i++)
        vector3[i] = vector;
    sjtu::print(x);
    sjtu::print(y);
    sjtu::print(z);
//    sjtu::print(queue);
    sjtu::print(vector);
    sjtu::print(vector1);
    sjtu::print(vector2);
    sjtu::print(vector3);
}
