#ifndef SINGLELINKEDLIST_H_INCLUDED
#define SINGLELINKEDLIST_H_INCLUDED

#include <iostream>

struct SingleLinkedNode {
    int data;
    SingleLinkedNode* next;

    SingleLinkedNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SingleLinkedList {
    private:
        SingleLinkedNode* head;
        SingleLinkedNode* current;

        int length = 0;

        void moveToTail() {
            while (current->next != nullptr) {
                current = current->next;
            }
        }

        void moveToHead() {
            current = head;
        }

        void moveTo(int index) {
            moveToHead();
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
        }

        void emptyAdd(SingleLinkedNode* node) {
            head = node;
            moveToHead();
            length = 1;
        }

        SingleLinkedNode* NewNode(int value) {
            SingleLinkedNode* newNode = new SingleLinkedNode(value);
            if (newNode == nullptr) { 
                std::cout << "Memory allocation failed" << std::endl;
                return nullptr;
            }

            newNode->data = value;
            return newNode;
        }


    public:
        SingleLinkedList() {
            head = nullptr;
            moveToHead();
        }

        ~SingleLinkedList() {
            while (head != nullptr) {
                SingleLinkedNode* temp = head;
                head = head->next;
                delete temp;
            }
        }

        int get_length() { return length; }
        bool is_empty() { return (head == nullptr); }

        void append(int value) {
            SingleLinkedNode* newNode = NewNode(value);
            if (is_empty()) { emptyAdd(newNode); return; }

            moveToTail();
            current->next = newNode;
            length++;
        }

        void prepend(int value) {
            SingleLinkedNode* newNode = NewNode(value);
            if (is_empty()) { emptyAdd(newNode); return; }

            newNode->next = head;
            head = newNode;
            length++;
        }

        void insert(int value, int index) {
            if (index < 0 || index >= length) {
                std::cout << "Index out of range" << std::endl;
                return;
            }

            SingleLinkedNode* newNode = NewNode(value);
            if (is_empty()) { emptyAdd(newNode); return; }

            if (index == 0) { prepend(value); return; }
            if (index == length) { append(value); return; }

            moveTo(index - 1);
            newNode->next = current->next;
            current->next = newNode;
            length++;
        }

        int remove(int index) {
            if (is_empty()) {
                std::cout << "List is empty" << std::endl;
                return 1;
            }
            if (index < 0 || index >= length) {
                std::cout << "Index out of range" << std::endl;
                return 1;
            }

            moveTo(index - 1);

            int value = current->next->data;

            current->next = current->next->next;
            free(current->next);
            length--;

            return value;
        }

        int get(int index) {
            if (is_empty()) {
                std::cout << "List is empty" << std::endl;
                return 1;
            }

            moveTo(index);
            return current->data;
        }
};

#endif // SINGLELINKEDLIST_H_INCLUDED