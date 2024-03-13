// Delete a node at the end of a singly linked list using a structure.




#include <iostream>
using namespace std;

// Structure for the node of the singly linked list
struct Node {
    int data;
    Node* next;
};

// Function to delete the last node of the singly linked list
void deleteAtEnd(Node* &head) {
    if (head == NULL) {
        cout << "List is empty. No node to delete." << endl;
        return;
    }
    
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    delete current->next;
    current->next = NULL;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, NULL}}}; // Creating a sample singly linked list with 3 nodes

    // Displaying the initial linked list
    cout << "Initial Linked List: ";
    displayList(head);

    // Deleting the last node
    deleteAtEnd(head);

    // Displaying the linked list after deletion
    cout << "Linked List after Deletion: ";
    displayList(head);

    return 0;
}

