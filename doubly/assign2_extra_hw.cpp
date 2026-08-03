// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

class node{
    public:
    node* previous;
    int coachNumber;
    int coachType;
    node* next;
    
    node(int coachNumber, int coachType){
        this->coachNumber=coachNumber;
        this->coachType=coachType;
        previous=nullptr;
        next=nullptr;
    }
};

node* header=nullptr;


int totalnodes();

//insert node
void insertAtBeg(){
	int num1, num2;
	cout<<"Enter coach number";
	cin>>num1;
	cout<<"Enter coach type (1-Ac, 2-Sleeper, 3-General";
	cin>>num2;
	if(!(num2<4 && num2>0)){cout<<"Incalid Coach Type"<<endl;return;}
    if(header==nullptr){
        header=new node(num1, num2);
    }
    else{
        node* nn=new node(num1,num2);
        nn->next=header;
        header->previous=nn;
        header=nn;
    }
}

void insertAtBeg2(int num1, int num2){
    if(header==nullptr){
        header=new node(num1, num2);
    }
    else{
        node* nn=new node(num1,num2);
        nn->next=header;
        header->previous=nn;
        header=nn;
    }
}

void insertAtEnd(){
	int num1, num2;
	cout<<"Enter coach number";
	cin>>num1;
	cout<<"Enter coach type (1-Ac, 2-Sleeper, 3-General";
	cin>>num2;
	if(!(num2<4 && num2>0)){cout<<"Incalid Coach Type"<<endl;return;}
    if(header==nullptr){
        header=new node(num1, num2);
    }
    else{
        node* temp=header;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        node* nn=new node(num1, num2);
        temp->next=nn;
        nn->previous=temp;
    }
}

void insertInMiddle(){
	int index;
	cout<<"Enter index to add Coach";
	cin>>index;
	int total=totalnodes();
	if((index>0)&&(total>0)&&(index<=total)){
		int num1, num2;
		cout<<"Enter coach number";
		cin>>num1;
		cout<<"Enter coach type (1-Ac, 2-Sleeper, 3-General";
		cin>>num2;
		if(!(num2<4 && num2>0)){cout<<"Incalid Coach Type"<<endl;return;}
		if(index==1){
			insertAtBeg2(num1, num1);
		}
		else{
			node* temp=header;
			for(int i=1; i<index; i++){
				temp=temp->next;
			}
			node* nn=new node(num1, num2);
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
    int n=1;
    while(temp!=nullptr){
        cout<<n<<" Coach number: "<<temp->coachNumber<<"\t\t"<<
        "Coach type: "<<temp->coachType<<endl;
        temp=temp->next;
        n++;
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
void deletenode(){ //index->nuber of node to delete
	display();
	int index;
	cout<<"Enter index to delete Coach";
	cin>>index;
	int total=totalnodes();
	//cout<<total<<endl;
	if((index>0)&&(index<=total)&&(total>0)){
		if(index==1&&total>1){ //edge case
			header=header->next;
			header->previous=nullptr;
		}
		else if(index==1&&total==1){
			header=nullptr;
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


void displayReverse(int n, node* temp){
	if(temp==nullptr){
		return;
	}
	else{
		displayReverse(n-1,temp->next);
		cout<<n<<" Coach number: "<<temp->coachNumber<<"\t\t"<<
        "Coach type: "<<temp->coachType<<endl;
    }
}

		
		



int main() {
    
    display();
    cout<<"---------------"<<endl;
    
    displayReverse(totalnodes(),header);
    
    
    
    
    
    
    int ch;
    cout << "\033[2J\033[H"; 		
	while(1){
		
		cout<<"1. Add coach at Front"<<endl;
		cout<<"2. Add coach at Rear"<<endl;
		cout<<"3. Add coach at Specific Position"<<endl;
		cout<<"4. Remove Coach"<<endl;
		cout<<"5. Search Coach Number"<<endl;
		cout<<"6. Display Coaches from engine to last coach"<<endl;
		cout<<"7. Display COaches from last coach to Engine"<<endl;
		cout<<"Please Enter choice"<<endl;
	
		cin>>ch;
		cout << "\033[2J\033[H"; 
			
		
		switch(ch){
			case 1:
				insertAtBeg();
				break;
			case 2:
				insertAtEnd();
				break;
			case 3:
				insertInMiddle();
				break;
			case 4:
				deletenode();
				break;
			case 5:
				break;
			case 6:
				display();
				break;
			case 7:
				displayReverse(totalnodes(),header);
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
