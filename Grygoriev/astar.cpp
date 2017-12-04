#include "stdafx.h"
#include <iostream>
#include <queue>
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
  
  game a[25];
  
  //for(int i = 0; i<25; i++) a[i].num = i+1;
  
  for(int i = 0; i<25; i++) a[i].x = i%5 + 1;
  for(int i = 0; i<25; i++) a[i].y = i/5 + 1;
  
  for(int i = 0; i<25; i++) a[i].up = 1;
  for(int i = 0; i<25; i++) a[i].vertex = 0;
  
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
  a[init].vertex = 1;
  
   a[init].dist = 0;
  
  
 
 
