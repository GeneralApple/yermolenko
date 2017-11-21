#include <iostream>
#include <vector>
#define INT_MAX 100000
using namespace std;

void Dijkstra(const std::vector<std::vector<int> >& GR, int st)
{
  int V = (int)GR.size();
  int distance[V], count, i, u;
  bool visited[V];
//   Initialization verteces
  for (i=0; i<V; i++)
  {
    distance[i]=INT_MAX;
    visited[i]=false;
  }
  distance[st]=0;
//   Passing through all vertices except initial
  for (count=0; count<V-1; count++)
  {
//     Iteration over all vertices, if not visited and distance to initial smaller than current minimum, 
//     assign this vertex as current
    int min=INT_MAX;
    for (i=0; i<V; i++)
      if (!visited[i] && distance[i]<min)
      {
        min=distance[i]; 
        u=i;
      }
//       If one of these vertices has minimum distance to initial vertex make it visited
    visited[u]=true;
//     
    for (i=0; i<V; i++)
      if (!visited[i] && GR[u][i] && distance[u]+GR[u][i]<distance[i])
        distance[i]=distance[u]+GR[u][i];
  }
  cout<<"Way cost from initial vertex to final:\t\n";
  for (i=0; i<V; i++) 
    if (distance[i]!=INT_MAX)
      cout<< st+1 <<" > "<<i+1<<" = "<<distance[i]<<endl;
    else cout<< st+1 <<" > "<<i+1<<" = "<<"way is unabled"<<endl;
}

int main()
{
  std::vector<std::vector<int> > GR = {
  {0, 1, 4, 0, 2, 0},
  {1, 0, 0, 9, 0, 0},
  {4, 0, 0, 7, 0, 0},
  {0, 9, 7, 0, 0, 2},
  {2, 0, 0, 0, 0, 8},
  {0, 0, 0, 2, 8, 0}};
  int start;
  cout<<"Initial vertex >> "; cin>>start;
  Dijkstra(GR, start-1);
  return 0;
}
