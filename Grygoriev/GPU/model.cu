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

__device__ float expo(double mu, curandState* globalState, int ind)
{
  do{ double u = generate(globalState, ind);}
    while(u!=0);
    
  return -log(1- u) / mu;}

__device__ float generate( curandState* globalState, int ind ) 
{
    //int ind = threadIdx.x;
    curandState localState = globalState[ind];
    float RANDOM = curand_uniform( &localState );
    globalState[ind] = localState;
    return RANDOM;
}

__global__ void model(double *pos, double *dmu, double *dh, curandState* globalState)
{
    
     unsigned int id = blockIdx.x*blockDim.x+threadIdx.x;
    
    double mu = *dmu;
   double  h = *dh;
    
    


double x=0, y=0; //початкові координати частинки
    
    double l; //відстань прольоту частинки між актами взаємодії

//int n = 0;

double Theta = 0; //напрям руху частинки
    
    double dTh;
    
while (y<d)
{
  l = expo(mu, globalState, id);
    
    
 y = y + l*cos(Theta);
 x = x + l*sin(Theta);
    
    if(y<0)
{x = h*10;
break;}
    
    
    if(x<-h) break;

if(y>h) break;
    
    
    dTh = generate(globalState, id)*(4*pi)-(2*pi);

    Theta = Theta + dTh;
}
    
    pos[id] = x;
}
    
int main() {

int N;
cin >> N;
    
  double d;
    cin >> d;
 
double mu=0.07;

double h = 100;
  
  int *dN;
  
  double *dmu, *dh, *dd;
  
  //cudaMalloc((void**)&dN, sizeof(int));
  cudaMalloc((void**)&dmu, sizeof(double));
  cudaMalloc((void**)&dh, sizeof(double));
    cudaMalloc((void**)&dd, sizeof(double));
  
   //cudaMemcpy(dN, &N, sizeof(int), cudaMemcpyHostToDevice);
   cudaMemcpy(dmu, &mu, sizeof(double), cudaMemcpyHostToDevice);
   cudaMemcpy(dh, &h, sizeof(double), cudaMemcpyHostToDevice);
    cudaMemcpy(dd, &d, sizeof(double), cudaMemcpyHostToDevice);
  


  double xpos[N];
  double *pos;
 
 cudaMalloc((void**) &pos, N*sizeof(int));
 
 curandState* devStates;
 cudaMalloc ( &devStates, N*sizeof( curandState ) );
 
setup_kernel <<< N/1000, 1000 >>> ( devStates,unsigned(time(NULL)) );
 


