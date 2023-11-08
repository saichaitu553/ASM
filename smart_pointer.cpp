#include<iostream>
using namespace std;

class OSmartPtr//smart pointer
{
    private:
    int* m_data;
    public:
    explicit OSmartPtr(int *m_test)//explicit is to avoid implicit conversion
    {
        m_data=m_test;
    }
    int& operator *()
    {
        return *m_data;
    }
    virtual ~OSmartPtr()
    {
        cout<<"deleted pointed"<<endl;
        delete m_data;
    }
};

int main()
{
    int ref=10;
    int* test=&ref;
    cout<<"pointer created"<<endl;
    OSmartPtr smartPtr=OSmartPtr(test);
    cout<<*smartPtr<<endl;
    return 0;
}
