#include <iostream>
using namespace std;

// Define the structure for the doubly linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

// Function to traverse the doubly linked list from the end
void traverseFromEnd(Node* tail) {
    Node* current = tail;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }

}

int main() {
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    Node* tail = third;
    traverseFromEnd(tail);
    return 0;
}

