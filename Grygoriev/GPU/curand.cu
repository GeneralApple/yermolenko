#include <unistd.h>
#include <stdio.h>
#include <cuda.h>
#include <curand.h>
#include <curand_kernel.h>
#include <iostream>


__global__ void init(unsigned int seed, curandState_t* states) {

  /* we have to initialize the state */
  curand_init(seed, /* the seed can be the same for each core, here we pass the time in from the CPU */
              blockIdx.x*blockDim.x+threadIdx.x, /* the sequence number should be different for each core (unless you want all
                             cores to get the same sequence of numbers for some reason - use thread id! */
              0, /* the offset is how much extra we advance in the sequence for each call, can be 0 */
              &states[blockIdx.x*blockDim.x+threadIdx.x]);
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
  
  int N = 1000000;
  
   init<<<N/1000, 1000>>>(time(0), states);
  
  
  int *y, *d_y;
  
  y = (int*)malloc(N*sizeof(int));

  cudaMalloc((void**) &d_y, N*sizeof(int));
  


  for (int i = 0; i < N; i++) {
    y[i] = 0;
  }
  //cudaMemcpy(d_y, y, N*sizeof(int), cudaMemcpyHostToDevice);

   Random<<<(1000, 1000>>>(states,d_y);

  cudaMemcpy(y, d_y, N*sizeof(int), cudaMemcpyDeviceToHost);

 
 
	for (int i = 0; i < N; i++)
  {
   
   cout<<y[i]<<endl;
  }
	
/*for(int j = 0;j<1000;j++)
{ int n = 0;
 	for(int k = 0; k<N;k++){
		if(y[k]>1000*j && y[k]<=1000*(j+1)) n++ }
 cout<<n<<endl;
}*/
  

  cudaFree(d_y);
  free(y);
             
   return 0;
} 
