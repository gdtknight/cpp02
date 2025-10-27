/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:43:32 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/27 13:45:59 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// 선언 (declaration)
const int Fixed::nbFractionalBits = 8;

Fixed::Fixed(void) : rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;

  if (this != &fixed)
    this->rawBits = fixed.getRawBits();
  else
    this->rawBits = 0;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(Fixed &fixed) {
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
