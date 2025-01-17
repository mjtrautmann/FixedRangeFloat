#pragma once

#include <cstdint>
#include <limits>
#include <cmath>

template<double Lower, double Upper>
class FixedRangeFloat {
private:
  uint8_t m_value;
  static constexpr uint8_t kSteps = 254;

public:
  FixedRangeFloat& operator=(double rhs) {
    if (rhs <= Lower){this->m_value = 0;}
    else if (rhs >= Upper){ this->m_value = kSteps;}
    else {
    this->m_value = static_cast<uint8_t>(std::round((rhs - Lower) * kSteps / (Upper - Lower)));
    }
    return *this;
  }

  FixedRangeFloat() : m_value(0) {}
  
  operator double() const {
    return Lower + (Upper - Lower) * static_cast<double>(m_value) / kSteps;
  }

  [[nodiscard]] constexpr double error() {
    return (Upper - Lower) / (kSteps-1) / 2;
  }
};
