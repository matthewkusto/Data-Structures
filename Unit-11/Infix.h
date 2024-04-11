#ifndef INFIX_H
#define INFIX_H

#include "RPNCalc.h"

class Infix : public RPNCalc
{
public:
    /**
     * @brief
     *
     * @param expression
     * @return string
     * @note came from lecture material
     */
    string infixToPostfix(string expression)
    {
        char token;
        string postfix;
        istringstream iss(expression);

        while (iss >> token)
        {
            if (isOperand(token))
            {
                postfix += token;
                postfix += " ";
            }
            else if (token == '(')
            {
                stack.push(token);
            }
            else if (token == ')')
            {
                char topToken = stack.pop();
                while (topToken != '(')
                {
                    postfix += topToken;
                    postfix += " ";
                    topToken = stack.pop();
                }
            }
            else
            {
                while (stack.length() > 0 && precedence(stack.peek()) >= precedence(token))
                {
                    postfix += stack.pop();
                    postfix += " ";
                }
                stack.push(token);
            }
        }

        while (stack.length() > 0)
        {
            postfix += stack.pop();
            postfix += " ";
        }

        return postfix;
    }

    /**
     * @brief
     *
     * @param x
     * @return int
     * @note came from lecture material
     */
    int precedence(char x)
    {
        if (x == '+' || x == '-')
        {
            return 1;
        }
        else if (x == '*' || x == '/' || x == '%')
        {
            return 2;
        }
        else if (x == '^')
        {
            return 3;
        }
        return 0;
    }

    /**
     * @brief
     *
     * @param c
     * @return true
     * @return false
     * @note came from lecture material
     */
    bool isOperator(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')';
    }

    /**
     * @brief
     *
     * @param s
     * @return true
     * @return false
     * @note came from lecture material
     */
    bool isOperand(char s)
    {
        if (!isOperator(s) && s != '(' && s != ')')
        {
            return true;
        }
        return false;
    }

private:
    Stack<char> stack;
};

#endif // !INFIX_H