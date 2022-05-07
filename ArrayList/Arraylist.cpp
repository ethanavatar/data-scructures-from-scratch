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

        ArrayList() {
            size = 0;
            capacity = 1;

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
    ArrayList list;
    list.append(1);
    std::cout << list[0] << std::endl;
}