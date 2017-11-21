/** Implementation of Prototype Method **/
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include <string>
#include <cassert>
using namespace std;


class CPrototypeMonster
 {
 protected:            
     string           _name;
 public:
     CPrototypeMonster();
     CPrototypeMonster( const CPrototypeMonster& copy );
     virtual ~CPrototypeMonster();
 
     virtual CPrototypeMonster*    Clone() const=0; // This forces every derived class to provide an overload for this function.
     void        Name( string name );
     string    Name() const;
 };

 class CGreenMonster : public CPrototypeMonster
 {
 protected: 
     int         _numberOfArms;
     double      _slimeAvailable;
 public:
     CGreenMonster();
     CGreenMonster( const CGreenMonster& copy );
     ~CGreenMonster();
 
     virtual CPrototypeMonster*    Clone() const
     {
     return new CGreenMonster(*this);
 }
     void  NumberOfArms( int numberOfArms );
     void  SlimeAvailable( double slimeAvailable );
 
     int         NumberOfArms() const;
     double      SlimeAvailable() const;
 };

 class CPurpleMonster : public CPrototypeMonster
 {
 protected:
     int         _intensityOfBadBreath;
     double      _lengthOfWhiplikeAntenna;
 public:
     CPurpleMonster();
     CPurpleMonster( const CPurpleMonster& copy );
     
     ~CPurpleMonster();
 
     virtual CPrototypeMonster*    Clone() const
     {
     return new CPurpleMonster(*this);
 }
 
     void  IntensityOfBadBreath( int intensityOfBadBreath );
     void  LengthOfWhiplikeAntenna( double lengthOfWhiplikeAntenna );
 
     int       IntensityOfBadBreath() const;
     double    LengthOfWhiplikeAntenna() const;
 };

 class CBellyMonster : public CPrototypeMonster
 {
 protected:
     double      _roomAvailableInBelly;
 public:
     CBellyMonster();
     CBellyMonster( const CBellyMonster& copy );
     ~CBellyMonster();
 
     virtual CPrototypeMonster*    Clone() const
     {
     return new CBellyMonster(*this);
 }
 
     void       RoomAvailableInBelly( double roomAvailableInBelly );
     double     RoomAvailableInBelly() const;
 };
 
  void DoSomeStuffWithAMonster( const CPrototypeMonster* originalMonster )
 {
     CPrototypeMonster* newMonster = originalMonster->Clone();
     assert( newMonster );
 
     newMonster->Name("MyOwnMonster");
     // Add code doing all sorts of cool stuff with the monster.
     delete newMonster;
 }
 
 
 int main()
 {
   CPurpleMonster* pr = new CPurpleMonster();
   DoSomeStuffWithAMonster(pr);
 }