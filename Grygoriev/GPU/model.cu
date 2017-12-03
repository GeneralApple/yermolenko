#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <iostrem>
#include <time.h>
#include <cmath>
#include <cstdlib>

#define pi    3.1416
using namespace std;


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
  


  

//double position[N];


