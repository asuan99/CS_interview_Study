#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int sum=0;

void partSum(int start, int end)
{
    for(int i =start; i <=end;i++)
    {
            sum+=i;
            //cout<<"partial : "<< sum <<"("<<i<<")"<<endl;
    }
}

int main(){
    auto begin = steady_clock::now();

    partSum(1,100);

    auto end = steady_clock::now();

    cout<<"sum : "<< sum << endl;
    cout<<"runtime : "<<duration_cast<nanoseconds>(end-begin).count()<<"ns"<<endl;
    return 0;
}