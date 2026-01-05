// math/vec2.c
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "math/vec2.h"

vec2 vec2_create(float x, float y) {
    vec2 v = {x, y};
    return v;
}

float vec2_get_x(vec2 v) {
    return v.x;
}

float vec2_get_y(vec2 v) {
    return v.y;
}

void vec2_set_x(vec2 v, float x) {
    v.x = x;
}

void vec2_set_y(vec2 v, float y) {
    v.y = y;
}

vec2 vec2_add(vec2 v1, vec2 v2) {
    return vec2_create(v1.x + v2.x, v1.y + v2.y);
}

vec2 vec2_subtract(vec2 v1, vec2 v2) {
    return vec2_create(v1.x - v2.x, v1.y - v2.y);
}

float vec2_distance(vec2 v1, vec2 v2) {
    return(vec2_magnitude(vec2_subtract(v1, v2)));
}

vec2 vec2_scale(vec2 v, float scalar) {
    return vec2_create(v.x * scalar, v.y * scalar);
}

float vec2_dot(vec2 v1, vec2 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

float vec2_magnitude(vec2 v) {
    return sqrtf(vec2_dot(v, v));
}

vec2 vec2_normalize(vec2 v) {
    float mag = vec2_magnitude(v);
    if (mag == 0) {
        fprintf(stderr, "Cannot normalize a zero vector\n");
        exit(EXIT_FAILURE);
    }
    return vec2_scale(v, 1.0f / mag);
}

vec2 vec2_rotate(vec2 v, float angle) {
    float cos_angle = cosf(angle);
    float sin_angle = sinf(angle);
    float x_new = v.x * cos_angle - v.y * sin_angle;
    float y_new = v.x * sin_angle + v.y * cos_angle;
    return vec2_create(x_new, y_new);
}

vec2 vec2_perpendicular(vec2 v) {
    return vec2_create(-v.y, v.x);
}
