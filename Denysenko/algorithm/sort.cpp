#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> gsort(vector<int> &a)
{
	auto sortingFunc = [a](int i, int j)
	{
		return  i < j;
	};

	sort(a.begin(), a.end(), sortingFunc);
	return a;
}

int main()
{
  vector <int> a = {1, 10, 243, 21, 13, 2, 58, 112, -5, 58, 0};
  gsort(a);

  for(auto i = 0; i < a.size(); ++i)
    cout << a[i] << endl;

  return 0;
}
