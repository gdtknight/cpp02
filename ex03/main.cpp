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

/* 테스트 결과 출력 함수 */
void print_result(bool result) {
  if (result) {
    std::cout << "Inside" << std::endl;   /* 삼각형 내부 */
  } else {
    std::cout << "Outside" << std::endl;  /* 삼각형 외부 */
  }
}

/* BSP 알고리즘 테스트 */
int main(void) {
  /* 삼각형의 세 꼭짓점 정의 */
  Point a  = Point(Fixed(1), Fixed(1));
  Point b  = Point(Fixed(1), Fixed(4));
  Point c  = Point(Fixed(4), Fixed(1));

  /* 테스트할 점들 */
  Point p1 = Point(Fixed(2), Fixed(2));  /* 삼각형 내부 */
  Point p2 = Point(Fixed(3), Fixed(3));  /* 삼각형 외부 */

  /* 결과 출력 */
  print_result(bsp(a, b, c, p1));
  print_result(bsp(a, b, c, p2));

  return (EXIT_SUCCESS);
}
