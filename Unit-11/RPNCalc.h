#ifndef RPNCALC_H
#define PRNCALC_H

#include "Stack.h"
#include <string>
#include <sstream>

template <class T>
class RPNCalc : public Stack<T>
{
public:

	T performOp(const string& input)
	{
		string num;
		double rVal, lVal;
		
		istringstream iss(input);
		while (iss >> num)
		{
			if (isdigit(num[0])
			{
				double numValue = stod(num);
				this->push(numValue);
			}
			else
			{
				rVal = this->pop();
				lVal = this->pop();

				switch (num[0])
				{
				case '+':
					this->push(rVal + lVal);
					break;
				case '-':
					this->push(rVal - lVal);
					break;
				case '*':
					this->push(rVal * lVal);
					break;
				case '/':
					this->push(rVal / lVal);
					break;
				default:
					break;
				}
			}
		}
		
		T result = this->peek();
		return result;
	}

	bool isOperator(const T& input)
	{
		string ops[] = { "+", "-", "*", "/", "(", ")" };
		for (int i = 0; i < 6; i++)
		{
			if (input == ops[i])
			{
				return true;
			}
		}
		return false;
	}
};

#endif // !RPNCALC_H