#include "statevector.hpp"

#include <cmath>
#include <cassert>
#include <stdexcept>
#include <charconv>

using namespace qsim;

static void validate_qubit_count(size_t num_qubits)
{
  if (0 == num_qubits || num_qubits > MAX_QUBITS)
  {
    throw std::invalid_argument("qubit count out of bounds");
  }
}

void StateVector::_validate_qubit_index(size_t index)
{
  if (index >= _num_qubits)
  {
    std::string message = "qubit out of bounds";
    throw std::out_of_range(message);
  }
}


StateVector::StateVector(uint32_t n_qubits)
  : _num_qubits(n_qubits)
{
  validate_qubit_count(n_qubits);
  _amplitudes.assign(std::size_t{1} << n_qubits, Complex{0.0, 0.0});
  _amplitudes[0] = 1.0; // start in |0...0>
}

double StateVector::norm_squared()
{
  double sum{};

  for (auto& amplitude : _amplitudes)
  {
    sum += std::norm(amplitude);
  }

  return sum;
}


void StateVector::apply_gate(const qgate& gate, std::size_t qubit)
{
  _validate_qubit_index(qubit);

  uint64_t mask = std::size_t{1} << qubit;

  for (size_t i{}; i < _amplitudes.size(); i++)
  {
    if (i & mask)
    {
      continue;
    }

    Complex a0 = _amplitudes[i];
    Complex a1 = _amplitudes[i + mask];
    _amplitudes[i] = gate[0] * a0 + gate[1] * a1;
    _amplitudes[i + mask] = gate[2] * a0 + gate[3] * a1;
  }
}
