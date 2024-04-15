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
     */
    string infixToPostfix(string expression)
    {
        char token;
        string postfix;
        istringstream iss(expression);
        bool lastWasOp = false;

        while (iss >> noskipws >> token)
        {
            if (token == ' ' && lastWasOp)
            {
                postfix += " ";
                lastWasOp = false;
                continue;
            }
            else if (isOperand(token)) // if a number or letter
            {
                lastWasOp = true;
                postfix += token;
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
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(token))
                {
                    postfix += stack.pop();
                    postfix += " ";
                }
                stack.push(token);
            }
        }

        while (!stack.isEmpty())
        {
            // one condition needs to be here to append a space AFTER an opperand
            if (lastWasOp)
            {
                postfix += " ";
                lastWasOp = false;
            }
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