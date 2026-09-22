#include <iostream>
#include <stack>
#include <string>
#include <queue> //level order traversal
using namespace std;
class Node{
	public:
	string word;
	string meaning;
	Node* right;
	Node* left;
	
	Node(string word){
		this->word=word;
		this->meaning="";
		this->right=nullptr;
		this->left=nullptr;
	}
};

class Tree{
	public:
	Node* root;
	
	Tree(){
		root=nullptr;
	}

	void insert(Node* &root, string word){
		if(root==nullptr){
			root=new Node(word);
			return;
		}
		if(word<=root->word){
			if(root->left==nullptr){
				root->left=new Node(word);
			}
			else{
				insert(root->left, word);
			}
		}else{
			if(root->right==nullptr){
				root->right=new Node(word);
			}
			else{
				insert(root->right,word);
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
		cout<<root->word<<endl;
		if(root->right!=nullptr){
			inorder(root->right);
		}
	}
	
	void levelOrderTraversal(Node* root){
		if(root==nullptr){return;}
		
		queue<Node*> q;
		q.push(root);
		
		while(!q.empty()){
		    int n=q.size();
		    for(int i=0; i<n; i++){
		        Node* top=q.front();
		        if(top->left!=nullptr){
		            q.push(top->left);
		        }
		        if(top->right!=nullptr){
		            q.push(top->right);
		        }
		        cout<<top->word<<"\t";
		        q.pop();
		    }
		    cout<<endl;
		}
	}
	
	bool searchWord(Node* root, string "word"){
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

};

int main(){
	Tree t;
	
	t.insert(t.root, "hello");
	
	t.insert(t.root, "haha");
	t.insert(t.root,"a");
	t.insert(t.root,"z");
	t.insert(t.root,"p");
	t.insert(t.root,"polo");
	t.insert(t.root,"what");
	t.insert(t.root, "ananas");
	t.insert(t.root, "papa");
	t.insert(t.root, "aringetram");
	t.insert(t.root, "advance");
	t.insert(t.root, "advance");
	
	t.levelOrderTraversal(t.root);
}


	
