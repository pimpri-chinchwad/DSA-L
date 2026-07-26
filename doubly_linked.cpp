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

void display(){
    node* temp=header;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

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

int main() {
    for(int i=0; i<10; i++){
        insertatend(i);
    }
    display();
    cout<<"---------------"<<endl;
    for(int i=0; i<10; i++){
        insertatbeg(i);
    }
    
    //clear doubly linked list
    ::header=nullptr;

    display();
    return 0;
}
