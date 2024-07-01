
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <memory>

namespace wstd {
    template<typename T>
class arraylist {
    public:
        explicit arraylist(const size_t initCapacity) : capacity(initCapacity) {
            array = new T[capacity];
        }

        ~arraylist() {
            for (size_t i = 0; i < capacity; i++) {
                array[i].~T();
            }

            ::operator delete [](array);
        }

        [[nodiscard]] size_t get_size() const { return size; }

        void resize(const size_t newCapacity) {
            T* newArray = new T[newCapacity];
            capacity = newCapacity;

            for (size_t i = 0; i < capacity; i++) {
                newArray[i] = std::move(array[i]);
                array[i].~T();
            }

            delete [] array;

            array = newArray;
        }

        void push_back(const T& newData) {
            if (size == capacity) {
                resize(capacity +  (capacity / 2));
            }

            array[size] = newData;
            size++;
        }

        T& operator [] (const size_t index) {
            return array[index];
        }

    private:
        T* array{};
        size_t size = 0;
        size_t capacity{};
    };
}

#endif //ARRAYLIST_H
