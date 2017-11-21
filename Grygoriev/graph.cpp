#include <iostream>
using namespace std;

const int SIZE = 6;
const int INF = 1000000000;

void dijkstra(int a[SIZE][SIZE])
{

  int distance[SIZE]; // массив найденых кратчайших путей, индексы - вершины графа
  int vertex[SIZE]; // массив меток
  int temp; // для временного хранения пути
  int minindex, dist;

  for (i = 0; i<SIZE; i++) {
    distance[i] = INF; // массив путей инициализируется бесконечностью
    vertex[i] = 1;
  }
  
  d[0] = 0;
  
  do
  { // исполнение алгоритма 
    minindex = INF;
    dist = INF;
    for (int i = 0; i < SIZE; i++) // поиск ближайшей вершины к данной и непройденной до этого
    {
      if ((vertex[i] == 1) && (distance[i]<dist)) 
      {
        dist = distance[i];
        minindex = i;
      }
    }
if (minindex != INF) // исполнение алгоритма
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
  
  } while (minindex < INF);
    
      for (int i = 0; i < SIZE; i++)
  {
    cout << "Distance from 1st vertex to " << i+1 << " is " << distance[i] << endl;
  }
  cout << endl;
}

int main ()
{
  int a[SIZE][SIZE] = {{0  ,7  ,9  ,INF,INF,14 },
                       {7  ,0  ,10 ,15 ,INF,INF}, // матрица путей
                       {9  ,10 ,0  ,11 ,INF,2  },
                       {INF,15 ,11 ,0  ,6  ,INF}, // индексы по горизонтали из точки
                       {INF,INF,INF,6  ,0  ,9  },
                       {14 ,INF,2  ,INF,9  ,0  }}; // по вертикали в точку, значение - вес
  dijkstra(a);
  return 0;
}
