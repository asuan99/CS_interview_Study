#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;
int sum = 0;

void partSum(int start, int end)
{
    for(int i =start; i <=end;i++)
    {
            sum+=i;
            //cout<<"partial : "<< sum <<"("<<i<<")"<<endl;
    }
}

int main()
{
    thread thread1(partSum,1,25);
    thread thread2(partSum,26,50);
    thread thread3(partSum,51,75);
    thread thread4(partSum,76,100);

    auto begin = steady_clock::now();
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    auto end = steady_clock::now();
    cout<<"sum : "<< sum << endl;
    cout<<"runtime : "<<duration_cast<nanoseconds>(end-begin).count()<<"ns"<<endl;
    return 0;

}