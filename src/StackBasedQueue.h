#ifndef STACKBASEDQUEUE_H_INCLUDED
#define STACKBASEDQUEUE_H_INCLUDED

#include "DynamicStack.h"

class StackBasedQueue {
    private:
        DynamicStack s1, s2;

    public:
        void enqueue(int value) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }

            s1.push(value);

            while (!s2.isEmpty()) {
                s1.push(s2.pop());
            }
        }

        int dequeue() {
            if (isEmpty()) throw "Queue is empty";

            return s1.pop();
        }

        bool isEmpty() {
            return s1.isEmpty();
        }
};

#endif // STACKBASEDQUEUE_H_INCLUDED