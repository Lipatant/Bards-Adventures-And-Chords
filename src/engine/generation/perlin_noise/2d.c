/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/generation/perlin_noise/2d.c
** File description:
** Allows the creation of procedural maps, made following javidx9's video: https://www.youtube.com/watch?v=6-0UaeJBumA
*/

#include <stdlib.h>

struct int_vector_2_s {
    int x;
    int y;
};

struct float_vector_2_s {
    float x;
    float y;
};

static void free_float_2d(float **array, unsigned int const width)
{
    if (array == NULL)
        return;
    for (unsigned int x = 0; x < width; x++)
        free(array[x]);
    free(array);
}

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

static unsigned int HASH[] = {208,34,231,213,32,248,233,56,161,78,24,140,71,48,140,254,245,255,247,247,40,
                     185,248,251,245,28,124,204,204,76,36,1,107,28,234,163,202,224,245,128,167,204,
                     9,92,217,54,239,174,173,102,193,189,190,121,100,108,167,44,43,77,180,204,8,81,
                     70,223,11,38,24,254,210,210,177,32,81,195,243,125,8,169,112,32,97,53,195,13,
                     203,9,47,104,125,117,114,124,165,203,181,235,193,206,70,180,174,0,167,181,41,
                     164,30,116,127,198,245,146,87,224,149,206,57,4,192,210,65,210,129,240,178,105,
                     228,108,245,148,140,40,35,195,38,58,65,207,215,253,65,85,208,76,62,3,237,55,89,
                     232,50,217,64,244,157,199,121,252,90,17,212,203,149,152,140,187,234,177,73,174,
                     193,100,192,143,97,53,145,135,19,103,13,90,135,151,199,91,239,247,33,39,145,
                     101,120,99,3,186,86,99,41,237,203,111,79,220,135,158,42,30,154,120,67,87,167,
                     135,176,183,191,253,115,184,21,233,58,129,233,142,39,128,211,118,137,139,255,
                     114,20,218,113,154,27,127,246,250,1,8,198,250,209,92,222,173,21,88,102,219};

static float **create_seeds_array(unsigned int const width, unsigned int const height, unsigned int const seed)
{
    float **seeds = create_output_array(width, height);

    if (seeds == NULL)
        return NULL;
    for (unsigned int x = 0; x < width; x++)
        for (unsigned int y = 0; y < height; y++) {
            srand(seed + HASH[(x * width + y) % (sizeof(HASH) / sizeof(unsigned int))]);
            seeds[x][y] = (float)rand() / RAND_MAX;
        }
    return seeds;
}

float **engine_generation_perlin_noise_2d(unsigned int const width, unsigned int const height,
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
        free_float_2d(output, width);
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
                sample_final.x = (1.0 - blending.x) * seeds[sample1.x][sample1.y] + blending.x * seeds[sample2.x][sample2.y];
                sample_final.y = (1.0 - blending.x) * seeds[sample1.x][sample2.y] + blending.x * seeds[sample2.x][sample1.y];
                scale_total += scale;
                noise += (blending.y * (sample_final.y - sample_final.x) + sample1.x) * scale;
                scale = scale / bias;
            }
            output[x][y] = noise / scale_total;
            printf("value at x:%i y:%i -> %.10f | noise:%.5f | original at %.10f\n", (int)x, (int)y, (float)output[x][y], noise, seeds[x][y]);
        }
    }
    free_float_2d(seeds, width);
    return output;
}
