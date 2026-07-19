#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

// Insert at End
void insertEnd(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at Beginning
void insertBeginning(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Delete First Node
void deleteBeginning()
{
    if(head == NULL)
        return;

    Node *temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete Last Node
void deleteEnd()
{
    if(head == NULL)
        return;

    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    delete temp;
}

// Search
void search(int value)
{
    Node *temp = head;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            cout << "Found\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Not Found\n";
}

// Reverse List
void reverse()
{
    Node *temp = NULL;
    Node *current = head;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if(temp != NULL)
        head = temp->prev;
}

// Display Forward
void display()
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    insertBeginning(5);

    display();

    deleteBeginning();
    display();

    deleteEnd();
    display();

    search(20);

    reverse();

    display();

    return 0;
}
