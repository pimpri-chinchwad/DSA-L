#include <iostream>
using namespace std;

int arr[3];
int front=-1;
int rear=-1;

void enqueue(int x){
	if (front==-1&&rear==-1){
		front=0;
		rear=0;
		arr[rear]=x;
	}
	else if(rear==3-1){
		cout<<"Queue is full"<<endl;
	}
	else{
		rear++;
		arr[rear]=x;
	}
}

void dequeue(){
	if(front==-1&&rear==-1){
		cout<<"Queue is empty"<<endl;
	}
	else if(front==rear){
		front=-1;
		rear=-1;
	}
	else{
		front++;
	}
}

void display_queue(){
	for(int i=front; i<=rear; i++){
		cout<<arr[i]<<",";
	}
	cout<<endl<<endl;
}

int main(){
	enqueue(20);
	enqueue(30);
	enqueue(40);	
	display_queue();
	
	dequeue();
	display_queue();
	enqueue(20);
}
