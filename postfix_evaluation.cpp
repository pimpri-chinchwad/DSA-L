#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

/*
bool isOperator(string c) {
    switch (c) {
        case "+":
        case "-":
        case "*":
        case "/":
        case "^":
        case "%":
        case "(":
        case ")":
            return true;
        default:
            return false;
    }
}*/

bool isHigher(string one, string two){
	if((one=="*"||one=="/")&&(two=="+"||two=="-")){
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
	string current;
	
	stringstream ss(myStr);
	int op2, op1;
    
    // Read tokens separated by commas
    while (getline(ss, current, ',')) {
        cout<<current<<endl;
        
        
    
	
	
	/*
	char current, temp;
	for(int i=0; i<16; i++){ 
		getline(cin, myStr[i]);
		cout<<myStr[i]<<endl;
		
		
		
		
		current=myStr[i]; //current character*/
		
		
		
		if (current=="+"||current=="-"||current=="*"||current=="/"){ //operator
			op2=operandStack.top();
			operandStack.pop();
			op1=operandStack.top();
			operandStack.pop();
			cout<<"operand1:"<<op1<<endl<<"operand2:"<<op2<<endl;
			if(current=="+"){	
				operandStack.push(op1+op2);}
			else if(current=="-")
					operandStack.push(op1-op2);
				
				else if(current== "*")
					operandStack.push(op1*op2);
					
				else if(current=="/"){
					//cout<<"operand1:"<<op1<<endl<<"operand2:"<<op2<<endl;
					//cout<<((op1/op2))<<endl;
					operandStack.push((op1/op2));
					cout<<"divided"<<endl;}
			cout<<"result: "<<operandStack.top()<<endl;
			}
		
	
			

		
		else{//operand
			int temp=stoi(current);
			//cout<<temp<<endl;
			operandStack.push(temp);
		}
		
		
		
	}	
	
	
	cout<<"Size:"<<operandStack.size()<<endl;
	cout<<operandStack.top()<<endl;
	
	//cout<<operandStack.top()<<endl;
	
	
}




