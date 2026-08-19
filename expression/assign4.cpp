#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isHigher(char one, char two){
	if((one=='*'||one=='/')&&(two=='+'||two=='-')){
		return true;
	}
	else{
		return false;
	}
}

bool isOperator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}

void infixToPostfix(){
	stack<char> opStack;
	stack<char> postfixStack;
	string myStr;
	
	cin>>myStr;
	
	int n=myStr.length();
	
	char current, temp;
	for(int i=0; i<n; i++){
		current=myStr[i];
		if (isOperator(current)){
			operator_label:
			if(current=='('){
				opStack.push(current);
				continue;
			}
			if(current==')'){
				while(opStack.top()!='('){
					postfixStack.push(opStack.top());
					opStack.pop();
				}
			opStack.pop();
			continue;
			}
			
			if(opStack.empty()){
				//cout<<"Stack is empty, pushing"<<current<<"in op stack"<<endl;
				opStack.push(current);
				
			}
			else if(isHigher(current, opStack.top())){
				//cout<<"Higher precedence, pushing"<<current<<"in op stack"<<endl;
				opStack.push(current);
				continue;
			}
			else if(!(isHigher(current, opStack.top()))){
				//cout<<"Lower precednece, pushing"<<opStack.top()<<"in postfix stack"<<endl;
				postfixStack.push(opStack.top());
				opStack.pop();
				goto operator_label;
			}
		}
		else{
			//cout<<"Operand, pushing"<<current<<"in postfix stack"<<endl;
			postfixStack.push(current);
		}
		
		
		
	}
	
	while(!(opStack.empty())){
		postfixStack.push(opStack.top());
		opStack.pop();
	}
	
	
	cout<<"Size:"<<postfixStack.size()<<endl;
	while(!(postfixStack.empty())){
		cout<<postfixStack.top();
		postfixStack.pop();
	}
	
}

//done
void evaluatePostfix(){
	cout<<"Please enter valid postfix expression"<<endl;
	cout<<"Example: 2,3,*,8,4,/,*"<<endl;
	stack<int> operandStack;
	string myStr;
	
	cin>>myStr;
	string current;
	
	stringstream ss(myStr);
	int op2, op1;
    
    // Read tokens separated by commas
    while (getline(ss, current, ',')) {
        //cout<<current<<endl;
   
		
		
		
		if (current=="+"||current=="-"||current=="*"||current=="/"){ //operator
			op2=operandStack.top();
			operandStack.pop();
			op1=operandStack.top();
			operandStack.pop();
			if(current=="+"){	
				operandStack.push(op1+op2);}
			else if(current=="-")
					operandStack.push(op1-op2);
				
				else if(current== "*")
					operandStack.push(op1*op2);
					
				else if(current=="/"){
					operandStack.push((op1/op2));}
			//cout<<"result: "<<operandStack.top()<<endl;
			}
		
	
			

		
		else{//operand
			int temp=stoi(current);
			//cout<<temp<<endl;
			operandStack.push(temp);
		}
		
		
		
	}	
	
	
	//cout<<"Size:"<<operandStack.size()<<endl;
	cout<<"Result: "<<operandStack.top()<<endl;
}

//done
void evaluatePrefix(){
	cout<<"Please enter valid prefix expression"<<endl<<"Note: Number of operands should be more than no of operators"<<endl;
	cout<<"Example: +,*,/,+,100,200,2,5,7"<<endl;
	stack<int> operandStack;
	string myStr;
	
	cin>>myStr;
	string current;
	int op2, op1;
	
	stringstream ss(myStr);
	
	vector<string> listOfItems;
	
	while (getline(ss, current, ',')) {
        cout<<current<<endl;
        listOfItems.push_back(current);}
	
		
	for (int i = listOfItems.size() - 1; i >= 0; --i) {	
		current=listOfItems.at(i);
		if (current=="+"||current=="-"||current=="*"||current=="/"){ //operator
			op1=operandStack.top();
			operandStack.pop();
			op2=operandStack.top();
			operandStack.pop();
			if(current=="+")	
					operandStack.push(op1+op2);
			else if(current=="-")
					operandStack.push(op1-op2);
			else if(current== "*")
					operandStack.push(op1*op2);
					
			else if(current=="/")
					operandStack.push((op1/op2));
			}
		
	
			

		
		else{//operand
			int temp=stoi(current);
			operandStack.push(temp);
		}
		
		
		
	}
	
	
	cout<<"Size:"<<operandStack.size()<<endl;
	
	cout<<operandStack.top()<<endl;
}


int main(){
	int ch;
	
	while(1){
		
		cout<<"======================================================="<<endl;
		cout<<"1.Convert Infix to postfix"<<endl;
		cout<<"2. Evaluate Postfix expression"<<endl;
		cout<<"3. Evaluate Prefix expression"<<endl;
		
		
		cout<<"Enter choice:";
		cin>>ch;
		
		
		switch(ch){
			case 1:
				cout<<"Enter valid infix expression with valid brackets"<<endl;
				infixToPostfix();
				break;
			case 2:
				evaluatePostfix();
				break;
			case 3:
				evaluatePrefix();
				break;
		}
	}
}
