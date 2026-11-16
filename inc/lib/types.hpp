#pragma once

#include <array>
#include <cmath>
#include <complex>
#include <iostream>
#include <numbers>
#include <cstdint>

using Complex = std::complex<double>;

using qgate = std::array<Complex, 4>;

inline constexpr Complex imag_unit = Complex(0.0, 1.0);

inline constexpr double float_tolerance = 1e-12;

static constexpr uint32_t MAX_QUBITS = 16; // Subject to change after performance testing

template<typename T>
constexpr int kron_d(T i, T j)
{
  static_assert(std::is_integral<T>::value, "Kronecker Delta requires integer types");
  return (i == j) ? 1 : 0;
}