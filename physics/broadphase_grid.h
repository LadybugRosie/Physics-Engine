// physics/broadphase_grid.h
#ifndef PHYSICS_BROADPHASE_GRID_H
#define PHYSICS_BROADPHASE_GRID_H

#include "math/vec2.h"
#include "physics/body.h"

void grid_init(float cell_size, vec2 world_min, vec2 world_max);
void grid_clear();

void grid_insert_body(body* b);
void grid_remove_body(body* b);

int grid_compute


#endif // PHYSICS_BROADPHASE_GRID_H