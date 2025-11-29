/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:45:34 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/29 17:39:01 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <cstdlib>
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

void print_result(bool result) {
  if (result) {
    std::cout << "Inside" << std::endl;
  } else {
    std::cout << "Outside" << std::endl;
  }
}

int main(void) {
  Point a = Point(Fixed(1), Fixed(1));
  Point b = Point(Fixed(1), Fixed(4));
  Point c = Point(Fixed(4), Fixed(1));

  Point p1 = Point(Fixed(2), Fixed(2));
  Point p2 = Point(Fixed(3), Fixed(3));

  print_result(bsp(a, b, c, p1));
  print_result(bsp(a, b, c, p2));

  return (EXIT_SUCCESS);
}
