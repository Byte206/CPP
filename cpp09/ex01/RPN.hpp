#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stdexcept>

class RPN
{
public:
  explicit RPN(const std::string &expression);

  int evaluate() const;

private:
  std::string _expression;
};

#endif
