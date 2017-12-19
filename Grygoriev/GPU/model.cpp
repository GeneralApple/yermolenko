#include <thread>  
#include <iostream>
#include <time.h>
#include <cmath>
#include <cstdlib>
//#include <unistd.h>

using namespace std;

double random()
{
	double r = rand() / (RAND_MAX + 1.0);
}

void model();


int main() {

	srand(time(0));
	int N = 1000;
	double d; //товщина пластинки
        cin >> d;
        double mu=0.1; //довжина вільного пробігу
        double h = 10;
	double xpos[N];
	
	
	//створити масив потоків
	thread myThreads[N];
	
	
	
	thread t1(foo);
	thread t2(bar);

	t.detach();

	system("pause");
	return 0;
}
