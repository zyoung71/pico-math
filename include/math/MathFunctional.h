#pragma once

#include <array>
#include <cstddef>

template<typename D>
using MathFunction = D(*)(D); // same type on input and output

constexpr size_t lut_size = 256;
template<typename D>
using FunctionLUT = std::array<D, lut_size>;