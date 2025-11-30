/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:08:07 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/30 19:16:12 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* Include stdint types for int64_t (C++98 compatible via cstdlib/climits) */
#ifdef __cplusplus
#include <climits>
#endif

/* Initialize static member - must be defined outside the class */
const int Fixed::_fractionalBits = 8;

/*
 * Fixed::Fixed - Default constructor
 *
 * Initializes the fixed-point value to 0.
 * Uses member initializer list (C++98 style).
 */
Fixed::Fixed() : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

/*
 * Fixed::Fixed - Copy constructor
 * @other: The Fixed object to copy from
 *
 * Creates a new Fixed object by copying the raw value from another.
 * Uses member initializer list for efficiency.
 */
Fixed::Fixed(const Fixed &other) : _value(other._value) {
  std::cout << "Copy constructor called" << std::endl;
}

/*
 * Fixed::Fixed - Integer constructor
 * @n: The integer value to convert to fixed-point
 *
 * Converts an integer to fixed-point format by left-shifting.
 * Left shift by _fractionalBits (8) effectively multiplies by 256,
 * allocating 8 bits for the fractional part.
 */
Fixed::Fixed(const int n) {
  std::cout << "Int constructor called" << std::endl;

  _value = n << _fractionalBits;
}

/*
 * Fixed::Fixed - Float constructor
 * @f: The floating-point value to convert to fixed-point
 *
 * Converts a float to fixed-point format:
 * 1. Multiply float by 2^8 (256) to preserve 8 bits of fractional precision
 * 2. Round to nearest integer using roundf
 * 3. Cast to int for storage
 *
 * This allows storing decimal values in integer format.
 */
Fixed::Fixed(const float f) {
  std::cout << "Float constructor called" << std::endl;
  _value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

/*
 * Fixed::~Fixed - Destructor
 *
 * Default destructor, no special cleanup needed as we use primitive types.
 */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/*
 * Fixed::operator= - Copy assignment operator
 * @other: The Fixed object to assign from
 *
 * Assigns the value from another Fixed object to this one.
 * Includes self-assignment check for safety.
 *
 * Return: Reference to this object for chained assignments
 */
Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    _value = other._value;
  }
  return *this;
}

/*
 * Fixed::getRawBits - Gets the raw fixed-point value
 *
 * Returns the internal integer representation without conversion.
 *
 * Return: The raw fixed-point value
 */
int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return _value;
}

/*
 * Fixed::setRawBits - Sets the raw fixed-point value
 * @raw: The raw value to set
 *
 * Directly sets the internal integer representation.
 */
void Fixed::setRawBits(int raw) { _value = raw; }

/*
 * Fixed::toFloat - Converts fixed-point to floating-point
 *
 * Converts the fixed-point value back to float by:
 * 1. Casting the integer value to float
 * 2. Dividing by 2^8 (256) to shift the decimal point back
 *
 * Return: The floating-point representation
 */
float Fixed::toFloat() const {
  return static_cast<float>(_value) / (1 << _fractionalBits);
}

/*
 * Fixed::toInt - Converts fixed-point to integer
 *
 * Extracts the integer part by right-shifting, effectively
 * dividing by 256 and discarding the fractional bits.
 *
 * Return: The integer part of the fixed-point value
 */
int Fixed::toInt() const { return _value >> _fractionalBits; }

/*
 * Comparison operators
 * These operators compare the raw fixed-point values directly.
 * Since both operands use the same scale (8 fractional bits),
 * we can compare the raw integers without conversion.
 */

/* Greater than comparison */
bool Fixed::operator>(const Fixed &other) const {
  return _value > other._value;
}

/* Less than comparison */
bool Fixed::operator<(const Fixed &other) const {
  return _value < other._value;
}

/* Greater than or equal comparison */
bool Fixed::operator>=(const Fixed &other) const {
  return _value >= other._value;
}

/* Less than or equal comparison */
bool Fixed::operator<=(const Fixed &other) const {
  return _value <= other._value;
}

/* Equality comparison */
bool Fixed::operator==(const Fixed &other) const {
  return _value == other._value;
}

/* Inequality comparison */
bool Fixed::operator!=(const Fixed &other) const {
  return _value != other._value;
}

/*
 * Arithmetic operators
 * These operators perform arithmetic on fixed-point numbers.
 */

/*
 * Fixed::operator+ - Addition operator
 * @other: The Fixed value to add
 *
 * Adds two fixed-point numbers by adding their raw values.
 * Since both use the same scale, direct addition works correctly.
 *
 * Return: New Fixed object containing the sum
 */
Fixed Fixed::operator+(const Fixed &other) const {
  Fixed r;
  r._value = _value + other._value;
  return r;
}

/*
 * Fixed::operator- - Subtraction operator
 * @other: The Fixed value to subtract
 *
 * Subtracts two fixed-point numbers by subtracting their raw values.
 *
 * Return: New Fixed object containing the difference
 */
Fixed Fixed::operator-(const Fixed &other) const {
  Fixed r;
  r._value = _value - other._value;
  return r;
}

/*
 * Fixed::operator* - Multiplication operator
 * @other: The Fixed value to multiply by
 *
 * Multiplies two fixed-point numbers:
 * 1. Cast both values to long long to prevent overflow
 * 2. Multiply the values (doubles the fractional bits)
 * 3. Right shift by _fractionalBits to restore correct scale
 *
 * Example: (a * 256) * (b * 256) = (a * b) * 65536
 *          Then shift right by 8: (a * b) * 256 (correct scale)
 *
 * Return: New Fixed object containing the product
 */
Fixed Fixed::operator*(const Fixed &other) const {
  Fixed r;
  /* Use long long to avoid overflow during multiplication */
  long long tmp =
      static_cast<long long>(_value) * static_cast<long long>(other._value);
  /* Right shift to remove extra fractional bits */
  tmp = tmp >> _fractionalBits;
  r._value = static_cast<int>(tmp);
  return r;
}

/*
 * Fixed::operator/ - Division operator
 * @other: The Fixed value to divide by
 *
 * Divides two fixed-point numbers:
 * 1. Left shift numerator by _fractionalBits to maintain precision
 * 2. Divide by denominator
 * 3. Handle division by zero by returning max/min int
 *
 * Return: New Fixed object containing the quotient
 */
Fixed Fixed::operator/(const Fixed &other) const {
  Fixed r;
  /* Shift numerator left to preserve precision */
  long long num = (static_cast<long long>(_value) << _fractionalBits);
  long long denom = other._value;

  /* Guard against division by zero */
  if (denom == 0) {
    /* Return maximum or minimum value based on sign */
    r._value = (num >= 0) ? INT_MAX : INT_MIN;
  } else {
    long long tmp = num / denom;
    r._value = static_cast<int>(tmp);
  }
  return r;
}

/*
 * Increment and Decrement operators
 * These operators modify the raw value by 1, which represents
 * the smallest representable fractional increment (1/256).
 */

/*
 * Fixed::operator++ - Pre-increment operator
 *
 * Increments the value before returning.
 * Increments by 1 raw unit = 1/256 in actual value.
 *
 * Return: Reference to this object after incrementing
 */
Fixed &Fixed::operator++() {
  ++_value;
  return *this;
}

/*
 * Fixed::operator++ - Post-increment operator
 * @: Unused int parameter to distinguish from pre-increment
 *
 * Increments the value but returns the old value.
 * C++98 pattern for post-increment operator.
 *
 * Return: Copy of the object before incrementing
 */
Fixed Fixed::operator++(int) {
  Fixed old(*this);
  _value++;
  return old;
}

/*
 * Fixed::operator-- - Pre-decrement operator
 *
 * Decrements the value before returning.
 *
 * Return: Reference to this object after decrementing
 */
Fixed &Fixed::operator--() {
  --_value;
  return *this;
}

/*
 * Fixed::operator-- - Post-decrement operator
 * @: Unused int parameter to distinguish from pre-decrement
 *
 * Decrements the value but returns the old value.
 *
 * Return: Copy of the object before decrementing
 */
Fixed Fixed::operator--(int) {
  Fixed old(*this);
  _value--;
  return old;
}

/*
 * Min/Max static functions
 * These provide utility functions to find minimum and maximum
 * of two Fixed objects. Overloaded for both const and non-const.
 */

/*
 * Fixed::min - Returns the smaller of two Fixed values (non-const version)
 * @a: First Fixed value
 * @b: Second Fixed value
 *
 * Return: Reference to the smaller value
 */
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

/*
 * Fixed::min - Returns the smaller of two Fixed values (const version)
 * @a: First Fixed value (const)
 * @b: Second Fixed value (const)
 *
 * Return: Const reference to the smaller value
 */
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b) ? a : b;
}

/*
 * Fixed::max - Returns the larger of two Fixed values (non-const version)
 * @a: First Fixed value
 * @b: Second Fixed value
 *
 * Return: Reference to the larger value
 */
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

/*
 * Fixed::max - Returns the larger of two Fixed values (const version)
 * @a: First Fixed value (const)
 * @b: Second Fixed value (const)
 *
 * Return: Const reference to the larger value
 */
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b) ? a : b;
}

/*
 * operator<< - Stream insertion operator
 * @os: Output stream to write to
 * @f: Fixed object to output
 *
 * Allows printing Fixed objects to output streams.
 * Converts the fixed-point value to float for human-readable output.
 *
 * Return: Reference to the output stream for chained operations
 */
std::ostream &operator<<(std::ostream &os, const Fixed &f) {
  os << f.toFloat();
  return os;
}
