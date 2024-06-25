#include "triangle.h"

bool is_really_triangle(triangle_t tri) {
    if (tri.a <= 0 || tri.b <= 0 || tri.c <= 0) return (false);
    if ((tri.a + tri.b) < tri.c) return (false);
    if ((tri.b + tri.c) < tri.a) return (false);
    if ((tri.a + tri.c) < tri.b) return (false);
    return (true);
}

bool is_equilateral(triangle_t tri) {
    if (is_really_triangle(tri) == false) return (false);
    if (!(tri.a == tri.b && tri.b == tri.c)) return (false);
    return (true);
}

bool is_isosceles(triangle_t tri) {
    if (is_really_triangle(tri) == false) return (false);
    if (tri.a != tri.b && tri.a != tri.c && tri.b != tri.c) return (false);
    return (true);
}

bool is_scalene(triangle_t tri) {
    if (is_really_triangle(tri) == false) return (false);
    if (!(tri.a != tri.b && tri.a != tri.c && tri.b != tri.c)) return (false);
    return (true);
}
