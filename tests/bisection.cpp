#include "numerical/bisection.hpp"

#include <cassert>
#include <iostream>

#define ERROR 1e-2

auto func_1(double_t x) -> double_t { return 4 * std::exp(-x) * std::sin(x) - 1; }
auto func_2(double_t x) -> double_t { return 2 * pow(x, 3) - 2 * x - 5; }

int main(int argc, char **argv) {
  assert(std::abs(0.371 - numerical::bisection(func_1, 0, 0.5)) < ERROR);
  assert(std::abs(1.601 - numerical::bisection(func_2, -1, 12)) < ERROR);
}
