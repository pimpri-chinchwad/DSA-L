#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
	
	node(int data){
		this->data=data;
		this->next=nullptr;
	}
};

int main(){

	node* header;
	node* last;
	node* nn;
	
	nn=new node(0);
	header=nn;
	last=nn;
	
	//create lined list of 100nodes with data as its index
	for(int i=1; i<=100; i++){
		nn=new node(i);
		last->next=nn;
		last=nn;
	}
		
	
	//insertion-inserted number 42 at beginning
	node* temp1=header;
	header=new node(42);
	header->next=temp1;
	
		
	/*	
	node* header;
	node* last;
	
	last=header;
	
	node* nn;
	nn=new node(10);
	nn->next=nullptr;
	
	header=nn;
	last=nn;
	
	nn=new node(20);
	last->next=nn;
	last=nn;
	*/
	
	//find a number and remove it	
	node* current=header;
	while(current->next->data!=11){
		current=current->next;
	}
	current->next=current->next->next;	
	
		
	//display
	node* temp;
	temp=header;
	while(temp!=nullptr){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	
	
	
	
	
	
	
	
	return 0;
}	
