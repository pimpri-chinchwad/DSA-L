 // Online C++ compiler to run C++ program online
#include <iostream>
#include <string.h>
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


//insert text at end
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

//insert text at beginning
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


//display linked list
void display(){
    node* temp=header;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}



int main() {
    for(int i=0; i<10; i++){
        insertatend("hello "+to_string(i));
    }
    display();
    cout<<"---------------"<<endl;
    for(int i=0; i<10; i++){
        insertatbeg(to_string(i));
    }
    
    //clear doubly linked list
    //::header=nullptr;

    display();
    return 0;
}
