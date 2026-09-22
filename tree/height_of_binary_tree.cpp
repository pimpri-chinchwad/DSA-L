#include <iostream>
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
  
  cout<<height(header);
}
