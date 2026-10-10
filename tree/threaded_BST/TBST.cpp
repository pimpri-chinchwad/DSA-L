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
	
	void inorder(){
		if(root==nullptr){return;} //check if root null
		Node* current=root;
		
		while(1){
			if(current->left==nullptr){
				if(current->rightThreaded){
					while(1){
						if(current->rightThreaded){
							cout<<current->val<<endl;
							current=current->right;
						}
						else{
							cout<<current->val<<endl;
							current=current->right;
							if(current==nullptr){return;}
							break;
						}
					}
				}
				else{
					cout<<current->val<<endl;
					if(current->right==nullptr){return;}
					else{current=current->right;}
				}
			}
			else{
				current=current->left;
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
		
