#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MASK 123459876
#define IQ 127773
#define AI 16807
#define IA 16807
#define IR 2836
#define IM 2147483647

#include "DFE.max"
#include "MaxSLiCInterface.h"

long gen_seed(long idum){
    long k;
    idum ^= MASK;
    k = idum/IQ;
    idum = IA*(idum-k*IQ)-IR*k;
    if(idum < 0) idum += IM;
    idum ^= MASK;
    return idum;
}

int main(void)
{
    clock_t tic,toc;
	const long size = 1000000;
	int sizeBytes = size * sizeof(float);
	long *x = malloc(size*sizeof(long));
	float *s = malloc(sizeBytes);

    x[0] = gen_seed(5);
	// TODO Generate input data
	for(int i = 1; i < size; ++i) {
		x[i] = gen_seed(x[i-1]);
	}

	printf("Running on DFE.\n");
	tic = clock();
	DFE(size, x, s);
	toc = clock();

	// TODO Use result data
	printf("Elapsed: %f seconds\n",(double)(toc-tic) / CLOCKS_PER_SEC);

	printf("Everything done.\n");
	return 0;
}
