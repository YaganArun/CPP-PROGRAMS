#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
private:
    Node *HEAD;

public:
    LinkedList();
    ~LinkedList();

    void push_back(int);         // Complexity for Insertion at the end :=> O(n)
    void push_front(int);        // Complexity for Insertion at beginning :=> O(1)
    void push_between(int, int); // Complexity for insertion in between :=> O(n)
    void traverse();             // Complexity for traversing :=> O(n)
};

LinkedList::LinkedList()
{
    this->HEAD = NULL;
}

LinkedList::~LinkedList()
{
    Node *temp = this->HEAD;
    while (temp->next != NULL)
    {
        Node *current = temp;
        temp = temp->next;
        delete current;
    }
    delete temp;
}

void LinkedList::push_back(int data)
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
    return;
}

void LinkedList::push_front(int data)
{
    Node *new_node = new Node(data);
    if (this->HEAD == NULL)
    {
        this->HEAD = new_node;
        return;
    }
    new_node->next = this->HEAD;
    this->HEAD = new_node;
}

void LinkedList::push_between(int data, int location)
{
    Node *new_node = new Node(data);
    Node *temp = this->HEAD;
    while (location--)
    {
        // if(temp->next == NULL)
        //     break;
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void LinkedList::traverse()
{
    Node *temp = this->HEAD;
    while (temp->next != NULL)
    {
        cout << "[" << temp->data << "]--->";
        temp = temp->next;
    }
    cout << "[" << temp->data << "]--->[NULL]" << endl;
}

int main()
{
    LinkedList LIST;
    LIST.push_back(10);
    LIST.push_back(20);
    LIST.push_back(30);
    LIST.push_back(100);
    LIST.push_front(300);
    LIST.push_between(1020, 3);
    LIST.traverse();
}