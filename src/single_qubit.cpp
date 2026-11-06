#include <array>
#include <cmath>
#include <complex>
#include <iostream>
#include <numbers>

using Complex = std::complex<double>;
using qstate = std::array<Complex, 2>;
using qgate = std::array<Complex, 4>; // row-major {u00, u01, u10, u11}
static constexpr Complex imag_unit = Complex(0.0, 1.0);
//
//


qstate apply_gate(const qgate& gate, const qstate& state)
{
  qstate postgatestate{};
  postgatestate[0] = gate[0] * state[0] + gate[1] * state[1];
  postgatestate[1] = gate[2] * state[0] + gate[3] * state[1];
  return postgatestate;
}

qgate hadamard()
{
  constexpr double sqrt2 = 1.0 / std::numbers::sqrt2;
  return {sqrt2, sqrt2, sqrt2 ,-sqrt2};
}

qgate pauliX()
{
  return {0, 1, 1, 0};
}

qgate pauliY()
{
  return {0, -imag_unit, imag_unit, 0};
}

qgate pauliZ()
{
  return {1, 0, 0, -1};
}

int main()
{
  qstate state = {Complex(1.0, 0.0), Complex(0.0, 0.0)};

  state = apply_gate(hadamard(), state);
  std::cout << state[0] << " " << state[1] << std::endl;

  state = apply_gate(hadamard(), state);
  std::cout << state[0] << " " << state[1] << std::endl;

  state = apply_gate(pauliX(), state);
  std::cout << state[0] << " " << state[1] << std::endl;

  return 0;
}