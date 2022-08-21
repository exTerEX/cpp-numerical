#include "numerical/newton-raphson.hpp"

#include <cassert>
#include <iostream>

#define ERROR 1e-2

auto func(double_t x) -> double_t { return x * std::sin(x) + std::cos(x); }

int main(int argc, char **argv) { assert(std::abs(2.798 - numerical::newton_raphson(func, 3.1416)) < ERROR); }
