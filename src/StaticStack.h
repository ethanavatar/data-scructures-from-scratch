#ifndef STATICSTACK_H_INCLUDED
#define STATICSTACK_H_INCLUDED

class StaticStack {
    private:
        int* stack;
        int top = 0;
        int capacity;

    public:
        StaticStack(int capacity) {
            stack = new int[capacity];
            this->capacity = capacity;
        }

        void push(int value) {
            if (top == capacity) {
                throw "Stack is full";
            }
            stack[++top] = value;
        }

        int pop() {
            if (isEmpty()) throw "Stack is empty";

            return stack[top--];
        }

        int peek() { return stack[top]; }

        int get_size() { return top; }

        bool isEmpty() { return (top == 0); }

        bool isFull() { return (top == capacity); }
};

#endif // STATICSTACK_H_INCLUDED