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

/*
 * Point - 2D 좌표 점을 나타내는 클래스
 *
 * Fixed 고정 소수점 숫자를 사용하여 2D 공간의 점을 나타냅니다.
 * x와 y 좌표는 const이므로 생성 후 변경할 수 없습니다 (불변).
 *
 * 다음에 사용됩니다:
 * - 점이 삼각형 내부에 있는지 확인하는 BSP 알고리즘
 * - 기하학적 계산
 */
class Point {
  public:
  /* 생성자 */
  Point(void);  /* 기본 생성자 - (0, 0)으로 초기화 */
  Point(const Fixed &x, const Fixed &y);  /* 좌표 생성자 */
  Point(const Point &other);  /* 복사 생성자 */
  
  /* 대입 연산자 - const 멤버로 인해 제한적 */
  Point &operator=(const Point &other);
  
  /* 소멸자 */
  ~Point(void);

  /* 산술 연산자 - 점 간 연산 */
  Point        operator+(const Point &other) const;  /* 벡터 덧셈 */
  Point        operator-(const Point &other) const;  /* 벡터 뺄셈 */
  Point        operator*(const Point &other) const;  /* 요소별 곱셈 */
  Point        operator/(const Point &other) const;  /* 요소별 나눗셈 */

  /* Getter 메서드 - const 좌표 접근 */
  const Fixed &getX(void) const;
  const Fixed &getY(void) const;

  protected:
  private:
  /* const 멤버 - 생성 후 변경 불가 (불변 점) */
  const Fixed x;  /* X 좌표 */
  const Fixed y;  /* Y 좌표 */
};

#endif
