#ifndef BKLINKEDHASHTABLE_H
#define BKLINKEDHASHTABLE_H

#include <iostream>
#include "BKLinkedHashEntry.h"
#include "BKHashInterface.h"
#include <stdexcept>
#include <cmath>

namespace BKData
{
  template<class K, class V>
  class BKLinkedHashTable: public BKHashInterface<K,V>{
  public:
    BKLinkedHashTable(size_t size = 1e8);
    ~BKLinkedHashTable();
    V BKGetValue(K key) override;
    void BKPutValue(K key, V value) override;
    K BKHash(K key) override;
    void BKSetSize(const size_t& size) override;
    void BKRemove(K key) override;
  private:
    BKLinkedHashEntry<K,V>** fTable;
    size_t fSize;
  };
}
#endif