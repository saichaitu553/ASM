#include<iostream>
#include<memory>
using namespace std;

class SP
{
    private:
    int x;
    public:
    explicit SP(int x): x{x} {};//creating member variables this.x=x;
    int getx()
    {
        return x;
    }
};

int main()
{
    shared_ptr<SP> sp(new SP(10));
    cout<< sp->getx() << " "<<sp.use_count() << endl;
    shared_ptr<SP> sp1{sp};
    cout<< sp1->getx() << " " << sp1.use_count() << " " <<sp.use_count()<< endl;
    return 0;
}