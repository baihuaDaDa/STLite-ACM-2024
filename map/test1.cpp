#include "map.hpp"
#include "bonus1.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <queue>
#include <vector>

int main(void) {
    freopen("1.out", "w", stdout);
    sjtu::map<int, int> map;
    std::queue<int> queue;
    std::vector<int> vector;
    for (int i = 1; i <= 10; i++) {
        map.insert(sjtu::pair<int, int>(i, i));
        queue.push(10 - i);
        vector.push_back(10 - i);
    }
    sjtu::my_sort(map.begin(), map.end());
    sjtu::my_sort(vector.begin(), vector.end());
    for (int i = 0; i < 10; i++)
        std::cout << vector[i] << ' ';
}
