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

class CircularLinkedList
{
private:
    Node *HEAD, *TAIL;

public:
    CircularLinkedList();
    ~CircularLinkedList();
    void push_back(int);         // Complexity :=> O(1)
    void push_front(int);        // Complexity :=> O(1)
    void push_between(int, int); // Complexity :=> O(n)
    void pop_back();             // Complexity :=> O(n-1) = O(n)
    void pop_front();            // Complexity :=> O(1)
    void pop_at(int);            // Complexity :=> O(n)
    void traverse();             // Complexity :=> O(n)
};

CircularLinkedList::CircularLinkedList()
{
    this->HEAD = NULL;
    this->TAIL = NULL;
}

CircularLinkedList::~CircularLinkedList()
{
    Node *temp = this->HEAD;
    while (temp->next != this->TAIL)
    {
        Node *current = temp;
        temp = temp->next;
        delete current;
    }
    delete temp;
}

void CircularLinkedList::push_back(int data)
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
    this->TAIL->next = this->HEAD;
}

void CircularLinkedList::push_front(int data)
{
    Node *new_node = new Node(data);
    if (this->HEAD == NULL)
    {
        this->HEAD = new_node;
        this->TAIL = new_node;
        return;
    }
    new_node->next = this->HEAD;
    this->HEAD = new_node;
    this->TAIL->next = this->HEAD;
}

void CircularLinkedList::push_between(int data, int pos)
{
    Node *temp = this->HEAD;
    Node *pre_ptr;
    while (pos--)
    {
        pre_ptr = temp;
        temp = temp->next;
    }
    pre_ptr->next = pre_ptr->next->next;
    delete temp;
}

void CircularLinkedList::pop_back()
{
    Node *temp = this->HEAD;
    while (temp->next != this->TAIL)
        temp = temp->next;
    // this->TAIL = temp;
    // delete temp->next; // BAD PRACTICE
    // this->TAIL = this->HEAD;

    Node *node_del = temp->next;
    this->TAIL = temp;
    this->TAIL->next = this->HEAD;
    delete node_del;
}

void CircularLinkedList::pop_front()
{
    Node *node_del = this->HEAD;
    this->HEAD = this->HEAD->next;
    delete node_del;
}

void CircularLinkedList::pop_at(int pos)
{
    Node *temp = this->HEAD;
    Node *pre_ptr;
    while (pos--)
    {
        pre_ptr = temp;
        temp = temp->next;
    }
    pre_ptr->next = pre_ptr->next->next;
    delete temp;
}

void CircularLinkedList::traverse()
{
    Node *temp = this->HEAD;
    while (temp != this->TAIL)
    {
        cout << "[" << temp->data << "]--->";
        temp = temp->next;
    }
    cout << "[" << temp->data << "]" << endl;
}

int main()
{
    CircularLinkedList LIST;

    // Insertion
    LIST.push_back(10);
    LIST.push_back(20);
    LIST.push_back(2000);
    LIST.push_front(400);
    LIST.push_front(500);
    LIST.push_back(800);
    LIST.traverse();

    // Deletion
    LIST.pop_back();
    LIST.pop_back();
    LIST.pop_front();
    LIST.pop_at(1);
    LIST.traverse();
}