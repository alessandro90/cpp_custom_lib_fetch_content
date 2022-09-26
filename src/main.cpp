#include "cpputils/functional/operator_sections.hpp"
#include "cpputils/types/number.hpp"
#include <algorithm>
#include <array>
#include <iostream>


using cpputils::_;  // NOLINT
using namespace cpputils::literals;

int main() {
    static constexpr auto v = std::array{1_i32, -9_i32, 6_i32, 5_i32};
    static constexpr auto negative = std::ranges::find_if(v, _ < 0_i32);
    if (negative != v.end()) {
        std::cout << "Found a negative number: " << *negative << '\n';
    }
}