#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
	int coeff;
	int power;
	Node* next;
	
	Node(int coeff, int power){
		this->coeff=coeff;
		this->power=power;
		next=nullptr;
	}
};



void insertAtEnd(Node* &header, int coeff, int power){
    if(header==nullptr){
        header=new Node(coeff, power);
    }
    else{
        Node* temp=header;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node* nn=new Node(coeff, power);
        temp->next=nn;
    }
}

void display(Node* &header){
	if(header==nullptr){
		return;
	}
	else if(header->next==nullptr){
		cout<<header->coeff<<"x^"<<header->power<<endl;
		return;
	}
	Node* temp=header;
	cout<<temp->coeff<<"x^"<<temp->power;
	temp=temp->next;
	while(temp!=nullptr){
		if(temp->coeff==0){temp=temp->next;continue;}
		(temp->coeff>0)?cout<<"+":cout<<"-";
		cout<<temp->coeff<<"x^"<<temp->power;
		temp=temp->next;
	}
}
	
			

void removeDuplicates(Node* &unsortedHeader, Node* &sortedHeader){
	Node* one = unsortedHeader;
	while(one!=nullptr){
    	Node* two=sortedHeader;
		while(two!=nullptr){
			if(two->power==one->power){
				two->coeff+=one->coeff;
				break;
			}
			two=two->next;
		}
		if(two==nullptr){
			insertAtEnd(sortedHeader, one->coeff, one->power);
		}
	one=one->next;
	}
}
       
       
int main(){
	Node* header1=nullptr;
	int value;
	int value2;
	for(int i=0; i<10; i++){
		value = rand() % 10;
		value2=rand()%10;
		cout<<value<<" "<<value2<<endl;
        insertAtEnd(header1, value, value2);	
    }   
    
    display(header1);
    
    Node* header2=nullptr;
    
    removeDuplicates(header1, header2);
    cout<<"================"<<endl;
    display(header2);
}
                        
