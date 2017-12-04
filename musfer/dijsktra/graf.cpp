#include <stdio.h>
#include <fstream>
#include <iostream>
#include "graf.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <map>


using namespace std;
#define INF 1000000000

int main()
{
ifstream inFile;
inFile.open("graf.txt");
int N; //number of cities
inFile >> N;
graf m(N);

int minindex, min;
int x;
int n;
string t;
int weight;
int i=0;
{
	while (inFile >> t) 
	{
	if (t!="s")
	{	
	inFile >> weight;
	n=std::stoi(t)	;
	//m.city[i][n]=weight;	
        //std::cout <<n<< " ";
	//std::cout <<weight<< std::endl;	
	m.roads[i][n]=weight;
	}
	else {i++; };	
	}
	//std::cout <<m.roads[0][7]<< std::endl;
}	


int temp=0;
m.dist[0]=0;
do {
minindex =INF;
min = INF;
    for (i = 0; i<N; i++) 
    {
      if ((m.mark[i] == 1) && (m.dist[i]<min)) 
	{
        min = m.dist[i];
        minindex = i;
        }
    }
    if (minindex != INF) {
      for (i = 0; i<N; i++) {
        if (m.roads[minindex][i] > 0) {
          temp = min + m.roads[minindex][i];
          if (temp < m.dist[i])
            m.dist[i] = temp;
        }
      }
      m.mark[minindex] = 0;
    }

} while (minindex<INF);

for (i = 0; i<N; i++)
{
std::cout <<"minimal distans from city 0 to city "<<i<<" = "<<m.dist[i]<<std::endl;
}

	

return 0;
}

