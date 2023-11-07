#include<iostream>
using namespace std;

class Final
{
    Final();
    friend class bike;
};
class vehicle
{
    public:
    vehicle()
    {
        cout<<"drive"<<endl;
    }
};
class car : public virtual vehicle//single if no bike
{
    public:
    car()
    {
        cout<<"4 wheels"<<endl;
    }
};
class bike : public vehicle, virtual public Final//hirarchial non derivable class due to Final
{
    public:
    bike()
    {
        cout<<"2 wheels"<<endl;
    }
};
/*class sedan
{
    public:
    sedan()
    {
        cout<<"sedan"<<endl;
    }
};*/
class suv : public virtual car//multilevel
{
    public:
    suv()
    {
        cout<<"7 seater"<<endl;
    }

};
class cross : public virtual car, public virtual suv//multiple -- vehicle not allowd due to ambiguity hence virtual
{
    public:
    cross()
    {
        cout<<"5 seater"<<endl;
    }
};
int main()
{
    vehicle v;
    cout<<endl;
    car c;
    cout<<endl;
    bike b;
    cout<<endl;
    suv s;
    cout<<endl;
    cross cr;
    return 0;
}