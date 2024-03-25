#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node *nextNode;
    Node *prevNode;

public:
    Node() { value = 0, nextNode = nullptr, prevNode = nullptr; }
    Node(int value)
    {
        this->value = value;
        nextNode = nullptr;
        prevNode = nullptr;
    }
    void setValue(int value) { this->value = value; }
    void setNextNode(Node *nextNode) { this->nextNode = nextNode; }
    void setPrevNode(Node *prevNode) { this->prevNode = prevNode; }
    int getValue() { return value; }
    Node *getNextNode() { return nextNode; }
    Node *getPrevNode() { return prevNode; }
};

class DoublyLinkedList
{
private:
    int size;
    Node *headNode;
    Node *currentNode;

public:
    DoublyLinkedList() { size = 0, headNode = nullptr, currentNode = nullptr; }

    void printDoublyLinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);
    void insertAfter(int after, int value);
    void insertTwoAfter(int after, int value1, int value2);
    void insertBefore(int before, int value);
    void insertTwoBefore(int before, int value1, int value2);

    void remove(int value);
};

void DoublyLinkedList::printDoublyLinkedList()
{
    if (headNode == nullptr)
    {
        cout << "Linked List is empty\n";
        return;
    }
    cout << "Size: " << size << endl;
    currentNode = headNode;

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
    cout << currentNode->getValue() << endl;
}

void DoublyLinkedList::insertAtHead(int value)
{
    Node *temp = new Node(value);
    if (headNode == nullptr)
    {
        headNode = temp;
    }
    else
    {
        temp->setNextNode(headNode);
        headNode->setPrevNode(temp);
        headNode = temp;
    }
    size++;
    cout << value << " successfully added at Head" << endl;
}

void DoublyLinkedList::insertAtTail(int value)
{
    Node *temp = new Node(value);
    if (headNode == nullptr)
    {
        headNode = temp;
    }
    else
    {
        currentNode = headNode;
        while (currentNode->getNextNode() != nullptr)
        {
            currentNode = currentNode->getNextNode();
        }
        currentNode->setNextNode(temp);
        temp->setPrevNode(currentNode);
    }
    size++;
    cout << value << " successfully added at Tail" << endl;
}

void DoublyLinkedList::insertAfter(int after, int value)
{
    Node *temp = new Node(value);
    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == after)
        {
            if (currentNode->getNextNode() == nullptr)
            {
                currentNode->setNextNode(temp);
                temp->setPrevNode(currentNode);
            }
            else
            {
                temp->setNextNode(currentNode->getNextNode());
                currentNode->getNextNode()->setPrevNode(temp);
                currentNode->setNextNode(temp);
                temp->setPrevNode(currentNode);
            }

            size++;
            cout << value << " successfully added after " << after << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }

    cout << "Reference value not found\n"; // because if found, it would not reach this line because return from function.
}

void DoublyLinkedList::insertTwoAfter(int after, int value1, int value2)
{
    Node *temp1 = new Node(value1);
    Node *temp2 = new Node(value2);
    temp1->setNextNode(temp2);
    temp2->setPrevNode(temp1);

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == after)
        {
            if (currentNode->getNextNode() == nullptr)
            {
                currentNode->setNextNode(temp1);
                temp1->setPrevNode(currentNode);
            }
            else
            {
                currentNode->getNextNode()->setPrevNode(temp2);
                temp2->setNextNode(currentNode->getNextNode());
                currentNode->setNextNode(temp1);
                temp1->setPrevNode(currentNode);
            }

            size += 2;
            cout << value1 << " and " << value2 << " successfully added after " << after << endl;
            return;
        }
        currentNode = currentNode->getNextNode();
    }
    cout << "Reference value not found\n"; // because if found, it would not reach this line because return from function.
}

void DoublyLinkedList::insertBefore(int before, int value)
{
    Node *temp = new Node(value);

    if (headNode->getValue() == before)
    {
        headNode->setPrevNode(temp);
        temp->setNextNode(headNode);
        headNode = temp;
        size++;
        cout << value << " successfully added before " << before << endl;
        return;
    }
    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == before)
        {
            temp->setPrevNode(currentNode->getPrevNode());
            currentNode->getPrevNode()->setNextNode(temp);
            currentNode->setPrevNode(temp);
            temp->setNextNode(currentNode);
            size++;
            cout << value << " successfully added before " << before << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }

    cout << "Reference value not found" << endl;
}

void DoublyLinkedList::insertTwoBefore(int before, int value1, int value2)
{
    Node *temp1 = new Node(value1);
    Node *temp2 = new Node(value2);
    temp1->setNextNode(temp2);
    temp2->setPrevNode(temp1);

    if (headNode->getValue() == before)
    {
        headNode->setPrevNode(temp2);
        temp2->setNextNode(headNode);
        headNode = temp1;
        size++;
        cout << value1 << " and " << value2 << " successfully added before " << before << endl;
        return;
    }

    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == before)
        {
            temp1->setPrevNode(currentNode->getPrevNode());
            currentNode->getPrevNode()->setNextNode(temp1);
            currentNode->setPrevNode(temp2);
            temp2->setNextNode(currentNode);
            size++;
            cout << value1 << " and " << value2 << " successfully added before " << before << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }

    cout << "Reference value not found" << endl;
}

void DoublyLinkedList::remove(int value)
{
    if (headNode->getValue() == value)
    {
        Node *temp = headNode;
        headNode = headNode->getNextNode();
        headNode->setPrevNode(nullptr);
        delete temp;
        size--;
        cout << value << " successfully deleted" << endl;
        return;
    }

    currentNode = headNode;
    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == value)
        {
            if (currentNode->getNextNode() == nullptr)
            {
                currentNode->getPrevNode()->setNextNode(nullptr);
            }
            else
            {
                currentNode->getNextNode()->setPrevNode(currentNode->getPrevNode());
                currentNode->getPrevNode()->setNextNode(currentNode->getNextNode());
            }
            delete currentNode;
            currentNode = nullptr;
            size--;
            cout << value << " successfully deleted" << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }
    cout << "Reference value not found\n";
}

int main()
{
    DoublyLinkedList list;
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);
    list.insertAtTail(8);
    list.insertAtTail(9);
    list.insertAtTail(10);

    cout << "\n\n\n";
    list.printDoublyLinkedList();

    // test case # 1
    cout << "\n\n\n";
    list.remove(11);
    list.printDoublyLinkedList();

    // test case # 2
    cout << "\n\n\n";
    list.remove(7);
    list.printDoublyLinkedList();
    return 0;
}