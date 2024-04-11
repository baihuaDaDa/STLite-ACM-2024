#ifndef MAP_BONUS2_HPP
#define MAP_BONUS2_HPP

#include <iterator>
#include <algorithm>
#include <type_traits>
#include <vector>

namespace sjtu {

    template <typename _Tp>
    void print(const _Tp &__val) {
        // Your code here.
    }

} // namespace sjtu


void sample() {
    std::vector<int> a[5];
    for (int i = 0 ; i < 5 ; ++i)
        a[i].push_back(i), a[i].push_back(i);
    sjtu::print(a);
}

/*
应当输出类似如下(总之好看即可):
[
  [0 0]
  [1 1]
  [2 2]
  [3 3]
  [4 4]
]
*/

#endif //MAP_BONUS2_HPP
