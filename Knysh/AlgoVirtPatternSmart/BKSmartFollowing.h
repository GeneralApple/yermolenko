#ifndef BKSMARTFOLLOWING_H
#define BKSMARTFOLLOWING_H

namespace BKData{
template <class T>
class BKSmartFollowing {
public:
  BKSmartFollowing();
  BKSmartFollowing(const BKSmartFollowing<T>&);
  ~BKSmartFollowing();
  T* operator->() const;
  BKSmartFollowing<T>& operator=(const BKSmartFollowing<T>&);
private:
  T* fT;
};
template <class T>
BKSmartFollowing<T>::BKSmartFollowing()
{
  fT = new T();
}
template <class T>
inline BKSmartFollowing<T>::BKSmartFollowing(const BKSmartFollowing<T>& mp) : fT(new T(*(mp.fT)))
{}
template <class T>
inline BKSmartFollowing<T>& BKSmartFollowing<T>::operator=(const BKSmartFollowing<T>& mp)
{
  if (this != &mp)
  {
    delete fT;
    fT = new T(*(mp.fT));
  }
  return *this;
}
template <class T>
BKSmartFollowing<T>::~BKSmartFollowing()
{
  delete fT;
}
template <class T>
inline T* BKSmartFollowing<T>::operator->() const
{
  return fT;
}
#endif
}