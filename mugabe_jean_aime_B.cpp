#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


struct Node {
   int data;
   Node* next;
};


void addNode(Node*& head, int value) {
   Node* newNode = new Node;
   newNode->data = value;
   newNode->next = NULL;

   if (head == NULL) {
       head = newNode;
   } else {
       Node* temp = head;
       while (temp->next != NULL) {
           temp = temp->next;
       }
       temp->next = newNode;
   }
}


void deleteLastNode(Node*& head) {
   if (head == NULL || head->next == NULL) {
       delete head;
       head = NULL;
   } else {
       Node* temp = head;
       while (temp->next->next != NULL) {
           temp = temp->next;
       }
       delete temp->next;
       temp->next = NULL;
   }
}


void displayLinkedList(Node* head) {
   Node* temp = head;
   while (temp != NULL) {
       cout << temp->data << " ";
       temp = temp->next;
   }
   cout << endl;
}


void sortLinkedList(Node*& head) {
   if (head == NULL || head->next == NULL) {
       return;
   }

   Node* current = head;
   Node* index = NULL;
   int temp;

   while (current != NULL) {
       index = current->next;
       while (index != NULL) {
           if (current->data > index->data) {
               temp = current->data;
               current->data = index->data;
               index->data = temp;
           }
           index = index->next;
       }
       current = current->next;
   }
}


bool isStackEmpty(int top) {
   return top == -1;
}


bool isStackFull(int top, int maxSize) {
   return top == maxSize - 1;
}


void pushStack(int stack[], int& top, int maxSize, int value) {
   if (isStackFull(top, maxSize)) {
       cout << "Stack is full. Cannot push." << endl;
       return;
   }
   stack[++top] = value;
}


void popStack(int stack[], int& top) {
   if (isStackEmpty(top)) {
       cout << "Stack is empty. Cannot pop." << endl;
       return;
   }
   cout << "Popped element: " << stack[top--] << endl;
}


void displayStack(int stack[], int top) {
   if (isStackEmpty(top)) {
       cout << "Stack is empty." << endl;
   } else {
       cout << "Stack elements after 5 pushing and 1 pop operations: ";
       for (int i = top; i >= 0; i--) {
           cout << stack[i] << " ";
       }
       cout << endl;
   }
}


bool isQueueEmpty(int front, int rear) {
   return front == -1 || front > rear;
}


bool isQueueFull(int rear, int maxSize) {
   return rear == maxSize - 1;
}


void enqueueQueue(int queue[], int& front, int& rear, int maxSize, int value) {
   if (isQueueFull(rear, maxSize)) {
       cout << "Queue is full. Cannot enqueue." << endl;
       return;
   }
   queue[++rear] = value;
}


void dequeueQueue(int queue[], int& front, int rear) {
   if (isQueueEmpty(front, rear)) {
       cout << "Queue is empty. Cannot dequeue." << endl;
       return;
   }
   cout << "Dequeued element: " << queue[front++] << endl;
}


void displayQueue(int queue[], int front, int rear) {
   if (isQueueEmpty(front, rear)) {
       cout << "Queue is empty." << endl;
   } else {
       cout << "Queue elements: ";
       for (int i = front; i <= rear; i++) {
           cout << queue[i] << " ";
       }
       cout << endl;
   }
}

int main() {
   const int MAX_SIZE = 5;
   int choice;
   Node* linkedList = NULL;
   int stack[MAX_SIZE];
   int queue[MAX_SIZE];
   int top = -1; 
   int front = -1;
   int rear = -1;

    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Operate on Linked list" << endl;
        cout << "2. Operate on Stack" << endl;
        cout << "3. Operate on Queue" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    int value;
                    for (int i = 1; i <= 4; i++) {
                        cout << "Enter value for node " << i << ": ";
                        cin >> value;
                        addNode(linkedList, value);
                    }
                    cout << "Linked List after adding 4 elements: ";
                    displayLinkedList(linkedList);

                    sortLinkedList(linkedList);
                    deleteLastNode(linkedList);
                    cout << "Linked list after sorting and deleting last element: ";
                    displayLinkedList(linkedList);
                }
                break;
            case 2:
                {
                    int value;
                    for (int i = 0; i < 5; i++) {
                        cout << "Enter value to push onto stack: ";
                        cin >> value;
                        pushStack(stack, top, MAX_SIZE, value);
                    }
                    displayStack(stack, top);
                    popStack(stack, top);
                    displayStack(stack, top);
                }
                break;
            case 3:
                {
                    int value;
                    for (int i = 0; i < 5; i++) {
                        cout << "Enter value to add to queue: ";
                        cin >> value;
                        enqueueQueue(queue, front, rear, MAX_SIZE, value);
                    }
                    displayQueue(queue, front, rear);
                    dequeueQueue(queue, front, rear);
                    displayQueue(queue, front, rear);
                }
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 0);

    return 0;
}

