
#include "stdafx.h"
#include <iostream>
#include <time.h> 
#include <cstdlib>
#include <algoritm>

using namespace std;

int main
{
srand(time(NULL));
 int rnd0 = 1 + rand()/100;
int arr[32];

for(int i = 0; i<100;i++)
{arr[i] = i;}

for_each(arr, arr+100, [](int n) {
unsigned long int rnd = rnd0* (1664525<<n) + 1013904223UL;
cout<<rnd;
});

int pause;
cin>>pause;
return 0;
}
