#ifndef DYNAMICSTACK_H_INCLUDED
#define DYNAMICSTACK_H_INCLUDED

#include <iostream>

class DynamicStack {
    private:
        int* stack;
        int top = 0;
        int capacity = 1;

        void resize(int newCapacity) {
            stack = (int*)realloc(stack, newCapacity * sizeof(int));
            capacity = newCapacity;
        }

        bool isFull() { return (top == capacity); }

    public:
        DynamicStack() {
            stack = (int*)calloc(capacity, sizeof(int));
        }

        ~DynamicStack() {
            free(stack);
        }

        void push(int value) {
            if (isFull()) resize(capacity * 2);

            stack[++top] = value;
        }

        int pop() {
            if (isEmpty()) {
                std::cout << "Stack is empty" << std::endl;
                return 1;
            }

            return stack[top--];
        }

        int peek() { return stack[top]; }

        int get_size() { return top; }

        int get_capacity() { return capacity; }

        bool isEmpty() { return (top == 0); }
};

#endif // DYNAMICSTACK_H_INCLUDED