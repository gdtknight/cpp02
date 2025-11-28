/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:43:32 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/27 21:08:48 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed) {
  std::cout << "Copy constructor called" << std::endl;

  if (this != &fixed)
    this->rawBits = fixed.getRawBits();
  else
    this->rawBits = 0;
}

Fixed::Fixed(int const integer) { this->rawBits = integer << nbFractionalBits; }

Fixed::Fixed(float const floatNum) {
  this->rawBits = (int)floatNum << nbFractionalBits;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(Fixed const &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;

  if (this != &fixed)
    this->rawBits = fixed.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (rawBits);
}

void Fixed::setRawBits(int const raw) { this->rawBits = raw; }

float Fixed::toFloat(void) const { return (0.0); }

int Fixed::toInt(void) const {
  return (int)(this->rawBits >> nbFractionalBits);
}
