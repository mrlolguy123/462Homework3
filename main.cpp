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

int prdnc(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

std::string inToPost(std::string str)
{
    std::string post = "";
    std::stack<char> opStack;

    for(int x = 0; x<str.length(); x++)
    {
        std::cout << x << ". Post = " << post << std::endl;

        if(str.at(x) == ' ') {
            continue; // skip whitespace
        }

        if(isOperand(str.at(x))) {
            post = post + str.at(x); // if operand, add to post
        }

        else if(str.at(x) == '(') {
            opStack.push(str.at(x)); // if (, push to stack
        }

        else if(str.at(x) == ')') { // if ), pop all in stack
            while(opStack.top() != '(') { post = post + opStack.top(); opStack.pop(); } // all pops go to post exp
            opStack.pop(); // get rid of last '('
        }

        else if(isOperator(str.at(x))) {
            while(prdnc(str.at(x)) <= prdnc(opStack.top()))
                post = post + opStack.top(); opStack.pop();
            opStack.push(str.at(x));
        }

    }

    while(opStack.size() != 0)
    {
        post = post + opStack.top();
        opStack.pop();
    }

    std::cout << "Done" << std::endl;
    return post;
}

int main() {
    std::string infix = "5+9-2+1";
    std::cout << "Length of infix: " << infix.length() << std::endl;
    std::cout << inToPost(infix);
}
