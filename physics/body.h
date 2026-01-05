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
void body_create(Body *b, const BodyDef *def);

// Setters
void  body_set_type(Body* b, BodyType type);
void  body_set_mass(Body* b, float mass);
void  body_set_density(Body* b, float density);

// Make the body static (infinite mass)
void  body_make_static(Body* b);

// Modify the forces acting on the body
void  body_apply_force(Body* b, vec2 F);
void  body_clear_forces(Body* b);

void  body_apply_linear_impulse(Body* b, vec2 J);

void  body_integrate_velocity(Body* b, float dt);
void  body_integrate_position(Body* b, float dt);

bool  body_is_static(const Body* b);

#endif // PHYSICS_BODY_H