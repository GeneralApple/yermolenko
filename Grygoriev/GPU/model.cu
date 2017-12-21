#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include<curand.h>
#include<curand_kernel.h>
#include <cuda.h>
#include <stdio.h>


using namespace std;

__global__ void setup_kernel ( curandState * state, unsigned long seed )
{
unsigned int id = blockIdx.x*blockDim.x+threadIdx.x;
curand_init ( seed, id, 0, &state[id] );
}



__device__ float generate( curandState* globalState, int ind )
{
    //int ind = threadIdx.x;
    curandState localState = globalState[ind];
    float RANDOM = curand_uniform( &localState );
    globalState[ind] = localState;
    return RANDOM;
}


__device__ float expo(double mu, curandState* globalState, int ind)
{
    double u;
    do{
        u = generate(globalState, ind);
    } while(u==1.0);
    
    return -log(1- u) * mu;
}


__global__ void model(double *dd, double *pos, double *dmu, double *dh, curandState* globalState)
{
unsigned int id = blockIdx.x*blockDim.x+threadIdx.x;

double mu = *dmu;
double h = *dh;
double d = *dd;
double pi = 3.1416;
double x=0, y=0; //початкові координати частинки
double l; //відстань прольоту частинки між актами взаємодії
//int n = 0;
double Theta = 0; //напрям руху частинки
double dTh;
int n = 0;
while (n<10)
{
    l = expo(mu, globalState, id);
    
    y = y + l*cos(Theta);
    x = x + l*sin(Theta);
        if(y>=d) break;
    if(y<0)
    {x = h*10;
    break;}
    if(x<-h) break;
    if(y>h) break;
    dTh = generate(globalState, id)*(4*pi)-(2*pi);
    Theta = Theta + dTh;
n++;

}

//printf("position: %f \n", x);
pos[id] = x;
}



int main() {
int N = 1; //кількість частинок
//cin >> N;
double d; //товщина пластинки
cin >> d;
double mu=0.07; //довжина вільного пробігу
double h = 100;
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
cudaMalloc((void**) &pos, N*sizeof(double));
curandState* devStates;
cudaMalloc ( &devStates, N*sizeof( curandState ) );

setup_kernel <<< 1, 1 >>> ( devStates,unsigned(time(NULL)) );

model <<< 10, 1 >>> (dd,pos,dmu,dh, devStates);

cudaMemcpy(xpos, pos, N*sizeof(double), cudaMemcpyDeviceToHost);

for (int j = 0; j<20; j++)
{
    int n = 0;
    for(int k = 0; k<N;k++){
    
    if( (0.1*j -1)<=xpos[k] && (0.1*j -0.9) > xpos[k]) n++;
     }
cout<<n<<endl;
}

    //запис в файл
	ofstream f;

	f.open("E:\\data.txt");
	for (int i = 0; i < N; i++) f << xpos[i] << endl;
	f.close();
    
return 0;}
