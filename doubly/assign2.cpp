// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

class node{
    public:
    node* previous;
    string data;
    node* next;
    
    node(string data){
        this->data=data;
        previous=nullptr;
        next=nullptr;
    }
};

node* header=nullptr;


int totalnodes();

//insert node
void insertatbeg(string data){
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

void insertatend(string data){
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

void insertinmiddle(string data, int index){
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
	string tempdata;
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
        insertatend(to_string(i+1));
    }
    display();
    cout<<"---------------"<<endl;
    
    //deletenode(0);
    insertinmiddle("hello", 6);
    display();
    cout<<"---------------"<<endl;
    reverse();
    display();
    
    
    
    
    
    int ch;
    cout << "\033[2J\033[H"; 		
	while(1){
		
		cout<<"1. Insert Text"<<endl;
		cout<<"2. Delete Text"<<endl;
		cout<<"3. Display Text"<<endl;
		cout<<"4. Search Text"<<endl;
		cout<<"5. Print text in reverse"<<endl;
		cout<<"Please Enter choice"<<endl;
	
		cin>>ch;
		cout << "\033[2J\033[H"; 	
		
		switch(ch){
			case 1:
				insertatbeg("hi");
				break;
			case 2:
				deletenode(2);
				break;
			case 3:
				display();
				break;
			case 4:
				display();
				break;
			case 5:
				reverse();
				display();
				break;
			default:
				cout<<"Enter valid choice"<<endl;
				break;
			}
			
			if (cin.fail()) {
				cin.clear(); // Reset error state
				cin.ignore(10000, '\n'); // Ignore bad characters until newline
				continue;
			}
	}	
    
}
