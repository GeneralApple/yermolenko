#include <thread>  
#include <iostream>
#include <time.h>
#include <cmath>
#include <cstdlib>
//#include <unistd.h>

using namespace std;

double random(int id)
{	double r = (rand()* (1+1664524*id) + 1013904223UL*id)%RAND_MAX;
	double r = rand() / (RAND_MAX + 1.0);
	return rnd0 * (1+1664524*id) + 1013904223UL*id;
}

void model(int j){
	
	double x=0, y=0; //початкові координати частинки
	double l; //відстань прольоту частинки між актами взаємодії
	//int n = 0;
	double Theta = 0; //напрям руху частинки
	double dTh;
	
	int n = 0;


int main() {

	srand(time(0));
	int N = 1000;
	double d; //товщина пластинки
        cin >> d;
        double mu=0.1; //довжина вільного пробігу
        double h = 10;
	double xpos[N];
	
	double pi = 3.1416;
	
	
	
	//створити масив потоків
	thread myThreads[N];
	
	
	
	thread t1(foo);
	thread t2(bar);

	t.detach();

	system("pause");
	return 0;
}
