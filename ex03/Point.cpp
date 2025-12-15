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

/*
 * Point::Point - 기본 생성자
 *
 * 원점 (0, 0)에 점을 생성합니다.
 */
Point::Point(void) {}

/*
 * Point::Point - 좌표 생성자
 * @x: X 좌표 (Fixed)
 * @y: Y 좌표 (Fixed)
 *
 * 지정된 x, y 좌표로 점을 생성합니다.
 */
Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

/*
 * Point::Point - 복사 생성자
 * @other: 복사할 Point 객체
 *
 * 다른 점의 좌표를 복사하여 새 점을 생성합니다.
 */
Point::Point(const Point &other) : x(other.x), y(other.y) {}

/*
 * Point::operator= - 대입 연산자
 * @other: 할당할 Point 객체
 *
 * 주의: x와 y가 const이므로 실제로는 새 Point를 생성합니다.
 * const 멤버는 생성 후 변경할 수 없습니다.
 *
 * Return: 이 객체의 참조
 */
Point &Point::operator=(const Point &other) {
  if (this != &other) {
    *this = Point(other.x, other.y);
  }
  return (*this);
}

/*
 * Point::~Point - 소멸자
 *
 * Point 객체를 파괴합니다.
 */
Point::~Point() {}

/*
 * Point::operator+ - 덧셈 연산자 (벡터 덧셈)
 * @other: 더할 점
 *
 * 두 점을 벡터처럼 더합니다.
 *
 * Return: 결과 점 (x1+x2, y1+y2)
 */
Point Point::operator+(const Point &other) const {
  return (Point(this->x + other.x, this->y + other.y));
}

/*
 * Point::operator- - 뺄셈 연산자 (벡터 뺄셈)
 * @other: 뺄 점
 *
 * 두 점을 벡터처럼 뺍니다.
 *
 * Return: 결과 점 (x1-x2, y1-y2)
 */
Point Point::operator-(const Point &other) const {
  return (Point(this->x - other.x, this->y - other.y));
}

/*
 * Point::operator* - 곱셈 연산자 (요소별 곱셈)
 * @other: 곱할 점
 *
 * 각 좌표를 요소별로 곱합니다.
 *
 * Return: 결과 점 (x1*x2, y1*y2)
 */
Point Point::operator*(const Point &other) const {
  return (Point(this->x * other.x, this->y * other.y));
}

/*
 * Point::operator/ - 나눗셈 연산자 (요소별 나눗셈)
 * @other: 나눌 점
 *
 * 각 좌표를 요소별로 나눕니다.
 *
 * Return: 결과 점 (x1/x2, y1/y2)
 */
Point Point::operator/(const Point &other) const {
  return (Point(this->x / other.x, this->y / other.y));
}

/*
 * Point::getX - X 좌표 가져오기
 *
 * Return: X 좌표의 const 참조
 */
const Fixed &Point::getX(void) const { return (x); }

/*
 * Point::getY - Y 좌표 가져오기
 *
 * Return: Y 좌표의 const 참조
 */
const Fixed &Point::getY(void) const { return (y); }
