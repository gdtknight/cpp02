/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 10:20:44 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/29 14:27:13 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) {}
Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}
Point::Point(const Point &other) : x(other.x), y(other.y) {}
Point &Point::operator=(const Point &other) {
  if (this != &other) {
    *this = Point(other.x, other.y);
  }
  return (*this);
}
Point::~Point() {}

Point Point::operator+(const Point &other) const {
  return (Point(this->x + other.x, this->y + other.y));
}

Point Point::operator-(const Point &other) const {
  return (Point(this->x - other.x, this->y - other.y));
}

Point Point::operator*(const Point &other) const {
  return (Point(this->x * other.x, this->y * other.y));
}

Point Point::operator/(const Point &other) const {
  return (Point(this->x / other.x, this->y / other.y));
}

const Fixed &Point::getX(void) const { return (x); }

const Fixed &Point::getY(void) const { return (y); }
