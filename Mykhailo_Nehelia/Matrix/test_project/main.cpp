#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


using namespace std;

double **RandomMatrix(int size) {
    
    double **M = new double * [size];
    for(int i=0; i<size; i++) {
        M[i] = new double [size];
        for(int j=0; j<size; j++) {

            
            M[i][j] = 1000.* rand( )/RAND_MAX;
        }
    }
    
    return M;
}

double **MultiPly(double **a, double **b, int size) {
    double **M = new double * [size];
    for(int i=0; i<size; i++) {
        M[i] = new double [size];
        for(int j=0; j<size; j++) {
            M[i][j] = 0;
        }
    }
    
    clock_t start = clock();
    
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            for(int k=0; k<size; k++) {
                M[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    
    cout << size << ", " << seconds << "\n";
    
    return M;
}

void printMatrix(double **M, int size) {
    
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            cout << M[i][j] << '\t';
        }
        
        cout << '\n';
    }
}



int main(){
    
    
    int seed = time(NULL);
    srand(seed);
    
    for(int n=1; n<=500; n++) {
        int N = n;
        double **A = RandomMatrix(N);
        double **B = RandomMatrix(N);
        double **M = MultiPly(A,B,N);
    }
    return 0;
}
