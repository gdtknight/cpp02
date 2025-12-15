/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:45:34 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/27 21:07:51 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// clang-format off

/* $> ./a.out
 *     Default constructor called
 *     Copy constructor called
 *     Copy assignment operator called // <-- This line may be missing depending on your implementation
 *     getRawBits member function called
 *     Default constructor called
 *     Copy assignment operator called
 *     getRawBits member function called
 *     getRawBits member function called
 *     0
 *     getRawBits member function called
 *     0
 *     getRawBits member function called
 *     0
 *     Destructor called
 *     Destructor called
 *     Destructor called
 *     $>
 */

//clang-format on
/* Fixed 클래스의 기본 기능 테스트 */
int main(void) {
  Fixed a;     /* 기본 생성자 호출 */
  Fixed b(a);  /* 복사 생성자 호출 */
  Fixed c;     /* 기본 생성자 호출 */

  c = b;  /* 복사 대입 연산자 호출 */
  std::cout << a.getRawBits() << std::endl;  /* a의 원시 값 출력 (0) */
  std::cout << b.getRawBits() << std::endl;  /* b의 원시 값 출력 (0) */
  std::cout << c.getRawBits() << std::endl;  /* c의 원시 값 출력 (0) */
  return 0;
}
