#include<iostream>
#include<memory>
using namespace std;

class OSharedPtr
{
    private:
    int m_test;
    public:
    explicit OSharedPtr(int m_test): m_test{m_test} {};//creating member variables this.x=x;
    int getTest()
    {
        return m_test;
    }
};

int main()
{
    shared_ptr<OSharedPtr> sharedPtr(new OSharedPtr(10));
    cout<< sharedPtr->getTest() << " "<<sharedPtr.use_count() <<endl;
    shared_ptr<OSharedPtr> sharedPtr1{sharedPtr};
    cout<< sharedPtr1->getTest() << " " << sharedPtr1.use_count() << " " <<sharedPtr.use_count()<< endl;
    return 0;
}
