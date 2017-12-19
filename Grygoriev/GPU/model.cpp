#include <thread>  
#include <iostream>
#include <time.h>
//#include <unistd.h>

using namespace std;


int main() {

	srand(time(0));

	thread t1(foo);
	thread t2(bar);

	t.detach();

	system("pause");
	return 0;
}
