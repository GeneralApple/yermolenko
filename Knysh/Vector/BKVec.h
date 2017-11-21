//!This class provides efficient, safe and convenient usage of arrays in C++
#ifndef BKVEC_H
#define BKVEC_H

#include <iostream>
#include <stdexcept>

/*!
  Class: BKVec<T>
  ____________________________________
  This class keeps an ordered list of values. It supports
  array selection ("[]"), but also supports inserting elements to the end.
  \author Borys Knysh
  
  \version Revision: 1.0
  
  \date 2017/10/28
  
  Contact: borys.knysh@gmail.com
  */


template <class T>
  class BKVec{
  public:
    //! Default constructor: BKVec()
     /*! Usage: 
         BKVec<T> bkVec
         Initializes a new vector. The default constructor creates an empty vector.
     */
    BKVec();
   //! Constructor: BKVec(size_t)
   /*! Usage: BKVec<T> bkVec(size);
      Initializes a new vector. Creates array with given size of elements, which are initialized to zero.
   */
    BKVec(size_t size);
    //! Copy constructor: BKVec(const BKVec& )
    /*! Usage: 
        BKVec<T> bkVec(bkVec2);
        Initializes a new vector. Creates the new vector from old one by assigning it size, capacity and values.
     */
    BKVec(const BKVec& v);
    /**
     * Virtual destructor: ~BKVec()
     * Frees any heap storage allocated by this vector.
     */
    virtual ~BKVec();
    /**
     * Method: BKSize
     * Usage: int nEl = (int)bkVec.BKSize();
     * ________________________________________
     * Returns number of elements in this vector.
     */
    size_t BKSize() const
    {
      return fSize;
    }
    
    
    /**
     * Method: BKPushBack
     * Usage: bkVec.BKPushBack(val);
     * ________________________________________
     * Adds element to the end of the vector. 
     */
    
    void BKPushBack(T const& v);
    
    
    
    /**
     * Metod: operator[]
     * Usage: bkVec[i] = 1;
     * Overloads operator [], which is used to access vector elements.
     */
    T& operator[](size_t idx) const;
    
    /**
     * Method: operator=
     * Usage: bkVec2 = bkVec1;
     * This method is used for assigning one vector to another.
     */
    
    
    BKVec& operator=(const BKVec& v);
    
    /**
     * Method: BKClear
     * Usage: bkVec.BKClear();
     * This method is used for clearing vector.
     */
    void BKClear();
    
  private:
    
    /**
     * Method: BKDeepCopy
     * Usage: BKDeepCopy(bkVec);
     * This private method is designed for replacing old vector on new vector.
     */
    void BKDeepCopy(const BKVec& v);
    
    //! Method for allocation memory BKReserve
    /*!
      Usage: if(fSize == fCapacity)
      BKReserve();
      This method allocates more memory for vector, if vector size reaches capacity level or 
      vector is empty, while new elements are added, increases vector's capacity by chosing maximum value 
      between 0 and double previous capacity.
     */
    void BKReserve();
    
    /**
     * Instance variables
     */
    
    //! Size of the vector
    /*!
      This member class variable contains number of effectivly used parts of memory by user. Note: size value SHOULD be less or equal,
      than capacity value.
    */
    size_t fSize;
    //! Available capacity
    /*!
      This member class varible contains number of allocated parts of memory for the given vector.
    */
    size_t fCapacity;
    //! Pointer to the basic data types
    /*!
      This member class variable corresponds for keeping data in the ``vector'', could be any basic data types. 
    */
    T* fArray;
  };
  template <class T> BKVec<T>::BKVec():
  fSize(0),
  fCapacity(0),
  fArray(NULL)
  {
    std::cout << "BKVec default constructor calling. . ." << std::endl;
  }
  template <class T> BKVec<T>::BKVec(const BKVec<T>& v):
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
  void BKVec<T>::BKDeepCopy(const BKVec& v) /*!< vector of basic data-type variables */
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
  void BKVec<T>::BKPushBack(T const& v) /*!< value of basic data type*/
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
    fSize = fCapacity = 0;
  }
  template <class T>
  T& BKVec<T>::operator[](size_t idx) /*!< index of element position in the vector */ const
  {
    if(idx < 0 || idx > fSize)
      throw std::out_of_range{ "Given element is out of vector's range!" };
    return fArray[idx];
  }
  
  template <class T>
  BKVec<T>& BKVec<T>::operator=(const BKVec<T>& v) /*!< vector of basic data-type variables */
  {
    if(this != &v)
    {
      if(fArray != NULL)
        delete[] fArray;
      BKDeepCopy(v);
    }
    return *this;
  }
#endif