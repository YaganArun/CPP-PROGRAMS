#include <iostream>
using namespace std;
#define SIZE 500

// Arr Impl.
int TOP = -1;
int arr[SIZE];

bool push(int data)
{
    if (TOP == SIZE - 1)
    {
        cout << "ERROR: OVER FLOW" << endl;
        return false;
    }
    TOP++;
    arr[TOP] = data;
    return true;
}

bool pop()
{
    if (TOP == -1)
    {
        cout << "ERROR: UNDER FLOW" << endl;
        return false;
    }
    TOP--;
    return true;
}

int peek()
{
    return arr[TOP];
}

void traverse()
{
    for (int it = 0; it <= TOP; it++)
        cout << "[" << arr[it] << "]   ";
    cout << endl;
}

// Linked List Impl.
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

class Stack
{
private:
    Node *TOP;

public:
    Stack();
    ~Stack();
    void push(int); // Complexity :=> O(1)
    void pop();     // Complexity :=> O(1)
    void peek();    // Complexity :=> O(1)
};

Stack::Stack(/* args */)
{
    this->TOP = NULL;
}

Stack::~Stack()
{
    Node *temp = this->TOP;
    while (temp->next != NULL)
    {
        Node *node_del = temp;
        temp = temp->next;
        delete node_del;
    }
}

void Stack::push(int data)
{
    Node *new_node = new Node(data);
    if (this->TOP == NULL)
    {
        this->TOP = new_node;
        return;
    }
    new_node->next = this->TOP;
    this->TOP = new_node;
    return;
}

void Stack::pop()
{
    Node *current = this->TOP;
    this->TOP = this->TOP->next;
    delete current;
}

void Stack::peek()
{
    cout << " TOP :=> " << this->TOP->data << endl;
}

int main()
{
    // Insertion => Arr Imp
    push(10);
    push(20);
    push(30);
    traverse();
    cout << peek();
    // Deletion => Arr Imp
    pop();
    pop();
    pop();
    traverse();

    Stack s;
    //Insertion => Linked List Impl
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.peek();
    // Deletion => Linked List Impl
    s.pop();
    s.pop();
    s.peek();
    // traverse();
}