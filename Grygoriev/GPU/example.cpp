#include <thread>  
#include <iostream>

#include <unistd.h>

using namespace std;

void foo
{
  for(int i=0; i<10; i++)
  {
    cout<<i<<" done"<<endl;
    sleep(1)
    }
 }

int main(){

thread t(foo)

t.detach;

system("pause");
return 0;
}
