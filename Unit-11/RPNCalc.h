#ifndef RPNCALC_H
#define PRNCALC_H

#include "Stack.h"
#include <string>
#include <sstream>

class RPNCalc : public Stack<double>
{
public:
	/**
	 * @brief
	 *
	 * @param expression
	 * @return double
	 */
	double performOp(const string &expression)
	{
		string token;
		istringstream iss(expression);

		while (iss >> token)
		{
			if (isdigit(token[0]))
			{
				this->push(stod(token));
			}
			else
			{
				double rVal = this->pop();
				double lVal = this->pop();
				double result = 0;

				switch (token[0])
				{
				case '+':
					result = (lVal + rVal);
					break;
				case '-':
					result = (lVal - rVal);
					break;
				case '*':
					result = (lVal * rVal);
					break;
				case '/':
					result = (lVal / rVal);
					break;
				}
				this->push(result);
			}
		}

		return this->peek();
	}
};

#endif // !RPNCALC_H