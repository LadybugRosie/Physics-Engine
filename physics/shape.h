#ifndef PHYSICS_SHAPE_H
#define PHYSICS_SHAPE_H

#include "math/vec2.h"
#include <stddef.h>

typedef enum {
    SHAPE_CIRCLE, // Circle shape
    SHAPE_AABB, // Axis-Aligned Bounding Box
    SHAPE_OBB, // Oriented Bounding Box 
    SHAPE_POLYGON // Convex Polygon
} ShapeType;

typedef struct {
    ShapeType type;
    union {
        struct {
            float radius;
        } circle;
        struct {
            vec2 half_size; // Half-width and half-height
        } aabb;
        struct {
            vec2 half_size; // Half-width and half-height
            float rotation; // Rotation angle in radians
        } obb;
        struct {
            vec2* vertices; // Array of vertices
            size_t vertex_count; // Number of vertices
        } polygon;
    };
} Shape;

#endif