#ifndef SINGLELINKEDSTACK_H_INCLUDED
#define SINGLELINKEDSTACK_H_INCLUDED

#include <iostream>
#include "SingleLinkedList.hpp"


class SingleLinkedStack {
    private:
        SingleLinkedList stack;
        int top = -1;

    public:

        void push(int value) {
            stack.append(value);
            top++;
        }

        int pop() {
            if (isEmpty()) {
                std::cout << "Stack is empty" << std::endl;
                return 1;
            }

            return stack.remove(top--);
        }

        int peek() { return stack.get(top); }

        int get_size() { return top; }

        bool isEmpty() { return (top == 0); }
};


#endif // SINGLELINKEDSTACK_H_INCLUDED