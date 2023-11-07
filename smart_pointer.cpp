#include<iostream>
using namespace std;

class SP//smart pointer
{
    private:
    int* data;
    public:
    explicit SP(int *p)//explicit is to avoid implicit conversion
    {
        data=p;
    }
    int& operator *()
    {
        return *data;
    }
    virtual ~SP()
    {
        cout<<"deleted pointed"<<endl;
        delete data;
    }
};

int main()
{
    int a=10;
    int* p=&a;
    cout<<"pointer created"<<endl;
    SP sp=SP(p);
    cout<<*sp<<endl;
    return 0;
}