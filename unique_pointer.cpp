#include<iostream>
#include<memory>
using namespace std;

class UP
{
    private:
    int x;
    public:
    explicit UP(int x): x{x} {};//creating member variables this.x=x;
    int getx()
    {
        return x;
    }
};
int main()
{
    unique_ptr<UP> up=make_unique<UP>(20);// thi s function helps in error handling
    //unique_ptr<UP> up2{up}; //copy constructor id deleted
    unique_ptr<UP> up1=make_unique<UP>(100);
    cout<< up->getx() << up1->getx() <<endl;
    unique_ptr<UP> up2{move(up1)};//or up1.release() to delete in up1 and move to up2 or reset() where up1 
    //pointer it self is deleted
    cout<< up2->getx()<<endl;//printing up1 gives error;
    return 0;
}