#ifndef BKHASHTABLE_H
#define BKHASHTABLE_H

#include <iostream>
#include "BKHashEntry.h"
#include <stdexcept>
#include <cmath>
#include "BKHashInterface.h"

namespace BKData
{
  template<class K, class V>
  class BKHashTable: public BKHashInterface<K,V>{
  public:
    BKHashTable(size_t size = 1e8);
    ~BKHashTable();
    V BKGetValue(K key) override;
    void BKPutValue(K key, V value) override;
    K BKHash(K key) override;
    void BKSetSize(const size_t& size) override;
    void BKRemove(K key) override;
  private:
    BKHashEntry<K,V>** fTable;
    size_t fSize;
  };
}
#endif