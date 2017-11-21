#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;
 
int main ()
{
srand(time(NULL));

 
const int size = 17000;
int a[size];
    int start_time;
	int search_time;
 
cout<< "\n" <<endl;
for (int i=0; i<size; i++)
{
a[i] = rand();
start_time = clock();
cout<< a[i] << "\t";
}
 
for (int i=0; i<size; ++i)
{
int value = a[i];
int j=i-1;
for (;j>=0 && a[j]>value; --j)
a[j+1] = a[j];
a[j+1] = value;
}
 

cout<< "After sort: " <<endl;
for (int i=0; i<size; i++)
cout<< a[i] << "\t";
cout<<endl;
search_time = clock() - start_time;
std::cout << search_time << " vremya v s \n";
 
system("pause");
return 0;
}
