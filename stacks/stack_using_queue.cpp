#include <iostream>
#include <queue>
using namespace std;

class stack
{
public:
    queue<int> q;

    void push(int x)
    {
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (!q.empty())
        { // Add check for empty queue
            q.pop();
        }
        else
        {
            cout << "Error: Stack is empty. Cannot pop." << endl;
        }
    }

    int getTop()
    {

        if (!q.empty())
        {
            return q.front();
        }
        else
        {
            return -1;
        }
    }
    bool empty()
    {
        return q.empty();
    }
};

int main()
{

    stack myStack; // Remember the C++ naming convention for class, 'Stack' is preferred.

    cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; // Yes

    myStack.push(10);
    myStack.push(20);
    myStack.push(30); // 30 should be the top

    cout << "Top element: " << myStack.getTop() << endl;                    // Should be 30
    cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; // No

    myStack.pop();                                         // Pop 30
    cout << "Top after pop: " << myStack.getTop() << endl; // Should be 20

    myStack.pop(); // Pop 20
    myStack.pop(); // Pop 10

    cout << "Top after all pops: " << myStack.getTop() << endl;             // Should return -1 and error message
    cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; // Yes

    myStack.pop(); // Test popping from empty stack
    return 0;
}