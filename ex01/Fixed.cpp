/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:08:07 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/30 19:06:04 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* int64_t를 위한 stdint 타입 포함 (cstdlib/climits를 통한 C++98 호환) */
#ifdef __cplusplus
#include <climits>
#endif

/* 정적 멤버 초기화 - 클래스 외부에서 정의해야 함 */
const int Fixed::_fractionalBits = 8;

/*
 * Fixed::Fixed - 기본 생성자
 *
 * 고정 소수점 값을 0으로 초기화합니다.
 * 멤버 초기화 리스트 사용 (C++98 스타일).
 */
Fixed::Fixed() : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

/*
 * Fixed::Fixed - 복사 생성자
 * @other: 복사할 Fixed 객체
 *
 * 다른 객체로부터 원시 값을 복사하여 새 Fixed 객체를 생성합니다.
 * 효율성을 위해 멤버 초기화 리스트를 사용합니다.
 */
Fixed::Fixed(const Fixed &other) : _value(other._value) {
  std::cout << "Copy constructor called" << std::endl;
}

/*
 * Fixed::Fixed - 정수 생성자
 * @n: 고정 소수점으로 변환할 정수 값
 *
 * 왼쪽 시프트를 통해 정수를 고정 소수점 형식으로 변환합니다.
 * _fractionalBits(8)만큼 왼쪽 시프트는 256을 곱하는 것과 같으며,
 * 소수부에 8비트를 할당합니다.
 */
Fixed::Fixed(const int n) { _value = n << _fractionalBits; }

/*
 * Fixed::Fixed - Float 생성자
 * @f: 고정 소수점으로 변환할 부동 소수점 값
 *
 * float를 고정 소수점 형식으로 변환합니다:
 * 1. float에 2^8 (256)을 곱하여 8비트의 소수 정밀도 보존
 * 2. roundf를 사용하여 가장 가까운 정수로 반올림
 * 3. 저장을 위해 int로 캐스팅
 *
 * 이를 통해 정수 형식으로 소수 값을 저장할 수 있습니다.
 */
Fixed::Fixed(const float f) {
  _value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

/*
 * Fixed::~Fixed - 소멸자
 *
 * 기본 소멸자, 원시 타입을 사용하므로 특별한 정리가 필요 없습니다.
 */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/*
 * Fixed::operator= - 복사 대입 연산자
 * @other: 할당할 Fixed 객체
 *
 * 다른 Fixed 객체의 값을 이 객체에 할당합니다.
 * 안전을 위한 자기 자신 할당 검사를 포함합니다.
 *
 * Return: 연쇄 할당을 위한 이 객체의 참조
 */
Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    _value = other._value;
  }
  return *this;
}

/*
 * Fixed::getRawBits - 원시 고정 소수점 값 가져오기
 *
 * 변환 없이 내부 정수 표현을 반환합니다.
 *
 * Return: 원시 고정 소수점 값
 */
int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return _value;
}

/*
 * Fixed::setRawBits - 원시 고정 소수점 값 설정
 * @raw: 설정할 원시 값
 *
 * 내부 정수 표현을 직접 설정합니다.
 */
void Fixed::setRawBits(int raw) { _value = raw; }

/*
 * Fixed::toFloat - 고정 소수점을 부동 소수점으로 변환
 *
 * 다음과 같이 고정 소수점 값을 float로 다시 변환합니다:
 * 1. 정수 값을 float로 캐스팅
 * 2. 2^8 (256)으로 나누어 소수점을 다시 이동
 *
 * Return: 부동 소수점 표현
 */
float Fixed::toFloat() const {
  return static_cast<float>(_value) / (1 << _fractionalBits);
}

/*
 * Fixed::toInt - 고정 소수점을 정수로 변환
 *
 * 오른쪽 시프트를 통해 정수부를 추출하며, 이는
 * 256으로 나누고 소수 비트를 버리는 것과 같습니다.
 *
 * Return: 고정 소수점 값의 정수부
 */
int Fixed::toInt() const { return _value >> _fractionalBits; }

/*
 * 비교 연산자
 * 이 연산자들은 원시 고정 소수점 값을 직접 비교합니다.
 * 두 피연산자가 같은 스케일(8 소수 비트)을 사용하므로,
 * 변환 없이 원시 정수를 비교할 수 있습니다.
 */

/* 크다 비교 */
bool Fixed::operator>(const Fixed &other) const {
  return _value > other._value;
}

/* 작다 비교 */
bool Fixed::operator<(const Fixed &other) const {
  return _value < other._value;
}

/* 크거나 같다 비교 */
bool Fixed::operator>=(const Fixed &other) const {
  return _value >= other._value;
}

/* 작거나 같다 비교 */
bool Fixed::operator<=(const Fixed &other) const {
  return _value <= other._value;
}

/* 같다 비교 */
bool Fixed::operator==(const Fixed &other) const {
  return _value == other._value;
}

/* 같지 않다 비교 */
bool Fixed::operator!=(const Fixed &other) const {
  return _value != other._value;
}

/*
 * 산술 연산자
 * 이 연산자들은 고정 소수점 숫자에 대한 산술 연산을 수행합니다.
 */

/*
 * Fixed::operator+ - 덧셈 연산자
 * @other: 더할 Fixed 값
 *
 * 원시 값을 더하여 두 고정 소수점 숫자를 더합니다.
 * 둘 다 같은 스케일을 사용하므로 직접 덧셈이 올바르게 작동합니다.
 *
 * Return: 합을 포함하는 새 Fixed 객체
 */
Fixed Fixed::operator+(const Fixed &other) const {
  Fixed r;
  r._value = _value + other._value;
  return r;
}

/*
 * Fixed::operator- - 뺄셈 연산자
 * @other: 뺄 Fixed 값
 *
 * 원시 값을 빼서 두 고정 소수점 숫자를 뺍니다.
 *
 * Return: 차를 포함하는 새 Fixed 객체
 */
Fixed Fixed::operator-(const Fixed &other) const {
  Fixed r;
  r._value = _value - other._value;
  return r;
}

/*
 * Fixed::operator* - 곱셈 연산자
 * @other: 곱할 Fixed 값
 *
 * 두 고정 소수점 숫자를 곱합니다:
 * 1. 오버플로를 방지하기 위해 두 값을 long long으로 캐스팅
 * 2. 값을 곱함 (소수 비트가 두 배가 됨)
 * 3. _fractionalBits만큼 오른쪽 시프트하여 올바른 스케일 복원
 *
 * 예: (a * 256) * (b * 256) = (a * b) * 65536
 *     그런 다음 8만큼 오른쪽 시프트: (a * b) * 256 (올바른 스케일)
 *
 * Return: 곱을 포함하는 새 Fixed 객체
 */
Fixed Fixed::operator*(const Fixed &other) const {
  Fixed r;
  /* 곱셈 중 오버플로를 피하기 위해 long long 사용 */
  long long tmp =
      static_cast<long long>(_value) * static_cast<long long>(other._value);
  /* 추가 소수 비트를 제거하기 위해 오른쪽 시프트 */
  tmp = tmp >> _fractionalBits;
  r._value = static_cast<int>(tmp);
  return r;
}

/*
 * Fixed::operator/ - 나눗셈 연산자
 * @other: 나눌 Fixed 값
 *
 * 두 고정 소수점 숫자를 나눕니다:
 * 1. 정밀도를 유지하기 위해 분자를 _fractionalBits만큼 왼쪽 시프트
 * 2. 분모로 나눔
 * 3. 0으로 나누기를 최대/최소 int를 반환하여 처리
 *
 * Return: 몫을 포함하는 새 Fixed 객체
 */
Fixed Fixed::operator/(const Fixed &other) const {
  Fixed r;
  /* Shift numerator left to preserve precision */
  long long num = (static_cast<long long>(_value) << _fractionalBits);
  long long denom = other._value;

  /* Guard against division by zero */
  if (denom == 0) {
    /* Return maximum or minimum value based on sign */
    r._value = (num >= 0) ? INT_MAX : INT_MIN;
  } else {
    long long tmp = num / denom;
    r._value = static_cast<int>(tmp);
  }
  return r;
}

/*
 * 증감 연산자
 * 이 연산자들은 원시 값을 1만큼 수정하며, 이는
 * 가장 작은 표현 가능한 소수 증가분(1/256)을 나타냅니다.
 */

/*
 * Fixed::operator++ - 전위 증가 연산자
 *
 * 반환 전에 값을 증가시킵니다.
 * 1 원시 단위만큼 증가 = 실제 값에서 1/256.
 *
 * Return: 증가 후 이 객체의 참조
 */
Fixed &Fixed::operator++() {
  ++_value;
  return *this;
}

/*
 * Fixed::operator++ - 후위 증가 연산자
 * @: 전위 증가와 구분하기 위한 미사용 int 매개변수
 *
 * 값을 증가시키지만 이전 값을 반환합니다.
 * 후위 증가 연산자를 위한 C++98 패턴.
 *
 * Return: 증가 전 객체의 복사본
 */
Fixed Fixed::operator++(int) {
  Fixed old(*this);
  _value++;
  return old;
}

/*
 * Fixed::operator-- - 전위 감소 연산자
 *
 * 반환 전에 값을 감소시킵니다.
 *
 * Return: 감소 후 이 객체의 참조
 */
Fixed &Fixed::operator--() {
  --_value;
  return *this;
}

/*
 * Fixed::operator-- - 후위 감소 연산자
 * @: 전위 감소와 구분하기 위한 미사용 int 매개변수
 *
 * 값을 감소시키지만 이전 값을 반환합니다.
 *
 * Return: 감소 전 객체의 복사본
 */
Fixed Fixed::operator--(int) {
  Fixed old(*this);
  _value--;
  return old;
}

/*
 * Min/Max 정적 함수
 * 이들은 두 Fixed 객체의 최소값과 최대값을 찾는
 * 유틸리티 함수를 제공합니다. const와 비-const 모두에 대해 오버로드됩니다.
 */

/*
 * Fixed::min - 두 Fixed 값 중 더 작은 것 반환 (비-const 버전)
 * @a: 첫 번째 Fixed 값
 * @b: 두 번째 Fixed 값
 *
 * Return: 더 작은 값의 참조
 */
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

/*
 * Fixed::min - 두 Fixed 값 중 더 작은 것 반환 (const 버전)
 * @a: 첫 번째 Fixed 값 (const)
 * @b: 두 번째 Fixed 값 (const)
 *
 * Return: 더 작은 값의 const 참조
 */
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b) ? a : b;
}

/*
 * Fixed::max - 두 Fixed 값 중 더 큰 것 반환 (비-const 버전)
 * @a: 첫 번째 Fixed 값
 * @b: 두 번째 Fixed 값
 *
 * Return: 더 큰 값의 참조
 */
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

/*
 * Fixed::max - 두 Fixed 값 중 더 큰 것 반환 (const 버전)
 * @a: 첫 번째 Fixed 값 (const)
 * @b: 두 번째 Fixed 값 (const)
 *
 * Return: 더 큰 값의 const 참조
 */
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b) ? a : b;
}

/*
 * operator<< - 스트림 삽입 연산자
 * @os: 쓸 출력 스트림
 * @f: 출력할 Fixed 객체
 *
 * Fixed 객체를 출력 스트림에 출력할 수 있게 합니다.
 * 사람이 읽을 수 있는 출력을 위해 고정 소수점 값을 float로 변환합니다.
 *
 * Return: 연쇄 작업을 위한 출력 스트림의 참조
 */
std::ostream &operator<<(std::ostream &os, const Fixed &f) {
  os << f.toFloat();
  return os;
}
