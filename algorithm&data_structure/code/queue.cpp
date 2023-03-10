#include <iostream>

using namespace std;

class Queue
{
    public:
        Queue()
        {
            size = 10;
            front = -1;
            rear = -1;
            array = new int(size);
        }
        Queue(int num)
        {
            size = num;
            front = -1;
            rear = -1;
            array = new int(size);
        }
        ~Queue(){}

        void enqueue(int num)
        {
            if(isFull())    return;
            array[++rear]=num;
        }

        int dequeue()
        {
            if(isEmpty())   return -99999999;
            return array[++front];
        }

        void print()
        {
            cout<<"current state"<<endl;
            isEmpty();
            for(int i = front+1; i <= rear;i++)
                cout<<array[i]<<" ";
            cout<<"\n"<<endl;
        }

        bool isEmpty()
        {
            if(front==rear)
            {
                cout<<"Stack is Empty"<<endl; 
                return true;
            }
            return false;
        }

        bool isFull()
        {
            if(rear==size-1)
            {   
                refresh();
                if(rear==size-1)
                {
                    cout<<"Stack is Full"<<endl;
                    return true;
                }
            }
            return false;
        }

    
    private:
        int * array;
        int size;
        int front;
        int rear;

        void refresh() // 큐의 특성상 계속해서 front와 rear를 뒤로 밀어내기 때문에 공간이 부족해짐
        {
            int count = rear - front;

            for(int i=0;i<count;i++)
                array[i] = array[front+i+1];

            front = -1;
            rear = count-1;
        }
};

int main()
{
    Queue queue = Queue();

    for(int i =0;i<5;i++)
        queue.enqueue(i);

    queue.print();

    for(int i =0;i<5;i++)
        cout<<queue.dequeue()<<" ";
    cout<<endl;

    queue.print();

    for(int i =10;i<21;i++)
        queue.enqueue(i);

    queue.print();

    for(int i=0;i<5;i++)
        cout<<queue.dequeue()<<" ";
    cout<<endl;
    queue.print();

    for(int i=20;i<25;i++)
        queue.enqueue(i);
    queue.print();
    
}