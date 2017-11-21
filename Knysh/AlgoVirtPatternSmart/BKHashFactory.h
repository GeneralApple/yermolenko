#ifndef BKHASHFACTORY_H
#define BKHASHFACTORY_H

#include "BKHashInterface.h"
#include "BKHashTable.h"
#include "BKLinkedHashTable.h"

namespace BKData
{
template<class K, class V>
  class BKHashFactory{
  public:
    static BKHashInterface<K,V>* BKNewHash(const char* str)
    {
       if(strcmp(str,"simple_hash") == 0)
        return new BKHashTable<K,V>();
       else if(strcmp(str,"linked_hash") == 0)
        return new BKLinkedHashTable<K,V>();
       else 
         return NULL;
    }
  };
}
#endif