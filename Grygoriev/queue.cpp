#include <iostream>
#include <queue>
using namespace std;


int main ()
{
  queue<int> num;
  queue<int> num2;
  
  int a;
  
  cin >> a;
  
  while(a)
  {
    //b = (a*2 + 7)/3;
    num.push((a*2 + 7)/3);
    num2.push((a*2 + 3)/7);
    cin >> a;
    
  }
  
  num.swap(num2);
  
  if(num.empty()) cout << "Sorry, there is some problem!"<<endl;
  else cout <<"You have "<<num.size()<<" from each quene"<<endl;
  
  while(!num.empty())
    
  {
    cout <<num.front() <<"   ";
    num2.pop();
  }
   
  cout<<endl;
    
  while(!num2.empty())
    
  {
    cout <<num2.front() <<"  ";
    num.pop();
  }
    
 return 0;
}
