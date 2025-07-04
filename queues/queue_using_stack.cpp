#include <iostream>
#include <stack> // For std::stack
#include <stdexcept> // For std::runtime_error (a better way to handle errors)

class Queue // Following C++ naming convention for classes
{
private:
    std::stack<int> s1; // For enqueuing elements (acts as input stack)
    std::stack<int> s2; // For dequeuing elements (acts as output stack)

    // Helper function to transfer elements from s1 to s2
    // This is called when s2 is empty and we need to dequeue/front
    void transferElements() {
        if (s2.empty()) { // Only transfer if s2 is truly empty
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    // Constructor (optional, as default will work for std::stack members)
    Queue() {}

    // Enqueue operation (push an element to the back of the queue)
    void push(int x) // Similar to std::queue::push
    {
        s1.push(x); // Simply push onto the input stack
    }

    // Dequeue operation (remove the front element of the queue)
    void pop() // Similar to std::queue::pop
    {
        if (empty()) {
            throw std::runtime_error("Queue is empty. Cannot pop.");
            // Or: std::cout << "Error: Queue is empty. Cannot pop." << std::endl; return;
        }

        transferElements(); // Ensure s2 has elements if s1 has them
        s2.pop(); // Pop from the output stack
    }

    // Get the front element of the queue
    int front() // Similar to std::queue::front
    {
        if (empty()) {
            throw std::runtime_error("Queue is empty. No front element.");
            // Or: std::cout << "Error: Queue is empty. No front element." << std_endl; return -1;
        }

        transferElements(); // Ensure s2 has elements if s1 has them
        return s2.top(); // Return the top of the output stack
    }

    // Check if the queue is empty
    bool empty() const // Using const as it doesn't modify the object
    {
        return s1.empty() && s2.empty(); // Queue is empty if both stacks are empty
    }

    // Get the size of the queue
    // Note: This operation can be O(N) if you don't maintain a separate size counter.
    // For std::stack, size() is O(1). Here, it's sum of two stack sizes.
    int size() const // Using const as it doesn't modify the object
    {
        return s1.size() + s2.size();
    }

    // Destructor (not strictly necessary here as std::stack handles its own memory)
    // ~Queue() {}
};

int main()
{
    Queue myQueue;

    std::cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl; // Yes

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    std::cout << "Queue size: " << myQueue.size() << std::endl; // 3
    std::cout << "Front element: " << myQueue.front() << std::endl; // 10

    myQueue.pop(); // Dequeue 10
    std::cout << "Front after pop: " << myQueue.front() << std::endl; // 20

    myQueue.push(40); // Push 40 (will go to s1)
    std::cout << "Queue size: " << myQueue.size() << std::endl; // 3 (20, 30, 40)

    myQueue.pop(); // Dequeue 20
    std::cout << "Front after pop: " << myQueue.front() << std::endl; // 30

    myQueue.pop(); // Dequeue 30
    myQueue.pop(); // Dequeue 40

    std::cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl; // Yes

    // Test error handling
    try {
        myQueue.pop(); // Should throw an exception
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught error: " << e.what() << std::endl;
    }

    try {
        myQueue.front(); // Should throw an exception
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught error: " << e.what() << std::endl;
    }

    return 0;
}