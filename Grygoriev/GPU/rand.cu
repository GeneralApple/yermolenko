#include <stdio.h>
#include <cuda.h>
#include <ctime>
#include <cstdlib>

using namespace std;

__global__ void Random(int *c,int r)
{
  
  
  unsigned int ind = blockIdx.x*blockDim.x+threadIdx.x;
  unsigned long int tmp = rnd0 * (1+1664524*ind) + 1013904223UL*ind;
  
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
cudaMalloc(&d_rnd0, N*sizeof(int));
  
  cudaMemcpy(d_rnd0, &rnd0, sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(d_y, y, N*sizeof(int), cudaMemcpyHostToDevice);
  
   Random<<<(N+255)/256, 256>>>(d_y, *d_rnd0);
	
  cudaMemcpy(y, d_y, N*sizeof(int), cudaMemcpyDeviceToHost);	
	
	for (int i = 0; i < N; i++)
  {
   
   cout<<y[i]<<endl;
  }
	
for(int j = 0;j<10;j++)
{ int n = 0;
 	for(int k = 0; k<N;k++){
		if(y[k]>10*j && y[k]<=10*(j+1)) n++ }
 cout<<n<<endl;
}
	
cudaFree(d_y);

	
 free(y);
