#include <stdio.h>
#include <iostream>
#include "vect.h"

vect::vect()
{
array = new int[3];
capacity=3;
s=0;
}

int vect::size()
{
return s;
}


void vect::push_back(int a)
{
if (s<capacity)
  {
        array[s]=a;
	s++;
  }
else
  {
	sarray = new int[s+1];
	for (int j=0; j<s; j++)
	{
		sarray[j]=array[j];
	}
	sarray[s]=a;
        
	//delete [] array;
	
	array = sarray;
        
	capacity++;
	s++;
  }
}
		
int	 main()
{
vect m;
m.push_back(9); 
m.push_back(2);

int a=m.s;
//std::cout << m.array << std::endl;
std::cout << m.s << std::endl;
std::cout << m.capacity << std::endl;
return 0;
}
