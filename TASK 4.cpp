#include <iostream>
#include <string>
using namespace std;

int stack[100];
int top = -1;

void push(int val) {
	stack[++top] = val;
}

int pop() {
	return stack[top--];
}

int main() {
	string token;
	cout << "Enter postfix expression (e.g. 6 3 + 2 *): ";

	while (cin >> token) {
		if (isdigit(token[0])) {
			push(stoi(token));
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
			int b = pop();
			int a = pop();
			if (token == "+") push(a + b);
			else if (token == "-") push(a - b);
			else if (token == "*") push(a * b);
			else if (token == "/") push(a / b);
		}
		else {
			break; // stop on invalid or extra input
		}
	}

	cout << "Result: " << pop() << endl;
	system("pause");
	return 0;
}
