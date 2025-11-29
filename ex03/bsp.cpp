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

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  // Vector(a->b) X Vector(a->point)
  Fixed d1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) -
             (b.getY() - a.getY()) * (point.getX() - a.getX());

  // Vector(b->c) X Vector(b->point)
  Fixed d2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) -
             (c.getY() - b.getY()) * (point.getX() - b.getX());

  // Vector(c->a) X Vector(c->point)
  Fixed d3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) -
             (a.getY() - c.getY()) * (point.getX() - c.getX());

  bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

  return !(has_neg && has_pos); // 같은 부호 = 내부 (경계 포함)
}
