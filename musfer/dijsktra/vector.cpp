#include <stdio.h>
#include <iostream>
#include "vector.h"


int main()
{
vector<double> m( 1);

m.push_back(9); 
m.push_back(2);
m.push_back(5);
m.push_back(6);
for (int k=0; k<m.size(); ++k)
{
std::cout <<  m.array[k] << "   ";	
}
std::cout << std::endl;
//std::cout << m.array << std::endl;
std::cout << m.size() << std::endl;
return 0;
}

