

template <typename T>
class vector
{
public:
vector(T q)
{
s=1;
capacity=2;
array = new T[2];
array[0]=q;
}
int size()
	{
	return s;
	}
T *array;
T *sarray;
int s;
int capacity ;
void push_back(T a)
{
if (s<capacity)
  {
        array[s]=a;
	s++;
  }
else
  {
	sarray = new T[s+1];
	for (int j=0; j<s; j++)
	{
		sarray[j]=array[j];
	}
	sarray[s]=a;
        
	//delete [] array;
	
	array = sarray;
        
	capacity++;
	s++;
  }
}
};
struct arr
{
int x,y;
};


//template <typename T>

