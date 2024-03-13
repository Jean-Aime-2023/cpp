//Insert a node at the end of a singly linked list using a class




#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class SinglyLinkedList {
public:
    Node* head;

    // Constructor to initialize the head to null
    SinglyLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end of the linked list
    void insertAtEnd(int newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = newNode;
    }

    // Function to print the linked list
    void displayList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    SinglyLinkedList myList; // Creating a new instance of SinglyLinkedList

    // Adding nodes to the linked list
    myList.insertAtEnd(5);
    myList.insertAtEnd(10);
    myList.insertAtEnd(15);

    // Displaying the linked list
    myList.displayList();

    return 0;
}

