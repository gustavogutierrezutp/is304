#include <cctype>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

// Function to get precedence of operators
int precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

// Function to perform operation
int applyOp(int a, int b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    if (b == 0)
      throw runtime_error("Division by zero");
    return a / b;
  default:
    throw runtime_error("Invalid operator");
  }
}

// Function to evaluate expression using stack
int evaluateExpression(const string &expression) {
  stack<int> values; // Stack for numbers
  stack<char> ops;   // Stack for operators

  for (int i = 0; i < expression.length(); i++) {
    char c = expression[i];

    // Skip whitespace
    if (isspace(c))
      continue;

    // If current char is a digit, parse the full number
    if (isdigit(c)) {
      int num = 0;
      while (i < expression.length() && isdigit(expression[i])) {
        num = num * 10 + (expression[i] - '0');
        i++;
      }
      values.push(num);
      cout << "Pushed number: " << num << endl;
      i--; // Adjust for loop increment
    }

    // If current char is an opening parenthesis
    else if (c == '(') {
      ops.push(c);
      cout << "Pushed '(': " << c << endl;
    }

    // If current char is a closing parenthesis
    else if (c == ')') {
      while (!ops.empty() && ops.top() != '(') {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        int result = applyOp(val1, val2, op);
        values.push(result);
        cout << "pushed result: " << result << endl;
      }
      if (!ops.empty())
        ops.pop(); // Pop '('
      else
        throw runtime_error("Mismatched parentheses");
    }

    // If current char is an operator
    else if (isOperator(c)) {
      //cout << "Current operator: " << c << endl;
      while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
        cout << "inside the while" << endl;
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
      }
      ops.push(c);
      cout << "Pushed operator: " << c << endl;
    }

    else {
      throw runtime_error("Invalid character in expression");
    }
  }

  // Process remaining operators
  while (!ops.empty()) {
    if (ops.top() == '(' || ops.top() == ')')
      throw runtime_error("Mismatched parentheses");

    int val2 = values.top();
    values.pop();
    int val1 = values.top();
    values.pop();
    char op = ops.top();
    ops.pop();
    int result = applyOp(val1, val2, op);
    values.push(result);
    cout << "Computing " << val1 <<  " " << op << " " << val2 << " = " << result << endl;
    cout << "pushed result: " << result << endl;
  }

  if (values.size() != 1)
    throw runtime_error("Invalid expression");

  return values.top();
}

// Main function
int main() {
  string expr;
  cout << "Enter an arithmetic expression (e.g., 3+5*(2-8)): ";
  getline(cin, expr);

  try {
    int result = evaluateExpression(expr);
    cout << "Result: " << result << endl;
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}