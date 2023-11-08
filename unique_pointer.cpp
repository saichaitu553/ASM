#include<iostream>
#include<memory>
using namespace std;

class OUniquePtr
{
    private:
    int m_test;
    public:
    explicit OUniquePtr(int m_test): m_test{m_test} {};//creating member variables this.x=x;
    int getTest()
    {
        return m_test;
    }
};
int main()
{
    unique_ptr<OUniquePtr> uniquePtr=make_unique<OUniquePtr>(20);// this function helps in error handling
    //unique_ptr<UP> up2{up}; //copy constructor id deleted
    unique_ptr<OUniquePtr> uniquePtr1=make_unique<OUniquePtr>(100);
    cout<< uniquePtr->getTest() << uniquePtr1->getTest() <<endl;
    unique_ptr<OUniquePtr> uniquePtr2{move(uniquePtr1)};//or up1.release() to delete in up1 and move to up2 or reset() where up1 
    //pointer it self is deleted
    cout<< uniquePtr2->getTest()<<endl;//printing up1 gives error;
    return 0;
}
