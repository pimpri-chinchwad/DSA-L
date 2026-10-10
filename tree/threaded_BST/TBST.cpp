#include <iostream>
using namespace std;

class Node{
	public:
	Node* left;
	int val;
	Node* right;
	bool rightThreaded;
	
	Node(int val){
		this->val=val;
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
	
	void insert(int val){
		if(root==nullptr){root=new Node(val);return;}
		Node* current=root;
		Node* nn=new Node(val);
		
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
		Node* current=leftMost(root);;
		
		while(current!=nullptr){
			cout<<current->val<<" ";
			
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
	
	t.insert(40);
	t.insert(30);
	t.insert(25);
	t.insert(35);
	t.insert(55);
	
	t.inorder();
	
	
	return 0;
}
		
