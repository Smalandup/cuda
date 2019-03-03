#ifndef _UTILS_H
#define _UTILS_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define CUDA_CALL(x) do { if((x) != cudaSuccess) { \
    printf("Error %d at %s:%d\n",x, __FILE__,__LINE__); \
    return EXIT_FAILURE;}} while(0)

double elapsed(clock_t begin, clock_t end)
{
    return (double)(end - begin) / CLOCKS_PER_SEC;
}

int check_power_two(int n)
{
    return !(n & (n-1));
}

void disp(double *t, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%lf ", t[i]);
    }
    printf("\n");
}

void fill_rand(double *t, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        t[i] = (rand() % INT_MAX)*1e-5;
    }
}

#endif