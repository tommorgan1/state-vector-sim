#pragma once

#include "types.hpp"

namespace qsim
{
  namespace gates
  {
    inline constexpr double inv_sqrt2 = 1.0 / std::numbers::sqrt2;

    inline constexpr qgate hadamard = {inv_sqrt2, inv_sqrt2, inv_sqrt2 ,-inv_sqrt2};

    inline constexpr qgate pauliX = {0, 1, 1, 0};

    inline constexpr qgate pauliY = {0, -imag_unit, imag_unit, 0};

    inline constexpr qgate pauliZ = {1, 0, 0, -1};
  }
}

