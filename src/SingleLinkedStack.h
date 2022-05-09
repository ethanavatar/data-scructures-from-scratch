#ifndef SINGLELINKEDSTACK_H_INCLUDED
#define SINGLELINKEDSTACK_H_INCLUDED

#include <iostream>
#include "SingleLinkedList.h"

class SingleLinkedStack {
    private:
        SingleLinkedList* stack;
        int top = 0;

    public:
        SingleLinkedStack() {
            stack = new SingleLinkedList();
            top = 0;
        }

        ~SingleLinkedStack() {
            delete stack;
        }

        void push(int value) {
            stack->append(value);
            top++;
        }

        int pop() {
            if (isEmpty()) throw "Stack is empty";

            return stack->remove(top--);
        }

        int peek() { return stack->get(top); }

        int get_size() { return top; }

        bool isEmpty() { return (top == 0); }
};

#endif // SINGLELINKEDSTACK_H_INCLUDED