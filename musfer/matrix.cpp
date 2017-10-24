#include <stdio.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>
#define N 10000
using namespace std;
using namespace std::chrono;
double a[N][N], b[N][N], c[N][N];
int main(int argc, char *argv[])
  {
int n=0;
double time1=0;
double time2=0;

sscanf(argv[1],"%d",&n);
for (int i=0; i<n; i++)
     for (int j=0; j<n; j++)
	{a[i][j]=rand()%5; b[i][j]=rand()%5;}
high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i=0; i<n; i++)
     for (int j=0; j<n; j++)
	{
	for (int k=0; k<n; k++)
	{
	c[i][j]=c[i][j]+a[i][k]*b[k][j];	
	}	
	} 

high_resolution_clock::time_point t2 = high_resolution_clock::now();
 duration<double, std::milli> time_span = t2 - t1;
std::cout <<  time_span.count()/1000 << "s\n";

  }
