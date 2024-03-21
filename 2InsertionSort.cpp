#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j = j-1;
		}	
		arr[j+1] = key;
	}
}

void selectionSort(int arr[],int n){
	int i,j,targetIndex;
	for(i=0;i<n-1;i++){
		targetIndex = i;
		for(j=i+1;j<n;j++){
			if(arr[j]>arr[targetIndex]){
				targetIndex = j;
			}
		}
		swap(arr[j],arr[targetIndex]);
	}
}


void mergeSort(int a[] , int s , int e){
	if(s>=e){
		return;
	}
	
	int mid = (s+e)/2;
	int x[100],int y[100];
	
	for(int i=s; i<mid;i++){
		x[i] = a[i];
	}	
	for(int i=mid+1; i<e;i++){
		y[i] = a[i];
	}
	
	mergeSort(x,s,mid);
	mergeSort(y,mid+1,e);
	mergeArrays(x,y,a,s,e);
}


void mergeArrays(int x[] ,int y[] , int a[] ,int s,int e){
	int mid = (s+e)/2;
	int i = s;
	int k = s;
	int j = mid + 1;
	
	while(i<=mid && j<=e){
           if(x[i] < y[j]){
            a[k] = x[i];
            i++;
            k++;
           }else{
             a[k] = y[j];
             j++;
             k++;
           }
       }
       while(i<=mid){
        a[k] = x[i];
        k++;
        i++;
       }
       while(j<=e){
        a[k] = y[j];
        k++;
        j++;
       }
}



// Write a program that implement the circular linked list with
// functions./15pts in c++
// a) Insert at the beginning
// b) Insert at the end function
// c) Delete at the beginning
// d) Delete at the end
// e) Prints element of the linked list
// Add a main function to call these functions.



#include <iostream>
using namespace std;

// Define the structure for a node in the circular linked list
struct Node {
   int data;
   Node* next;
};



// Function to insert a new node at the beginning
Node* insertAtBeginning(Node* head, int newData) {
   Node* newNode = new Node();
   newNode->data = newData;
   newNode->next = head;
   if (head != nullptr) {
       Node* temp = head;
       while (temp->next != head) {
           temp = temp->next;
       }
       temp->next = newNode;
   } else {
       newNode->next = newNode;
   }
   head = newNode;
   return head;
}

// Function to insert a new node at the end
Node* insertAtEnd(Node* head, int newData) {
   Node* newNode = new Node();
   newNode->data = newData;
   newNode->next = head;
   if (head != nullptr) {
       Node* temp = head;
       while (temp->next != head) {
           temp = temp->next;
       }
       temp->next = newNode;
   } else {
       newNode->next = newNode;
       head = newNode;
   }
   return head;
}

// Function to delete the node at the beginning
Node* deleteAtBeginning(Node* head) {
   if (head == nullptr)
       return nullptr;
   if (head->next == head) {
       delete head;
       return nullptr;
   }
   Node* temp = head;
   Node* lastNode = head;
   while (lastNode->next != head) {
       lastNode = lastNode->next;
   }
   head = head->next;
   lastNode->next = head;
   delete temp;
   return head;
}

// Function to delete the node at the end
Node* deleteAtEnd(Node* head) {
   if (head == nullptr)
       return nullptr;
   if (head->next == head) {
       delete head;
       return nullptr;
   }
   Node* temp = head;
   Node* prevNode = nullptr;
   while (temp->next != head) {
       prevNode = temp;
       temp = temp->next;
   }
   prevNode->next = head;
   delete temp;
   return head;
}

// Function to print the elements of the linked list
void printLinkedList(Node* head) {
   if (head == nullptr)
       return;
   Node* temp = head;
   do {
       cout << temp->data << " ";
       temp = temp->next;
   } while (temp != head);
}

int main() {
   Node* head = nullptr;

   // Insert at the beginning
   head = insertAtBeginning(head, 5);
   
   // Insert at the end
   head = insertAtEnd(head, 10);
   
   // Delete at the beginning
   head = deleteAtBeginning(head);
   
   // Delete at the end
   head = deleteAtEnd(head);
   
   // Prints elements of the linked list
   printLinkedList(head);
   
   return 0;
}





























Node* deleteFirstNode(Node* head){
if (head == NULL)
return NULL;
// Move the head pointer to the next node
Node* temp = head;
head = temp->next;
delete temp;
return head;
}


Node* insertTail(Node *head, int val){
if(head==NULL){
Node* n = new Node(val);
n->next = head;
head = n;
return head;
}
Node *temp = head;
while(head->next!=NULL){
head = head->next;
}



if(head){
Node *n = new Node(val);
n->next = head->next;
head->next = n;
}
return temp;
}

void addFirst(Node **head, int val)
{
      Node *newNode = new Node();
      newNode->data = val;
      newNode->next = *head;
      *head = newNode;
}


Node* deleteLastNode(Node* head)
{
    if (head == NULL)
        return NULL;
  
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
  
    // Find the second last node
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
  
    // Delete last node
    delete (second_last->next);
    // Change next of second last
    second_last->next = NULL;
  
    return head;
}


void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
cout<<'NULL';
}












