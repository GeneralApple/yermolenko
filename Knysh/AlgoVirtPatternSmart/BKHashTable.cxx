#include "BKHashTable.h"

namespace BKData{
  template<class K,class V>
  BKHashTable<K,V>::BKHashTable(size_t size): BKHashInterface<K,V>(),
  fSize(size)
  {
    std::cout << "BKHashTable constructor calling. . ." << std::endl;
    if(fSize <= 0)
      fSize = 100;
    fTable = new BKHashEntry<K,V>*[fSize];
    for(size_t cntr = 0; cntr < fSize; cntr++)
      fTable[cntr] = NULL;
  }
  template<class K,class V>
  BKHashTable<K,V>::~BKHashTable()
  {
    std::cout << "BKHashTable destructor calling. . ." << std::endl;
    if(fTable)
    {
      for(size_t cntr = 0; cntr < fSize; cntr++)
        if(fTable[cntr])
          delete fTable[cntr];
      delete [] fTable;
    } 
  }
  template<class K, class V>
  void BKHashTable<K,V>::BKSetSize(const size_t& size)
  {
    fSize = size;
  }
  template<class K, class V>
  K BKHashTable<K,V>::BKHash(K key)
  {
    return (key)%(fSize);
  }
  template<class K, class V>
  void BKHashTable<K,V>::BKPutValue(K key, V value)
  {
    K hash = BKHash(key);
    if(hash < 0 || hash > int(fSize) )
      throw std::out_of_range("hash value is out of range! Chose different hash-function!!");
    while(fTable[hash] != NULL && fTable[hash]->BKGetKey() != key)
      hash = BKHash(hash+1);
    if(fTable[hash] != NULL)
      delete fTable[hash];
    fTable[hash] = new BKHashEntry<K,V>(key, value);
  }
  template<class K, class V>
  V BKHashTable<K,V>::BKGetValue(K key)
  {
    K hash = BKHash(key);
    while(fTable[hash] != NULL && fTable[hash]->BKGetKey() != key)
      hash = BKHash(hash+1);
    if(fTable[hash] == NULL)
      return -1;
    else 
      return fTable[hash]->BKGetValue();
  }
  template<class K, class V>
  void BKHashTable<K,V>::BKRemove(K key)
  {
    K hash = BKHash(key);
    if(fTable[hash] != NULL && fTable[hash]->BKGetKey() == key)
       fTable[hash] = NULL;
  }
  
  template class BKHashTable<int, int>;
}