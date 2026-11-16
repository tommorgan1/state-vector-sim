#include "statevector.hpp"
#include "gates.hpp"

#include <iostream>

using namespace qsim;

int main()
{
  StateVector sv(2);

  // |00> -> H on qubit 0 -> X on qubit 1
  sv.apply_gate(gates::hadamard, 0);
  sv.apply_gate(gates::pauliX, 1);

  for (uint32_t i{}; i < sv.size(); i++)
  {
    std::cout << "|" << i << "> : " << sv.amplitude(i) << "\n";
  }

  std::cout << "norm^2 = " << sv.norm_squared() << "\n";
}
