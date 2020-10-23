// Find Loop in an Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int);
};
Node::Node(int data)
{
    this->data = data;
    this->next = NULL;
}

class LinkedList
{
public:
    Node *HEAD;
    Node *TAIL;
    LinkedList()
    {
        this->HEAD = NULL;
        this->TAIL = NULL;
    }
    ~LinkedList()
    {
        Node *temp = this->HEAD;
        while (temp->next != this->TAIL->next)
        {
            Node *current = temp;
            temp = temp->next;
            delete current;
        }
        delete temp;
    }
    void push(int);
    void traverse();
    bool checkLoop();
};

void LinkedList::push(int data)
{
    Node *new_node = new Node(data);
    if (this->HEAD == NULL)
    {
        this->HEAD = new_node;
        this->TAIL = new_node;
        return;
    }
    this->TAIL->next = new_node;
    this->TAIL = new_node;
}

void LinkedList::traverse()
{
    Node *temp = this->HEAD;
    while (temp->next != this->TAIL->next)
    {
        cout << "[" << temp->data << "]"
             << "--->";
        temp = temp->next;
    }
    cout << "[" << temp->data << "]";
}

bool LinkedList::checkLoop() // Complexity to find loop :=> O(1)
{
    if (this->TAIL->next != NULL)
        return true;
    else
        return false;
}

int main()
{
    LinkedList LIST;
    LIST.push(10);
    LIST.push(100);
    LIST.push(1000);
    LIST.push(2000);
    //LIST.TAIL->next = LIST.HEAD->next->next;
    //LIST.TAIL->next = NULL;
    if (LIST.checkLoop())
        cout << "LOOP IS PRESENT" << endl;
    else
        cout << "NO LOOP IS PRESENT" << endl;
}