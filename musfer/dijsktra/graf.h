#include <algorithm>
#include <map>

using namespace std;
#define INF 1000000000

class graf
{
public:
graf(int s)
{
roads = new map<int,int> [s];
mark = new int[s];
dist = new int[s];
for (int j=0; j<s; j++)
{
 dist[j]=INF;
 mark[j]=1;
}


}
int *mark;
int *dist;

map<int,int> *roads;
};


//template <typename T>

