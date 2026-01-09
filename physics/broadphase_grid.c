#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "physics/body.h"
#include "math/vec2.h"
#include "physics/broadphase_grid.h"

static bool initialized = false;

static float cell_size;
static int cell_count;
static int num_cells_x;
static int num_cells_y;

static grid_cell* cells = NULL;

static vec2 world_min;
static vec2 world_max;

static body **bodies = NULL;
static int body_count = 0;
static int body_capacity = 0;


// Cells are organized in a 2D grid and indexed left to right, bottom to top.
void grid_init(float cell_size, vec2 world_min, vec2 world_max) {
    initialized = true;
    grid_clear();
    cell_size = cell_size;
    world_min = world_min;
    world_max = world_max;

    // Calculate grid dimensions and build cells
    int grid_width = (int)ceilf((world_max.x - world_min.x) / cell_size);
    int grid_height = (int)ceilf((world_max.y - world_min.y) / cell_size); // These cells shouldn't be problematic?
    cells = malloc(sizeof(grid_cell) * grid_width * grid_height);
    if (cells == NULL) {
        initialized = false;
        fprintf(stderr, "Failed to allocate memory for broadphase grid cells.\n");
        return;
    }
    num_cells_x = grid_width;
    num_cells_y = grid_height;
    cell_count = grid_width * grid_height;

    // Build an array of grid cells
    cells = malloc(cell_count * sizeof(grid_cell));

    if (cells == NULL) {
        initialized = false;
        free(cells);
        fprintf(stderr, "Failed to allocate memory for broadphase grid cell buckets");
    }
}

inline void grid_clear() {
    if (bodies != NULL) {
        free(bodies);
        bodies = NULL;
    }
    if (cells != NULL) {
        free(cells);
        cells = NULL;
    }
    body_count = 0;
    body_capacity = 0;
}

void grid_insert_body(body* b) {
    // Ensure capacity
    if (body_count >= body_capacity) {
        body_capacity = (body_capacity == 0) ? 16 : body_capacity * 2;
        bodies = realloc(bodies, sizeof(body*) * body_capacity);
    }
    bodies[body_count++] = b;

    // Insert body into grid cells
    vec2 pos = b->position;
    int cell_x = (int)((pos.x - world_min.x) / cell_size);
    int cell_y = (int)((pos.y - world_min.y) / cell_size);
    int cell_index = num_cells_x * cell_y + cell_x;
    grid_cell cell = cells[cell_index];

    // Check if grid cell is initialized (and initialize if not)
    if (cell.count == 0) {
        cell.indices = malloc(4 * sizeof(int));

        if (cell.indices == NULL) {
            fprintf(stderr, "Error allocating memory for cell"); // Don't forget to free
        }
        cell.capacity = 4;
    }

    // Check that count is not at capacity
    if (cell.count == cell.capacity) {
        int * temp_ptr = NULL;
        int * index_ptr = cell.indices;
        int capacity = cell.capacity;

        temp_ptr = realloc(index_ptr, 2 * capacity * sizeof(int)); // Change capacity to a size_t

        if (temp_ptr == NULL) {
            fprintf(stderr, "Reallocation for broadphase_grid failed"); // Figure out how to handle this
        }
        cell.indices = temp_ptr;
    }

    // Insert new index
    cell.indices[cell.count] = body_count - 1;
    cell.count++;
}

void grid_remove_body(body* b) {
    for (int i = 0; i < body_count; i++) {
        if (bodies[i] == b) {
            bodies[i] = bodies[body_count - 1];
            body_count--;
            return;
        }
    }
}

int grid_compute(body_pair *out_pairs, int max_pairs) {
    int pair_count = 0;
    for (int i = 0; i < body_count; i++) {
        for (int j = i + 1; j < body_count; j++) {
            if (pair_count >= max_pairs) {
                return pair_count;
            }
            out_pairs[pair_count++] = (body_pair){bodies[i], bodies[j]};
        }
    }
    return pair_count;
}

inline void grid_remove() {
    grid_clear();
    cell_size = 0;
    cell_count = 0;
    initialized = false;
}