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
class queue
{

public:
    Node *start;
    Node *end;
    int size = 0;

    // Constructor for the queue class
 queue() : start(NULL),end(NULL), size(0) {} // Explicitly initialize members for good practice

    void push(int n)
    {
        Node *newNode = new Node(n);
        if(start == NULL){
            start = newNode;
            end = newNode;
        }
        else{
            end->next = newNode;
            end= newNode;
        }
        size =size+1;
        
    }

    void pop()
    {
        // CRITICAL: Handle empty queue case!
        if (start == NULL) // Or if (size == 0)
        {
            cout << "Error: queue is empty. Cannot pop." << endl;
            return; // Exit if queue is empty to prevent crash
        }
        Node *temp = start; // Store the current start node
        start = start->next; 
        if(start == NULL){ //if popping last element present
            end = nullptr;
        } // Move start to the next node
        delete temp;      // Delete the old start node to free memory
        size = size - 1;  // Decrement size
    }

    int getstart()
    {
        if (start == NULL)
        {
            cout << " queue is empty. no start element" << endl;

            //exit(EXIT_FAILURE); better practice to throw exceptions
            throw std::out_of_range("queue is empty");
        }
        return start->data;
    }

    int size_queue()
    {

        return size;
    }

    // Add an 'isEmpty' method for clarity and safety checks
    bool isEmpty()
    {
        return start == NULL; // Or return size == 0;
    }

    // Destructor for the queue class: Crucial for memory management!
    // This will correctly deallocate all nodes when the queue object goes out of scope.
     ~queue()
    {
        while (start != NULL)
        {
            Node *temp = start;
            start = start->next;
            delete temp;
        }
        size = 0;                                            // Reset size
        cout <<  "queue destroyed and memory freed." << endl; // Optional: for debugging
    }
};