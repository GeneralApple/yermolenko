#include <iostream>
#define LEPTON

using namespace std;

/**
 * Abstract base product. It should define an interface
 * which will be common to all products. Clients will
 * work with products through this interface, so it
 * should be sufficient to use all products.
 */
class SMFermion {
 public:
  virtual void SMGetParticle() = 0;
};

/**
 * Concrete product family 1.
 */
class SMElectron : public SMFermion {
 public:
  void SMGetParticle() 
  {
    cout << "*****************Electron****************:\n";
    cout << "Mass: 0.51 MeV" << endl << "Charge: -1" << endl << "Spin: 1/2" << endl << "Lepton number: 1" << endl << "Baryon number: 0" 
    << endl << "Color charge: no" << endl;;
  }
};
class SMElectronNeutrino : public SMFermion {
 public:
  void SMGetParticle() 
  { 
    cout << "*****************Electron neutrino****************:\n"; 
    cout << "Mass: 0 MeV" << endl << "Charge: 0" << endl << "Spin: 1/2" << endl << "Lepton number: 1" << endl << "Baryon number: 0"
    << endl << "Color charge: no" << endl;
  }
};
/**
 * Concrete product family 2.
 */
class SMUpQuark : public SMFermion {
 public:
  void SMGetParticle() 
  { 
    cout << "*****************Upper quark****************:\n"; 
    cout << "Mass: 2.3 MeV" << endl << "Charge: +2/3" << endl << "Spin: 1/2" << endl << "Lepton number: 0" << endl << "Baryon number: 1/3"
    << endl << "Color charge: yes" << endl;
  }
};
class SMDownQuark : public SMFermion {
 public:
  void SMGetParticle() 
  { 
    cout << "*****************Down quark****************:\n"; 
    cout << "Mass: 4.8 MeV" << endl << "Charge: -1/3" << endl << "Spin: 1/2" << endl << "Lepton number: 0" << endl << "Baryon number: 1/3"
    << endl << "Color charge: yes" << endl;;
  }
};
/**
 * Abstract SMFactory defines methods to create all
 * related products.
 */
class SMFactory {
 public:
  virtual SMFermion *SMCreateUp() = 0;
  virtual SMFermion *SMCreateDown() = 0;
};

/**
 * Each concrete factory corresponds to one product
 * family. It creates all possible products of
 * one kind.
 */
class SMLeptonFactory : public SMFactory {
 public:
  SMFermion *SMCreateUp() {
    return new SMElectron;
  }
  SMFermion *SMCreateDown() {
    return new SMElectronNeutrino;
  }
};

/**
 * Concrete factory creates concrete products, but
 * returns them as abstract.
 */
class SMQuarksFactory : public SMFactory {
 public:
  SMFermion *SMCreateUp() {
    return new SMUpQuark;
  }
  SMFermion *SMCreateDown() {
    return new SMDownQuark;
  }
};

/**
 * Client receives a factory object from its creator.
 *
 * All clients work with factories through abstract
 * interface. They don't know concrete classes of
 * factories. Because of this, you can interchange
 * concrete factories without breaking clients.
 *
 * Clients don't know the concrete classes of created
 * products either, since abstract factory methods
 * returns abstract products.
 */
class Client {
 private:
  SMFactory *factory;

 public:
  Client(SMFactory *f) {
    factory = f;
  }

  void draw() {
    SMFermion *w = factory->SMCreateUp();
    w->SMGetParticle();
    display_fermion_one();
    display_fermion_two();
  }

  void display_window_one() {
    SMFermion *smf[] = {
        factory->SMCreateUp(),
        factory->SMCreateDown()
    };
    smf[0]->SMGetParticle();
    smf[1]->SMGetParticle();
  }

  void display_window_two() {
    SMFermion *smf[] = {
        factory->SMCreateDown(),
        factory->SMCreateUp()
    };
    smf[0]->SMGetParticle();
    smf[1]->SMGetParticle();
  }
};

/**
 * Now the nasty switch statement is needed only once to
 * pick and create a proper factory. Usually that's
 * happening somewhere in program initialization code.
 */
int main() {
  SMFactory *factory;
#ifdef LEPTON
  factory = new SMLeptonFactory;
#else // QUARK
  factory = new SMQuarksFactory;
#endif

  Client *c = new Client(factory);
  c->draw();
}