#include <iostream>
#include <string.h>
using namespace std;

struct node{
    string my_data;
    node* next;

    node(string my_data){
        this->my_data=my_data;
        this->next=nullptr;
    }
};

node* header=new node("first_song");
node* current=header;
node* last=header;
string my_data;

void display_playlist();
void add_song(){
	cout<<"Enter name of song"<<endl;
	cin>>my_data;
	node* nn=new node(my_data);
	last->next=nn;
	last=nn;
	cout<<"song "<<my_data<<" added"<<endl;
}

void play_song(){
	display_playlist();
	int x;
	cout<<"Enter song to play"<<endl;
	cin>>x;
	for(int i=0; i<x;i++){
		current=current->next;
	}
	cout<<"playing song "<<current->my_data;
}

void display_playlist(){
	current=header->next;
	int m=1;
	while(1){
		cout<<m<<" "<<current->my_data<<endl;
		if(current->next==nullptr){
			break;
		}
		current=current->next;
		m++;
	}
}

void remove_song(int x){
	current=header;
	for(int i=0; i<x-1;i++){
		current=current->next;
	}
	cout<<"removed "<<current->next->my_data<<endl;
	current->next=current->next->next;
	
}

int main(){
	while(1){
		cout<<"1. Add song"<<endl;
		cout<<"2. Remove song"<<endl;
		cout<<"3. Display Entire Playlist"<<endl;
		cout<<"4. Play song"<<endl;
	
		int ch;
		cin>>ch;
		
		switch(ch){
			case 1:
				add_song();
				break;
			case 2:
				display_playlist();
				cout<<"Enter song to remove"<<endl;
				int x;
				cin>>x;
				remove_song(x);
				break;
			case 3:
				display_playlist();
				break;
			case 4:
				play_song();
				break;
			default:
				cout<<"Enter valid choice"<<endl;
				break;
			}
	}
/*
	for(int i=0; i<5; i++){
		add_song();
	}
	display_playlist();
	
	int x;
	cin>>x;
	remove_song(x);
	
	display_playlist();*/
}
	
