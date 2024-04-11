#ifndef MAP_BONUS1_HPP
#define MAP_BONUS1_HPP

#include <iterator>
#include <algorithm>
#include <type_traits>

namespace sjtu {

    template<typename _Iter>
    static constexpr bool is_sorted = requires() {
        typename _Iter::sorted_iterator_tag;
    };

    template <typename _Iter>
    void my_sort(_Iter __first, _Iter __last) {
        // Your code here.
        // For random access iterator, use std::sort.
        // For sjtu::map iterator, return directly.
        // For others, static_assert(false, "Not a random access iterator.");
        // You may use std::iterator_traits to get the iterator category.
        if constexpr (std::is_same_v<typename std::iterator_traits<_Iter>::iterator_category, std::random_access_iterator_tag>) {
            std::sort(__first, __last);
            return;
        } else if constexpr (is_sorted<_Iter>) {
            return;
        } else {
            static_assert(false, "Not a random access iterator.");
        }
    }

} // namespace sjtu

#endif //MAP_BONUS1_HPP
