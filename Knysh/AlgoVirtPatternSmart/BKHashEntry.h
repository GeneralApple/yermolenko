#ifndef BKHASHENTRY_H
#define BKHASHENTRY_H

#include <iostream>

namespace BKData
{
  template<class K, class V>
  class BKHashEntry{
  public:
    BKHashEntry(K key, V value):
    fKey(key),
    fValue(value)
    {}
    virtual ~BKHashEntry()
    {}
    virtual const K& BKGetKey()
    {
      return fKey;
    }
    virtual const V& BKGetValue()
    {
      return fValue;
    }
  private:
    K fKey;
    V fValue;
  };
}
#endif