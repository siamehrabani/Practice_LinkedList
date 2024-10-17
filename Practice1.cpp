#include <iostream>
using namespace std;

class Node {
public:
    int Value;
    Node* Next;
};

void printList(Node*n) {
    while (n != NULL) {
        cout << n->Value << "\n";
        n = n->Next;
    }
}
void insertAtTheFront(Node**head, int newValue){
    // 1. Prepare the new node
    Node* newNode = new Node ();
    newNode->Value = newValue;
    // 2. Put it in front of current head
    newNode->Next = *head;
    // 3. Move head of list to point to the newNode
    *head = newNode;
}
void insertAtTheEnd(Node**head, int newValue){
    // 1. Prepare a newNode
    Node* newNode = new Node();
    newNode->Value = newValue;
    newNode->Next = NULL;
    // 2. If LinkedList is empty, make the newNode the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // 3. Find the last node
    Node* last = *head;
    while (last->Next!=NULL){
        last = last->Next;
    }
    // 4. Insert newNode after last node
    last->Next = newNode;
}
void insertAfter(Node* previous, int newValue){
    // 1. Check if previous node is NULL
    if (previous == NULL) {
        cout << "Previous node cannot be NULL";
        return;
    }
    // 2. Prepare a newNode
    Node* newNode = new Node();
    newNode->Value = newValue;
    // 3. Insert newNode after previous node
    newNode->Next= previous->Next;
    previous->Next= newNode;
}



int main() 
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->Value = 1;
    head->Next = second;
    second->Value = 2;
    second->Next = third;
    third->Value = 3;
    third->Next = NULL;


    insertAfter(head, -1);


    printList(head);



    return 0;
}