#include <stdio.h>
#include <cuda.h>
#include <ctime>
#include <cstdlib>

using namespace std;

__global__ 
void Random(int *c,int r)
{
  
  
  unsigned int ind = blockIdx.x*blockDim.x+threadIdx.x;
  unsigned long int tmp = rnd0 * (1+1664524*ind) + 1013904223UL*ind;
  /*curandState_t state;
  curand_init(ind, /* the seed controls the sequence of random values that are produced */
              0, /* the sequence number is only important with multiple cores */
              0, /* the offset is how much extra we advance in the sequence for each call, can be 0 */
             /* &state);*/
  c[ind] = 1 + tmp%100;
}


int main()
{
int N = 1000;
  int *y, *d_y;
  y = (int*)malloc(N*sizeof(int));
  cudaMalloc(&d_y, N*sizeof(int));
  
  srand(time(0));
	int rnd0 = 1 + rand() % 100;
  
  int *d_rnd0;
  
  cudaMemcpy(d_rnd0, &rnd0, sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(d_y, y, N*sizeof(int), cudaMemcpyHostToDevice);
  
