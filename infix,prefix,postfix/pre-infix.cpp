#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c)
{

    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string pre_to_infix(string input)
{
    stack<string> st;
    int n = input.length();

    for (int i = n-1; i >=0; --i)
    {
        char c = input[i];

        if (!isOperator(c))
        {
            // not a operator

            string to_insert = "";
            to_insert.push_back(c);

            st.push(to_insert);
        }
        else
        { // it is a operator

            string top1 = st.top();

            st.pop();
            string top2 = st.top();

            st.pop();
            string ans = '(' + top1 + c + top2 + ')';

            st.push(ans);
        }
    }

    return st.top();
}

int main()
{

    string input;
    cout << "Enter the expression: " << endl;
    cin >> input;
    string result = pre_to_infix(input); // call the function
    cout << result << endl;

    return 0;
}