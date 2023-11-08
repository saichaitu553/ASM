#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
class OBase
{
    public:
    void Print(int m_test)
    {
        cout<<"Non-static member function"<<m_test<<endl;
    }
    void operator ()(int m_test)
    {
        cout<<"functor(function object)"<<m_test<<endl;
    }
};

void Fun(int m_test)
{
    cout<<"function pointer"<<m_test<<endl;
}

mutex mutex0;
int globalVar=0;
void adm(int m_test)
{//try_lock(m1,m2....mn) it locks all lockable options at the same time like mutex etc.true -1 return else index
 // if one fails all are unlocked
    mutex0.lock();//m.try_lock() locks if free and returns true if busy goes back retuens false and skips
    cout<<"lock by"<<m_test<<endl;
    ++globalVar;
    mutex0.unlock();
}

//timed mutex
timed_mutex mutex1;
void i(int x)
{
    if(mutex1.try_lock_for(chrono::seconds(1)))
    {
        ++globalVar;
        mutex1.unlock();
        cout<<x<<"entered"<<endl;
    }
    else
    {
        cout<<x<<"not entered"<<endl;
    }
}

int main()
{
    OBase base1;
    auto lamda=[](int x)
    {
        cout<<"lamda function"<<x<<endl;
    };

    thread thread1(Fun, 1);
    thread thread2((OBase()),3);
    thread thread3(&OBase::Print,&base1,4);
    thread thread4(lamda,2);
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    thread thread5(adm,5);
    thread thread6(adm,6);
    thread5.join();
    thread6.join();
    cout<<globalVar<<endl;

    thread thread7(i,7);
    thread thread8(i,8);
    thread7.join();
    thread8.join();
    cout<<globalVar<<endl;

    return 0;
}
