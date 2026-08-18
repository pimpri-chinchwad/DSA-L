#include <iostream>
#include <string>
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
	
	stack<int> operandStack;
	string myStr;
	
	cin>>myStr;
	string item;
	
	stringstream ss(myStr);
    
    // Read tokens separated by commas
    while (getline(ss, item, ',')) {
        cout<<item<<endl;
    }
	
	
	/*
	char current, temp;
	for(int i=0; i<16; i++){ 
		getline(cin, myStr[i]);
		cout<<myStr[i]<<endl;
		
		
		
		
		current=myStr[i]; //current character
		int op2, op1;
		
		if(current==','){continue;}
		if (isOperator(current)){ //operator
			op2=operandStack.top();
			operandStack.pop();
			op1=operandStack.top();
			operandStack.pop();
			cout<<"operand1:"<<op1<<endl<<"operand2:"<<op2<<endl;
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
					cout<<"operand1:"<<op1<<endl<<"operand2:"<<op2<<endl;
					//cout<<((op1/op2))<<endl;
					//operandStack.push((op1/op2)-0);
					cout<<"divided"<<endl;
					break;
			}
		}
	
			

		
		else{//operand
			int temp=current-'0';
			cout<<temp<<endl;
			operandStack.push(temp);
		}
		
		
		
	}	
	*/
	
	cout<<"Size:"<<operandStack.size()<<endl;
	
	//cout<<operandStack.top()<<endl;
	
	
}




