#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void push(int new_data) {
        Node* new_node = new Node(new_data);
        new_node->next = head;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode(int key) {
        Node* temp = head;

        // Search for the node to be deleted
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }

        // If node was not found
        if (temp == NULL) {
            cout << "Element not found in the list" << endl;
            return;
        }

        // If node to be deleted is head
        if (temp == head) {
            head = temp->next;
        }

        // Change next only if node to be deleted is NOT the last node
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        // Change prev only if node to be deleted is NOT the first node
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        // Finally, free the memory occupied by temp
        delete temp;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.push(7);
    dll.push(1);
    dll.push(3);
    dll.push(2);
    dll.printList();
    dll.deleteNode(3);
    dll.printList();

    return 0;
}
