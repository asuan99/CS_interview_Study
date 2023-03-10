#include <iostream>

using namespace std;

class Stack
{
    public:
        Stack()
        {
           size=10;
           top=-1;
           array= new int(size);
        }
        Stack(int num)
        {
            size=num;
            top=-1;
            array = new int(size);
        }
        ~Stack(){}

        void push(int num)
        {
            if(isFull()){
                cout<<"Stack is Full"<<endl;
                return;
            }
            array[++top] = num;
        }

        int pop()
        {
            if(isEmpty())
            {
                cout<<"Stack is Empty"<<endl;
                return -99999999;
            }
            return array[top--];
        }

        bool isEmpty()
        {
            if(top==-1) return true;
            return false;
        }

        bool isFull() // top이 가리키고 있는 위치는 stack이 가지고 있는 개수 - 1
        {
            if(top==size-1) return true; // top이 size-1이면 stack이 총 size만큼의 원소를 가짐  
            return false;
        }

        void print() // 먼저 표시되는 게 위에 있는 원소
        {
            for(int i = top; i!=-1;i--)
                cout<<array[i]<<" ";

            cout<<endl;
        }

    private:
        int top;
        int size;
        int *array;
};


int main()
{
    Stack first = Stack();
    Stack second = Stack(5);

    second.pop();

    for(int i=0;i<10;i++)
    {
        first.push(i);
        second.push(i);
    }

    cout<<"First : ";
    first.print();
    cout<<endl;
    cout<<"Second : ";
    second.print();

    cout<<second.pop()<<endl;

}