#include <iostream>
#include <string>
using namespace std;

class Node{
	public:
	Node* left;
	int val;
	string name;
	Node* right;
	bool rightThreaded;
	
	Node(int val, string str){
		this->val=val;
		this->name=str;
		left=nullptr;
		right=nullptr;
		rightThreaded=false;
	}
};

class threadedBST{
	Node* root;
	
	public:
	threadedBST(){
		root=nullptr;
	}
	
	void insert(int val, string str){
		if(root==nullptr){root=new Node(val, str);return;}
		Node* current=root;
		Node* nn=new Node(val, str);
		
		while(true){
			if(val<=current->val){//less than
				if(current->left!=nullptr){//left present
					current=current->left;
				}
				else{//left not present
					current->left=nn;
					nn->rightThreaded=true;
					nn->right=current;
					break;
				}
			}else{//greater than
				if(current->rightThreaded || current->right==nullptr){//right not present
					if(current->rightThreaded){
						current->rightThreaded=false;
						nn->right=current->right;
						nn->rightThreaded=true;
					}
					current->right=nn;
					break;
				}
				else{//right present
					current=current->right;
				}
			}
		}
			
	}
	
	Node* leftMost(Node* root){
		if(root==nullptr)return root;
		while(root->left!=nullptr){
			root=root->left;
		}
		return root;
	}
	
	void inorder(){
		Node* current=leftMost(root);
		
		while(current!=nullptr){
			cout<<current->val<<" "<<current->name<<" "<<endl;
			
			if(current->rightThreaded){
				current=current->right;
			}
			else{
				current=leftMost(current->right);
			}
		}
	}
					
			
};

int main(){
	threadedBST t;
	
	int ch;
	int id;
	string name;
	while(1){
		cout<<"Enter choice:\n1.Add book\n2.Inorder Traversal of Book\n3.Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter ID(integer) and name of book(string) respectively";
				cin>>id;
				cin>>name;
				t.insert(id, name);
				cout<<"Inserted";
				break;
			case 2:
				t.inorder();
				break;
			case 3:
				return 0;
				break;
			default:
				cout<<"Enter correct choice"<<endl;
				break;
		}
	}
				
	
	return 0;
}
		
