#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>

template <double Lower, double Upper>
class FixedRangeFloat {
 private:
  uint8_t m_value{0};
  static constexpr uint8_t kSteps{254};
  static constexpr double kHalf{0.5};

 public:
  FixedRangeFloat& operator=(double rhs) {
    const double clamped = std::clamp(rhs, Lower, Upper);
    m_value = static_cast<uint8_t>((clamped - Lower) * kSteps / (Upper - Lower) + kHalf);
    return *this;
  }

  operator double() const {
    return Lower + (Upper - Lower) * static_cast<double>(m_value) / kSteps;
  }

  [[nodiscard]] constexpr double error() { return (Upper - Lower) / (kSteps - 1) / 2; }
};
