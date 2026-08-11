#include <iostream>
using namespace std;

class Node{
	public:
	int coeff;
	int pow;
	Node* next;
	
	Node(int coeff, int pow){
		this->pow=pow;
		this->coeff=coeff;
		next=nullptr;
	}
};


void insertAtEnd(Node* &header, int coeff, int pow){
    if(header==nullptr){
        header=new Node(coeff, pow);
    }
    else{
        Node* temp=header;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node* nn=new Node(coeff, pow);
        temp->next=nn;
    }
}

Node* poly1;
Node* poly2;
Node* poly3;

void inputPoly(Node* &header){
	int n, coeff, pow;
	cout<<"Enter number of nodes"<<endl;
	cin>>n;
	for(int i=0; i<n;i++){
		cout<<"Coeff:";
		cin>>coeff;
		cout<<"Power:";
		cin>>pow;
		insertAtEnd(header, coeff, pow);
	}
}

void displayPoly(Node* &header){
	Node* temp=header;
	cout<<"Coeff \t\t\t Power"<<endl;
	while(temp!=nullptr){
		cout<<temp->coeff<<"\t\t\t"<<temp->pow<<endl;
		temp=temp->next;
	}
}

int main(){

	inputPoly(poly1);
	inputPoly(poly2);
	//displayPoly(poly1);
	//displayPoly(poly2);
	//adddition code
	Node* ptr1=poly1;
	Node* ptr2=poly2;
	while(!(ptr1==nullptr&&ptr2==nullptr)){
		if(ptr1==nullptr){
			while(ptr2!=nullptr){
				insertAtEnd(poly3, ptr2->coeff, ptr2->pow);
				ptr2=ptr2->next;
			}
		}
		else if(ptr2==nullptr){
			while(ptr1!=nullptr){
				insertAtEnd(poly3, ptr1->coeff, ptr1->pow);
				ptr1=ptr1->next;
			}
		}
		else if(ptr1->pow==ptr2->pow){
			insertAtEnd(poly3, ptr1->coeff+ptr2->coeff, ptr1->pow);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->pow>ptr2->pow){
			insertAtEnd(poly3,ptr1->coeff, ptr1->pow);
			ptr1=ptr1->next;
		}
		else if(ptr1->pow<ptr2->pow){
			insertAtEnd(poly3, ptr2->coeff, ptr2->pow);
			ptr2=ptr2->next;
		}
	}
	
	displayPoly(poly3);
}
		
