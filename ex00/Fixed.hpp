/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:39:02 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/27 18:59:10 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cstddef>

/*
 * • Public members:
 *   ◦ A default constructor that initializes the fixed-point number value to 0.
 *   ◦ A copy constructor.
 *   ◦ A copy assignment operator overload.
 *   ◦ A destructor.
 *   ◦ A member function int getRawBits( void ) const;
 *     that returns the raw value of the fixed-point value.
 *   ◦ A member function void setRawBits( int const raw );
 *     that sets the raw value of the fixed-point number.
 *
 * • Private members:
 *   ◦ An integer to store the fixed-point number value.
 *   ◦ A static constant integer to store the number of fractional bits.
 *     Its value will always be the integer literal 8.
 *
 */

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed &fixed);
  ~Fixed(void);

  Fixed &operator=(Fixed &fixed);

  int getRawBits(void) const;
  void setRawBits(int const raw);

protected:
private:
  static const int nbFractionalBits;
  int rawBits;
};

#endif
