#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int);
};

Node::Node(int data)
{
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
}

class DoublyLinkedList
{
private:
    Node *HEAD;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void push_back(int);    // Complexity O(n)
    void push_front(int);   // Complexity O(1)
    void push_at(int, int); // Complexity O(n)
    void traverse();        // Complexity O(n)
};

DoublyLinkedList::DoublyLinkedList()
{
    this->HEAD = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node *temp = this->HEAD;
    while (temp->next != NULL)
    {
        Node *node_del = temp;
        temp = temp->next;
        delete node_del;
    }
    delete temp;
}

void DoublyLinkedList::push_back(int data)
{
    Node *new_node = new Node(data);
    if (this->HEAD == NULL)
    {
        this->HEAD = new_node;
        return;
    }
    Node *temp = this->HEAD;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

void DoublyLinkedList::push_front(int data)
{
    Node *new_node = new Node(data);
    if (this->HEAD == NULL)
    {
        this->HEAD = new_node;
        return;
    }
    new_node->next = this->HEAD;
    this->HEAD->prev = new_node;
    this->HEAD = new_node;
}

void DoublyLinkedList::push_at(int data, int pos)
{
    Node *new_node = new Node(data);
    Node *temp = this->HEAD;
    while (--pos)
        temp = temp->next;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    new_node->prev = temp;
    temp->next = new_node;
}

void DoublyLinkedList::traverse()
{
    Node *temp = this->HEAD;
    while (temp->next != NULL)
    {
        cout << "[" << temp->data << "]"
             << "--->";
        temp = temp->next;
    }
    cout << "[" << temp->data << "]"
         << "--->[NULL]" << endl;
}
int main()
{
    DoublyLinkedList LIST;
    LIST.push_front(100);
    LIST.push_back(200);
    LIST.push_back(300);
    LIST.push_back(600);
    LIST.push_back(700);
    LIST.push_at(5000, 3);
    LIST.traverse();
}