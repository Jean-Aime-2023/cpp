//Insert a node at the end of a doubly linked list using a structure. 



#include <iostream>
using namespace std;

// Structure for the node of the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

int main() {
    Node* head = NULL; // Initializing an empty doubly linked list

    // Adding nodes to the doubly linked list
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);

    // Displaying the doubly linked list
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}

