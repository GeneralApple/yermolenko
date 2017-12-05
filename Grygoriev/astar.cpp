#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int INF = 1000000000;

struct game
{  
  //int num;// номер клітини
  //x та y- координати
  int x,y;
  bool up; //1 - клітинка відкрита, 0 - закрита (стіна)
  int pointer; //вказівник на попередню клітинку
  int dist; //шлях до клітини
  bool vertex; // массив міток (чи відвідана дана rклітина?)
  bool nodes; //відмічає виявлені (додані в чергу) клітини
  
}

int main{
  queue<int> Queue;
  
  game a[25];
  
  //for(int i = 0; i<25; i++) a[i].num = i+1;
  
  for(int i = 0; i<25; i++) a[i].x = i%5 + 1;
  for(int i = 0; i<25; i++) a[i].y = i/5 + 1;
  
  for(int i = 0; i<25; i++) a[i].up = 1;
  for(int i = 0; i<25; i++) a[i].vertex = 1;
  for(int i = 0; i<25; i++) a[i].dist = INF;
  for(int i = 0; i<25; i++) a[i].nodes = 0;
  
  
  //малюємо стіни
  a[8].up = 0;
  a[13].up = 0;
  a[17].up = 0;
  a[18].up = 0;
  
  int init, end;
  cout << "Enter start point:";
  cin >> init;
   init--;
  
  a[init].pointer = 0;
  a[init].vertex = 0;
  
   a[init].dist = 0;
  
  
    cout << "Enter finish point:";
    cin >> end;
   end--;
 
    Queue.push(init); // поміщаємо в чергу першу вершину
    
  while (!Queue.empty())
  {
    int node = Queue.front(); 
    Queue.pop();
    a[node].vertex = 0; // відмічаємо її як таку, що віввідана
    
    //хід вправо
    if((node+1)%5  !=0 && a[node+1].up && a[node+1].vertex) 
    {
        if (!a[node+1].nodes)
          {
          Queue.push(node+1); 
          a[node+1].nodes = 1;
         } //якщо вершина не виявлена, додаємо в чергу і відмічаємо як виявлену
      
       if (a[node].dist+10 < a[node+1].dist) 
       {
         a[node+1].dist = a[node].dist+10;
         a[node+1].pointer = node + 1;
       }
    }
    
    //хід вліво
     if(node%5!=0 && a[node-1].up && a[node-1].vertex) 
    {
        if (!a[node-1].nodes)
          {
          Queue.push(node-1); 
          a[node-1].nodes = 1;
         } //якщо вершина не виявлена, додаємо в чергу і відмічаємо як виявлену
      
       if (a[node].dist+10 < a[node-1].dist) 
       {
         a[node-1].dist = a[node].dist+10;
         a[node-1].pointer = node + 1;
       }
    }
    

     //хід вверх
     if(node>4 && a[node-5].up && a[node-5].vertex) 
    {
        if (!a[node-5].nodes)
          {
          Queue.push(node-5); 
          a[node-5].nodes = 1;
         } //якщо вершина не виявлена, додаємо в чергу і відмічаємо як виявлену
      
       if (a[node].dist+10 < a[node-5].dist) 
       {
         a[node-5].dist = a[node].dist+10;
         a[node-5].pointer = node + 1;
       }
    }
    
     //хід вниз
     if(node<20 && a[node+5].up && a[node+5].vertex) 
    {
        if (!a[node+5].nodes)
          {
          Queue.push(node+5); 
          a[node+5].nodes = 1;
         } //якщо вершина не виявлена, додаємо в чергу і відмічаємо як виявлену
      
       if (a[node].dist+10 < a[node+5].dist) 
       {
         a[node+5].dist = a[node].dist+10;
         a[node+5].pointer = node + 1;
       }
    }
    
    //хід по діагоналі - вверх і вліво
     if(node>4 && node%5!=0 && a[node-6].up  && a[node-6].vertex) 
    {
        if (!a[node-6].nodes)
          {
          Queue.push(node-6); 
          a[node-6].nodes = 1;
         } //якщо вершина не виявлена, додаємо в чергу і відмічаємо як виявлену
      
       if (a[node].dist+14 < a[node-6].dist) 
       {
         a[node-6].dist = a[node].dist+14;
         a[node-6].pointer = node + 1;
        
       }
     }
    
        //хід по діагоналі - вверх і вправо
     if(node>4 && (node+1)%5  !=0 && a[node-4].up && a[node-4].vertex ) 
    {
        if (!a[node-4].nodes)
          {
          Queue.push(node-4); 
          a[node-4].nodes = 1;
         } //якщо вершина не виявлена, додаємо в чергу і відмічаємо як виявлену
      
       if (a[node].dist+14 < a[node-4].dist) 
       {
         a[node-4].dist = a[node].dist+14;
         a[node-4].pointer = node + 1;
        
       }
    }
       
   //хід по діагоналі - вниз і вліво
     if(node<20 && node%5!=0 && a[node+4].up  && a[node+4].vertex) 
    {
        if (!a[node+4].nodes)
          {
          Queue.push(node+4); 
          a[node+4].nodes = 1;
         } //якщо вершина не виявлена, додаємо в чергу і відмічаємо як виявлену
      
       if (a[node].dist+14 < a[node+4].dist) 
       {
         a[node+4].dist = a[node].dist+14;
         a[node+4].pointer = node + 1;
        
       }   
     }
    
       //хід по діагоналі - вниз і вправо
     if(node<20 && (node+1)%5  !=0 && a[node+6].up  && a[node+6].vertex) 
    {
        if (!a[node+6].nodes)
          {
          Queue.push(node+6); 
          a[node+6].nodes = 1;
         } //якщо вершина не виявлена, додаємо в чергу і відмічаємо як виявлену
      
       if (a[node].dist+14 < a[node+6].dist) 
       {
         a[node+6].dist = a[node].dist+14;
         a[node+6].pointer = node + 1;
        
       }   
     }
    
    if(a[end].vertex)
    { 
      cout<<"Error. The path to finish point is blocked.");
      return 0;
    }
    
    

    int tmp = end;
    
    cout<<"Distance - "<<a[end].dist;
    
    while(a[tmp].pointer)
    {
