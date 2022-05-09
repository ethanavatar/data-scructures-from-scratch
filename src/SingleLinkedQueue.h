#ifndef SINGLELINKEDQUEUE_H_INCLUDED
#define SINGLELINKEDQUEUE_H_INCLUDED

#include <iostream>
#include "SingleLinkedList.h"

class SingleLinkedQueue {
    private:
        SingleLinkedList queue;
        int length = 0;

    public:

        void enqueue(int value) {
            queue.prepend(value);
            length++;
        }

        int dequeue() {
            if (isEmpty()) {
                std::cout << "Queue is empty" << std::endl;
                return 1;
            }
            int popped = queue.remove(length - 1);
            length--;
            return popped;

        }

        bool isEmpty() {
            return (length == 0);
        }
};

#endif // SINGLELINKEDQUEUE_H_INCLUDED