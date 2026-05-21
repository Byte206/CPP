#include "RPN.hpp"

#include <cctype>
#include <stack>
#include <sstream>

namespace
{
	bool isOperatorToken(const std::string &token)
	{
		return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
	}

	int applyOperator(int left, int right, char op)
	{
		switch (op)
		{
			case '+': return left + right;
			case '-': return left - right;
			case '*': return left * right;
			case '/':
				if (right == 0)
					throw std::runtime_error("division by zero");
				return left / right;
			default:
				throw std::runtime_error("invalid operator");
		}
	}

	bool isSingleDigit(const std::string &token)
	{
		return token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0]));
	}
}

RPN::RPN(const std::string &expression) : _expression(expression)
{
}

int RPN::evaluate() const
{
	std::stack<int> values;
	std::istringstream input(_expression);
	std::string token;

	while (input >> token)
	{
		if (isSingleDigit(token))
		{
			values.push(token[0] - '0');
			continue;
		}

		if (isOperatorToken(token))
		{
			if (values.size() < 2)
				throw std::runtime_error("invalid expression");

			int right = values.top();
			values.pop();
			int left = values.top();
			values.pop();
			values.push(applyOperator(left, right, token[0]));
			continue;
		}

		throw std::runtime_error("invalid token");
	}

	if (values.size() != 1)
		throw std::runtime_error("invalid expression");

	return values.top();
}
