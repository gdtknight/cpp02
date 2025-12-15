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
 * 이 클래스는 부동 소수점 하드웨어 없이 소수 값을 저장하기 위한
 * 고정 소수점 숫자 표현을 구현합니다.
 *
 * 형식: 24비트 정수부 + 8비트 소수부 (총 32비트)
 * 소수 비트 = 8은 256단계(2^8)의 소수 정밀도를 의미
 *
 * 다음을 보여줍니다:
 * - 연산자 오버로딩 (산술, 비교, 증감)
 * - 정적 멤버 함수
 * - 타입 변환 (int/float ↔ 고정 소수점)
 */
class Fixed {
public:
  /* 기본 생성자 - 값을 0으로 초기화 */
  Fixed();
  
  /* 복사 생성자 - 다른 Fixed 객체로부터 복사 */
  Fixed(const Fixed &other);
  
  /* 정수 생성자 - int를 고정 소수점으로 변환 */
  Fixed(const int n);
  
  /* 부동 소수점 생성자 - float를 고정 소수점으로 변환 */
  Fixed(const float f);
  
  /* 소멸자 */
  ~Fixed();

  /* 복사 대입 연산자 */
  Fixed &operator=(const Fixed &other);

  /* 변환 없이 원시 고정 소수점 값 가져오기 */
  int getRawBits() const;
  
  /* 원시 값 직접 설정 */
  void setRawBits(int raw);

  /* 고정 소수점을 float로 변환 */
  float toFloat() const;
  
  /* 고정 소수점을 int로 변환 (정수부만) */
  int toInt() const;

  /* 비교 연산자 */
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  /* 산술 연산자 */
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  /* 증감 연산자 */
  Fixed &operator++();   /* 전위 증가 */
  Fixed operator++(int); /* 후위 증가 */
  Fixed &operator--();   /* 전위 감소 */
  Fixed operator--(int); /* 후위 감소 */

  /* 최소/최대 정적 함수 */
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

private:
  /* 고정 소수점 값의 원시 정수 표현 */
  int _value;
  
  /* 소수부에 사용되는 비트 수 (8비트 = 1/256 정밀도) */
  static const int _fractionalBits;
};

/* 스트림 삽입 연산자 - Fixed 객체 출력 허용 */
std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif // FIXED_HPP
