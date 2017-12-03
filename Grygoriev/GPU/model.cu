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
double mu=0.07,l,dTh;

double h = 100;

srand(time(NULL));

double position[N];

int *N_gpu;

do
