// physics/body.h
#ifndef PHYSICS_BODY_H
#define PHYSICS_BODY_H

#include "math/vec2.h"
#include "physics/shape.h"

typedef struct {
    float inv_m; // Inverse mass
    Shape shape; 
    float CoR; // Coefficient of Restitution
    float CoF; // Coefficient of Friction
    vec2 position;
    vec2 velocity;
    vec2 force;
} body;

typedef struct {
    float density;
    Shape shape;
    float CoR; // Coefficient of Restitution
    float CoF; // Coefficient of Friction
    vec2 position;
    vec2 velocity;
    vec2 force;
} BodyDef;

// Create a new body with the given definition
void body_create(body *b, const BodyDef *def);

// Setters
void  body_set_mass(body* b, float mass);
void  body_set_density(body* b, float density);

// Make the body static (infinite mass)
void  body_make_static(body* b);

// Modify the forces acting on the body
void  body_apply_force(body* b, vec2 F);
void  body_clear_forces(body* b);

void  body_apply_linear_impulse(body* b, vec2 J);

void  body_integrate_velocity(body* b, float dt);
void  body_integrate_position(body* b, float dt);

bool  body_is_static(const body* b);

#endif // PHYSICS_BODY_H