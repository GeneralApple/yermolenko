#include "stdafx.h"
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
  bool nodes[SIZE]; //відмічає виявлені (додані в чергу) вершини
  


  for (int i = 0; i<SIZE; i++) {
    distance[i] = INF; 
    vertex[i] = 0;
    nodes[i] = 0;
  }
  distance[0] = 0;  
  Queue.push(0); // поміщаємо в чергу першу вершину
  
  
  
  while (!Queue.empty())
  {
    int node = Queue.front(); 
    Queue.pop();
    vertex[node] = 1; // відмічаємо її як таку, що віввідана
    for (int j = 0; j < 7; j++)
    {
      if (a[node][j]!=0 && vertex[j] == 0)
      { // якщо в нас є ребро і вершина не відвідана
        
         if (!nodes[j])
         {
        Queue.push(j); 
        nodes[j] = 1;
         } //якщо вершина не виявлена, додаємо в чергу і відмічаємо як виявлену
        
      
        if (distance[node]+a[node][j] < distance[j]) distance[j] = distance[node]+a[node][j];
       }
    }
    
  }
  
  
for (int k = 0; k < SIZE; k++)
  {
    cout << "Distance from 1st vertex to " << k+1 << " is " << distance[k] << endl;
  }
  
}  
  

int main ()
{
  int a[SIZE][SIZE] = {{0  ,7  ,9  ,0,0,14 },
                       {7  ,0  ,10 ,15 ,0,0}, // матриця відстаней
                       {9  ,10 ,0  ,11 ,0,2  },
                       {0,15 ,11 ,0  ,6  ,0}, 
                       {0,0,0,6  ,0  ,9  },
                       {14 ,0,2  ,0,9  ,0  }}; // "0" означає відсутність ребер
   
  
  dijkstra(a); 
  
   int pause;
  cin>>pause;
  
  return 0;
  
 
}
