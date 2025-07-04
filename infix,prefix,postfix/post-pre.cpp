#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c)
{

    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string post_to_pre(string input)
{
    stack<string> st;
    int n = input.length();

    for (int i = 0; i < n; i++)
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
            string ans = c + top2 + top1 ;

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
    string result = post_to_pre(input); // call the function
    cout << result << endl;

    return 0;
}