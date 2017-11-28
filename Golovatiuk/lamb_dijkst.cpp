#include <iostream>
#include <vector>
#include <algorithm>
#define DMAX 10000
using namespace std;


int mini(int *dis, bool *vis, int len)
{
	int min=DMAX;
	int j=-1;
	for(int i=0; i<len; ++i)
	{
	 if(dis[i]<min && !vis[i]) { min=dis[i]; j=i;}
	}
return j;
}

int main()
{
 int st, i, min, epoch, Nv=5, v;
 int dist[Nv]; bool visit[Nv];
//define the graph
std::vector<std::vector<int>> graph = { {1,4,7}, {1,5,2}, {1,2,1}, {4,1,7}, {5,1,2}, {2,1,1}, {2,5,4}, {2,3,5}, {5,2,4}, {3,2,5}, {3,4,1}, {3,5,4}, {5,3,4}, {4,3,1} };

st=3;


//dijkstra init
 for(i=0; i<Nv; ++i)
 { dist[i]=DMAX; visit[i]=false;}
 dist[st-1]=0;
// for(i=0; i<Nv; ++i)
// {cout<< dist[i]<< endl;}
// cout<<"dist"<<endl;

//dijkstra go
 for(epoch=0; epoch<Nv-1; ++epoch)
 {
 	v=mini(dist, visit, Nv);
	visit[v]=true;
	std::for_each(graph.begin(), graph.end(), [&](std::vector<int> &path){ if(path[0]-1==v && dist[path[1]-1]>dist[v]+path[2]) {dist[path[1]-1]=dist[v]+path[2];} });	
//cout<<path[0]-1<< " "<< path[1]-1 << "\t"<<dist[path[1]-1]<<"\t" << dist[v]+path[2] << endl;
 }
//finish
 cout<< "dist from vert "<< st << endl;
 for(i=0; i<Nv; ++i)
 {
	if(dist[i]!=DMAX)
	{cout<<"to vert " <<i+1<< " = " << dist[i]<<endl;}
 }


return 0;
}
