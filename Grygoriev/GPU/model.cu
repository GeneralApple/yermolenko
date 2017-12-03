#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostrem>
#include <time.h>
#include <cmath>
#include <cstdlib>

//#define pi    3.1416
using namespace std;

__global__ void setup_kernel ( curandState * state, unsigned long seed )
{
    unsigned int id = blockIdx.x*blockDim.x+threadIdx.x;
    curand_init ( seed, id, 0, &state[id] );
}



int main() {

int N;
cin >> N;
 
double mu=0.07;

double h = 100;
  
  int *dN;
  
  double *dmu, *dh;
  
  cudaMalloc((void**)&dN, sizeof(int));
  cudaMalloc((void**)&dmu, sizeof(double));
  cudaMalloc((void**)&dh, sizeof(double));
  
   cudaMemcpy(dN, &N, sizeof(int), cudaMemcpyHostToDevice);
   cudaMemcpy(dmu, &mu, sizeof(double), cudaMemcpyHostToDevice);
   cudaMemcpy(dh, &h, sizeof(double), cudaMemcpyHostToDevice);
  


  double pos[N];
  double *dpos;
 
 cudaMalloc((void**) &dpos, N*sizeof(int));
 
 curandState* devStates;
 cudaMalloc ( &devStates, N*sizeof( curandState ) );
 
setup_kernel <<< N/1000, 1000 >>> ( devStates,unsigned(time(NULL)) );
 


