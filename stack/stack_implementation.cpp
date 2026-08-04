#include <iostream>
using namespace std;



class Node{
	public:
	int data;
	Node* next;
	
	Node(int data){
		this->next=nullptr;
		this->data=data;
	}
};

Node* top=nullptr;
	
void push(int data){
	Node* nn=new Node(data);
	if(top==nullptr){
		top=nn;
	}
	else{
		nn->next=top;
		top=nn;
	}
}
int size(){
	if(top==nullptr){
		return 0;
	}
	else{
		Node* temp=top;
		int count=1;
		while(temp!=nullptr){
			temp=temp->next;
			count++;
		}
		return count;
	}
}

void pop(){
	if(size()>0){
		top=top->next;
	}
}

bool isEmpty(){
	return (size()==0)? true: false;
}

void displayTop(){
	cout<<top->data<<endl;
}

void displayStack(){
	if(top==nullptr){
		return;
	}
	else{
		Node* temp=top;
		while(temp!=nullptr){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}

int main(){
	for(int i=0; i<10; i++){
		push(i);
	}
	
	
	push(42);
	pop();
	pop();
	displayStack();
	
	
}
		
		
