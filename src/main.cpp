#include "cpputils/functional/operator_sections.hpp"
#include "cpputils/types/number.hpp"
#include <algorithm>
#include <array>
#include <iostream>


using cpputils::_;  // NOLINT
using cpputils::i32;
using namespace cpputils::literals;

struct Integer {
public:
    constexpr explicit Integer(i32 value)
        : m_value{value} {}
    [[nodiscard]] constexpr i32 get() const noexcept { return m_value; }

private:
    i32 m_value{};
};

int main() {
    static constexpr auto v = std::array{Integer{1_i32}, Integer{-9_i32}, Integer{6_i32}, Integer{5_i32}};
    static constexpr auto negative = std::ranges::find_if(v, _.fn(&Integer::get) < 0_i32);
    if (negative != v.end()) {
        std::cout << "Found a negative number: " << negative->get() << '\n';
    }
}