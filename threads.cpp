#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
class b
{
    public:
    void p(int x)
    {
        cout<<"Non-static member function"<<x<<endl;
    }
    void operator ()(int x)
    {
        cout<<"functor(function object)"<<x<<endl;
    }
};

void f(int x)
{
    cout<<"function pointer"<<x<<endl;
}

mutex m;
int g=0;
void adm(int x)
{//try_lock(m1,m2....mn) it locks all lockable options at the same time like mutex etc.true -1 return else index
 // if one fails all are unlocked
    m.lock();//m.try_lock() locks if free and returns true if busy goes back retuens false and skips
    cout<<"lock by"<<x<<endl;
    ++g;
    m.unlock();
}

//timed mutex
timed_mutex m1;
void i(int x)
{
    if(m1.try_lock_for(chrono::seconds(1)))
    {
        ++g;
        m1.unlock();
        cout<<x<<"entered"<<endl;
    }
    else
    {
        cout<<x<<"not entered"<<endl;
    }
}

int main()
{
    b b1;
    auto l=[](int x)
    {
        cout<<"lamda function"<<x<<endl;
    };

    thread t1(f, 1);
    thread t2((b()),3);
    thread t3(&b::p,&b1,4);
    thread t4(l,2);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    thread t5(adm,5);
    thread t6(adm,6);
    t5.join();
    t6.join();
    cout<<g<<endl;

    thread t7(i,7);
    thread t8(i,8);
    t7.join();
    t8.join();
    cout<<g<<endl;

    return 0;
}