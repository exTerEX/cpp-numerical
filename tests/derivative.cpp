#include "numerical/derivative.hpp"

#include <cassert>
#include <iostream>

#define ERROR 1e-2

auto func_1(double_t x) -> double_t { return 4 * std::exp(-x) * std::sin(x) - 1; }
auto func_2(double_t x) -> double_t { return 2 * std::pow(x, 3) - 2 * x - 5; }
auto func_3(double_t x) -> double_t { return std::sin((std::sqrt(std::exp(x) + 5)) / 2); }
auto func_4(double_t x) -> double_t { return (5 * std::pow(x, 2) / std::sin(x)); }

int main(int argc, char **argv) {
  assert(std::abs(4 - numerical::derivative(func_1, 0)) < ERROR);
  assert(std::abs(862 - numerical::derivative(func_2, 12)) < ERROR);
  assert(std::abs(0.0356038 - numerical::derivative(func_3, 0.045)) < ERROR);
  assert(std::abs(5.0250487 - numerical::derivative(func_4, 0.1)) < ERROR);
}
