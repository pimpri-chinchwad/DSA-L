#include <iostream>
using namespace std;

int arr[3];
int size=3;
int front=-1;
int rear=-1;

void enqueue(int x){
	if(front==-1&&rear==-1){
		front=0;
		rear=0;
		arr[rear]=x;
	}
	else if(front==(rear+1)%size){
		cout<<"Queue is full"<<endl;
	}
	else{
		rear++;
		if(rear>size){
			rear=0;
		}
	}
}

void dequeue(){
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else if(front==-1&&rear==-1){
		cout<<"Empty"<<endl;
	}
	else{
		front++;
	}
}

void display(){
	int i=0;
	while(i!=rear){
		
	
