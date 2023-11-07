#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Ki?m tra xem stack có r?ng không
    bool isEmpty() {
        return top == -1;
    }

    // Ki?m tra xem stack có d?y không
    bool isFull() {
        return top == capacity - 1;
    }

    // Ð?y m?t ph?n t? vào stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // L?y m?t ph?n t? t? stack và tr? v? giá tr? dó
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Giá tr? m?c d?nh cho tru?ng h?p stack r?ng
        }
        int poppedValue = arr[top--];
        return poppedValue;
    }

    // In n?i dung c?a stack
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack content: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack myStack(5); // Kh?i t?o m?t stack có dung lu?ng là 5

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.printStack();

    int poppedValue = myStack.pop();
    if (poppedValue != -1) {
        cout << "Popped " << poppedValue << " from the stack." << endl;
    }

    myStack.printStack();

    return 0;
}

