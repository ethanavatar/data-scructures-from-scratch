#include <iostream>

class ArrayList {
    private:
        int size;
        int capacity;
        int* items;

        void resize(int newSize) {
            int* newItems = (int*)malloc(newSize * sizeof(int));
            for (int i = 0; i < size; i++) {
                newItems[i] = items[i];
            }
            free(items);
            items = newItems;
            capacity = newSize;
        }

    public:

        int operator [] (int index) {
            return items[index];
        }

        ArrayList(int initValues) {
            size = initValues.length;
            capacity = initValues.length;
            items = NULL;
            for (int i = 0; i < initValues.length; i++) {
                append(initValues[i]);
            }
        }

        ~ArrayList() {
            clear();
        }

        int get(int index) {
            if (index < 0 || index >= size) {
                throw "Index out of bounds";
            }
            return items[index];
        }

        void set(int index, int value) {
            items[index] = value;
        }

        void append(int value) {
            if (size == capacity) {
                resize(capacity * 2);
            }
            items[size] = value;
            size++;
        }

        void insert(int index, int value) {
            if (index < 0 || index > size) {
                throw "Index out of bounds";
            }
            if (size == capacity) {
                resize(capacity * 2);
            }
            for (int i = size; i > index; i--) {
                items[i] = items[i - 1];
            }
            items[index] = value;
            size++;
        }

        void remove(int index) {
            if (index < 0 || index >= size) {
                throw "Index out of bounds";
            }
            for (int i = index; i < size - 1; i++) {
                items[i] = items[i + 1];
            }
            size--;
        }

        int length() {
            return size;
        }

        void clear() {
            free(items);
        }
};

int main() {
    ArrayList list = {1, 2, 3, 4, 5};
    std::cout << list[0] << std::endl;
}