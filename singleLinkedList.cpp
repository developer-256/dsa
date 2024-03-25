#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node *nextNode;

public:
    Node() { value = 0, nextNode = nullptr; }
    Node(int value)
    {
        this->value = value;
        nextNode = nullptr;
    }
    void setValue(int value) { this->value = value; }
    void setNextNode(Node *nextNode) { this->nextNode = nextNode; }
    int getValue() { return value; }
    Node *getNextNode() { return nextNode; }
};

class LinkedList
{
private:
    int size;
    Node *headNode;
    Node *currentNode;

public:
    LinkedList() { size = 0, headNode = nullptr, currentNode = nullptr; }

    void printLinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);
    void insertAfter(int after, int value);
    void insertTwoAfter(int after, int value1, int value2);
    void insertBefore(int before, int value);
    void insertTwoBefore(int before, int value1, int value2);

    void remove(int value);
};

void LinkedList::printLinkedList()
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
}

void LinkedList::insertAtHead(int value)
{
    Node *temp = new Node(value);

    if (headNode == nullptr)
    {
        headNode = temp;
    }
    else
    {
        temp->setNextNode(headNode);
        headNode = temp;
    }
    size++;
    cout << value << " successfully added at Head" << endl;
}

void LinkedList::insertAtTail(int value)
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
    }

    size++;
    cout << value << " successfully added at tail" << endl;
}

void LinkedList::insertAfter(int after, int value)
{
    Node *temp = new Node(value);
    bool notFound = true;
    currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == after)
        {
            notFound = !notFound;
            temp->setNextNode(currentNode->getNextNode());
            currentNode->setNextNode(temp);
            size++;
            cout << value << " successfully added after: " << after << endl;
            return;
        }
        currentNode = currentNode->getNextNode();
    }

    if (notFound)
    {
        cout << "Reference value not found\n";
    }
}

void LinkedList::insertTwoAfter(int after, int value1, int value2)
{
    Node *temp = new Node(value1);
    Node *temp2 = new Node(value2);
    temp->setNextNode(temp2);
    bool notFound = true;
    currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == after)
        {
            notFound = !notFound;
            temp2->setNextNode(currentNode->getNextNode());
            currentNode->setNextNode(temp);
            size += 2;
            cout << value1 << " and " << value2 << " successfully added after: " << after << endl;
            return;
        }
        currentNode = currentNode->getNextNode();
    }

    if (notFound)
    {
        cout << "Reference value not found\n";
    }
}

void LinkedList::insertBefore(int before, int value)
{
    Node *temp = new Node(value);
    if (headNode->getValue() == before)
    {
        temp->setNextNode(headNode);
        headNode = temp;
        size++;
        return;
    }

    Node *previousNode = headNode;
    currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == before)
        {
            previousNode->setNextNode(temp);
            temp->setNextNode(currentNode);
            size++;
            cout << value << " successfully added before: " << before << endl;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->getNextNode();
    }

    cout << "Reference value not found\n";
}

void LinkedList::insertTwoBefore(int before, int value1, int value2)
{
    Node *temp1 = new Node(value1);
    Node *temp2 = new Node(value2);
    temp1->setNextNode(temp2);

    if (headNode->getValue() == before)
    {
        temp2->setNextNode(headNode);
        headNode = temp1;
        size += 2;
        cout << value1 << " and " << value2 << " successfully added before: " << before << endl;
        return;
    }

    Node *previousNode = headNode;
    currentNode = headNode;

    while (currentNode != nullptr)
    {
        if (currentNode->getValue() == before)
        {
            previousNode->setNextNode(temp1);
            temp2->setNextNode(currentNode);
            size += 2;
            cout << value1 << " and " << value2 << " successfully added before: " << before << endl;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->getNextNode();
    }

    cout << "Reference value not found\n";
}

void LinkedList::remove(int value)
{
    Node *temp;

    if (headNode->getValue() == value)
    {
        temp = headNode;
        headNode = headNode->getNextNode();
        delete temp;
        size--;
        cout << value << " is deleted" << endl;
        return;
    }

    currentNode = headNode;
    // if program reached here, it means headNode is not value to be deleted. So we will now check value next to the headNode
    while (currentNode->getNextNode() != nullptr)
    {
        if (currentNode->getNextNode()->getValue() == value)
        {
            temp = currentNode->getNextNode();
            currentNode->setNextNode(temp->getNextNode());
            delete temp;
            size--;
            cout << value << " is deleted" << endl;
            return;
        }

        currentNode = currentNode->getNextNode();
    }

    cout << "Reference value not found" << endl;
}

int main()
{
    LinkedList list;
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);
    list.insertAtTail(8);
    list.insertAtTail(9);
    list.insertAtTail(10);
    cout << "\n\n\n";
    list.printLinkedList();
    cout << "\n\n\n";
    list.remove(10);
    list.printLinkedList();
    return 0;
}