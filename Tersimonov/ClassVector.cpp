#include <iostream>
using namespace std;

class MyVector
{
  public:
   MyVector();
   void AddElement(char el); // adding some element
   void Screen();
   void iEl(); // element number i
   void nEl(); // quantity of the elements
  private:
    char * mas; // elements array
    int size;  // how many elementa are in this array
};

/*
 Method AddElement adds some element to the vector
 Method iEl() returns the element number
 Method nEl() returns the total quantity of elements
 */

MyVector:: MyVector()
{
   mas = new char[2];
   size = 0;
}

void MyVector:: AddElement(char el)
{
   mas[size]=el;
   size++;
}

void MyVector:: Screen()
{
   for(int i=0;i<size;i++)
     cout<<"element["<<i+1<<"]: "<<mas[i]<<endl;
}

void MyVector:: iEl()
{
    int i;
     cout<<"element["<<i+1<<"]: "<<mas[i];
}

void MyVector:: nEl()
{
   cout<<"There are "<<size<<" elements in the vector"<<endl;
}

int main(int argc, char* argv[])
{
  MyVector *a = new MyVector();
  //adding the elements
  a->AddElement('h');
  a->AddElement('e');
  a->AddElement('l');
  a->AddElement('l');
  a->AddElement('o');
  // display the output
  a->Screen();
  a->nEl();
  //getch();
  return 0;
}

