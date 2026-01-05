#include <stdio.h>
#include <stdlib.h>

#ifndef MATH_VEC2_H
#define MATH_VEC2_H

typedef struct vec2 {
    float x;
    float y;
} *vec2_ptr;

// Return a new vec2 pointer with given x and y values
vec2_ptr vec2_create(float x, float y);

// Free the memory allocated for the vec2 pointer
void vec2_destroy(vec2_ptr v);

// Getters and setters for x and y components
float vec2_get_x(vec2_ptr v);

float vec2_get_y(vec2_ptr v);

void vec2_set_x(vec2_ptr v, float x);

void vec2_set_y(vec2_ptr v, float y);

// Add two vec2 vectors and return a new vec2 pointer
vec2_ptr vec2_add(vec2_ptr v1, vec2_ptr v2);

// Subtract two vec2 vectors and return a new vec2 pointer
vec2_ptr vec2_subtract(vec2_ptr v1, vec2_ptr v2);

// Scale a vec2 vector by a scalar and return a new vec2 pointer
vec2_ptr vec2_scale(vec2_ptr v, float scalar);

// Calculate the dot product of two vec2 vectors
float vec2_dot(vec2_ptr v1, vec2_ptr v2);

// Calculate the magnitude of a vec2 vector
float vec2_magnitude(vec2_ptr v);

// Normalize a vec2 vector and return a new vec2 pointer
vec2_ptr vec2_normalize(vec2_ptr v);

#endif // MATH_VEC2_H