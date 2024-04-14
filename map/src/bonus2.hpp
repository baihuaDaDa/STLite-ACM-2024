#ifndef MAP_BONUS2_HPP
#define MAP_BONUS2_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <type_traits>
#include <vector>

namespace sjtu {

    template<typename _Tp>
    static constexpr bool is_atomic_printable = requires(const _Tp &x) {
        std::cout << x;
        requires !std::is_bounded_array_v<_Tp>;
    };

    template<class T>
    static constexpr bool is_iterable = requires(T value) {
        { std::begin(value) };
        { std::end(value) };
    };

    template<typename _Tp>
    static constexpr bool is_printable = requires(const _Tp &x) {
        requires is_atomic_printable<_Tp> || (is_printable<decltype(x[0])>) ||
                 (is_iterable<_Tp> && is_printable<decltype(*(std::begin(x)))>);
    };

    template<typename _Tp>
    void print(const _Tp &__val, size_t __indent = 0) {
        // Your code here.
        if constexpr (is_printable<_Tp>) {
            if constexpr (is_atomic_printable<_Tp>) {
                std::cout << __val << '\n';
            } else if constexpr (std::is_bounded_array_v<_Tp>) {
                if constexpr (is_atomic_printable<typename std::remove_extent<_Tp>::type>) {
                    for (int j = 0; j < __indent; j++)
                        std::cout << "    ";
                    std::cout << "[ ";
                    for (int i = 0; i < std::extent_v<_Tp>; i++)
                        std::cout << __val[i] << ' ';
                    std::cout << "]\n";
                } else {
                    for (int j = 0; j < __indent; j++)
                        std::cout << "    ";
                    std::cout << "[\n";
                    for (int i = 0; i < std::extent_v<_Tp>; i++)
                        print(__val[i], __indent + 1);
                    for (int j = 0; j < __indent; j++)
                        std::cout << "    ";
                    std::cout << "]\n";
                }
            } else if constexpr (is_iterable<_Tp>) {
                if constexpr (is_atomic_printable<typename _Tp::value_type>) {
                    for (int j = 0; j < __indent; j++)
                        std::cout << "    ";
                    std::cout << "[ ";
                    for (auto iter = std::begin(__val); iter != std::end(__val); ++iter)
                        std::cout << *iter << ' ';
                    std::cout << "]\n";
                } else {
                    for (int j = 0; j < __indent; j++)
                        std::cout << "    ";
                    std::cout << "[\n";
                    for (auto iter = std::begin(__val); iter != std::end(__val); ++iter)
                        print(*iter, __indent + 1);
                    for (int j = 0; j < __indent; j++)
                        std::cout << "    ";
                    std::cout << "]\n";
                }
            }
        } else static_assert(sizeof(_Tp) != sizeof(_Tp), "Unable to be printed without overloading stream inserting operator('<<').");
    }

} // namespace sjtu

#endif //MAP_BONUS2_HPP
