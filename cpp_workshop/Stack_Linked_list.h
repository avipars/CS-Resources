//stack template implemented via a node and linked list 
#include <iostream>
using namespace std;
template <typename  D>
class noder
{
public:
    D data;
    noder<D> *next;
};

template <typename  T>
class Stack
{
protected:
    int size;
    int capacity = 100;
    noder<T> *top; // head

public:
    Stack();
    Stack(int capacity);
    ~Stack();

    void push(T value);
    void pop();

    T peek() const;
    T front() const;

    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    int getCapacity() const;

    void print() const;
    void clear();
};

template <typename T>
Stack<T>::Stack() : size(0),
                    capacity(100)
{
    top = nullptr;
}

template <typename T>
Stack<T>::Stack(int cap) : size(0)
{
    if (cap <= 0)
    {
        cout << "Invalid capacity" << endl;
        return;
    }
    capacity = cap;
    top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    clear();
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return (top == nullptr || size <= 0);
}

template <typename T>
bool Stack<T>::isFull() const
{
    return (top != nullptr && size >= capacity);
}

template <typename T>
int Stack<T>::getSize() const
{
    return size;    
}

template <typename T>
int Stack<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
void Stack<T>::push(T value)
{
    if (isFull())
    {
        cout << "Stack is full" << endl;
        return;
    }
    noder<T> *newNode = new noder<T>; // create new noder
    newNode->data = value; // assign value to new noder
    newNode->next = top; // assign next noder to top
    top = newNode; // assign new noder to top
     ++size; // increment size
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    noder<T> *temp = top; // assign top to temp
    top = top->next; // assign next noder to top
    delete temp; // delete temp
    temp = nullptr; // set temp to nullptr
    --size; // decrement size
}

template <typename T>
T Stack<T>::peek() const
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return top->data;
}

template <typename T>
T Stack<T>::front() const
{
    return peek();
}

template <typename T>
void Stack<T>::clear(){
    while(!isEmpty()){
        pop();
    }
    size = 0;
    capacity = 0;
}
template <typename T>
void Stack<T>::print() const
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    noder<T> *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
