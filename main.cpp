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

    return str;
}

int main() {
    std::string balls;
    std::cout << "The: ";
    std::cin >> balls;
    std::cout << "PLEASE " << inToPost(balls) << std::endl;
}
