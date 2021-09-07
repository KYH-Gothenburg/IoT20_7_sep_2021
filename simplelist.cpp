#include <iostream>
using namespace std;

class Node
{
public:
    Node();
    Node(int data);
    ~Node();

    int getData();
    void setData(int data);
    Node* getNext();
    void setNext(Node *next);
private:
    int data_;
    Node *next_;
};

Node::Node(): data_(0), next_(nullptr) {}

Node::Node(int data): data_(data), next_(nullptr) {}

int Node::getData()
{
    return data_;
}

void Node::setData(int data)
{
    data_ = data;
}

Node* Node::getNext()
{
    return next_;
}

void Node::setNext(Node *next)
{
    next_ = next;
}

Node::~Node()
{
    cout << "Deleting node with data " << data_ << endl;
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;

    head = new Node(3);
    tail = head;

    tail->setNext(new Node(4));
    tail = tail->getNext();

    tail->setNext(new Node(5));
    tail = tail->getNext();

    tail->setNext(new Node(6));
    tail = tail->getNext();

    Node *current = head;
    while (current)
    {
        cout << current->getData() << ", ";
        current = current->getNext();
    }
    cout << endl;

    // pop head

    // Delete all nodes

    while(head)
    {
        current = head->getNext();
        delete head;
        head = current;
    }
    return 0;
}
