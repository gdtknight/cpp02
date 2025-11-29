/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:08:07 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/27 14:08:07 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <cstdint>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &other) : _value(other._value) {}

Fixed::Fixed(const int n) { _value = n << _fractionalBits; }

Fixed::Fixed(const float f) {
  // 소수점 8자리까지 남겨놓은 후 나머지 부분은 다 버림
  _value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    _value = other._value;
  }
  return *this;
}

int Fixed::getRawBits() const { return _value; }

void Fixed::setRawBits(int raw) { _value = raw; }

// 소수점 8자리까지  표시
float Fixed::toFloat() const {
  return static_cast<float>(_value) / (1 << _fractionalBits);
}

// 소수점을 제거하는 것과 동일한 효과
int Fixed::toInt() const { return _value >> _fractionalBits; }

// comparisons
bool Fixed::operator>(const Fixed &other) const {
  return _value > other._value;
}
bool Fixed::operator<(const Fixed &other) const {
  return _value < other._value;
}
bool Fixed::operator>=(const Fixed &other) const {
  return _value >= other._value;
}
bool Fixed::operator<=(const Fixed &other) const {
  return _value <= other._value;
}
bool Fixed::operator==(const Fixed &other) const {
  return _value == other._value;
}
bool Fixed::operator!=(const Fixed &other) const {
  return _value != other._value;
}

// arithmetic
Fixed Fixed::operator+(const Fixed &other) const {
  Fixed r;
  r._value = _value + other._value;
  return r;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed r;
  r._value = _value - other._value;
  return r;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed r;
  // Use int64_t to avoid overflow
  int64_t tmp =
      static_cast<int64_t>(_value) * static_cast<int64_t>(other._value);
  tmp = tmp >> _fractionalBits;
  r._value = static_cast<int>(tmp);
  return r;
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed r;
  // avoid loss of precision: shift numerator first
  int64_t num = (static_cast<int64_t>(_value) << _fractionalBits);
  int64_t denom = other._value;
  // division by zero guard (undefined behaviour in subject — keep simple)
  if (denom == 0) {
    // define behaviour: set to max int
    r._value = (num >= 0) ? INT32_MAX : INT32_MIN;
  } else {
    int64_t tmp = num / denom;
    r._value = static_cast<int>(tmp);
  }
  return r;
}

// increment / decrement
Fixed &Fixed::operator++() {
  ++_value;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed old(*this);
  _value++;
  return old;
}

Fixed &Fixed::operator--() {
  --_value;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed old(*this);
  _value--;
  return old;
}

// min / max
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b) ? a : b;
}

// stream operator
std::ostream &operator<<(std::ostream &os, const Fixed &f) {
  os << f.toFloat();
  return os;
}
