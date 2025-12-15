/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:45:34 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/30 19:08:50 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/*
 *    $> ./a.out
 *    Default constructor called
 *    Int constructor called
 *    Float constructor called
 *    Copy constructor called
 *    Copy assignment operator called
 *    Float constructor called
 *    Copy assignment operator called
 *    Destructor called
 *    a is 1234.43
 *    b is 10
 *    c is 42.4219
 *    d is 10
 *    a is 1234 as integer
 *    b is 10 as integer
 *    c is 42 as integer
 *    d is 10 as integer
 *    Destructor called
 *    Destructor called
 *    Destructor called
 *    Destructor called
 *    $>
 */

#include <iostream>

/* Fixed 클래스의 타입 변환 기능 테스트 */
int main(void) {
  Fixed a;                      /* 기본 생성자 */
  Fixed const b(10);            /* 정수 생성자 */
  Fixed const c(42.42f);        /* 부동 소수점 생성자 */
  Fixed const d(b);             /* 복사 생성자 */

  a = Fixed(1234.4321f);        /* 복사 대입 연산자 */

  /* float 형태로 출력 */
  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  /* 정수로 변환하여 출력 */
  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;

  return 0;
}
