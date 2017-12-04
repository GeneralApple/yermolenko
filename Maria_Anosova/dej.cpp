#include <iostream>
using namespace std;

const int SIZE = 6;
const int INF = 1000000000;

void dijkstra(int A[SIZE*SIZE])
{
    int a[SIZE][SIZE];
    for(int i = 0 ; i < SIZE; ++i)
    {
        for(int j = 0 ; j < SIZE ; ++j)
        {
            a[i][j] = A[j+ i*SIZE];
        }
    }
    int distance[SIZE]; 
    int vertex[SIZE]; 
    int temp; 
    int minindex, dist;

    for (int i = 0; i<SIZE; i++) {
        distance[i] = INF; 
        vertex[i] = 1;
    }
    distance[0] = 0;
    do
    { 
        minindex = INF;
        dist = INF;
        for (int i = 0; i < SIZE; i++) 
        {
            if ((vertex[i] == 1) && (distance[i]<minindex))
            {
                dist = distance[i];
                minindex = i;
            }
        }
        if (minindex != INF) 
        {
            for (int i = 0; i<SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = dist + a[minindex][i];
                    if (temp < distance[i]) distance[i] = temp;
                }
            }
            vertex[minindex] = 0;
        }
    } while (minindex < INF);

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Distance from 1st vertex to " << i+1 << " is " << distance[i] << endl;
    }
    cout << endl;
}

int main ()
{

    int A[SIZE*SIZE] = {0  ,5  ,9  ,INF,INF,14 , 5  ,0  ,10 ,15 ,INF,INF, 9  ,10 ,0  ,11 ,INF,2  ,
                         INF,15 ,11 ,0  ,6  ,INF, INF,INF,INF,6  ,0  ,9  , 14 ,INF,2  ,INF,9  ,0  };
    dijkstra(A);
    return 0;
}
