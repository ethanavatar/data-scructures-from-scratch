#include <iostream>

struct Stack {
    int* stack;
    int top = 0;

    Stack(int capacity) { stack = new int[capacity]; }

    void push(int value) { stack[top++] = value; }

    int pop() { return stack[--top]; }

    int peek() { return stack[top]; }

    int size() { return top; }

    bool isEmpty() { return (top == 0); }
};

int main () {
    Stack s = Stack(10);
    s.push(1);
    s.push(2);
    s.push(3);
    int three = s.pop();

    std::cout << three << std::endl;
}