// "CompileTimeArrayInitialisation.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <type_traits>
#include <utility>
#include <array>
#include <iterator>
#include <iostream>
#include <stdint.h>

template <typename T = std::size_t>
constexpr T generate_ith_number(const std::size_t index) {
    static_assert(std::is_integral<T>::value, "T must to be an integral type");

    if (index == 0) return 0;
    return (3 * index - 1) / 2;
}

template <std::size_t... Is>
constexpr auto make_sequence_impl(std::index_sequence<Is...>)
{
    return std::index_sequence<generate_ith_number(Is)...>{};
}

template <std::size_t N>
constexpr auto make_sequence()
{
    return make_sequence_impl(std::make_index_sequence<N>{});
}

template <std::size_t... Is>
constexpr auto make_array_from_sequence_impl(std::index_sequence<Is...>)
{
    return std::array<std::size_t, sizeof...(Is)>{Is...};
}

template <typename Seq>
constexpr auto make_array_from_sequence(Seq)
{
    return make_array_from_sequence_impl(Seq{});
}

int main()
{
    constexpr auto arr = make_array_from_sequence(make_sequence<(uint8_t)6>());
//   static_assert(arr[0] == 0);
//   static_assert(arr[1] == 1);
//   static_assert(arr[2] == 2);
//   static_assert(arr[3] == 4);
//   static_assert(arr[4] == 5);
//   static_assert(arr[5] == 7);
    for(const auto& s : arr)
        std::cout << s << ' ';
    std::cout << "\n";

    std::cout << "Size of arr: " << (int) sizeof(arr) << "\n";

    return 0;
}
