#ifndef SINGLELINKEDLIST_H_INCLUDED
#define SINGLELINKEDLIST_H_INCLUDED

#include <iostream>

struct SingleLinkedNode {
    int data;
    SingleLinkedNode* next = nullptr;
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

    public:
        SingleLinkedList() {
            head = nullptr;
            moveToHead();
        }
        ~SingleLinkedList() {
            // Idk if this works
            while (head != nullptr) {
                SingleLinkedNode* temp = head;
                head = head->next;
                delete temp;
            }
        }

        // TODO: Check if this is proper use of references
        int* operator [] (int index) {
            if (index < 0 || index >= length) {
                throw "Index out of bounds";
            }
            
            moveToHead();
            for (int i = 0; i < index; i++) {
                current = current->next;
            }

            return &current->data;
        }

        int get_length() { return length; }

        void append(int value) {
            SingleLinkedNode* newNode = (SingleLinkedNode*)malloc(sizeof(SingleLinkedNode));
            newNode->data = value;

            if (head == nullptr) {
                head = newNode;
                current = head;
                return;
            }

            moveToTail();

            current->next = newNode;

            moveToHead();

            length++;
        }

        void prepend(int value) {
            SingleLinkedNode* newNode = (SingleLinkedNode*)malloc(sizeof(SingleLinkedNode));
            newNode->data = value;

            newNode->next = head;
            head = newNode;

            moveToHead();

            length++;
        }

        void insert(int value, int index) {
            SingleLinkedNode* newNode = (SingleLinkedNode*)malloc(sizeof(SingleLinkedNode));
            newNode->data = value;

            moveToHead();
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;

            moveToHead();

            length++;
        }

        void remove(int index) {
            moveToHead();
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            current->next = current->next->next;
            free(current->next);

            moveToHead();

            length--;
        }

        void print() {
            moveToHead();
            while (current->next != nullptr) {
                std::cout << current->next->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
};

#endif // SINGLELINKEDLIST_H_INCLUDED