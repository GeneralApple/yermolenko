#include <thread>  
#include <iostream>
#include <time.h>
#include <cmath>
#include <cstdlib>
//#include <unistd.h>

#define N 1000

using namespace std;

double random(int id)
{	unsigned long int rnd = (rand()* (1+1664524*id) + 1013904223UL*id)%RAND_MAX;
	return rnd / RAND_MAX;
}

double expo(double mu,int i)
{
	double u = ranomd(i);
	return -log(1- u) / mu;
};

void model(int j)
{
	
	double x=0, y=0; //початкові координати частинки
	double l; //відстань прольоту частинки між актами взаємодії
	//int n = 0;
	double Theta = 0; //напрям руху частинки
	double dTh;
	
	//int n = 0;
  	
	while ()
	{
	    l = expo(mu, j);

	    y = y + l*cos(Theta);
	    x = x + l*sin(Theta);
		if(y>=d) break;
	    if(y<0)
	    {x = h*10;
	    break;}
	    if(x<-h) break;
	    if(y>h) break;
	    dTh = (random(j) *(4*pi)-(2*pi);;
	    Theta = Theta + dTh;
//	    n++;
	}
		   
        xpos[j] = x;
}



int main() {

	srand(time(0));
	//int N = 1000;
	double d; //товщина пластинки
        cin >> d;
        double mu=0.1; //довжина вільного пробігу
        double h = 10;
	double xpos[N];
	
	double pi = 3.1416;
	
	
	
	//створити масив потоків
	thread myThreads[N];
	
	for (int i=0; i<N; i++)
	{
		myThreads[i] = thread(model, i);
	}
	
	for (int i=0; i<N; i++) myThreads[i].join();
	
	for (int j = 0; j<20; j++)
{
    int n = 0;
    for(int k = 0; k<N;k++){
    
    if( h*(0.1*j -1)<=xpos[k] && h*(0.1*j -0.9) > xpos[k]) n++;
     }
cout<<n<<endl;
}
    

	system("pause");
	return 0;
}
