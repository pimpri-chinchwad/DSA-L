#include <iostream>
#include <string.h>
using namespace std;

struct node{
    string name;
    string artist;
    string duration;
    
    node* next;

    node(string name, string artist, string duration){
        this->name=name;
        this->artist=artist;
        this->duration=duration;
        this->next=nullptr;
    }
};

node* header=new node("first_song", "", "");
node* current=header;
node* last=header;
node* temp;

void clearScreen() {
    // \033[2J clears the screen, \033[H moves cursor to the top-left corner
    cout << "\033[2J\033[H"; 
}


void display_playlist();

void add_song_at_index(int index){
	if(index==1){
		node* nn=new node("1", "1", "1");
		nn->next=header;
		header=nn;
	}
	else{
		temp=header;
		for(int i=1; i<index-1; i++){
			temp=temp->next;
		}
		node* nn=new node("1", "1", "1");
		nn->next=temp;
		temp->next=nn;
	}
}

void add_song(){
	string name_temp;
	string artist_temp;
	string duration_temp;
	
	cout<<"Enter name of song"<<endl;
	cin.ignore();
	getline(cin, name_temp);
	
	cout<<"Enter artist";
	getline(cin, artist_temp);
	
	cout<<"Enter duration";
	getline(cin, duration_temp);
	
	temp=header;
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->next=new node(name_temp, artist_temp, duration_temp);
	cout<<"song "<<name_temp<<","<<artist_temp<<","<<duration_temp<<" added"<<endl;
}

void play_song(){
	display_playlist();
	int x;
	cout<<"Enter song to play"<<endl;
	cin>>x;
	current=header;
	for(int i=0; i<x;i++){
		current=current->next;
	}
	cout<<"playing song "<<current->name<<"|"<<current->artist<<"|"<<current->duration<<endl;
}

void display_playlist(){
	current=header->next;
	int m=1;
	while(1){
		cout<<m<<"."<<current->name<<"|"<<current->artist<<"|"<<current->duration<<endl;
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
	cout<<"removed "<<current->next->name<<endl;
	current->next=current->next->next;
	
}

int main(){

	node* nn=new node("one", "one", "one");
	last->next=nn;
	last=nn;
	
	nn=new node("two", "two", "two");
	last->next=nn;
	last=nn;

	int ch;
	clearScreen();	
	while(1){
		
		cout<<"1. Add song"<<endl;
		cout<<"2. Remove song"<<endl;
		cout<<"3. Display Entire Playlist"<<endl;
		cout<<"4. Play song"<<endl;
		cout<<"Please Enter choice"<<endl;
	
		cin>>ch;
		clearScreen();	
		
		switch(ch){
			case 1:
				add_song();
				break;
			case 2:
				display_playlist();
				cout<<"Enter index of song to remove"<<endl;
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
			case 5:
				add_song_at_index(2);
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
		
