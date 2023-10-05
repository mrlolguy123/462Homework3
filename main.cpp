#include <iostream>
#include <string>
#include <stack>

bool isOp(char c)
{
    return ((c=='+') || (c=='-') || (c=='*') || (c=='/'));
}

int precedence(char c)
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
    std::stack<char> operatorStack;

    for(int x = 0; x<str.length(); x++)
    {
        if(isOp(str.at(x))) { operatorStack.push(str.at(x)); }
        else
            post = post + str.at(x);
    }

    while(!operatorStack.empty())
    {
        post = post + operatorStack.top();
        operatorStack.pop();
    }

    return post;
}

int main() {
    std::string infix = "5+9-2+1";
    std::cout << inToPost(infix);
}
