#include "stdafx.h"
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Phone
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
                cout << "My phone: " << m_brand << " " << m_model << " " << m_cclass << endl;
        }
private:
        string m_brand;
        string m_model;
        string m_cclass;
};

class PhoneChooser
{
public:
        virtual ~PhoneChooser() {};

        Phone* getPhone()
        {
                return m_brand.release();
        }
        void createNewPhone()
        {
                m_brand = make_unique<Phone>();
        }
        virtual void buildBrand() = 0;
        virtual void buildModel() = 0;
        virtual void buildClass() = 0;
protected:
        unique_ptr<Phone> m_brand;
};

class Samsung : public PhoneChooser
{
public:
        virtual ~Samsung() {};

        virtual void buildBrand()
        {
                m_brand->setBrand("Samsung");
        }
        virtual void buildModel()
        {
                m_brand->setModel("Galaxy");
        }
        virtual void buildClass()
        {
                m_brand->setClass("J");
        }
};

class Buy
{
public:
        void openPhone()
        {
                m_phone->getPhone()->open();
        }
        void makePhone(PhoneChooser* pb)
        {
                m_phone = pb;
                m_phone->createNewPhone();
                m_phone->buildBrand();
                m_phone->buildModel();
                m_phone->buildClass();
        }
private:
        PhoneChooser* m_phone;
};

int main()
{
        Buy buy;
        Samsung sams;

        buy.makePhone(&sams);
        buy.openPhone();

		system("pause");

        return 0;
}
