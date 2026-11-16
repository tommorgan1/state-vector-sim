#pragma once 

#include <array>
#include <complex>
#include <cstddef>
#include <vector>
#include <cstdint>

#include "types.hpp"

namespace qsim 
{
  class StateVector
  {
    public:
      explicit StateVector(uint32_t n_qubits);

      double norm_squared(); // Must add up to 1 (with tolerances for floating point roundinga)

      void apply_gate(const qgate& gate, std::size_t qubit);

      inline Complex amplitude(uint32_t index) { return _amplitudes.at(index); }

      inline uint64_t size() { return _amplitudes.size(); }

    private:
      void _validate_qubit_index(size_t index);

      uint32_t _num_qubits;
      
      std::vector<Complex> _amplitudes;
  };
}