#ifndef N_DIMENSIONAL_ARRAY_H_INCLUDED
#define N_DIMENSIONAL_ARRAY_H_INCLUDED

#include <iostream>

class NDimensionalArray {
    private:
        int* array;
        int* dimensions;

        int find_item(int* indices) {
            int result = 0;
            for (int i = 0; i < sizeof(dimensions)/sizeof(dimensions[0]); i++) {
                result += indices[i] * dimensions[i];
            }
            return result;
        }

    public:
        NDimensionalArray(int* dimensions) {
            this->dimensions = dimensions;
            int total_items = 1;
            for (int i = 0; i < sizeof(dimensions)/sizeof(dimensions[0]); i++) {
                total_items = total_items * dimensions[i];
            }

            array = (int*)calloc(total_items, sizeof(int));
        }
        
        ~NDimensionalArray() {
            free(array);
        }

        int get(int* indices) {
            int index = find_item(indices);
            return array[index];
        }

        void set(int* indices, int value) {
            int index = find_item(indices);
            array[index] = value;
        }
};

#endif // N_DIMENSIONAL_ARRAY_H_INCLUDED