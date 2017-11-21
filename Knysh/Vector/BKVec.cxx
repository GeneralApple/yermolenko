#include "BKVec.h"

  template <class T> BKVec<T>::BKVec():
  fSize(0),
  fCapacity(0),
  fArray(NULL)
  {
    std::cout << "BKVec default constructor calling. . ." << std::endl;
  }
  template <class T> BKVec<T>::BKVec(BKVec<T>& v):
  fSize(v.BKSize()),
  fCapacity(fSize)
  {
    std::cout << "BKVec copy constructor calling. . ." << std::endl;
    fArray = new T[fCapacity];
    for(size_t cntr = 0; cntr < fSize; cntr++)
      fArray[cntr] = v[cntr];
  }
  template <class T> BKVec<T>::BKVec(size_t size):
  fSize(size),
  fCapacity(size),
  fArray(new T[fCapacity])
  {
    std::cout << "BKVec allocating constructor calling. . ." << std::endl;
    for(size_t cntr = 0; cntr < fSize; cntr++)
      fArray[cntr] = 0;
  }
  template <class T> BKVec<T>::~BKVec()
  {
    if(fArray)
      delete [] fArray;
    std::cout << "BKVec destructor calling. . ." << std::endl;
  }
  template <class T>
  void BKVec<T>::BKDeepCopy(const BKVec& v)
  {
    fSize = fCapacity = v.BKSize();
    fArray = (fCapacity == 0)?NULL:new T[fCapacity];
    for(size_t cntr = 0; cntr < fSize; cntr++)
      fArray[cntr] = v[cntr];
  }
  
  template <class T>
  void BKVec<T>::BKReserve()
  {
      fCapacity = std::max(1,int(2*fCapacity));
      T* tempArray = new T[fCapacity];
      for(size_t cntr = 0; cntr < fSize; cntr++)
        tempArray[cntr] = fArray[cntr];
      if(fArray != NULL)
        delete [] fArray;
      
      fArray = tempArray;
  }
  
  template <class T>
  void BKVec<T>::BKPushBack(T const& v)
  {
    if(fSize+1 > fCapacity)
      BKReserve();
    fArray[fSize] = v;
    fSize++;
  }
  template <class T>
  void BKVec<T>::BKClear()
  {
    for(size_t cntr = 0; cntr < fSize; cntr++)
      fArray[cntr] = 0;
    fSize = 0;
  }
  template <class T>
  T& BKVec<T>::operator[](size_t idx) const
  {
    if(idx < 0 || idx > fSize)
      throw std::out_of_range{ "Given element is out of vector's range!" };
    return fArray[idx];
  }
  
  template <class T>
  BKVec<T>& BKVec<T>::operator=(const BKVec<T>& v)
  {
    if(this != &v)
    {
      if(fArray != NULL)
        delete[] fArray;
      BKDeepCopy(v);
    }
    return *this;
  }
  
  template class BKVec<int>;
  template class BKVec<double>;
  template class BKVec<float>;
  template class BKVec<char>;
//   template class BKVec<BKVec<int> >;