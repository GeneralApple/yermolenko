#include <iostream>

using namespace std;

template <typename T>
class vectar
{
private:
	T *ptr;
	int size;
	int capasity;
public:
	vectar(): size(0), capasity(5)
		{
		ptr = new T[capasity];
		}
	vectar(int razm): size(0), capasity(razm)
		{
		ptr = new T[capasity];
		}
	~vectar()
		{
		delete [] ptr;
		}
	int getsize()
		{
		return size;
		}
	T& operator[] (int num)
		{
		if (num>size) 
			{ 
			cout<< "too much" <<endl; 
			return ptr[0];
			}
		else
			return ptr[num];
		}
	void print ()
		{
		for (int i=0; i < size; ++i)
			{
			(*this)[i].print();
			cout<<" ";
			}
		cout << endl;
		}
	void pushback (T elem)
		{
		if (size<capasity)
			{
			(*this)[size] = elem;
			++size;
			}
		else
			{
			T *copa = new T[capasity+1];
			for (int i=0; i<size; ++i)
				copa[i] = (*this)[i];
			copa[size] = elem;
			delete [] ptr;
			ptr = copa;
//			cout << copa.ptr << " " << ptr << endl;
			++capasity;
			++size;
//			(*this).print();
			}
		}
	
};

class artest
{
private:
	int art;
public:
	artest(): art(12)
	{}
	artest(int a): art(a)
	{}
	~artest()
	{}
	void print()
	{
	cout << art;
	}

};

int main()
{
	artest ara(145);
	vectar<artest> v(2);
	v.pushback(ara);
	cout << "size " << v.getsize() << endl;
	v.pushback(ara);
	v.print();
	v.pushback(ara);
	cout << "size " << v.getsize() << endl;
	v.print();
return 0;
}




