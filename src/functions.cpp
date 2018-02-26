#include "functions.h"
#include <iostream>
#include <stack>
#include <vector>

int main(int argc, char** argv) {

	bool balancesSymbols(std::string input) {
		std::stack<char, std::deque> myStack;
		
		//From balance.cpp code sample
		for (int i = 0; i < input.length; i++) {
			if(*it == '(' || *it == '[' || *it == '{')
			{
				myStack.push(*it);
				if (myStack.size() = 0) {
					return false;
				}
			}
			else {
				if(*it == ')' && st.top() == ')'){
					myStack.pop();
				}
			}		
		}	
		
		if (myStack.size() != 0) {
			return false;
		}
		else {
			return true;
		}
		
	}

	std::string iToP(std::string input) {
		char x;
		std::string output = "";
		std::stack<char, std::deque<char> > stack;

		for (int i = 0; i < input.length(); i++){
			x = input[i];
			// isalnum from Stack Overflow
			if (isalnum(x)){
				output += x;
			}
			else if (isOperator(x)) {
				if (!precedence(stack.top(), x)) {
					stack.push(x);
				}
			}
			else if (x == '(') {
        			stack.push(x);
			}
       			else if (isOperator(x)) {	
        			if (!precedence(stack.top(), x)){
					stack.push(x);
				}
				else {
					while (precedence(stack.top(), x)){
						output += stack.top();
						stack.pop();
					}
				}		
			}	
			else if(x == ')'){
				while(stack.top() != '('){
					output += stack.top();
					stack.pop();
				}
				stack.pop();
			}
		}
	return output;
	}

}
