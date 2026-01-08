// physics/broadphase_grid.h
#ifndef PHYSICS_BROADPHASE_GRID_H
#define PHYSICS_BROADPHASE_GRID_H

#include <stddef.h>

#include "math/vec2.h"
#include "physics/body.h"

typedef struct {
    body* a;
    body* b;
} body_pair;

typedef struct {
    int *indices;
    size_t count;
    size_t capacity;
} grid_cell;

// Initializes the broadphase grid with the specified cell size and world bounds.
void grid_init(float cell_size, vec2 world_min, vec2 world_max);

// Clears all bodies from the grid.
void grid_clear();

// Inserts a body into the grid.
void grid_insert_body(body* b);

// Removes a body from the grid.
void grid_remove_body(body* b);

// Computes potential collision pairs and stores them in out_pairs.
int grid_compute(body_pair *out_pairs, int max_pairs);


#endif // PHYSICS_BROADPHASE_GRID_H