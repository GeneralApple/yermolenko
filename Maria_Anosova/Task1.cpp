#include <iomanip>
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()

{for (int p = 0; p<5; p++)
{cout << "\n"; 

 int m = 0; 
    cin >>  m;
const int n = m;

cout << "\n"; 
 

int **matrix1 = new int *[n]; 
      for (int i=0; i<n; i++)
         matrix1[i] = new int [n];  


int **matrix2 = new int *[n]; 
      for (int i=0; i<n; i++)
         matrix2[i] = new int [n];  


 int i,j,k,l;

	for(i=0;i<n;i++)
 		{
			for(j=0;j<n;j++)
			{
				matrix1[i][j]=0;
			}
 		}


 	for(i=0;i<n;i++)
 		{
			for(j=0;j<n;j++)
			{
				matrix1[i][j]=rand()%50;
//			cout<<matrix1[i][j]<< "  "; 
			}
//		cout << "\n"; 
 		}

//cout << "\n"; 

	for(k=0;k<n;k++)
 		{
			for(l=0;l<n;l++)
			{
				matrix2[k][l]=rand()%50;
//				cout<<matrix2[k][l]<< "  ";
			}
//		cout << "\n"; 
 		}

//cout << "\n"; 

clock_t c_start = clock();


int **product = new int *[n]; 
      for (int i=0; i<n; i++)
         product[i] = new int [n];  


    for (int row = 0; row < n; row++) {  
        for (int col = 0; col < n; col++) {  
		product[row][col] = 0;
            for (int inner = 0; inner < n; inner++) {  
                product[row][col] += matrix1[row][inner] * matrix2[inner][col];  
            }  
//            cout << product[row][col] << "  ";  
        }  
//        cout << "\n";  
    }  

 clock_t c_end = clock();

cout << std::fixed << std::setprecision(3) << "CPU time used: "
              << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms\n" ;
}
 return 0;
}




