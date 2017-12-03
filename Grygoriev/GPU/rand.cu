#include <stdio.h>
#include <cuda.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
int N = 1000;
  int *y, *d_y;
  y = (int*)malloc(N*sizeof(int));

  cudaMalloc(&d_y, N*sizeof(int));
