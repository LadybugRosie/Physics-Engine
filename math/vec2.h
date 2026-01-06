// math/vec2.h
#ifndef MATH_VEC2_H
#define MATH_VEC2_H

#include <math.h>

typedef struct {
    float x;
    float y;
} vec2;

// Return a new vec2 pointer with given x and y values
vec2 vec2_create(float x, float y);

// Getters and setters for x and y components
float vec2_get_x(vec2 v);

float vec2_get_y(vec2 v);

void vec2_set_x(vec2 v, float x);

void vec2_set_y(vec2 v, float y);

// Add two vec2 vectors and return a new vec2 pointer
vec2 vec2_add(vec2 v1, vec2 v2);

// Subtract two vec2 vectors and return a new vec2 pointer
vec2 vec2_subtract(vec2 v1, vec2 v2);

// Return the distance between two vec2 vectors
float vec2_distance(vec2 v1, vec2 v2);

// Scale a vec2 vector by a scalar and return a new vec2 pointer
vec2 vec2_scale(vec2 v, float scalar);

// Calculate the dot product of two vec2 vectors
float vec2_dot(vec2 v1, vec2 v2);

// Calculate the magnitude of a vec2 vector
float vec2_magnitude(vec2 v);

// Normalize a vec2 vector and return a new vec2 pointer
vec2 vec2_normalize(vec2 v);

// Rotate a vec2 vector by an angle (in radians) and return a new vec2 pointer
vec2 vec2_rotate(vec2 v, float angle);

// Return vector v rotated 90 degrees counter-clockwise
vec2 vec2_perpendicular(vec2 v);

#endif // MATH_VEC2_H