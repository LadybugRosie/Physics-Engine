// physics/body.h
#ifndef PHYSICS_BODY_H
#define PHYSICS_BODY_H

#include "math/vec2.h"
#include "physics/shape.h"

typedef struct {
    float mass;
    Shape shape; 
    float CoR; // Coefficient of Restitution
    float CoF; // Coefficient of Friction
    vec2 position;
    vec2 velocity;
} body;

#endif // PHYSICS_BODY_H