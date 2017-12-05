#include <stdio.h>
#define N 16
double a[N][N], b[N][N], c[N][N];
int main(){
  int i, j, k;
  
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      a[i][j]=b[i][j]=i*j;

  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      c[i][j] = 0.0;
      for(k=0; k<N; k++) c[i][j]+=a[i][k]*b[k][j];
      printf("%lf\t", c[i][j]);
    }
  }
}
