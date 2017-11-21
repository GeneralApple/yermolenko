#include <algorithm>  
#include <iostream>  
#include <vector>  
  
using namespace std;  
  
class BKAction  
{  
public:  
    BKAction(const int& scale, const int& shift) :
    fScale(scale),
    fShift(shift)
    {}  
  
    void BKApplyScale(vector<int>& values) 
    {  
      for_each(values.begin(), values.end(), [this] (int & _val)
      {
        _val = fScale * _val;
      });
    }
    void BKApplyShift(vector<int>& values)
    {
      for_each(values.begin(), values.end(), [this] (int & _val)
      {
        _val = fShift + _val;
      });
    }
  
private:  
  int fScale;
  int fShift;
};  
  
int main()  
{  
    vector<int> values;  
    values.push_back(1);  
    values.push_back(2);  
    values.push_back(3);  
    values.push_back(4);  

    BKAction s(2,3);  
    s.BKApplyScale(values); 
    s.BKApplyShift(values);
    for_each(values.begin(), values.end(), [] (int m)
    {
      std::cout << m << std::endl;
    });
}
