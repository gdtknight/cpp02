/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 10:20:37 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/29 14:25:42 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
  Point(void);
  Point(const Fixed &x, const Fixed &y);
  Point(const Point &other);
  Point &operator=(const Point &other);
  ~Point(void);

  Point operator+(const Point &other) const;
  Point operator-(const Point &other) const;
  Point operator*(const Point &other) const;
  Point operator/(const Point &other) const;

  const Fixed &getX(void) const;
  const Fixed &getY(void) const;

protected:
private:
  const Fixed x;
  const Fixed y;
};

#endif
