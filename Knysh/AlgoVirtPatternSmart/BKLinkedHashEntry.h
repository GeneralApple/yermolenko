#ifndef BKLINKEDHASHENTRY_H
#define BKLINKEDHASHENTRY_H

#include "BKHashEntry.h"

namespace BKData
{
  template<class K, class V>
  class BKLinkedHashEntry: public BKHashEntry<K,V>{
  public:
    BKLinkedHashEntry(K key, V value): BKHashEntry<K,V>(key,value),
    fKey(key),
    fValue(value),
    fNext(NULL)
    {}
    ~BKLinkedHashEntry()
    {}
    void BKSetValue(V value)
    {
      fValue = value;
    }
    BKLinkedHashEntry* BKGetNext()
    {
      return fNext;
    }
    void BKSetNext(BKLinkedHashEntry* next)
    {
      fNext = next;
    }
  private:
    K fKey;
    V fValue;
    BKLinkedHashEntry* fNext;
  };
}
#endif