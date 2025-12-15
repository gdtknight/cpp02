/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:53:17 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/29 14:26:38 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
 * bsp - Binary Space Partitioning (이진 공간 분할)
 * @a: 삼각형의 첫 번째 꼭짓점
 * @b: 삼각형의 두 번째 꼭짓점
 * @c: 삼각형의 세 번째 꼭짓점
 * @point: 확인할 점
 *
 * 점이 삼각형 abc 내부에 있는지 확인합니다.
 *
 * 알고리즘: 외적(Cross Product)을 사용한 삼각형 내부 판정
 * 1. 삼각형의 각 변에 대해 외적 계산
 *    - Vector(a->b) X Vector(a->point)
 *    - Vector(b->c) X Vector(b->point)
 *    - Vector(c->a) X Vector(c->point)
 * 2. 모든 외적이 같은 부호이면 점은 내부에 있음
 * 3. 외적이 0이면 점은 경계에 있음 (이 구현에서는 내부로 간주)
 *
 * Return: 점이 삼각형 내부(경계 포함)에 있으면 true, 아니면 false
 */
bool bsp(const Point a, const Point b, const Point c, const Point point) {
  /* Vector(a->b) X Vector(a->point) */
  Fixed d1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) -
             (b.getY() - a.getY()) * (point.getX() - a.getX());

  /* Vector(b->c) X Vector(b->point) */
  Fixed d2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) -
             (c.getY() - b.getY()) * (point.getX() - b.getX());

  /* Vector(c->a) X Vector(c->point) */
  Fixed d3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) -
             (a.getY() - c.getY()) * (point.getX() - c.getX());

  /* 음수와 양수가 모두 있는지 확인 */
  bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

  /* 모두 같은 부호이면 내부 (경계 포함) */
  return !(has_neg && has_pos);
}
