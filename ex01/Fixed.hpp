/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:08:05 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/27 14:08:05 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed(const int n);
  Fixed(const float f);
  ~Fixed();

  Fixed &operator=(const Fixed &other);

  int getRawBits() const;
  void setRawBits(int raw);

  float toFloat() const;
  int toInt() const;

  // comparison
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  // arithmetic
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  // increment / decrement
  Fixed &operator++();   // pre-increment
  Fixed operator++(int); // post-increment
  Fixed &operator--();   // pre-decrement
  Fixed operator--(int); // post-decrement

  // min / max
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

private:
  int _value;
  static const int _fractionalBits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif // FIXED_HPP
