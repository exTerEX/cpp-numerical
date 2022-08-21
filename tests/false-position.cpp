#include "numerical/false-position.hpp"

#include <cassert>
#include <iostream>

#define ERROR 1e-2

auto func(double_t x) -> double_t { return 4 * std::exp(-x) * std::sin(x) - 1; }

int main(int argc, char **argv) { assert(std::abs(0.371 - numerical::false_position(func, 0, 0.5)) < ERROR); }
