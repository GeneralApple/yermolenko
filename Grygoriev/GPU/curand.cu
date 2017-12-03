#include <stdio.h>
#include <cuda.h>
#include <curand.h>
#include <curand_kernel.h>


__global__ void init(unsigned int seed, curandState_t* states) {

  /* we have to initialize the state */
  curand_init(seed, /* the seed can be the same for each core, here we pass the time in from the CPU */
              blockIdx.x*blockDim.x+threadIdx.x, /* the sequence number should be different for each core (unless you want all
                             cores to get the same sequence of numbers for some reason - use thread id! */
              0, /* the offset is how much extra we advance in the sequence for each call, can be 0 */
              &states[blockIdx.x]);
}
__global__ void Random(curandState_t* states, unsigned int *c)
{
  unsigned int ind = blockIdx.x*blockDim.x+threadIdx.x;
 
  c[ind] = 1 + curand(&states)%100;
}

int main(void)
{
  
   curandState_t* states;
  cudaMalloc((void**) &states, N * sizeof(curandState_t));
   init<<<(N+255)/256, 256>>>(time(0), states);
  int N = 1000000;
  int *y, *d_y;
  
  y = (int*)malloc(N*sizeof(int));

  cudaMalloc(&d_y, N*sizeof(int));
  


  for (int i = 0; i < N; i++) {
    y[i] = 0;
  }
  //cudaMemcpy(d_y, y, N*sizeof(int), cudaMemcpyHostToDevice);

   Random<<<(N+255)/256, 256>>>(d_y);

  cudaMemcpy(y, d_y, N*sizeof(int), cudaMemcpyDeviceToHost);

  //int maxError = 0;
  for (int i = 0; i < N; i++)
  {
   // maxError = max(maxError, abs(y[i]-4));
   printf("Rand is: %d\n", y[i]);
  }
  //printf("Max error: %d  %d\n", maxError, N);

  cudaFree(d_y);
  free(y);
} 
