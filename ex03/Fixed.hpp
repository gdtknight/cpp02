/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:08:05 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/27 14:08:05 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/*
 * Fixed - 고정 소수점 숫자를 나타내는 클래스
 *
 * 연산자 오버로딩을 통한 완전한 고정 소수점 산술 구현
 * 형식: 24비트 정수부 + 8비트 소수부 (총 32비트)
 */
class Fixed {
  public:
  /* 생성자 및 소멸자 */
  Fixed();
  Fixed(const Fixed &other);
  Fixed(const int n);
  Fixed(const float f);
  ~Fixed();

  /* 대입 연산자 */
  Fixed              &operator=(const Fixed &other);

  /* 원시 값 접근 */
  int                 getRawBits() const;
  void                setRawBits(int raw);

  /* 타입 변환 */
  float               toFloat() const;
  int                 toInt() const;

  /* 비교 연산자 */
  bool                operator>(const Fixed &other) const;
  bool                operator<(const Fixed &other) const;
  bool                operator>=(const Fixed &other) const;
  bool                operator<=(const Fixed &other) const;
  bool                operator==(const Fixed &other) const;
  bool                operator!=(const Fixed &other) const;

  /* 산술 연산자 */
  Fixed               operator+(const Fixed &other) const;
  Fixed               operator-(const Fixed &other) const;
  Fixed               operator*(const Fixed &other) const;
  Fixed               operator/(const Fixed &other) const;

  /* 증감 연산자 */
  Fixed              &operator++();    /* 전위 증가 */
  Fixed               operator++(int); /* 후위 증가 */
  Fixed              &operator--();    /* 전위 감소 */
  Fixed               operator--(int); /* 후위 감소 */

  /* 최소/최대 정적 함수 */
  static Fixed       &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed       &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

  private:
  int              _value;              /* 고정 소수점 값의 원시 정수 표현 */
  static const int _fractionalBits;     /* 소수부에 사용되는 비트 수 */
};

/* 스트림 삽입 연산자 */
std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif // FIXED_HPP
