#include <iostream>
#include <stack>
using namespace std;
class Node{
	public:
	int val;
	Node* right;
	Node* left;
	
	Node(int val){
		this->val=val;
		this->right=nullptr;
		this->left=nullptr;
	}
};

Node* header=nullptr;

void insert(Node* &root,int value){
	if(root==nullptr){
		root=new Node(value);
		return;
	}
	if(value<=root->val){
		if(root->left==nullptr){
			root->left=new Node(value);
		}
		else{
			insert(root->left, value);
		}
	}else{
		if(root->right==nullptr){
			root->right=new Node(value);
		}
		else{
			insert(root->right,value);
		}
	}
}

void inorderWithoutRecursion(Node* current){
	if(current==nullptr){return;}
	stack<Node*> myStack;
	while(1){
		if(current!=nullptr){
			myStack.push(current);
			current=current->left;
		}
		else{
			if(myStack.empty()){
				break;
			}
			current=myStack.top();
			cout<<current->val<<endl;
			current=current->right;
			myStack.pop();
		}
	}
}

void inorder(Node* root){
	if(root==nullptr){
		return;
	}
	if(root->left!=nullptr){
		inorder(root->left);
	}
	cout<<root->val<<endl;
	if(root->right!=nullptr){
		inorder(root->right);
	}
}

void preorder(Node* root){
	if(root==nullptr){
		return;
	}
	cout<<root->val<<endl;
	if(root->left!=nullptr){
		preorder(root->left);
	}
	
	if(root->right!=nullptr){
		preorder(root->right);
	}
}

void postorder(Node* root){
	if(root==nullptr){
		return;
	}
	if(root->left!=nullptr){
		postorder(root->left);
	}
	
	if(root->right!=nullptr){
		postorder(root->right);
	}
	cout<<root->val<<endl;
}

bool search(Node* root, int target){
	if(root==nullptr){return false;}
	
	if(root->val==target){
		return true;
	}
	else{
		if(root->left!=nullptr&&search(root->left, target)==true){
			return true;
		}
		else{
			if(root->right!=nullptr&&search(root->right, target)==true){
				return true;
			}
			else{return false;}
		}
	}
}

int height(Node* root){
	int l=0;
	int h=0;
	if(root->left!=nullptr){
		l=height(root->left);
	}
	if(root->right!=nullptr){
		h=height(root->right);
	}
	return (l>h)?l+1:h+1;
}

int leafnodes(Node* root){
	if(root==nullptr){return 0;}
	if((root->left==nullptr)&&(root->right==nullptr)){return 1;}
	return leafnodes(root->left)+leafnodes(root->right);
}

int leafnodesWithoutRecursion(Node* current){
	if(current==nullptr){return 0;}
	int count=0;
	stack<Node*> myStack;
	while(1){
		if(current==nullptr){
			if(myStack.empty()){break;}
			current=myStack.top();
			current=current->right;
			myStack.pop();
		}
		else if(current->left==nullptr&&current->right==nullptr){
			count++;
			myStack.push(current);
			current=current->left;
		}
		else{
			myStack.push(current);
			current=current->left;
		}
	}
	return count;
}

int main(){
	
	insert(header, 20);
	insert(header, 10);
	insert(header, 5);
	insert(header, 15);
	insert(header,11);
	
	insert(header,1);
	insert(header, 16);
	
	insert(header,30);
	insert(header, 40);
		
	cout<<"inorder traversal(using recursion): "<<endl;
	inorder(header);
	cout<<"inorder traversal(without recursion): "<<endl;
	inorderWithoutRecursion(header);
	
	/*
	cout<<search(header, 22)<<endl;
	
	cout<<height(header)<<endl;*/
	
	cout<<"number of leaf nodes(using recursion): "<<leafnodes(header)<<endl;
	cout<<"number of leaf nodes(without recursion): "<<leafnodesWithoutRecursion(header)<<endl;
}
