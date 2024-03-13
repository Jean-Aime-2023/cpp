// Delete a node in the middle of a doubly linked list using a class. 




#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
public:
    Node* head;

    // Constructor to initialize the head to null
    DoublyLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end of the doubly linked list
    void insertAtEnd(int newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = newNode;
        newNode->prev = last;
    }

    // Function to delete a node in the middle of the doubly linked list
    void deleteInMiddle(int key) {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with data " << key << " not found in the list." << endl;
            return;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // Function to display the doubly linked list
    void displayList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList myList; // Creating a new instance of DoublyLinkedList

    // Adding nodes to the doubly linked list
    myList.insertAtEnd(5);
    myList.insertAtEnd(10);
    myList.insertAtEnd(15);

    // Displaying the initial doubly linked list
    cout << "Initial Doubly Linked List: ";
    myList.displayList();

    // Deleting a node in the middle
    myList.deleteInMiddle(10);

    // Displaying the doubly linked list after deletion
    cout << "Doubly Linked List after Deletion: ";
    myList.displayList();

    return 0;
}

