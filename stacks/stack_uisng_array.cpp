#include <iostream>
using namespace std;

class stackImp
{

public:
    int top = -1;
    int st[10];

    void push(int n)
    {
        if (top >= 9)
        {
            cout << " warning ! stack at max. capacity" << endl;
            return;
        }
        top = top + 1;
        st[top] = n;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << " Stack is Empty!!" << endl;
            return;
        }
        cout<<" element "<<st[top]<<" has been popped out."<<endl;
        top = top - 1;
    }

    int top_element()
    {
        if (top == -1)
        {
            cout << " Stack is Empty!!" << endl;
            
            exit (EXIT_FAILURE);
           
        }
        return st[top];
    }

    int size()
    {
        return (top + 1);
    }

     bool isEmpty() const // Helper function
    {
        return top == -1;
    }

     // New: Member function to print the stack contents
    void printStack() const // Mark as const as it doesn't modify the stack
    {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to print." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        // Iterate from top down to 0
        for (int i = top; i >= 0; --i) {
            cout << st[i] << " ";
        }
        cout << endl;
    }
    
};


int main()
{

    stackImp mystack;
    mystack.push(10);
    mystack.push(20);
    mystack.push(30);
    mystack.push(40);
    mystack.push(50);
    // cout<<"my stack is: "<<endl;
    mystack.printStack();

    cout << " Size of stack is " << mystack.size() << endl;
    cout << " the top element is " << mystack.top_element() << endl;

    mystack.pop();
    cout << " size is now " << mystack.size() << endl;
    cout << " top element is "<<mystack.top_element()<<" after popping "<< endl;
    mystack.pop();
    // mystack.pop();
    // mystack.pop();
    // mystack.pop();    
    // mystack.pop();    
    // mystack.top_element();    

    return 0;
}