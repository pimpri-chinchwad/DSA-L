#include <iostream>
#include <string>
#include <stack>
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
	
	stack<int> operandStack;
	string myStr;
	
	cin>>myStr;
	
	int n=myStr.length();
	
	char current, temp;
	
	
	for(int i=n-1; i>=0	; i--){ 
		current=myStr[i]; //current character
		cout<<current<<endl;
		
		
		
		
		int op2, op1;
		
		if(current==','){continue;}
		else if (isOperator(current)){ //operator
			op1=operandStack.top();
			operandStack.pop();
			op2=operandStack.top();
			operandStack.pop();
			switch(current){
				case '+':
					operandStack.push(op1+op2);
					break;
				case '-':
					operandStack.push(op1-op2);
					break;
				case '*':
					operandStack.push(op1*op2);
					cout<<"multiplied and result is"<<op1*op2<<endl;
					break;
				case '/':
					operandStack.push((op1/op2)-0);
					cout<<"divided"<<endl;
					break;
			}
		}
	
			

		
		else{//operand
			int temp=current-'0';
			operandStack.push(temp);
		}
		
		
		
	}
	
	
	cout<<"Size:"<<operandStack.size()<<endl;
	
	//cout<<operandStack.top()<<endl;
	
	
}



	
