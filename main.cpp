#include <iostream>
#include <string>
#include <stack>

bool isOperator(char c)
{
    return ((c=='+') || (c=='-') || (c=='*') || (c=='/'));
}

bool isOperand(char c)
{
    return (c <= '9' && c >= '0');
}

int prdnc(char c) // prdnc was the best i could think of for shortening precedence
{
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    return -1;
}

std::string inToPost(std::string str)
{
    std::string post = "";
    std::stack<char> opStack;

    for(int x = 0; x<str.length(); x++)
    {
        if(str.at(x) == ' ') // ignore whitespace
            continue;

        if(isOperand(str.at(x))) {
            post = post + str.at(x); // if operand, add to post
        }

        else if(str.at(x) == '(') {
            opStack.push(str.at(x)); // if (, push to stack
        }

        else if(str.at(x) == ')') { // if ), pop all in stack
            while(opStack.top() != '(') {
                post = post + opStack.top();
                opStack.pop(); } // all pops go to post
            opStack.pop(); // get rid of last '('
        }

        else if(isOperator(str.at(x))) {
            while(!opStack.empty() && prdnc(str.at(x)) <= prdnc(opStack.top())) { // check for if stack is empty and if scanned operator's precedence is less than or equal to the stack's precedence
                post = post + opStack.top();
                opStack.pop();
            }
            opStack.push(str.at(x));
        }

    }

    while(opStack.size() != 0) // pop the rest of the terms
    {
        post = post + opStack.top();
        opStack.pop();
    }
    return post;
}

int main() {
    std::string infix;
    std::cout << "Enter infix expression: ";
    std::getline(std::cin, infix);

    std::cout << "Length of infix: " << infix.length() << std::endl;
    std::cout << inToPost(infix);
}
