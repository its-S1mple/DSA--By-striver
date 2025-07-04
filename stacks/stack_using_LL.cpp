#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        // std::cout << "Node with data " << data << " destroyed." << std::endl; // For debugging
    }
};
class stack
{

public:
    Node *top = NULL;
    int size = 0;

    // Constructor for the stack class
    stack() : top(NULL), size(0) {} // Explicitly initialize members for good practice

    void push(int n)
    {
        Node *newNode = new Node(n);
        newNode->next = top;
        top = newNode;
        size = size + 1;
    }

    void pop()
    {
        // CRITICAL: Handle empty stack case!
        if (top == NULL) // Or if (size == 0)
        {
            cout << "Error: Stack is empty. Cannot pop." << endl;
            return; // Exit if stack is empty to prevent crash
        }
        Node *temp = top; // Store the current top node
        top = top->next;  // Move top to the next node
        delete temp;      // Delete the old top node to free memory
        size = size - 1;  // Decrement size
    }

    int getTop()
    {
        if (top == NULL)
        {
            cout << " stack is empty. no top element" << endl;

            exit(EXIT_FAILURE);
        }
        return top->data;
    }

    int size_stack()
    {

        return size;
    }

    // Add an 'isEmpty' method for clarity and safety checks
    bool isEmpty()
    {
        return top == NULL; // Or return size == 0;
    }

    // Destructor for the Stack class: Crucial for memory management!
    // This will correctly deallocate all nodes when the stack object goes out of scope.
    ~stack()
    {
        while (top != NULL)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;                                            // Reset size
        cout << "Stack destroyed and memory freed." << endl; // Optional: for debugging
    }
};

int main()
{
    // Let's test your stack implementation
    stack myStack; // Creating an instance of your stack

    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl; // Yes
    cout << "Stack size: " << myStack.size_stack() << endl;                   // 0

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << "Pushed 10, 20, 30." << endl;

    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl; // No
    cout << "Stack size: " << myStack.size_stack() << endl;                   // 3
    cout << "Top element: " << myStack.getTop() << endl;                         // 30

    myStack.pop();
    cout << "Popped one element." << endl;
    cout << "Stack size: " << myStack.size_stack() << endl; // 2
    cout << "Top element: " << myStack.getTop() << endl;       // 20

    myStack.pop();
    myStack.pop();
    cout << "Popped two more elements." << endl;

    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl; // Yes
    cout << "Stack size: " << myStack.size_stack() << endl;                   // 0

    // Test popping from an empty stack (should print error)
    myStack.pop();

    // Test top from an empty stack (should print error and exit)
    // cout << "Attempting to get top from empty stack: " << myStack.top() << endl;

    return 0; // Good practice to explicitly return 0 from main
}
