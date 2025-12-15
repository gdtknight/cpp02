/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:45:34 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/27 21:04:28 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/* 연산자 오버로딩 테스트 메인 함수 */
int main(void) {
  Fixed a;                                  /* 기본 생성자: 0 */
  Fixed const b(Fixed(5.05f) * Fixed(2));  /* 곱셈 연산자 테스트 */

  std::cout << a << std::endl;              /* 0 출력 */
  std::cout << ++a << std::endl;            /* 전위 증가: 0.00390625 */
  std::cout << a << std::endl;              /* 증가된 값 출력 */
  std::cout << a++ << std::endl;            /* 후위 증가: 이전 값 출력 */
  std::cout << a << std::endl;              /* 증가 후 값 출력 */
  std::cout << b << std::endl;              /* b 값 출력: 10.1016 */
  std::cout << Fixed::max(a, b) << std::endl;  /* a와 b 중 최대값 출력 */
  return 0;
}

/*
 *    $> ./a.out
 *    0
 *    0.00390625
 *    0.00390625
 *    0.00390625
 *    0.0078125
 *    10.1016
 *    10.1016
 *    $>
 */
