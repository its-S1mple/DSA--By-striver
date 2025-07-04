#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')');
}

// Modified getPrecedence function
int getPrecedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '(')
    {
        // When '(' is ON THE STACK, it has the lowest precedence
        // so that operators can always be pushed on top of it.
        return 0; // Or any value lower than actual operators
    }
    // For ')' or operands, return -1 or handle explicitly in main logic
    return -1;
}

int main()
{
    string s;
    cout << "enter the s expression. " << endl;
    cin >> s;
    reverse(s.begin(), s.end());
    for (char &c : s)
    { // Iterate and swap parentheses
        if (c == '(')
        {
            c = ')';
        }
        else if (c == ')')
        {
            c = '(';
        }
    }

    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (!isOperator(c))
        { // If it's an operand
            ans += c;
        }
        else if (c == '(')
        { // If it's an opening parenthesis
            st.push(c);
        }
        else if (c == ')')
        { // If it's a closing parenthesis
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
            {
                st.pop(); // Pop and discard the '('
            }
            else
            {
                // Error: Mismatched parentheses
                std::cerr << "Error: Mismatched parentheses!" << std::endl;
                return 1; // Or throw an exception
            }
        }
        else
        { // If it's a regular operator (+, -, *, /, ^)
            while (!st.empty() &&
                   st.top() != '(' &&                          // Don't pop if '(' is on top
                   getPrecedence(st.top()) > getPrecedence(c)) // Handle associativity
            {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop any remaining operators
    while (!st.empty())
    {
        if (st.top() == '(')
        {
            // Mismatched parentheses error (unclosed original '(')
            throw std::runtime_error("Mismatched parentheses in original expression.");
        }
        ans += st.top();
        st.pop();
    }
    std::reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}