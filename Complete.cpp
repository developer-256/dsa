#include <iostream>
using namespace std;

// singly node
// class Node
// {
// private:
//     int value;
//     Node *nextNode;

// public:
//     Node() { value = 0, nextNode = nullptr; }
//     Node(int value) { this->value = value, nextNode = nullptr; }
//     void setNextNode(Node *nextNode) { this->nextNode = nextNode; }
//     void setValue(int value) { this->value = value; }
//     int getValue() { return value; }
//     Node *getNextNode() { return nextNode; }
// };

// doubly node
class Node
{
private:
    int value;
    Node *nextNode;
    Node *prevNode;

public:
    Node() { value = 0, nextNode = nullptr, prevNode = nullptr; }
    Node(int value) { this->value = value, nextNode = nullptr, prevNode = nullptr; }
    void setValue(int value) { this->value = value; }
    void setNextNode(Node *nextNode) { this->nextNode = nextNode; }
    void setPrevNode(Node *prevNode) { this->prevNode = prevNode; }
    int getValue() { return value; }
    Node *getNextNode() { return nextNode; }
    Node *getPrevNode() { return prevNode; }
};

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%% ( singly linked list ) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

class SinglyLinkedList
{
private:
    Node *headNode;
    Node *currentNode;
    int size;

public:
    SinglyLinkedList() { headNode = nullptr, currentNode = nullptr, size = 0; }

    void printLinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);
    void insertAfter(int after, int value);
    void insertTwoAfter(int after, int value1, int value2);
    void insertBefore(int before, int value);
    void insertTwoBefore(int before, int value1, int value2);

    void remove(int value);
};

void SinglyLinkedList::printLinkedList()
{
    if (headNode == nullptr)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        currentNode = headNode;
        while (currentNode->getNextNode() != nullptr)
        {
            cout << currentNode->getValue() << " -> ";
            currentNode = currentNode->getNextNode();
        }
        cout << currentNode->getValue() << endl;
    }
}

void SinglyLinkedList::insertAtHead(int value)
{
    Node *newNode = new Node(value);

    if (headNode == nullptr)
    {
        headNode = newNode;
    }
    else
    {
        newNode->setNextNode(headNode);
        headNode = newNode;
    }
    size++;
    cout << value << " successfully added to head" << endl;
}

void SinglyLinkedList::insertAtTail(int value)
{
    Node *newNode = new Node(value);

    if (headNode == nullptr)
    {
        headNode = newNode;
    }
    else
    {
        currentNode = headNode;
        while (currentNode->getNextNode() != nullptr)
        {
            currentNode = currentNode->getNextNode();
        }
        currentNode->setNextNode(newNode);
    }
    size++;
    cout << value << " successfully added at tail\n";
}

void SinglyLinkedList::insertAfter(int after, int value)
{
    Node *newNode = new Node(value);
    currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == after)
        {
            newNode->setNextNode(currentNode->getNextNode());
            currentNode->setNextNode(newNode);
            size++;
            cout << value << " successfully added after " << after << endl;
            return;
        }
        currentNode = currentNode->getNextNode();
    }

    cout << after << " not found in list\n";
}

void SinglyLinkedList::insertTwoAfter(int after, int value1, int value2)
{
    Node *newNode1 = new Node(value1);
    Node *newNode2 = new Node(value2);
    newNode1->setNextNode(newNode2);

    currentNode = headNode;

    while (currentNode->getNextNode() != nullptr)
    {
        if (currentNode->getValue() == after)
        {
            newNode2->setNextNode(currentNode->getNextNode());
            currentNode->setNextNode(newNode1);
            size++;
            cout << value1 << " and " << value2 << " successfully added after: " << after << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }
    cout << after << " not found in the list\n";
}

void SinglyLinkedList::insertBefore(int before, int value)
{
    Node *newNode = new Node(value);
    Node *previous = new Node;

    if (headNode->getValue() == before)
    {
        newNode->setNextNode(headNode);
        headNode = newNode;
        cout << value << " successfully added before " << before << endl;
        size++;
        return;
    }
    else
    {
        previous = headNode;
        currentNode = headNode->getNextNode();
        while (currentNode != nullptr)
        {
            if (currentNode->getValue() == before)
            {
                previous->setNextNode(newNode);
                newNode->setNextNode(currentNode);
                cout << value << " successfully added before " << before << endl;
                size++;
                return;
            }

            previous = currentNode;
            currentNode = currentNode->getNextNode();
        }

        cout << before << " not found in the list" << endl;
    }
}

void SinglyLinkedList::insertTwoBefore(int before, int value1, int value2)
{
}

void SinglyLinkedList::remove(int value)
{
    if (headNode->getValue() == value)
    {
        Node *temp = headNode;
        headNode = headNode->getNextNode();
        delete temp;
        size--;
        cout << value << " successfully removed from the list\n";
        return;
    }

    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getNextNode()->getValue() == value)
        {
            Node *temp = currentNode->getNextNode();
            currentNode->setNextNode(currentNode->getNextNode()->getNextNode());
            delete temp;
            size--;
            cout << value << " successfully removed from the list\n";
            return;
        }

        currentNode = currentNode->getNextNode();
    }
    cout << value << " not found in the list\n";
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%% ( doubly linked list ) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
class DoublyLinkedList
{
private:
    int size;
    Node *headNode;
    Node *currentNode;

public:
    DoublyLinkedList() { size = 0, headNode = nullptr, currentNode = nullptr; }

    void printLinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);
    void insertAfter(int after, int value);
    void insertTwoAfter(int after, int value1, int value2);
    void insertBefore(int before, int value);
    void insertTwoBefore(int before, int value1, int value2);

    void remove(int value);
};

void DoublyLinkedList::printLinkedList()
{
    cout << "Size: " << size << endl;
    if (headNode == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    else
    {
        currentNode = headNode;
        cout << "Start -> ";
        while (currentNode->getNextNode() != nullptr)
        {
            cout << currentNode->getValue() << " -> ";
            currentNode = currentNode->getNextNode();
        }
        cout << currentNode->getValue() << endl;

        while (currentNode->getPrevNode() != nullptr)
        {
            cout << currentNode->getValue() << " -> ";
            currentNode = currentNode->getPrevNode();
        }
        cout << currentNode->getValue() << " -> End" << endl;
    }
}

void DoublyLinkedList::insertAtHead(int value)
{
    Node *newNode = new Node(value);
    if (headNode == nullptr)
    {
        headNode = newNode;
    }
    else
    {
        newNode->setNextNode(headNode);
        headNode->setPrevNode(newNode);
        headNode = newNode;
    }
    size++;
    cout << value << " successfully added at head" << endl;
}

void DoublyLinkedList::insertAtTail(int value)
{
    Node *newNode = new Node(value);
    if (headNode == nullptr)
    {
        headNode = newNode;
    }
    else
    {
        currentNode = headNode;
        while (currentNode->getNextNode() != nullptr)
        {
            currentNode = currentNode->getNextNode();
        }
        currentNode->setNextNode(newNode);
        newNode->setPrevNode(currentNode);
    }
    size++;
    cout << value << " successfully added at Tail" << endl;
}

void DoublyLinkedList::insertAfter(int after, int value)
{
    Node *newNode = new Node(value);

    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == after)
        {
            currentNode->getNextNode()->setPrevNode(newNode);
            newNode->setNextNode(currentNode->getNextNode());

            currentNode->setNextNode(newNode);
            newNode->setPrevNode(currentNode);

            size++;
            cout << value << " successfully added after " << after << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }
    cout << after << " not found in the list" << endl;
}

void DoublyLinkedList::insertTwoAfter(int after, int value1, int value2)
{
    Node *newNode1 = new Node(value1);
    Node *newNode2 = new Node(value2);
    newNode1->setNextNode(newNode2);
    newNode2->setPrevNode(newNode1);

    if (headNode == nullptr)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        currentNode = headNode;

        while (currentNode != nullptr)
        {
            if (currentNode->getValue() == after)
            {
                currentNode->getNextNode()->setPrevNode(newNode2);
                newNode2->setNextNode(currentNode->getNextNode());

                currentNode->setNextNode(newNode1);
                newNode1->setPrevNode(currentNode);

                size += 2;
                cout << value1 << " and " << value2 << " successfully added after: " << after << endl;
                return;
            }

            currentNode = currentNode->getNextNode();
        }

        cout << after << " not found in the list\n";
    }
}

void DoublyLinkedList::insertBefore(int before, int value)
{
    Node *newNode = new Node(value);

    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == before)
        {
            currentNode->getPrevNode()->setNextNode(newNode);
            newNode->setPrevNode(currentNode->getPrevNode());

            newNode->setNextNode(currentNode);
            currentNode->setPrevNode(newNode);

            size++;
            cout << value << " successfully added before: " << before << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }
    cout << before << " not found in the list" << endl;
}

void DoublyLinkedList::insertTwoBefore(int before, int value1, int value2)
{
    Node *newNode1 = new Node(value1);
    Node *newNode2 = new Node(value2);
    newNode1->setNextNode(newNode2);
    newNode2->setPrevNode(newNode1);

    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == before)
        {
            currentNode->getPrevNode()->setNextNode(newNode1);
            newNode1->setPrevNode(currentNode->getPrevNode());

            currentNode->setPrevNode(newNode2);
            newNode2->setNextNode(currentNode);

            size++;
            cout << value1 << " and " << value2 << " successfully added before " << before << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }
    cout << before << " not found in the list" << endl;
}

void DoublyLinkedList::remove(int value)
{
    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == value)
        {
            Node *temp = currentNode;
            currentNode->getPrevNode()->setNextNode(currentNode->getNextNode());
            currentNode->getNextNode()->setPrevNode(currentNode->getPrevNode());

            size--;
            cout << value << " successfully removed from the list" << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }
    cout << value << " not found in the list" << endl;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%% ( circular doubly linked list ) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

class CircularLinkedList
{
private:
    Node *headNode;
    Node *currentNode;
    int size;

public:
    CircularLinkedList() { size = 0, headNode = nullptr, currentNode = nullptr; }
    void printLinkedList();
    void insertAtTail(int value);
    void insertAtHead(int value);
    void insertAfter(int after, int value);
    void insertBefore(int before, int value);
    void Remove(int value);
};

void CircularLinkedList::printLinkedList()
{
    cout << "Size: " << size << endl;
    if (headNode == nullptr)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        currentNode = headNode;
        while (currentNode->getNextNode() != headNode)
        {
            cout << currentNode->getValue() << " -> ";
            currentNode = currentNode->getNextNode();
        }
        cout << currentNode->getValue() << endl;

        while (currentNode != headNode)
        {
            cout << currentNode->getValue() << " -> ";
            currentNode = currentNode->getPrevNode();
        }
        cout << currentNode->getValue() << endl;
    }
}

void CircularLinkedList::insertAtTail(int value)
{
    Node *newNode = new Node(value);
    if (headNode == nullptr)
    {
        newNode->setNextNode(newNode);
        newNode->setPrevNode(newNode);
        headNode = newNode;
    }
    else
    {
        currentNode = headNode->getPrevNode();
        currentNode->setNextNode(newNode);
        newNode->setPrevNode(currentNode);
        newNode->setNextNode(headNode);
        headNode->setPrevNode(newNode);
    }
    size++;
    cout << value << " successfully added at tail" << endl;
}

void CircularLinkedList::insertAtHead(int value)
{
    Node *newNode = new Node(value);
    if (headNode == nullptr)
    {
        headNode = newNode;
        headNode->setNextNode(headNode);
        headNode->setPrevNode(headNode);
    }
    else
    {
        headNode->getPrevNode()->setNextNode(newNode);
        newNode->setPrevNode(headNode->getPrevNode());
        headNode->setPrevNode(newNode);
        newNode->setNextNode(headNode);
        headNode = newNode;
    }
    size++;
    cout << value << " successfully added at head" << endl;
}

void CircularLinkedList::insertAfter(int after, int value)
{
    Node *newNode = new Node(value);

    if (headNode->getValue() == after)
    {
        headNode->getNextNode()->setPrevNode(newNode);
        newNode->setNextNode(headNode->getNextNode());
        headNode->setNextNode(newNode);
        newNode->setPrevNode(headNode);
        size++;
        cout << value << " successfully added after " << after << endl;
        return;
    }
    else
    {
        currentNode = headNode->getNextNode();
        while (currentNode != headNode)
        {
            if (currentNode->getValue() == after)
            {
                currentNode->getNextNode()->setPrevNode(newNode);
                newNode->setNextNode(currentNode->getNextNode());
                currentNode->setNextNode(newNode);
                newNode->setPrevNode(currentNode);
                size++;
                cout << value << " successfully added after " << after << endl;
                return;
            }
            currentNode = currentNode->getNextNode();
        }
    }
    cout << after << " not found in the list" << endl;
}

void CircularLinkedList::insertBefore(int before, int value)
{
    Node *newNode = new Node(value);
    if (headNode->getValue() == before)
    {
        headNode->getPrevNode()->setNextNode(newNode);
        newNode->setPrevNode(headNode->getPrevNode());
        headNode->setPrevNode(newNode);
        newNode->setNextNode(headNode);
        size++;
        cout << value << " successfully added before " << before << endl;
        return;
    }
    else
    {
        currentNode = headNode->getNextNode();
        while (currentNode != headNode)
        {
            if (currentNode->getValue() == before)
            {
                currentNode->getPrevNode()->setNextNode(newNode);
                newNode->setPrevNode(currentNode->getPrevNode());
                currentNode->setPrevNode(newNode);
                newNode->setNextNode(currentNode);
                size++;
                cout << value << " successfully added before " << before << endl;
                return;
            }
            currentNode = currentNode->getNextNode();
        }
    }
    cout << before << " not found in the list" << endl;
}

void CircularLinkedList::Remove(int value)
{

    if (headNode->getValue() == value && size == 1)
    {
        size--;
        cout << value << " successfully deleted from the list" << endl;
        delete headNode;
        headNode = nullptr;
        return;
    }
    else if (headNode->getValue() == value)
    {
        currentNode = headNode;
        headNode = headNode->getNextNode();
        currentNode->getNextNode()->setPrevNode(currentNode->getPrevNode());
        currentNode->getPrevNode()->setNextNode(currentNode->getNextNode());
        delete currentNode;
        size--;
        cout << value << " successfully deleted from the list" << endl;
        return;
    }
    else
    {
        currentNode = headNode->getNextNode();
        while (currentNode != headNode)
        {
            if (currentNode->getValue() == value)
            {
                currentNode->getNextNode()->setPrevNode(currentNode->getPrevNode());
                currentNode->getPrevNode()->setNextNode(currentNode->getNextNode());
                delete currentNode;
                size--;
                cout << value << " successfully deleted from the list" << endl;
                return;
            }
            currentNode = currentNode->getNextNode();
        }
    }
    cout << value << " not found in the list" << endl;
}
