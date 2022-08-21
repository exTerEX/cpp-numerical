#ifndef NUMERICAL_FALSE_POSITION_HPP
#define NUMERICAL_FALSE_POSITION_HPP

#include <cmath>
#include <functional>

namespace numerical {

auto false_position(const std::function<double(double)>, double_t, double_t, double_t = 1e-4) -> double_t;

}; // namespace numerical

#endif
