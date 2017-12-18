#include <thread>  
#include <iostream>
#include <time.h>
//#include <unistd.h>

using namespace std;

void foo()
{
	for (int i = 0; i<10; i++)
	{
		int rnd = 1 + rand() % 100;
		cout << rnd << " done" << endl;
		//  sleep(1)
	}
}

int main() {

	srand(time(0));

	thread t1(foo);
	thread t2(bar);

		t.detach();

	system("pause");
	return 0;
}
