#include <iostream>

using namespace std;

typedef struct Node
{
    int number;
    Node* next;
    
}Node;

class LinkedList
{
    public:
        LinkedList()
        {
            start = NULL;
            size=0;
        }
        ~LinkedList(){}

        bool insert(int number)
        {
            Node * item = new Node{number,NULL};
            if(isEmpty())
            {
                start = item;
            }
            else
            {
                Node * ptr = start;
                for(;ptr->next!=NULL;ptr=ptr->next);
                ptr->next = item;
            }
            size++;
            return true;
        }

        void remove(int num)
        {
            Node * ptr = start;
            if(isEmpty())
            {
                cout<<"Empty List can not remove item"<<endl;
            }
            else if(start->number==num)
            {
                Node * temp = start->next;
                delete start;
                start = temp;
                size--;
                return;
            }
            else
            {
                for(;ptr->next->next!=NULL;ptr=ptr->next)
                {
                    if(ptr->next->number==num)
                        break;
                }
                if(ptr->next->number==num)
                    {
                        Node * temp = ptr->next->next;
                        delete (ptr->next);
                        ptr->next = temp;
                        size--;
                    }
            }
        }

        void print()
        {
            for(Node* ptr = start;ptr!=NULL;ptr=ptr->next)
                cout<<ptr->number<<",";
            cout<<endl;
        }

        bool isEmpty()
        {
            if(start==NULL) return true;
            return false;
        }

        int length()
        {
            return size;
        }

    private:
        Node * start;
        int size;
};


int main()
{
    LinkedList list = LinkedList();

    for(int i =0;i<10;i++)
        list.insert(i);

    cout<<list.length()<<endl;;
    list.print();

    list.remove(9);
    list.print();
}