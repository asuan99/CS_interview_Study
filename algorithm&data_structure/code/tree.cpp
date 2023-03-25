#include <iostream>
#include <cstring>

using namespace std;

typedef struct Node
{
    int value;
    struct Node * right_child;
    struct Node * left_child;
}Node;


class Tree
{
    public:
        Tree()
        {
            root = NULL;
        }
        ~Tree(){}

        void insert(int value)
        {
            Node * item = new Node{value,NULL,NULL};
            return insert(item, root);
        }

        void print(const char* method = "inorder")
        {
            if(strcmp(method,"inorder")==0)
            {
                return inorder(root);
            }
            else if(strcmp(method, "preorder")==0)
            {
                return preorder(root);
            }
            else if(strcmp(method,"postorder")==0)
            {
                return postorder(root);
            }
            else
            {
                cout<< "Invalid argument"<<endl;
            }
        }
    private:
        Node * root;

        void insert(Node * item, Node *&target)
        {
            if(target==NULL)
            {
                target = item;
                return;
            }
            if(item->value>=target->value)
            {
                if(target->right_child==NULL)
                {
                    target->right_child=item;
                    return;
                }
                return insert(item, target->right_child);
            }
            else
            {
                if(target->left_child==NULL)
                {
                    target->left_child=item;
                    return;
                }
                return insert(item, target->left_child);
            }
        }

        void inorder(Node * target)
        {
            if(target!=NULL)
            {
                inorder(target->left_child);
                cout<<target->value<<" ";
                inorder(target->right_child);
            }
            return;
        }
        
        void preorder(Node* target)
        {
            if(target!=NULL)
            {
                cout<<target->value<<" ";
                preorder(target->left_child);
                preorder(target->right_child);
            }
            return;
        }

        void postorder(Node* target)
        {
            if(target!=NULL)
            {
                postorder(target->left_child);
                postorder(target->right_child);
                cout<<target->value<<" ";
            }
            return;
        }
};


int main()
{
    Tree tree = Tree();

    for(int i=0; i<10;i++)
    {
        if(i%3==0)
            tree.insert(10-i);
        else
            tree.insert(i);
    }
    /*
    삽입 순서
    10, 1, 2, 7, 4, 5, 4, 7, 8, 1
    */

    tree.print("inorder");

    /*
    inorder (왼쪽 자기자신 오른쪽)
    1, 1, 2, 4, 4, 5, 7, 7, 8, 10

    preorder (자기자신 왼쪽 오른쪽)
    10, 1, 2, 1, 7, 4, 5, 4, 7, 8

    postorder (왼쪽 오른쪽 자기자신)
    1, 4, 5, 4, 8, 7, 7, 2, 1, 10
    */
}