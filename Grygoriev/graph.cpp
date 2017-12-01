#include <iostream>
#include <queue>
using namespace std;

const int SIZE = 6;
const int INF = 1000000000;

void dijkstra(int a[SIZE][SIZE])
{
  queue<int> Queue;
  int distance[SIZE]; // масив найкоротших шляхів 
  bool vertex[SIZE]; // массив міток (чи відвідана дана вершина?)
  
  int temp; // для временного хранения пути
  int minindex, dist;

  for (i = 0; i<SIZE; i++) {
    distance[i] = INF; 
    vertex[i] = 0;
  }
  
  Queue.push(0); // поміщаємо в чергу першу вершину
  
  d[0] = 0;
  
  while (!Queue.empty())
  {
    int node = Queue.front(); 
    Queue.pop();
    vertex[node] = 1; // відмічаємо її як таку, що віввідана
    for (int j = 0; j < 7; j++)
    {
      if (mas[node][j] && nodes[j] == 0)
      { // якщо в
        Queue.push(j); // добавляем ее в очередь
        nodes[j] = 1; // отмечаем вершину как обнаруженную
        e.begin = node; e.end = j;
        Edges.push(e);
        if (node == req) break;
      }
    }
    cout << node + 1 << endl; // выводим номер вершины
  }
  
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
  int a[SIZE][SIZE] = {{0  ,7  ,9  ,0,0,14 },
                       {7  ,0  ,10 ,15 ,0,0}, // матриця відстаней
                       {9  ,10 ,0  ,11 ,0,2  },
                       {0,15 ,11 ,0  ,6  ,0}, 
                       {0,0,0,6  ,0  ,9  },
                       {14 ,0,2  ,0,9  ,0  }}; // "0" означає відсутність ребер
  int s;
  cin>>s; 
  
  dijkstra(a,s); \\функція знаходить відстань з s-ї вершини до всіх інших вершин
  return 0;
}
