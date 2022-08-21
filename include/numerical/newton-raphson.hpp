#ifndef NUMERICAL_NEWTON_RAPHSON_HPP
#define NUMERICAL_NEWTON_RAPHSON_HPP

#include <cmath>
#include <functional>

namespace numerical {

auto newton_raphson(const std::function<double(double)>&, double_t, double_t = 1e-15) -> double_t;

}; // namespace numerical

#endif
