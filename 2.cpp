#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	
	node(int data){
		this->data=data;
		this->next=nullptr;
	}
};

void remove(int x, node* header){
	if (header->data==x){
		header=header->next;
		return;
	}
	else{
		node* current=header;
		while(current->next->data!=x){
			current=current->next;
		}
		current->next=current->next->next;
	}
}

int main(){
	node* header=new node(0);
	
	node* current=header;
	for(int i=1; i<=100; i++){
		current->next=new node(i);
		current=current->next;
	}
	
	remove(22, header);
	
	
	//display
	current=header;
	do{
		cout<<current->data<<endl;
		current=current->next;
	}while(current!=nullptr);	


}
	
	
	
