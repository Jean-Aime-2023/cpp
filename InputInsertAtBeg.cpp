#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
	Node(int data){
		this->data = data;
		next = 0;
	}
};


void printList(Node*n){
	while(n!=0){
		cout<<n->data<<endl;
		n=n->next;
	}
	cout<<"Empty"<<endl;
}

Node* userData(){
  int data;
  cin>>data;
  
  Node *head = 0;
  Node *tail= 0;
  
  while(data!=-1){
    Node *n = new Node(data);
  	if(head == 0){
  		head = n;
  		tail = n;
	}else{
		n -> next = head;
		head = n;
	}
	
	cin>>data;
  }
  
  return head;
}


int main(){
	Node *head = userData();
	printList(head);
	return 0;
}
