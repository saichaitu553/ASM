#include<iostream>
using namespace std;

class Final
{
    Final();
    friend class OBike; 
};
class OVehicle
{
    public:
    OVehicle()
    {
        cout<<"drive"<<endl;
    }
};
class OCar : public virtual OVehicle//single if no OBike
{
    public:
    OCar()
    {
        cout<<"4 wheels"<<endl;
    }
};
class OBike : public OVehicle, virtual public Final//hirarchial non derivable class due to Final
{
    public:
    OBike()
    {
        cout<<"2 wheels"<<endl;
    }
};
/*class OSedan
{
    public:
    OSedan()
    {
        cout<<"sedan"<<endl;
    }
};*/
class OSuv : public virtual OCar//multilevel
{
    public:
    OSuv()
    {
        cout<<"7 seater"<<endl;
    }

};
class OCross : public virtual OCar, public virtual OSuv//multiple -- vehicle not allowd due to ambiguity hence virtual
{
    public:
    OCross()
    {
        cout<<"5 seater"<<endl;
    }
};
int main()
{
    OVehicle vehicle;
    cout<<endl;
    OCar car;
    cout<<endl;
    OBike bike;
    cout<<endl;
    OSuv suv;
    cout<<endl;
    OCross cross;
    return 0;
}
