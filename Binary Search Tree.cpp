#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    Node (string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public:
    Node* ROOT;
    BinaryTree()
    {
        ROOT = nullptr;
    }

    void insert(string element)
    {
        Node* newNode = new Node(element, nullptr, nullptr);
        newNode->info = element;
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode);
        
        if (parent == nullptr)
        {
            ROOT = newNode;
            return;
        }

        if (element < parent->info)
        {
            parent->leftchild = newNode;
        }

        else if (element > parent->info)
        {
            parent->rightchild = newNode;
        }
    }

    void search (string element, Node*& parent, Node*& currentNode)
    {
        currentNode = ROOT;
        parent = NULL;
        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder (Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }
};



int main() {

}