#include <iostream>
#include <string>
using namespace std;

char stack[100];
int top = -1;

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void push(char c) {
	stack[++top] = c;
}

char pop() {
	if (top == -1) return '\0';
	return stack[top--];
}

char peek() {
	return (top == -1) ? '\0' : stack[top];
}

string reverseStr(string expr) {
	string rev = "";
	for (int i = expr.length() - 1; i >= 0; i--) {
		if (expr[i] == '(') rev += ')';
		else if (expr[i] == ')') rev += '(';
		else rev += expr[i];
	}
	return rev;
}

string infixToPostfix(string expr) {
	string result = "";
	for (char c : expr) {
		if (isalnum(c)) {
			result += c;
		}
		else if (c == '(') {
			push(c);
		}
		else if (c == ')') {
			while (peek() != '(') result += pop();
			pop(); // remove '('
		}
		else if (isOperator(c)) {
			while (precedence(peek()) >= precedence(c)) result += pop();
			push(c);
		}
	}
	while (top != -1) result += pop();
	return result;
}

string infixToPrefix(string expr) {
	string rev = reverseStr(expr);
	string postfix = infixToPostfix(rev);
	return reverseStr(postfix);
}

int main() {
	string infix;
	cout << "Enter infix expression: ";
	cin >> infix;

	string prefix = infixToPrefix(infix);
	cout << "Prefix expression: " << prefix << endl;
	system("pause");
	return 0;
}
