// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class node{
    public:
    node* previous;
    int data;
    node* next;
    
    node(int data){
        this->data=data;
        previous=nullptr;
        next=nullptr;
    }
};

node* header=nullptr;


int totalnodes();

//insert node
void insertatbeg(int data){
    if(header==nullptr){
        header=new node(data);
    }
    else{
        node* nn=new node(data);
        nn->next=header;
        header->previous=nn;
        header=nn;
    }
}

void insertatend(int data){
    if(header==nullptr){
        header=new node(data);
    }
    else{
        node* temp=header;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        node* nn=new node(data);
        temp->next=nn;
        nn->previous=temp;
    }
}

void insertinmiddle(int data, int index){
	int total=totalnodes();
	if((index>0)&&(total>0)&&(index<=total)){
		if(index==1){
			insertatbeg(data);
		}
		else{
			node* temp=header;
			for(int i=1; i<index; i++){
				temp=temp->next;
			}
			node* nn=new node(data);
			temp->previous->next=nn;
			nn->previous=temp->previous;
			temp->previous=nn;
			nn->next=temp;
		}
	}
}

//display node
void display(){
    node* temp=header;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

//total number of nodes
int totalnodes(){
	if(header==nullptr){
		return 0;
	}
	else{
		int count =0;
		node* temp=header;
		while(temp!=nullptr){
			temp=temp->next;
			count++;
		}
		return count;
	}
}

//delete node
void deletenode(int index){ //index->nuber of node to delete
	int total=totalnodes();
	//cout<<total<<endl;
	if((index>0)&&(index<=total)&&(total>0)){
		if(index==1){ //edge case
			header=header->next;
			header->previous=nullptr;
		}
		else{
			node* temp=header;
			for(int i=1; i<index; i++){
				
				//cout<<temp->data<<endl;
				temp=temp->next;
			}
			if(index==total){ //edge case
				temp->previous->next=nullptr;
			}
			else{ //middle case
				temp->previous->next=temp->next;
				temp->next->previous=temp->previous;
			}
		}
	}
}


void reverse(){
	int t;
	int n=totalnodes();
	if(n<=1){return;}
	
	node* one=header;
	node* two=header;
	while(two->next!=nullptr){
		two=two->next;
	}
	
	(n%2==0)?t=n/n:t=(n-1)/2;
	int tempdata;
	for(int i=0; i<t; i++){
		tempdata=one->data;
		one->data=two->data;
		two->data=tempdata;
		one=one->next;
		two=two->previous;
	}
}
		
		



int main() {
    for(int i=0; i<10; i++){
        insertatend(i+1);
    }
    display();
    cout<<"---------------"<<endl;
    
    //deletenode(0);
    insertinmiddle(45, 6);
    display();
    cout<<"---------------"<<endl;
    reverse();
    display();
    
}
