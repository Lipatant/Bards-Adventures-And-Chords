/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** utility/generation/perlin_noise/2d.c
** File description:
** Allows the creation of procedural maps, made following javidx9's video: https://www.youtube.com/watch?v=6-0UaeJBumA
*/

#include "utility/free.h"
#include "utility/generation/hash.h"
#include <stdlib.h>

struct int_vector_2_s {
    int x;
    int y;
};

struct float_vector_2_s {
    float x;
    float y;
};

static float **create_output_array(unsigned int const width, unsigned int const height)
{
    float **output = malloc(sizeof(float *) * width);

    if (output == NULL)
        return NULL;
    for (unsigned int x = 0; x < width; x++) {
        output[x] = malloc(sizeof(float) * height);
        if (output[x] == NULL) {
            for (unsigned int x2 = 0; x2 <= x; x2++) {
                free(output[x2]);
                free(output);
                return NULL;
            }
        }
        for (unsigned int y = 0; y < height; y++)
            output[x][y] = 0;
    }
    return output;
}

static float **create_seeds_array(unsigned int const width, unsigned int const height, unsigned int const seed)
{
    float **seeds = create_output_array(width, height);
    unsigned int starting_hash = 0;
    unsigned long hash_size = 0;

    if (seeds == NULL)
        return NULL;
    srand(seed);
    starting_hash = rand();
    hash_size = sizeof(HASH) / sizeof(unsigned int);
    for (unsigned int x = 0; x < width; x++)
        for (unsigned int y = 0; y < height; y++) {
            starting_hash = (starting_hash + rand()) % hash_size;
            srand(seed + HASH[(x * width + y + starting_hash) % hash_size]);
            seeds[x][y] = (float)rand() / RAND_MAX;
        }
    return seeds;
}

float **utility_generation_perlin_noise_2d(unsigned int const width, unsigned int const height,
    unsigned int const octaves, float const bias, unsigned int const seed)
{
    struct float_vector_2_s blending = {0, 0};
    struct float_vector_2_s sample_final = {0, 0};
    struct int_vector_2_s sample1 = {0, 0};
    struct int_vector_2_s sample2 = {0, 0};
    float **seeds = NULL;
    float **output = create_output_array(width, height);
    float noise = 0.0;
    float scale = 0.0;
    float scale_total = 0.0;
    int pitch = 0;

    if (output == NULL)
        return NULL;
    seeds = create_seeds_array(width, height, seed);
    if (seeds == NULL) {
        utility_free_float_2d(output, width);
        return NULL;
    }
    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            noise = 0.0;
            scale = 1.0;
            scale_total = 0.0;
            for (unsigned int o = 0; o < octaves; o++) {
                pitch = width >> o;
                sample1.x = (x / pitch) * pitch;
                sample1.y = (y / pitch) * pitch;
                sample2.x = (sample1.x + pitch) % width;
                sample2.y = (sample1.y + pitch) % width;
                blending.x = (float)(x - sample1.x) / (float)pitch;
                blending.y = (float)(y - sample1.y) / (float)pitch;
                sample_final.x = (1.0 - blending.x) * seeds[sample1.x][sample1.y] + blending.x * seeds[sample2.x][sample1.y];
                sample_final.y = (1.0 - blending.x) * seeds[sample1.x][sample2.y] + blending.x * seeds[sample2.x][sample2.y];
                scale_total += scale;
                noise += (blending.y * (sample_final.y - sample_final.x) + sample_final.x) * scale;
                scale /= bias;
            }
            output[x][y] = noise / scale_total;
        }
    }
    utility_free_float_2d(seeds, width);
    return output;
}
