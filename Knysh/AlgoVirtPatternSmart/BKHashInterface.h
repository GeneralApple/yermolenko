#ifndef BKHASHINTERFACE_H
#define BKHASHINTERFACE_H

namespace BKData
{
  template<class K, class V>
  class BKHashInterface{
  public:
    virtual ~BKHashInterface()
    {}
    virtual V BKGetValue(K key) = 0;
    virtual void BKPutValue(K key, V value) = 0;
    virtual K BKHash(K key) = 0;
    virtual void BKSetSize(const size_t& size) = 0;
    virtual void BKRemove(K key) = 0;
  };
}
#endif