#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')');
}
// Modified getPrecedence function
int getPrecedence(char c)
{
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else if (c == '(') {
        // When '(' is ON THE STACK, it has the lowest precedence
        // so that operators can always be pushed on top of it.
        return 0; // Or any value lower than actual operators
    }
    // For ')' or operands, return -1 or handle explicitly in main logic
    return -1;
}


int main() {
    std::string input;
    std::cout << "enter the infix expression (with/without brackets): " << std::endl;
    std::cin >> input;

    std::stack<char> st;
    std::string ans = "";

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (!isOperator(c)) { // If it's an operand
            ans += c;
        } else if (c == '(') { // If it's an opening parenthesis
            st.push(c);
        } else if (c == ')') { // If it's a closing parenthesis
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop(); // Pop and discard the '('
            } else {
                // Error: Mismatched parentheses
                std::cerr << "Error: Mismatched parentheses!" << std::endl;
                return 1; // Or throw an exception
            }
        } else { // If it's a regular operator (+, -, *, /, ^)
            while (!st.empty() &&
                   st.top() != '(' && // Don't pop if '(' is on top
                   (getPrecedence(st.top()) > getPrecedence(c) ||
                    (getPrecedence(st.top()) == getPrecedence(c) && c != '^'))) // Handle associativity
            {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop any remaining operators from the stack (should not be '(' if valid expression)
    while (!st.empty()) {
        if (st.top() == '(') {
            std::cerr << "Error: Mismatched parentheses (unclosed)!" << std::endl;
            return 1;
        }
        ans += st.top();
        st.pop();
    }

    std::cout << "Postfix: " << ans << std::endl;

    return 0;
}