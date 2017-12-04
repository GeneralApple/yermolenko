#include <string>
#include <iostream>
#include <memory>
using namespace std;

// "Product"
class Car
{
public:
        void setBrand(const string& brand)
        {
                m_brand = brand;
        }
        void setModel(const string& model)
        {
                m_model = model;
        }
        void setClass(const string& cclass)
        {
                m_cclass = cclass;
        }
        void open() const
        {
                cout << "My car: " << m_brand << " " << m_model << " " << m_cclass
                     << ". Good choise!" << endl;
        }
private:
        string m_brand;
        string m_model;
        string m_cclass;
};

// "Abstract Builder"
class CarChooser
{
public:
        virtual ~CarChooser() {};

        Car* getCar()
        {
                return m_brand.release();
        }
        void createNewCar()
        {
                m_brand = make_unique<Car>();
        }
        virtual void buildBrand() = 0;
        virtual void buildModel() = 0;
        virtual void buildClass() = 0;
protected:
        unique_ptr<Car> m_brand;
};

//----------------------------------------------------------------

class Mercedes : public CarChooser
{
public:
        virtual ~Mercedes() {};

        virtual void buildBrand()
        {
                m_brand->setBrand("Mercedes-Benz");
        }
        virtual void buildModel()
        {
                m_brand->setModel("Coupé");
        }
        virtual void buildClass()
        {
                m_brand->setClass("E-Class");
        }
};

//----------------------------------------------------------------

class Buy
{
public:
        void openCar()
        {
                m_car->getCar()->open();
        }
        void makeCar(CarChooser* pb)
        {
                m_car = pb;
                m_car->createNewCar();
                m_car->buildBrand();
                m_car->buildModel();
                m_car->buildClass();
        }
private:
        CarChooser* m_car;
};

int main()
{
        Buy buy;
        Mercedes merc;

        buy.makeCar(&merc);
        buy.openCar();
        return 0;
}
