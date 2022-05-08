#include <iostream>

#include "StaticStack.h"
#include "DynamicStack.h"

#include "StackBasedQueue.h"

void testStaticStack() {
    StaticStack s = StaticStack(10);
    s.push(1);
    s.push(2);
    int two = s.pop();

    std::cout << two << std::endl;
    std::cout << s.peek() << std::endl;
}

void testDynamicStack() {
    DynamicStack s;
    for (int i = 0; i < 10; i++) {
        s.push(1);
        std::cout << i << " : " << s.peek() << ", capacity: " << s.get_capacity() << std::endl;
    }
}

void testStackBasedQueue() {
    StackBasedQueue s;
    s.enqueue(1);
    s.enqueue(2);
    
    std::cout << s.dequeue() << std::endl;
}

int main () {
    //testStaticStack();
    //testDynamicStack();

    //testStackBasedQueue();
}