#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	
	Node(int data){
		this->data=data;
		next=nullptr;
	}
};

class Queue{
	Node* front;
	Node* rear;
	
	public:
	Queue(){
		front=nullptr;
		rear=nullptr;
	}
	
	void enqueue(int data){
		if(front==nullptr){ //no element
			front=new Node(data);
			rear=front;
		}
		else{//normal
			rear->next=new Node(data);
			rear=rear->next;
		}
	}
	
	int dequeue(){
		int x;
		if(front==nullptr){//no elemenr
			cout<<"Queue is empty"<<endl;
			return -1;
		}
		else if(front==rear){//one element
			x=front->data;
			front=nullptr;
			rear=nullptr;
			return x;
		}
		else{
			x=front->data;
			front=front->next;
			return x;
		}
	}
	
	bool isEmpty(){
		return (front==nullptr)?true: false;
	}
	
	void display(){
		Node* temp=front;
		while(temp!=nullptr){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
};


class CircularQueue{
	Node* tail;
	int count;
	int max;
	
	public:
	CircularQueue(int max){ //constructor
		tail=nullptr;
		count=0;
		this->max=max;
	}
	
	void enqueue(int data){
		if(tail==nullptr){//no element
			tail=new Node(data);
			tail->next=tail;
			count++;
		}
		else if(count==max){//full
			cout<<"Queue full"<<endl;
		}
		else{
			Node* nn=new Node(data);
			nn->next=tail->next;
			tail->next=nn;
			tail=nn;
			count++;
		}
	}
	
	void dequeue(){
		if(tail==nullptr){//no element
			cout<<"Queue empty"<<endl;
		}
		else if(tail->next==tail){ //one element
			tail=nullptr;
			count--;
		}
		else{
			tail->next=tail->next->next;
			count--;
		}
	}
	
	bool isFull(){
		return (count==max)?true: false;
	}
	
	void display(){
		if(tail==nullptr){//empty
			return;
		}
		else{
			Node*temp=tail->next;
			while(temp!=tail){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
			cout<<tail->data<<endl;
		}
	}
};
	
		
int main(){
	Queue waitingList;
	CircularQueue tables(4);
	
	int ch, data;
	
	while(1){
		cout<<"========================"<<endl
			<<"1.New Customer"<<endl
			<<"2.Customer Done Eating"<<endl
			<<"3.Display Waiting list"<<endl
			<<"4.Display Customers on Table"<<endl
			<<"Ctrl+C to Exit"<<endl;
		cin>>ch;
		
		switch(ch){
			case 1://New Customer
				cout<<"Enter customer id"<<endl;
				cin>>data;
				if(tables.isFull()){ //Yes
					waitingList.enqueue(data);
				}
				else{//no
					tables.enqueue(data);
				}
				break;
			case 2://customer done eating
				tables.dequeue();
				if(!waitingList.isEmpty()){//not empty
					tables.enqueue(waitingList.dequeue());
				}
				break;
			case 3:
				waitingList.display();
				break;
			case 4:
				tables.display();
				break;
			default:
				cout<<"Enter valid input"<<endl;
				break;
			}
	}
					
				
	
}
		
			
	
