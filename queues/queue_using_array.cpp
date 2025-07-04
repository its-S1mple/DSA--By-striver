#include <iostream>
using namespace std;

class Q
{
public:
    int size = 10;
    int q[10];
    int curr_size = 0;
    int start = -1;
    int end = -1;

    void push(int n)
    {

        if (curr_size == size)
        {
            cout << " queue is full" << endl;
            return;
        }
        if (curr_size == 0)
        {
            start = (start + 1) % size;
            end = (end + 1) % size;
        }
        else
        {
            end = (end + 1) % size;
        }
        q[end] = n;
        curr_size += 1;
    }

    void pop()
    {
        if (curr_size == 0)
        {
            cout << " Queue is empty." << endl;
            return;
        }
        int el = q[start];
        if (curr_size == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {

            start = (start + 1) % size;
        }
        cout << " element " << el << " is removed from the queue" << endl;
        curr_size -= 1;
    }

    int top()
    {
        if (curr_size == 0)
        {
            cout << " Queue is Empty." << endl;
           exit(EXIT_FAILURE);
        }
        return q[start];
    }

    int size_Queue()
    {
        return curr_size;
    }
};

int main()

{
    Q myqueue;
    cout << myqueue.size_Queue() << endl;
    myqueue.push(11);
    cout << "size of queue is " << myqueue.size_Queue() << endl;
    cout << "Top of queue is " << myqueue.top() << endl;
    myqueue.push(23);
    cout << "size of queue is " << myqueue.size_Queue() << endl;
    cout << "Top of queue is " << myqueue.top() << endl;
    myqueue.push(57);
    cout << "size of queue is " << myqueue.size_Queue() << endl;
    cout << "Top of queue is " << myqueue.top() << endl;
    myqueue.pop();
    cout << "size of queue is " << myqueue.size_Queue() << endl;
    cout << "Top of queue is " << myqueue.top() << endl;
    myqueue.pop();
    cout << "size of queue is " << myqueue.size_Queue() << endl;
    cout << "Top of queue is " << myqueue.top() << endl;
    myqueue.pop();
    cout << "size of queue is " << myqueue.size_Queue() << endl;
    cout << "Top of queue is " << myqueue.top() << endl;
    
    myqueue.push(15);
    myqueue.push(6);
    myqueue.pop();
    cout<<"size of queue is "<<myqueue.size_Queue()<<endl;
    cout<<"Top of queue is "<<myqueue.top()<<endl;
    myqueue.push(8);

    cout<<"size of queue is "<<myqueue.size_Queue()<<endl;
    cout<<"Top of queue is "<<myqueue.top()<<endl;

    myqueue.pop();

    return 0;
}