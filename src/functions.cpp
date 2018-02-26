#include "functions.h"
#include <iostream>
#include <stack>
#include <vector>

bool balancesSymbols(std::string input) {
	std::stack<char, std::deque<char>> myStack;
		
	//From balance.cpp code sample
	for (auto it = input.begin(); it != input.end(); ++it) {
		if(*it == '(' || *it == '[' || *it == '{') {
			myStack.push(*it);
			if (myStack.size() == 0) {
				return false;
			}
		}
		else {
			if(*it == ')' && myStack.top() == ')'){
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

// From Stack Overflow 
// https://stackoverflow.com/questions/12684086/convert-from-an-infix-expression-to-postfix-c-using-stacks
bool isOperator(char x) {
    switch (x) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '%':
        return true;
    default:
        return false;
    }
}

// From Stack Overflow
// https://stackoverflow.com/questions/12684086/convert-from-an-infix-expression-to-postfix-c-using-stacks
bool precedence(char leftOperator, char rightOperator)
{
    if ( leftOperator == '^' ) {
        return true;
    } else if ( rightOperator == '^' ) {
        return false;
    } else if ( leftOperator == '*' || leftOperator == '/' || leftOperator == '%' ) {
        return true;
    } else if ( rightOperator == '*' || rightOperator == '/' || rightOperator == '%' ) {
        return false;
    }

    return true;
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
}
