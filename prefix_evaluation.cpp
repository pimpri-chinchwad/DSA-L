#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;


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

bool isHigher(char one, char two){
	if((one=='*'||one=='/')&&(two=='+'||two=='-')){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	cout<<"Note: Number of operands should be more than no of operators"<<endl;
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



	
