#include <stdio.h>
#include <stdlib.h>
#include "math/vec2.h"

vec2_ptr vec2_create(float x, float y) {
    vec2_ptr v = (vec2_ptr)malloc(sizeof(struct vec2));
    if (v == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    v->x = x;
    v->y = y;
    return v;
}

void vec2_destroy(vec2_ptr v) {
    free(v);
}

float vec2_get_x(vec2_ptr v) {
    return v->x;
}

float vec2_get_y(vec2_ptr v) {
    return v->y;
}

void vec2_set_x(vec2_ptr v, float x) {
    v->x = x;
}

void vec2_set_y(vec2_ptr v, float y) {
    v->y = y;
}

vec2_ptr vec2_add(vec2_ptr v1, vec2_ptr v2) {
    return vec2_create(v1->x + v2->x, v1->y + v2->y);
}

vec2_ptr vec2_subtract(vec2_ptr v1, vec2_ptr v2) {
    return vec2_create(v1->x - v2->x, v1->y - v2->y);
}

vec2_ptr vec2_scale(vec2_ptr v, float scalar) {
    return vec2_create(v->x * scalar, v->y * scalar);
}

float vec2_dot(vec2_ptr v1, vec2_ptr v2) {
    return v1->x * v2->x + v1->y * v2->y;
}

float vec2_magnitude(vec2_ptr v) {
    return sqrtf(v->x * v->x + v->y * v->y);
}

vec2_ptr vec2_normalize(vec2_ptr v) {
    float mag = vec2_magnitude(v);
    if (mag == 0) {
        fprintf(stderr, "Cannot normalize a zero vector\n");
        exit(EXIT_FAILURE);
    }
    return vec2_scale(v, 1.0f / mag);
}

vec2_ptr vec2_rotate(vec2_ptr v, float angle) {
    float cos_angle = cosf(angle);
    float sin_angle = sinf(angle);
    float x_new = v->x * cos_angle - v->y * sin_angle;
    float y_new = v->x * sin_angle + v->y * cos_angle;
    return vec2_create(x_new, y_new);
}

vec2_ptr vec2_perpendicular(vec2_ptr v) {
    return vec2_create(-v->y, v->x);
}
