// ConsoleApplication43.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <thread>  
#include <iostream>
#include <time.h>
#include <cmath>
#include <cstdlib>
//#include <unistd.h>

#define N 100
#define pi 3.1416
#define d 1  //товщина пластини

double mu = 0.3; //довжина вільного пробігу
double h = 10;
double xpos[N];

using namespace std;

double random(int id)
{
	unsigned long int rnd = (rand()* (1 + 1664524 * id) + 1013904223UL * id) % RAND_MAX;
	return (double)rnd / (double)RAND_MAX;
}

double expo(double mu, int i)
{
	double u = random(i);
	return -log(1 - u) * mu;
};

void model(int j)
{
	srand(time(0));
	double x = 0, y = 0; //початкові координати частинки
	double l; //відстань прольоту частинки між актами взаємодії
			  //int n = 0;
	double Theta = 0; //напрям руху частинки
	double dTh;

	int n = 0;

	while (n<10)
	{
		//cout << "l:  " << l << "  dTh:  " << dTh << "  Theta:  " << Theta << "  y:  " << y << "  x:  " << x << endl;
		l = expo(mu, j);

		y = y + l*cos(Theta);
		x = x + l*sin(Theta);

		if (y >= d) break;
		
		if (x<-h) break;
		if (x>h) break;
		dTh = random(j) *(2*pi) - (pi);
		Theta = Theta + dTh;

		    n++;
	}

	xpos[j] = x;
	//cout << xpos[j]<<"   ";
}



int main() {


	//int N = 1000;
	//double pi = 3.1416;


	//створити масив потоків
	thread myThreads[N];

	for (int i = 0; i<N; i++)
	{
		myThreads[i] = thread(model, i);
	}

	for (int i = 0; i<N; i++) myThreads[i].join();

	for (int j = 0; j<40; j++)
	{
		int n = 0;
		for (int k = 0; k<N; k++) {

			if (h*(0.05*j - 1) <= xpos[k] && h*(0.05*j - 0.95) > xpos[k]) n++;
		}
		//cout << "startpos:  "<< h*(0.05*j - 1)<<"  finpos:  "<< h*(0.05*j - 0.95) <<"  n:  "<<n << endl;
		cout << n << endl;
	}


	system("pause");
	return 0;
}
