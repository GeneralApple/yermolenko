#include "BKLinkedHashTable.h"

namespace BKData{
  template<class K,class V>
  BKLinkedHashTable<K,V>::BKLinkedHashTable(size_t size): BKHashInterface<K,V>(),
  fSize(size)
  {
    std::cout << "BKLinkedHashTable constructor calling. . ." << std::endl;
    if(fSize <= 0)
      fSize = 100;
    fTable = new BKLinkedHashEntry<K,V>*[fSize];
    for(size_t cntr = 0; cntr < fSize; cntr++)
      fTable[cntr] = NULL;
  }
  template<class K,class V>
  BKLinkedHashTable<K,V>::~BKLinkedHashTable()
  {
    std::cout << "BKLinkedHashTable destructor calling. . ." << std::endl;
    if(fTable)
    {
      for(size_t cntr = 0; cntr < fSize; cntr++)
        if(fTable[cntr] != NULL)
        {
          BKLinkedHashEntry<K,V> * prev = NULL;
          BKLinkedHashEntry<K,V> * entry = fTable[cntr];
          while(entry != NULL)
          {
            prev = entry;
            entry = entry->BKGetNext();
            delete prev;
          }
        }
    }
    delete [] fTable;
  }
  template<class K,class V>
  void BKLinkedHashTable<K,V>::BKSetSize(const size_t& size)
  {
    fSize = size;
  }
  template<class K,class V>
  K BKLinkedHashTable<K,V>::BKHash(K key)
  {
    return (key)%(fSize);
  }
  template<class K,class V>
  void BKLinkedHashTable<K,V>::BKPutValue(K key, V value)
  {
    K hash = BKHash(key);
    if(fTable[hash] == NULL)
      fTable[hash] = new BKLinkedHashEntry<K,V>(key, value);
    else
    {
      BKLinkedHashEntry<K,V>* linkedHE = fTable[hash];
      while(linkedHE->BKGetNext() != NULL)
        linkedHE = linkedHE->BKGetNext();
      if(linkedHE->BKGetKey() == key)
        linkedHE->BKSetValue(value);
      else 
        linkedHE->BKSetNext(new BKLinkedHashEntry<K,V>(key, value));
    }
  }
  template<class K,class V>
  V BKLinkedHashTable<K,V>::BKGetValue(K key)
  {
    K hash = BKHash(key);
    if(fTable[hash] == NULL)
      return -1;
    else
    {
      BKLinkedHashEntry<K,V>* linkedHE = fTable[hash];
      while(linkedHE != NULL && linkedHE->BKGetKey() != key)
        linkedHE = linkedHE->BKGetNext();
      if(linkedHE == NULL)
        return -1;
      else 
        return linkedHE->BKGetValue();
    }
  }
  template<class K,class V>
  void BKLinkedHashTable<K,V>::BKRemove(K key)
  {
    K hash = BKHash(key);
    if(fTable[hash] != NULL)
    {
      BKLinkedHashEntry<K,V>* prev = NULL;
      BKLinkedHashEntry<K,V>* entry = fTable[hash];
      while(entry->BKGetNext() != NULL && entry->BKGetKey() != key)
      {
        prev = entry;
        entry = entry->BKGetNext();
      }
      if(prev == NULL)
      {
        BKLinkedHashEntry<K,V>* next = entry->BKGetNext();
        delete entry;
        fTable[hash] = next;
      }
      else
      {
        BKLinkedHashEntry<K,V>* next = entry->BKGetNext();
        delete entry;
        prev->BKSetNext(next);
      }
    }
  }
  template class BKLinkedHashTable<int, int>;
}