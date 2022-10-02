#include "cpputils/functional/operator_sections.hpp"
#include "cpputils/misc/benchmark.hpp"
#include "cpputils/types/number.hpp"
#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <thread>


using cpputils::_;  // NOLINT
using cpputils::i32;
using namespace cpputils::literals;
using namespace cpputils::benchmark;

using namespace std::literals;

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
    static constexpr auto negative = std::ranges::find_if(v, _.fn(CALL(get)) < 0_i32);
    if (negative != v.end()) {
        std::cout << "Found a negative number: " << negative->get() << '\n';
    }

    std::cout << "\n\n-------------\nBenchmark test\n-------------\n\n";

    auto logger = timer<>::logger_t{};
    {
        timer<>::scoped const t{logger, "section_1"};
        std::this_thread::sleep_for(350ms);
    }
    {
        timer<>::scoped const t{logger, "section_2"};
        std::this_thread::sleep_for(100ms);
    }
    {
        timer<>::scoped const t{logger, "section_3"};
        std::this_thread::sleep_for(503ms);
    }
    {
        timer<>::scoped const t{logger, "section_4"};
        std::this_thread::sleep_for(236005000ns);
    }
    auto const time_report = reporter<>::report<formatters::markdown>(logger);

    std::cout << time_report;
}